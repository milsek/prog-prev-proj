/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "minijs.y"

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
  int while_num = -1;
  int current_while = -1;
  int parent_while = -1;
  FILE *output;

#line 99 "minijs.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "minijs.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__VARDEC = 3,                    /* _VARDEC  */
  YYSYMBOL__FUNCDEC = 4,                   /* _FUNCDEC  */
  YYSYMBOL__ARROW = 5,                     /* _ARROW  */
  YYSYMBOL__COMMA = 6,                     /* _COMMA  */
  YYSYMBOL__WHILE = 7,                     /* _WHILE  */
  YYSYMBOL__BREAK = 8,                     /* _BREAK  */
  YYSYMBOL__CONTINUE = 9,                  /* _CONTINUE  */
  YYSYMBOL__POSTINCREMENT = 10,            /* _POSTINCREMENT  */
  YYSYMBOL__POSTDECREMENT = 11,            /* _POSTDECREMENT  */
  YYSYMBOL__IF = 12,                       /* _IF  */
  YYSYMBOL__ELSE = 13,                     /* _ELSE  */
  YYSYMBOL__RETURN = 14,                   /* _RETURN  */
  YYSYMBOL__ID = 15,                       /* _ID  */
  YYSYMBOL__NUMBER = 16,                   /* _NUMBER  */
  YYSYMBOL__LPAREN = 17,                   /* _LPAREN  */
  YYSYMBOL__RPAREN = 18,                   /* _RPAREN  */
  YYSYMBOL__LBRACKET = 19,                 /* _LBRACKET  */
  YYSYMBOL__RBRACKET = 20,                 /* _RBRACKET  */
  YYSYMBOL__ASSIGN = 21,                   /* _ASSIGN  */
  YYSYMBOL__SEMICOLON = 22,                /* _SEMICOLON  */
  YYSYMBOL__AROP = 23,                     /* _AROP  */
  YYSYMBOL__RELOP = 24,                    /* _RELOP  */
  YYSYMBOL_ONLY_IF = 25,                   /* ONLY_IF  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_program = 27,                   /* program  */
  YYSYMBOL_global_list = 28,               /* global_list  */
  YYSYMBOL_global_var = 29,                /* global_var  */
  YYSYMBOL_function_list = 30,             /* function_list  */
  YYSYMBOL_function = 31,                  /* function  */
  YYSYMBOL_32_1 = 32,                      /* $@1  */
  YYSYMBOL_33_2 = 33,                      /* $@2  */
  YYSYMBOL_34_3 = 34,                      /* $@3  */
  YYSYMBOL_parameters = 35,                /* parameters  */
  YYSYMBOL_arrow_parameters = 36,          /* arrow_parameters  */
  YYSYMBOL_parameter_list = 37,            /* parameter_list  */
  YYSYMBOL_parameter = 38,                 /* parameter  */
  YYSYMBOL_body = 39,                      /* body  */
  YYSYMBOL_40_4 = 40,                      /* $@4  */
  YYSYMBOL_variable_list = 41,             /* variable_list  */
  YYSYMBOL_variable = 42,                  /* variable  */
  YYSYMBOL_statement_list = 43,            /* statement_list  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_while_statement = 45,           /* while_statement  */
  YYSYMBOL_46_5 = 46,                      /* @5  */
  YYSYMBOL_47_6 = 47,                      /* $@6  */
  YYSYMBOL_break_statement = 48,           /* break_statement  */
  YYSYMBOL_continue_statement = 49,        /* continue_statement  */
  YYSYMBOL_postincrement_statement = 50,   /* postincrement_statement  */
  YYSYMBOL_postdecrement_statement = 51,   /* postdecrement_statement  */
  YYSYMBOL_compound_statement = 52,        /* compound_statement  */
  YYSYMBOL_assignment_statement = 53,      /* assignment_statement  */
  YYSYMBOL_num_exp = 54,                   /* num_exp  */
  YYSYMBOL_exp = 55,                       /* exp  */
  YYSYMBOL_literal = 56,                   /* literal  */
  YYSYMBOL_function_call = 57,             /* function_call  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_arguments = 59,                 /* arguments  */
  YYSYMBOL_argument_list = 60,             /* argument_list  */
  YYSYMBOL_argument = 61,                  /* argument  */
  YYSYMBOL_if_statement = 62,              /* if_statement  */
  YYSYMBOL_if_part = 63,                   /* if_part  */
  YYSYMBOL_64_8 = 64,                      /* @8  */
  YYSYMBOL_65_9 = 65,                      /* $@9  */
  YYSYMBOL_rel_exp = 66,                   /* rel_exp  */
  YYSYMBOL_return_statement = 67           /* return_statement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    76,    77,    80,    97,    98,   103,   102,
     127,   126,   151,   150,   177,   178,   182,   184,   185,   189,
     190,   194,   204,   203,   213,   214,   218,   228,   241,   242,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   259,
     266,   258,   278,   287,   296,   314,   332,   336,   350,   352,
     371,   372,   382,   388,   393,   401,   400,   420,   421,   428,
     429,   433,   445,   448,   454,   459,   453,   472,   482
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "_VARDEC", "_FUNCDEC",
  "_ARROW", "_COMMA", "_WHILE", "_BREAK", "_CONTINUE", "_POSTINCREMENT",
  "_POSTDECREMENT", "_IF", "_ELSE", "_RETURN", "_ID", "_NUMBER", "_LPAREN",
  "_RPAREN", "_LBRACKET", "_RBRACKET", "_ASSIGN", "_SEMICOLON", "_AROP",
  "_RELOP", "ONLY_IF", "$accept", "program", "global_list", "global_var",
  "function_list", "function", "$@1", "$@2", "$@3", "parameters",
  "arrow_parameters", "parameter_list", "parameter", "body", "$@4",
  "variable_list", "variable", "statement_list", "statement",
  "while_statement", "@5", "$@6", "break_statement", "continue_statement",
  "postincrement_statement", "postdecrement_statement",
  "compound_statement", "assignment_statement", "num_exp", "exp",
  "literal", "function_call", "$@7", "arguments", "argument_list",
  "argument", "if_statement", "if_part", "@8", "$@9", "rel_exp",
  "return_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -84,     4,    54,   -84,     3,     7,   -84,    66,   -84,    55,
     -84,    12,   -84,    34,   -84,    25,    24,    13,    49,    45,
     -84,    -4,    57,   -84,    47,    63,    69,   -84,   -84,    -1,
      53,    45,    53,    45,   -84,   -84,   -84,    72,   -84,   -84,
      88,    53,    77,   -84,   -84,   -84,    58,     1,    39,   -84,
     -84,    71,    73,    79,    39,    38,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,    81,   -84,    80,
     -84,    39,    60,   -84,   -84,   -84,    82,   -84,   -84,   -84,
      62,    76,    78,    39,    17,    59,    84,   -11,   -84,    39,
      39,    39,   -84,   -84,   -84,    64,   -84,   -84,    39,   -84,
     -84,    65,    85,   -84,   -84,    83,    86,    96,   -84,    39,
     -84,    87,   -84,    39,    83,    89,    59,   -84,   -84,   -84,
      32,   -84
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     4,     2,     6,     0,
       8,     0,     7,    10,     5,     0,     0,     0,     0,    14,
      21,     0,     0,    17,     0,     0,    15,    19,    16,     0,
       0,    14,     0,     0,    18,    24,    11,     0,     9,    20,
      22,     0,     0,    28,    25,    13,     0,     0,     0,    26,
      39,     0,     0,     0,     0,     0,    28,    23,    29,    34,
      35,    36,    37,    38,    30,    31,    32,    62,    33,    51,
      54,     0,     0,    48,    50,    52,     0,    42,    43,    64,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,    68,    44,    45,     0,    46,    63,    57,    53,
      49,     0,     0,    65,    47,    61,     0,    58,    59,     0,
      40,     0,    56,     0,    67,     0,     0,    60,    28,    66,
       0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   -84,   -84,   -84,   100,   -84,   -84,   -84,    90,
     -84,    91,   -14,     2,   -84,   -84,   -84,   -55,   -83,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -48,    20,
     -84,   -84,   -84,   -84,   -84,    -3,   -84,   -84,   -84,   -84,
      22,   -84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,    15,    17,    18,    25,
      22,    26,    27,    36,    43,    40,    44,    47,    58,    59,
      76,   115,    60,    61,    62,    63,    64,    65,   101,    73,
      74,    75,    86,   106,   107,   108,    66,    67,    91,   111,
     102,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      72,    84,    97,    23,     3,    33,    80,    99,    50,    51,
      52,    20,    89,    53,    28,    54,    55,    34,     9,    39,
      56,    57,    10,    87,    50,    51,    52,    16,    20,    53,
      21,    54,    55,   119,    38,    95,    56,    96,   -12,    50,
      51,    52,    19,    45,    53,    13,    54,    55,    81,    82,
     105,    56,   121,    24,    69,    70,    71,     4,     5,    83,
      20,   114,    30,   120,    31,   105,    50,    51,    52,    11,
       5,    53,    35,    54,    55,    33,    13,    14,    56,    48,
      49,    32,    88,    89,    92,    89,   104,    89,    89,   109,
      41,    42,    46,    77,    85,    78,    79,   -55,    93,    90,
      94,    98,   113,   110,   112,   116,    89,    12,   118,   100,
     117,     0,    29,   103,     0,     0,     0,     0,     0,     0,
       0,    37
};

static const yytype_int8 yycheck[] =
{
      48,    56,    85,    17,     0,     6,    54,    18,     7,     8,
       9,    15,    23,    12,    18,    14,    15,    18,    15,    33,
      19,    20,    15,    71,     7,     8,     9,    15,    15,    12,
      17,    14,    15,   116,    32,    83,    19,    20,     4,     7,
       8,     9,    17,    41,    12,    21,    14,    15,    10,    11,
      98,    19,    20,     4,    15,    16,    17,     3,     4,    21,
      15,   109,     5,   118,    17,   113,     7,     8,     9,     3,
       4,    12,    19,    14,    15,     6,    21,    22,    19,    21,
      22,    18,    22,    23,    22,    23,    22,    23,    23,    24,
      18,     3,    15,    22,    13,    22,    17,    17,    22,    17,
      22,    17,     6,    18,    18,    18,    23,     7,    19,    89,
     113,    -1,    21,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,     0,     3,     4,    29,    30,    31,    15,
      15,     3,    31,    21,    22,    32,    15,    33,    34,    17,
      15,    17,    36,    38,     4,    35,    37,    38,    18,    37,
       5,    17,    18,     6,    18,    19,    39,    35,    39,    38,
      41,    18,     3,    40,    42,    39,    15,    43,    21,    22,
       7,     8,     9,    12,    14,    15,    19,    20,    44,    45,
      48,    49,    50,    51,    52,    53,    62,    63,    67,    15,
      16,    17,    54,    55,    56,    57,    46,    22,    22,    17,
      54,    10,    11,    21,    43,    13,    58,    54,    22,    23,
      17,    64,    22,    22,    22,    54,    20,    44,    17,    18,
      55,    54,    66,    66,    22,    54,    59,    60,    61,    24,
      18,    65,    18,     6,    54,    47,    18,    61,    19,    44,
      43,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    27,    28,    28,    29,    30,    30,    32,    31,
      33,    31,    34,    31,    35,    35,    36,    36,    36,    37,
      37,    38,    40,    39,    41,    41,    42,    42,    43,    43,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    46,
      47,    45,    48,    49,    50,    51,    52,    53,    54,    54,
      55,    55,    55,    55,    56,    58,    57,    59,    59,    60,
      60,    61,    62,    62,    64,    65,    63,    66,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     1,     2,     0,     7,
       0,     7,     0,     9,     0,     1,     2,     1,     3,     1,
       3,     1,     0,     5,     0,     2,     3,     5,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     9,     2,     2,     3,     3,     3,     4,     1,     3,
       1,     1,     1,     3,     1,     0,     5,     0,     1,     1,
       3,     1,     1,     3,     0,     0,     7,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: global_list function_list  */
