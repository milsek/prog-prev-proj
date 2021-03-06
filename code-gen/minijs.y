%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int arg_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  int loop_num = -1;
  int current_loop = -1;
  int parent_loop = -1;
  int mul_num = -1;
  FILE *output;
%}

%union {
  int i;
  char *s;
}

%token <i> _VARDEC
%token _FUNCDEC
%token _ARROW
%token _COMMA
%token _WHILE
%token _FOR
%token _BREAK
%token _CONTINUE
%token _POSTINCREMENT
%token _POSTDECREMENT
%token _QMARK
%token _COLON


%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token <i> _RELOP

%type <i> num_exp exp literal
%type <i> function_call argument rel_exp if_part arguments argument_list ternary_exp for_statement

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : global_list function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
  ;

global_list
  : /* empty */
  | global_list global_var
  ;
global_var
  : _VARDEC _ID _SEMICOLON
      {
        int idx = lookup_symbol($2, GLET|GCONST);
        if (idx != NO_INDEX) {
          err("redefinition of '%s'", $2);
        }
        else {
          if ($1 == LET)
            insert_symbol($2, GLET, NUMBER, NO_ATR, NO_ATR);
          else if ($1 == CONST)
            err("At this point only LET variables can be global.");
          code("\n%s:\n\t\tWORD\t1", $2);
        }
      }
;

function_list
  : function
  | function_list function
  ;

