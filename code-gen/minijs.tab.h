/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MINIJS_TAB_H_INCLUDED
# define YY_YY_MINIJS_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    _VARDEC = 258,                 /* _VARDEC  */
    _FUNCDEC = 259,                /* _FUNCDEC  */
    _ARROW = 260,                  /* _ARROW  */
    _COMMA = 261,                  /* _COMMA  */
    _WHILE = 262,                  /* _WHILE  */
    _BREAK = 263,                  /* _BREAK  */
    _CONTINUE = 264,               /* _CONTINUE  */
    _POSTINCREMENT = 265,          /* _POSTINCREMENT  */
    _POSTDECREMENT = 266,          /* _POSTDECREMENT  */
    _IF = 267,                     /* _IF  */
    _ELSE = 268,                   /* _ELSE  */
    _RETURN = 269,                 /* _RETURN  */
    _ID = 270,                     /* _ID  */
    _NUMBER = 271,                 /* _NUMBER  */
    _LPAREN = 272,                 /* _LPAREN  */
    _RPAREN = 273,                 /* _RPAREN  */
    _LBRACKET = 274,               /* _LBRACKET  */
    _RBRACKET = 275,               /* _RBRACKET  */
    _ASSIGN = 276,                 /* _ASSIGN  */
    _SEMICOLON = 277,              /* _SEMICOLON  */
    _AROP = 278,                   /* _AROP  */
    _RELOP = 279,                  /* _RELOP  */
    ONLY_IF = 280                  /* ONLY_IF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "minijs.y"

  int i;
  char *s;

#line 94 "minijs.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MINIJS_TAB_H_INCLUDED  */