#line 69 "minijs.y"
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
#line 1243 "minijs.tab.c"
    break;

  case 5: /* global_var: _VARDEC _ID _SEMICOLON  */
#line 81 "minijs.y"
      {
        int idx = lookup_symbol((yyvsp[-1].s), GLET|GCONST);
        if (idx != NO_INDEX) {
          err("redefinition of '%s'", (yyvsp[-1].s));
        }
        else {
          if ((yyvsp[-2].i) == LET)
            insert_symbol((yyvsp[-1].s), GLET, NUMBER, NO_ATR, NO_ATR);
          else if ((yyvsp[-2].i) == CONST)
            err("At this point only LET variables can be global.");
          code("\n%s:\n\t\tWORD\t1", (yyvsp[-1].s));
        }
      }
#line 1261 "minijs.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 103 "minijs.y"
      {
        fun_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol((yyvsp[0].s), FUN, NUMBER, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", (yyvsp[0].s));

        arg_num = 0;
        code("\n%s:", (yyvsp[0].s));
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
#line 1278 "minijs.tab.c"
    break;

  case 9: /* function: _FUNCDEC _ID $@1 _LPAREN parameters _RPAREN body  */
#line 116 "minijs.y"
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1292 "minijs.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 127 "minijs.y"
      {
        fun_idx = lookup_symbol((yyvsp[-1].s), FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol((yyvsp[-1].s), FUN, NUMBER, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", (yyvsp[-1].s));

        arg_num = 0;
        code("\n%s:", (yyvsp[-1].s));
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
#line 1309 "minijs.tab.c"
    break;

  case 11: /* function: _VARDEC _ID _ASSIGN $@2 arrow_parameters _ARROW body  */
#line 140 "minijs.y"
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1323 "minijs.tab.c"
    break;

  case 12: /* $@3: %empty  */
#line 151 "minijs.y"
      {
        fun_idx = lookup_symbol((yyvsp[-1].s), FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol((yyvsp[-1].s), FUN, NUMBER, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", (yyvsp[-1].s));

        arg_num = 0;
        code("\n%s:", (yyvsp[-1].s));
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
#line 1340 "minijs.tab.c"
    break;

  case 13: /* function: _VARDEC _ID _ASSIGN $@3 _FUNCDEC _LPAREN parameters _RPAREN body  */
#line 164 "minijs.y"
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", (yyvsp[-7].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1354 "minijs.tab.c"
    break;

  case 14: /* parameters: %empty  */
#line 177 "minijs.y"
      { set_atr1(fun_idx, 0); }
#line 1360 "minijs.tab.c"
    break;

  case 16: /* arrow_parameters: _LPAREN _RPAREN  */
#line 183 "minijs.y"
      { set_atr1(fun_idx, 0); }
#line 1366 "minijs.tab.c"
    break;

  case 21: /* parameter: _ID  */
#line 195 "minijs.y"
      {
        insert_symbol((yyvsp[0].s), PAR, NUMBER, get_atr1(fun_idx) + 1, NO_ATR);
        set_atr1(fun_idx, get_atr1(fun_idx) + 1);
        set_atr2(fun_idx, NUMBER);
      }
#line 1376 "minijs.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 204 "minijs.y"
      {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
#line 1386 "minijs.tab.c"
    break;

  case 26: /* variable: _VARDEC _ID _SEMICOLON  */
#line 219 "minijs.y"
      {
        if ((yyvsp[-2].i) == CONST) {
          err("Const variable has to be initialized with a value!");
        }
        if(lookup_symbol((yyvsp[-1].s), PAR|LET|CONST|GLET|GCONST) == NO_INDEX)
           insert_symbol((yyvsp[-1].s), (yyvsp[-2].i), NUMBER, ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", (yyvsp[-1].s));
      }
#line 1400 "minijs.tab.c"
    break;

  case 27: /* variable: _VARDEC _ID _ASSIGN num_exp _SEMICOLON  */
#line 229 "minijs.y"
      {
        int idx = lookup_symbol((yyvsp[-3].s), PAR|LET|CONST|GLET|GCONST);
        if(idx == NO_INDEX)
           idx = insert_symbol((yyvsp[-3].s), (yyvsp[-4].i), NUMBER, ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", (yyvsp[-3].s));
        set_atr2(idx, 1);
        gen_mov((yyvsp[-1].i), idx);
      }
#line 1414 "minijs.tab.c"
    break;

  case 39: /* @5: %empty  */
#line 259 "minijs.y"
      {
        (yyval.i) = ++while_num;
        parent_while = current_while;
        current_while = while_num;
        code("\n@while_%d:", while_num);
      }
#line 1425 "minijs.tab.c"
    break;

  case 40: /* $@6: %empty  */
#line 266 "minijs.y"
      {
        code("\n\t\t%s\t@end_while_%d", opp_jumps[(yyvsp[-1].i)], while_num);
      }
#line 1433 "minijs.tab.c"
    break;

  case 41: /* while_statement: _WHILE @5 _LPAREN rel_exp _RPAREN $@6 _LBRACKET statement_list _RBRACKET  */
#line 270 "minijs.y"
      {
        code("\n\t\tJMP\t@while_%d", (yyvsp[-7].i));
        code("\n@end_while_%d:", (yyvsp[-7].i));
        current_while = parent_while;
      }
#line 1443 "minijs.tab.c"
    break;

  case 42: /* break_statement: _BREAK _SEMICOLON  */
#line 279 "minijs.y"
      {
        if (current_while > -1) {
          code("\n\t\tJMP\t@end_while_%d", current_while);
        }
      }
#line 1453 "minijs.tab.c"
    break;

  case 43: /* continue_statement: _CONTINUE _SEMICOLON  */
#line 288 "minijs.y"
      {
        if (current_while > -1) {
          code("\n\t\tJMP\t@while_%d", current_while);
        }
      }
#line 1463 "minijs.tab.c"
    break;

  case 44: /* postincrement_statement: _ID _POSTINCREMENT _SEMICOLON  */
#line 297 "minijs.y"
      {
        int idx = lookup_symbol((yyvsp[-2].s), LET|GLET|PAR|CONST|GCONST);
        if (get_atr2(idx) == 1 && (get_kind(idx) == CONST || get_kind(idx) == GCONST)) {
          err("Cannot increment const value!");
        }
        else if (idx == NO_INDEX)
          err("'%s' undeclared", (yyvsp[-2].s));
        else {
          code("\n\t\t\tADDS\t");
          gen_sym_name(idx);
          code(", $1,");
          gen_sym_name(idx);
        }
      }
#line 1482 "minijs.tab.c"
    break;

  case 45: /* postdecrement_statement: _ID _POSTDECREMENT _SEMICOLON  */
#line 315 "minijs.y"
      {
        int idx = lookup_symbol((yyvsp[-2].s), LET|GLET|PAR|CONST|GCONST);
        if (get_atr2(idx) == 1 && (get_kind(idx) == CONST || get_kind(idx) == GCONST)) {
          err("Cannot decrement const value!");
        }
        else if (idx == NO_INDEX)
          err("'%s' undeclared", (yyvsp[-2].s));
        else {
          code("\n\t\t\tSUBS\t");
          gen_sym_name(idx);
          code(", $1,");
          gen_sym_name(idx);
        }
      }
#line 1501 "minijs.tab.c"
    break;

  case 47: /* assignment_statement: _ID _ASSIGN num_exp _SEMICOLON  */
#line 337 "minijs.y"
      {
        int idx = lookup_symbol((yyvsp[-3].s), PAR|LET|CONST|GLET|GCONST);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", (yyvsp[-3].s));
        if (get_atr2(idx) == 1 && (get_kind(idx) == CONST || get_kind(idx) == GCONST)) {
          err("Cannot reassign const value!");
        }
        set_atr2(idx, 1);
        gen_mov((yyvsp[-1].i), idx);
      }
#line 1516 "minijs.tab.c"
    break;

  case 49: /* num_exp: num_exp _AROP exp  */
#line 353 "minijs.y"
      {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: arithmetic operation");
        int t1 = get_type((yyvsp[-2].i));    
        code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (t1 - 1) * AROP_NUMBER]);
        gen_sym_name((yyvsp[-2].i));
        code(",");
        gen_sym_name((yyvsp[0].i));
        code(",");
        free_if_reg((yyvsp[0].i));
        free_if_reg((yyvsp[-2].i));
        (yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), t1);
      }
#line 1536 "minijs.tab.c"
    break;

  case 51: /* exp: _ID  */
#line 373 "minijs.y"
      {
        (yyval.i) = lookup_symbol((yyvsp[0].s), PAR|LET|CONST|GLET|GCONST);
        if (get_kind((yyval.i)) == PAR) {
          set_atr1((yyval.i), get_atr1(fun_idx) - get_atr1((yyval.i)));
        }
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
      }
#line 1549 "minijs.tab.c"
    break;

  case 52: /* exp: function_call  */
#line 383 "minijs.y"
      {
        (yyval.i) = take_reg();
        gen_mov(FUN_REG, (yyval.i));
      }
#line 1558 "minijs.tab.c"
    break;

  case 53: /* exp: _LPAREN num_exp _RPAREN  */
#line 389 "minijs.y"
      { (yyval.i) = (yyvsp[-1].i); }
#line 1564 "minijs.tab.c"
    break;

  case 54: /* literal: _NUMBER  */
#line 394 "minijs.y"
      { 
        (yyval.i) = insert_literal((yyvsp[0].s), NUMBER);
      }
#line 1572 "minijs.tab.c"
    break;

  case 55: /* $@7: %empty  */
#line 401 "minijs.y"
      {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));
      }
#line 1582 "minijs.tab.c"
    break;

  case 56: /* function_call: _ID $@7 _LPAREN arguments _RPAREN  */
#line 407 "minijs.y"
      {
        if(get_atr1(fcall_idx) != (yyvsp[-1].i))
          err("wrong number of arguments. should be %d, but given %d", get_atr1(fcall_idx), (yyvsp[-1].i) );
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if((yyvsp[-1].i) > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", (yyvsp[-1].i) * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        (yyval.i) = FUN_REG;
      }
#line 1596 "minijs.tab.c"
    break;

  case 57: /* arguments: %empty  */
#line 420 "minijs.y"
    { (yyval.i) = 0; }
#line 1602 "minijs.tab.c"
    break;

  case 58: /* arguments: argument_list  */
#line 422 "minijs.y"
    {
      (yyval.i) = (yyvsp[0].i);
    }
#line 1610 "minijs.tab.c"
    break;

  case 59: /* argument_list: argument  */
#line 428 "minijs.y"
             { (yyval.i) = 1; }
#line 1616 "minijs.tab.c"
    break;

  case 60: /* argument_list: argument_list _COMMA argument  */
#line 429 "minijs.y"
                                  { (yyval.i) = (yyval.i) + 1; }
#line 1622 "minijs.tab.c"
    break;

  case 61: /* argument: num_exp  */
#line 434 "minijs.y"
    {
      // if(get_atr2(fcall_idx) != get_type($1))
      //   err("incompatible type for argument");
      free_if_reg((yyvsp[0].i));
      code("\n\t\t\tPUSH\t");
      gen_sym_name((yyvsp[0].i));
      (yyval.i) = 1;
    }
#line 1635 "minijs.tab.c"
    break;

  case 62: /* if_statement: if_part  */
#line 446 "minijs.y"
      { code("\n@exit%d:", (yyvsp[0].i)); }
#line 1641 "minijs.tab.c"
    break;

  case 63: /* if_statement: if_part _ELSE statement  */
#line 449 "minijs.y"
      { code("\n@exit%d:", (yyvsp[-2].i)); }
#line 1647 "minijs.tab.c"
    break;

  case 64: /* @8: %empty  */
#line 454 "minijs.y"
      {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
      }
#line 1656 "minijs.tab.c"
    break;

  case 65: /* $@9: %empty  */
#line 459 "minijs.y"
      {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i));
        code("\n@true%d:", (yyvsp[-1].i));
      }
#line 1665 "minijs.tab.c"
    break;

  case 66: /* if_part: _IF _LPAREN @8 rel_exp $@9 _RPAREN statement  */
#line 464 "minijs.y"
      {
        code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
        code("\n@false%d:", (yyvsp[-4].i));
        (yyval.i) = (yyvsp[-4].i);
      }
#line 1675 "minijs.tab.c"
    break;

  case 67: /* rel_exp: num_exp _RELOP num_exp  */
#line 473 "minijs.y"
      {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: relational operator");
        (yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[-2].i), (yyvsp[0].i));
      }
#line 1686 "minijs.tab.c"
    break;

  case 68: /* return_statement: _RETURN num_exp _SEMICOLON  */
#line 483 "minijs.y"
      {
        // if(get_type(fun_idx) != get_type($2))
        //   err("incompatible types in return");
        gen_mov((yyvsp[-1].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
#line 1697 "minijs.tab.c"
    break;


#line 1701 "minijs.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 491 "minijs.y"


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