function
  : _FUNCDEC _ID
      {
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, NUMBER, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", $2);

        arg_num = 0;
        code("\n%s:", $2);
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
    _LPAREN parameters _RPAREN body
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }

  | _VARDEC _ID _ASSIGN
      {
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, NUMBER, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", $2);

        arg_num = 0;
        code("\n%s:", $2);
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
    arrow_parameters _ARROW body
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }

    | _VARDEC _ID _ASSIGN
      {
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, NUMBER, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", $2);

        arg_num = 0;
        code("\n%s:", $2);
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
    _FUNCDEC _LPAREN parameters _RPAREN body
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
  ;

parameters
  : /* empty */
      { set_atr1(fun_idx, 0); }
  | parameter_list
  ;

arrow_parameters
  : _LPAREN /* empty */ _RPAREN
      { set_atr1(fun_idx, 0); }
  | parameter
  | _LPAREN parameter_list _RPAREN
  ;

parameter_list
  : parameter
  | parameter_list _COMMA parameter
  ;

parameter
  : _ID
      {
        insert_symbol($1, PAR, NUMBER, get_atr1(fun_idx) + 1, NO_ATR);
        set_atr1(fun_idx, get_atr1(fun_idx) + 1);
        set_atr2(fun_idx, NUMBER);
      }
  ;

body
  : _LBRACKET variable_list
      {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
    statement_list _RBRACKET
  ;

variable_list
  : /* empty */
  | variable_list variable
  ;

variable
  : _VARDEC _ID _SEMICOLON
      {
        if ($1 == CONST) {
          err("Const variable has to be initialized with a value!");
        }
        if(lookup_symbol($2, PAR|LET|CONST|GLET|GCONST) == NO_INDEX)
           insert_symbol($2, $1, NUMBER, ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", $2);
      }
  | _VARDEC _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($2, PAR|LET|CONST|GLET|GCONST);
        if(idx == NO_INDEX)
           idx = insert_symbol($2, $1, NUMBER, ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", $2);
        set_atr2(idx, 1);
        gen_mov($4, idx);
      }
  ;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | return_statement
  | while_statement
  | for_statement
  | break_statement
  | continue_statement
  | postincrement_statement
  | postdecrement_statement
  ;

while_statement
  : _WHILE
      {
        $<i>$ = ++loop_num;
        parent_loop = current_loop;
        current_loop = loop_num;
        code("\n@loop_%d:", loop_num);
      }
    _LPAREN rel_exp _RPAREN
      {
        code("\n\t\t%s\t@end_loop_%d", opp_jumps[$4], loop_num);
      }
      statement
      {
        code("\n\t\tJMP\t\t@loop_%d", $<i>2);
        code("\n@end_loop_%d:", $<i>2);
        current_loop = parent_loop;
      }
;

for_statement
  : _FOR _LPAREN _VARDEC _ID _ASSIGN literal
      {
        $<i>$ = ++loop_num;
        parent_loop = current_loop;
        current_loop = loop_num;
        int i = lookup_symbol($4, LET|GLET|CONST|GCONST|PAR);
        if (i != NO_INDEX)
          err("redefinition of %s", $4);
        else
          i = insert_symbol($4, $3, NUMBER, ++var_num, NO_ATR);
        gen_mov($6, i);
        code("\n@loop_%d:", loop_num);
      }
  _SEMICOLON rel_exp
      {
        code("\n\t\t%s\t@end_loop_%d", opp_jumps[$9], $<i>7);
      }
  _SEMICOLON _ID _POSTINCREMENT _RPAREN statement
      {
        int i = lookup_symbol($12, LET|GLET|CONST|GCONST|PAR);
        if (i == NO_INDEX)
          err("undecalred %s", $12);
        else if (get_kind(i) == CONST || get_kind(i) == GCONST)
          err("cannot increment const variable %s", $12);

        code("\n\t\tADDS\t");
        gen_sym_name(i);
        code(", $1, ");
        gen_sym_name(i);

        code("\n\t\tJMP \t@loop_%d", $<i>7);
        code("\n@end_loop_%d:", $<i>7);
      }
    ;
break_statement
  : _BREAK _SEMICOLON
      {
        if (current_loop > -1) {
          code("\n\t\tJMP\t@end_loop_%d", current_loop);
        }
      }
  ;

continue_statement
  : _CONTINUE _SEMICOLON
      {
        if (current_loop > -1) {
          code("\n\t\tJMP\t@loop_%d", current_loop);
        }
      }
  ;

postincrement_statement
  : _ID _POSTINCREMENT _SEMICOLON
      {
        int idx = lookup_symbol($1, LET|GLET|PAR|CONST|GCONST);
        if (get_atr2(idx) == 1 && (get_kind(idx) == CONST || get_kind(idx) == GCONST)) {
          err("Cannot increment const variable %s", $1);
        }
        else if (idx == NO_INDEX)
          err("'%s' undeclared", $1);
        else {
          code("\n\t\tADDS\t");
          gen_sym_name(idx);
          code(", $1,");
          gen_sym_name(idx);
        }
      }
  ;

postdecrement_statement
  : _ID _POSTDECREMENT _SEMICOLON
      {
        int idx = lookup_symbol($1, LET|GLET|PAR|CONST|GCONST);
        if (get_atr2(idx) == 1 && (get_kind(idx) == CONST || get_kind(idx) == GCONST)) {
          err("Cannot decrement const variable %s", $1);
        }
        else if (idx == NO_INDEX)
          err("'%s' undeclared", $1);
        else {
          code("\n\t\t\tSUBS\t");
          gen_sym_name(idx);
          code(", $1,");
          gen_sym_name(idx);
        }
      }
  ;

compound_statement
  : _LBRACKET statement_list _RBRACKET
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, PAR|LET|CONST|GLET|GCONST);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        if (get_atr2(idx) == 1 && (get_kind(idx) == CONST || get_kind(idx) == GCONST)) {
          err("Cannot reassign const value!");
        }
        set_atr2(idx, 1);
        gen_mov($3, idx);
      }
  ;

num_exp
  : exp

  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: arithmetic operation");
        if ($2 == ADD || $2 == SUB) {
          int t1 = get_type($1);    
          code("\n\t\t%s\t", ar_instructions[$2 + (t1 - 1) * AROP_NUMBER]);
          gen_sym_name($1);
          code(",");
          gen_sym_name($3);
          code(",");
          free_if_reg($3);
          free_if_reg($1);
          $$ = take_reg();
          gen_sym_name($$);
          set_type($$, t1);
        }
        else if ($2 == MUL) {
          int mul = ++mul_num;
          int counter = take_reg();
          $$ = take_reg();
          gen_mov($3, counter);
          code("\n\t\tMOV\t");
          code("\t$0, ");
          gen_sym_name($$);

          code("\n@mul_%d:", mul_num);

          code("\n\t\tCMPS \t");
          gen_sym_name(counter);
          code(", $0");
          code("\n\t\tJLTS\t@mul_neg_%d", mul_num);

          // positive multiplication
          code("\n@mul_pos_%d:", mul_num);
          code("\n\t\tCMPS\t");
          gen_sym_name(counter);
          code(", $0");
          code("\n\t\tJEQ\t\t@end_mul_%d", mul_num);

          code("\n\t\tADDS\t");
          gen_sym_name($$);
          code(", ");
          gen_sym_name($1);
          code(", ");
          gen_sym_name($$);

          code("\n\t\tSUBS\t");
          gen_sym_name(counter);
          code(", $1");
          code(", ");
          gen_sym_name(counter);
          code("\n\t\tJMP\t\t@mul_pos_%d", mul_num);


          // negative multiplication
          code("\n@mul_neg_%d:", mul_num);
          code("\n\t\tCMPS \t");
          gen_sym_name(counter);
          code(", $0");
          code("\n\t\tJEQ\t\t@end_mul_%d", mul_num);

          code("\n\t\tSUBS\t");
          gen_sym_name($$);
          code(", ");
          gen_sym_name($1);
          code(", ");
          gen_sym_name($$);

          code("\n\t\tADDS\t");
          gen_sym_name(counter);
          code(", $1");
          code(", ");
          gen_sym_name(counter);
          code("\n\t\tJMP\t\t@mul_neg_%d", mul_num);

          code("\n@end_mul_%d:", mul_num);
          free_if_reg($3);
          free_if_reg($1);
          free_if_reg(counter);
        }
      }
  ;

exp
  : literal
  | _ID
      {
        $$ = lookup_symbol($1, PAR|LET|CONST|GLET|GCONST);
        if (get_kind($$) == PAR) {
          set_atr1($$, get_atr1(fun_idx) - get_atr1($$));
        }
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
      }
  | function_call
      {
        $$ = take_reg();
        gen_mov(FUN_REG, $$);
      }
  | _LPAREN num_exp _RPAREN
      { $$ = $2; }
  | _LPAREN rel_exp _RPAREN _QMARK ternary_exp _COLON ternary_exp
      {
        int out = take_reg();
        lab_num++;
        if(get_type($5) != get_type($7))
          err("Ternary operator type mismatch!");
        code("\n\t\t%s\t@false%d", opp_jumps[$2], lab_num);
        code("\n@true%d:", lab_num);
        gen_mov($5, out);
        code("\n\t\tJMP \t@exit%d", lab_num);
        code("\n@false%d:", lab_num);
        gen_mov($7, out);
        code("\n@exit%d:", lab_num);
        $$ = out;
      }
  ;

ternary_exp
  : _ID
      {
        if(($$ = lookup_symbol($1, (LET|CONST|PAR|GLET|GCONST))) == NO_INDEX )
          err("'%s' undeclared", $1);
      }
  | literal
  ;

literal
  : _NUMBER
      { 
        $$ = insert_literal($1, NUMBER);
      }
  ;

function_call
  : _ID 
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
      }
    _LPAREN arguments _RPAREN
      {
        if(get_atr1(fcall_idx) != $4)
          err("wrong number of arguments. should be %d, but %d were given.", get_atr1(fcall_idx), $4 );
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if($4 > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", $4 * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        $$ = FUN_REG;
      }
  ;

arguments
  : /* empty */
    { $$ = 0; }
  | argument_list
    {
      $$ = $1;
    }
  ;

argument_list
  : argument { $$ = 1; }
  | argument_list _COMMA argument { $$ = $$ + 1; }
  ;

argument
  : num_exp
    {
      free_if_reg($1);
      code("\n\t\t\tPUSH\t");
      gen_sym_name($1);
      $$ = 1;
    }
  ;

if_statement
  : if_part %prec ONLY_IF
      { code("\n@exit%d:", $1); }

  | if_part _ELSE statement
      { code("\n@exit%d:", $1); }
  ;

if_part
  : _IF _LPAREN
      {
        $<i>$ = ++lab_num;
        code("\n@if%d:", lab_num);
      }
    rel_exp
      {
        code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3);
        code("\n@true%d:", $<i>3);
      }
    _RPAREN statement
      {
        code("\n\t\tJMP \t@exit%d", $<i>3);
        code("\n@false%d:", $<i>3);
        $$ = $<i>3;
      }
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: relational operator");
        $$ = $2 + ((get_type($1) - 1) * RELOP_NUMBER);
        gen_cmp($1, $3);
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      {
        // if(get_type(fun_idx) != get_type($2))
        //   err("incompatible types in return");
        gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
  ;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

