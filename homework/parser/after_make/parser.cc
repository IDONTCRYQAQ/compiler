// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 27 "parser.yy"

    #include "driver.hh"

#line 50 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 142 "parser.cc"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_formal_arguments_optional: // formal_arguments_optional
      case symbol_kind::S_formal_arguments: // formal_arguments
      case symbol_kind::S_comma_separated_expressions: // comma_separated_expressions
        value.YY_MOVE_OR_COPY<  std::vector<ValueType>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant_exp: // constant_exp
        value.YY_MOVE_OR_COPY< Data > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formal_argument: // formal_argument
      case symbol_kind::S_assign_type_optional: // assign_type_optional
      case symbol_kind::S_assign_type: // assign_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_array_reference: // array_reference
      case symbol_kind::S_integer_expression: // integer_expression
      case symbol_kind::S_function_invocation: // function_invocation
        value.YY_MOVE_OR_COPY< ValueType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_BOOLEAN: // CONSTANT_BOOLEAN
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_CHAR: // CONSTANT_CHAR
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_FLOAT: // CONSTANT_FLOAT
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_INTEGER: // CONSTANT_INTEGER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_CONSTANT_STRING: // CONSTANT_STRING
      case symbol_kind::S_declaring_id: // declaring_id
      case symbol_kind::S_data_type_id: // data_type_id
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_formal_arguments_optional: // formal_arguments_optional
      case symbol_kind::S_formal_arguments: // formal_arguments
      case symbol_kind::S_comma_separated_expressions: // comma_separated_expressions
        value.move<  std::vector<ValueType>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant_exp: // constant_exp
        value.move< Data > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formal_argument: // formal_argument
      case symbol_kind::S_assign_type_optional: // assign_type_optional
      case symbol_kind::S_assign_type: // assign_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_array_reference: // array_reference
      case symbol_kind::S_integer_expression: // integer_expression
      case symbol_kind::S_function_invocation: // function_invocation
        value.move< ValueType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_BOOLEAN: // CONSTANT_BOOLEAN
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_CHAR: // CONSTANT_CHAR
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_FLOAT: // CONSTANT_FLOAT
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_INTEGER: // CONSTANT_INTEGER
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_CONSTANT_STRING: // CONSTANT_STRING
      case symbol_kind::S_declaring_id: // declaring_id
      case symbol_kind::S_data_type_id: // data_type_id
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_formal_arguments_optional: // formal_arguments_optional
      case symbol_kind::S_formal_arguments: // formal_arguments
      case symbol_kind::S_comma_separated_expressions: // comma_separated_expressions
        value.copy<  std::vector<ValueType>  > (that.value);
        break;

      case symbol_kind::S_constant_exp: // constant_exp
        value.copy< Data > (that.value);
        break;

      case symbol_kind::S_formal_argument: // formal_argument
      case symbol_kind::S_assign_type_optional: // assign_type_optional
      case symbol_kind::S_assign_type: // assign_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_array_reference: // array_reference
      case symbol_kind::S_integer_expression: // integer_expression
      case symbol_kind::S_function_invocation: // function_invocation
        value.copy< ValueType > (that.value);
        break;

      case symbol_kind::S_CONSTANT_BOOLEAN: // CONSTANT_BOOLEAN
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_CONSTANT_CHAR: // CONSTANT_CHAR
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_CONSTANT_FLOAT: // CONSTANT_FLOAT
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_CONSTANT_INTEGER: // CONSTANT_INTEGER
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_CONSTANT_STRING: // CONSTANT_STRING
      case symbol_kind::S_declaring_id: // declaring_id
      case symbol_kind::S_data_type_id: // data_type_id
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_formal_arguments_optional: // formal_arguments_optional
      case symbol_kind::S_formal_arguments: // formal_arguments
      case symbol_kind::S_comma_separated_expressions: // comma_separated_expressions
        value.move<  std::vector<ValueType>  > (that.value);
        break;

      case symbol_kind::S_constant_exp: // constant_exp
        value.move< Data > (that.value);
        break;

      case symbol_kind::S_formal_argument: // formal_argument
      case symbol_kind::S_assign_type_optional: // assign_type_optional
      case symbol_kind::S_assign_type: // assign_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_array_reference: // array_reference
      case symbol_kind::S_integer_expression: // integer_expression
      case symbol_kind::S_function_invocation: // function_invocation
        value.move< ValueType > (that.value);
        break;

      case symbol_kind::S_CONSTANT_BOOLEAN: // CONSTANT_BOOLEAN
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_CONSTANT_CHAR: // CONSTANT_CHAR
        value.move< char > (that.value);
        break;

      case symbol_kind::S_CONSTANT_FLOAT: // CONSTANT_FLOAT
        value.move< float > (that.value);
        break;

      case symbol_kind::S_CONSTANT_INTEGER: // CONSTANT_INTEGER
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_CONSTANT_STRING: // CONSTANT_STRING
      case symbol_kind::S_declaring_id: // declaring_id
      case symbol_kind::S_data_type_id: // data_type_id
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_formal_arguments_optional: // formal_arguments_optional
      case symbol_kind::S_formal_arguments: // formal_arguments
      case symbol_kind::S_comma_separated_expressions: // comma_separated_expressions
        yylhs.value.emplace<  std::vector<ValueType>  > ();
        break;

      case symbol_kind::S_constant_exp: // constant_exp
        yylhs.value.emplace< Data > ();
        break;

      case symbol_kind::S_formal_argument: // formal_argument
      case symbol_kind::S_assign_type_optional: // assign_type_optional
      case symbol_kind::S_assign_type: // assign_type
      case symbol_kind::S_type: // type
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_array_reference: // array_reference
      case symbol_kind::S_integer_expression: // integer_expression
      case symbol_kind::S_function_invocation: // function_invocation
        yylhs.value.emplace< ValueType > ();
        break;

      case symbol_kind::S_CONSTANT_BOOLEAN: // CONSTANT_BOOLEAN
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_CONSTANT_CHAR: // CONSTANT_CHAR
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_CONSTANT_FLOAT: // CONSTANT_FLOAT
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_CONSTANT_INTEGER: // CONSTANT_INTEGER
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_CONSTANT_STRING: // CONSTANT_STRING
      case symbol_kind::S_declaring_id: // declaring_id
      case symbol_kind::S_data_type_id: // data_type_id
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // $@1: %empty
#line 93 "parser.yy"
                       { drv.symtab.enter_block(); }
#line 767 "parser.cc"
    break;

  case 6: // $@2: %empty
#line 101 "parser.yy"
                                              { 
            drv.symtab.insert(yystack_[5].value.as < std::string > (), {yystack_[3].value.as <  std::vector<ValueType>  > (), yystack_[1].value.as < ValueType > ()});
            drv.symtab.enter_block(); 
      }
#line 776 "parser.cc"
    break;

  case 7: // method: DEF declaring_id "(" formal_arguments_optional ")" assign_type_optional "{" $@2 constant_and_variable_declarations statements_optional "}"
#line 105 "parser.yy"
                                                                   { 
            drv.symtab.exit_block(); 
      }
#line 784 "parser.cc"
    break;

  case 8: // formal_arguments_optional: formal_arguments
#line 110 "parser.yy"
                                            { yylhs.value.as <  std::vector<ValueType>  > ().swap(yystack_[0].value.as <  std::vector<ValueType>  > ()); }
#line 790 "parser.cc"
    break;

  case 9: // formal_arguments_optional: %empty
#line 111 "parser.yy"
                                  { }
#line 796 "parser.cc"
    break;

  case 10: // formal_arguments: formal_arguments "," formal_argument
#line 114 "parser.yy"
                                                             {
                    yylhs.value.as <  std::vector<ValueType>  > ().swap(yystack_[2].value.as <  std::vector<ValueType>  > ()); yylhs.value.as <  std::vector<ValueType>  > ().push_back(yystack_[0].value.as < ValueType > ());
                }
#line 804 "parser.cc"
    break;

  case 11: // formal_arguments: formal_argument
#line 117 "parser.yy"
                                  { yylhs.value.as <  std::vector<ValueType>  > ().push_back(yystack_[0].value.as < ValueType > ()); }
#line 810 "parser.cc"
    break;

  case 12: // formal_argument: ID assign_type
#line 120 "parser.yy"
                                { 
                    drv.symtab.default_variable(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ValueType > ());
                    yylhs.value.as < ValueType > () = yystack_[0].value.as < ValueType > ();
               }
#line 819 "parser.cc"
    break;

  case 16: // $@3: %empty
#line 131 "parser.yy"
                                                                {
            drv.symtab.default_variable(yystack_[5].value.as < std::string > ()); 
     }
#line 827 "parser.cc"
    break;

  case 18: // boolean_expr: expressions
#line 136 "parser.yy"
                          {
                if(yystack_[0].value.as < ValueType > () != ValueType::BOOLEAN)
                    yy::parser::error(drv.location, "expression not boolean\n");
            }
#line 836 "parser.cc"
    break;

  case 21: // $@4: %empty
#line 146 "parser.yy"
           { drv.symtab.enter_block(); }
#line 842 "parser.cc"
    break;

  case 22: // block: "{" $@4 constant_and_variable_declarations statements "}"
#line 147 "parser.yy"
                                                         { drv.symtab.exit_block(); }
#line 848 "parser.cc"
    break;

  case 27: // constant_declaration: VAL declaring_id assign_type_optional "=" constant_exp
#line 158 "parser.yy"
                                                                                             {
                        if(yystack_[2].value.as < ValueType > () == ValueType::VOID || yystack_[2].value.as < ValueType > () == yystack_[0].value.as < Data > ().value_type)
                            drv.symtab.insert(yystack_[3].value.as < std::string > (), yystack_[0].value.as < Data > ().value, yystack_[0].value.as < Data > ().value_type);
                        else yy::parser::error(drv.location, std::string(yystack_[3].value.as < std::string > ()) + " type not matched\n");
                    }
#line 858 "parser.cc"
    break;

  case 28: // variable_declaration: VAR declaring_id assign_type "=" constant_exp
#line 165 "parser.yy"
                                                                        {
                        if(yystack_[2].value.as < ValueType > () == yystack_[0].value.as < Data > ().value_type)
                            drv.symtab.insert(yystack_[3].value.as < std::string > (), yystack_[2].value.as < ValueType > ());
                        else yy::parser::error(drv.location, std::string(yystack_[3].value.as < std::string > ()) +  " type not matched\n");
                    }
#line 868 "parser.cc"
    break;

  case 29: // variable_declaration: VAR declaring_id assign_type "[" CONSTANT_INTEGER "]"
#line 170 "parser.yy"
                                                                                {   // Arrays declaration
                        drv.symtab.insert(yystack_[4].value.as < std::string > (), yystack_[3].value.as < ValueType > (), true);
                    }
#line 876 "parser.cc"
    break;

  case 30: // variable_declaration: VAR declaring_id assign_type
#line 173 "parser.yy"
                                                       { drv.symtab.insert(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ValueType > ()); }
#line 882 "parser.cc"
    break;

  case 31: // variable_declaration: VAR declaring_id "=" constant_exp
#line 174 "parser.yy"
                                                            { drv.symtab.insert(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Data > ().value_type); }
#line 888 "parser.cc"
    break;

  case 32: // variable_declaration: VAR declaring_id
#line 175 "parser.yy"
                                           { drv.symtab.insert(yystack_[0].value.as < std::string > ()); }
#line 894 "parser.cc"
    break;

  case 33: // assign_type_optional: assign_type
#line 178 "parser.yy"
                                  { yylhs.value.as < ValueType > () = yystack_[0].value.as < ValueType > (); }
#line 900 "parser.cc"
    break;

  case 34: // assign_type_optional: %empty
#line 179 "parser.yy"
                             { yylhs.value.as < ValueType > () = ValueType::VOID; }
#line 906 "parser.cc"
    break;

  case 35: // assign_type: ":" type
#line 182 "parser.yy"
                      { yylhs.value.as < ValueType > () = yystack_[0].value.as < ValueType > (); }
#line 912 "parser.cc"
    break;

  case 36: // type: BOOLEAN
#line 184 "parser.yy"
                { yylhs.value.as < ValueType > () = ValueType::BOOLEAN; }
#line 918 "parser.cc"
    break;

  case 37: // type: INT
#line 185 "parser.yy"
             { yylhs.value.as < ValueType > () = ValueType::INTEGER; }
#line 924 "parser.cc"
    break;

  case 38: // type: FLOAT
#line 186 "parser.yy"
             { yylhs.value.as < ValueType > () = ValueType::FLOAT; }
#line 930 "parser.cc"
    break;

  case 39: // type: CHAR
#line 187 "parser.yy"
             { yylhs.value.as < ValueType > () = ValueType::CHAR; }
#line 936 "parser.cc"
    break;

  case 40: // type: STRING
#line 188 "parser.yy"
                 { yylhs.value.as < ValueType > () = ValueType::STRING; }
#line 942 "parser.cc"
    break;

  case 41: // declaring_id: ID
#line 191 "parser.yy"
                 {
                if( drv.symtab.is_declared(yystack_[0].value.as < std::string > ()) ) 
                yy::parser::error(drv.location, std::string(yystack_[0].value.as < std::string > ()) + " redeclared\n");
                yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
            }
#line 952 "parser.cc"
    break;

  case 51: // procedure_invocations: ID "(" comma_separated_expressions ")"
#line 213 "parser.yy"
                                                                      {
                        if(std::string m(std::move(drv.symtab.match_procedure(yystack_[3].value.as < std::string > (), yystack_[1].value.as <  std::vector<ValueType>  > ()))); m != "match")
                            yy::parser::error(drv.location, m);
                     }
#line 961 "parser.cc"
    break;

  case 52: // procedure_invocations: ID
#line 217 "parser.yy"
                          {
                        if(std::string m(std::move(drv.symtab.match_procedure(yystack_[0].value.as < std::string > (), {}))); m != "match")
                            yy::parser::error(drv.location, m);
                     }
#line 970 "parser.cc"
    break;

  case 53: // simple: data_type_id "=" expressions
#line 224 "parser.yy"
                                         {
switch (drv.symtab.lookup(yystack_[2].value.as < std::string > ())) {
                case ClassType::NIL :
                    yy::parser::error(drv.location, "id: " + yystack_[2].value.as < std::string > () + " not declared\n" );
                    break;
                case ClassType::FUNCTION :
                    yy::parser::error(drv.location, "can't assign value to funcion\n" );
                case ClassType::DATA : {
                    const DataType& id_data_type = drv.symtab.get_data_type(yystack_[2].value.as < std::string > ());
                    if(id_data_type.is_array)
                        yy::parser::error(drv.location, "id: " + yystack_[2].value.as < std::string > () + " is array type\n");
                    if(id_data_type.value_type != yystack_[0].value.as < ValueType > ())
                        yy::parser::error(drv.location, "type not matched\n" );
                    if(id_data_type.is_const)
                        yy::parser::error(drv.location, "can't reassigned constant val\n" );
                }
            }
      }
#line 993 "parser.cc"
    break;

  case 54: // simple: array_reference "=" expressions
#line 242 "parser.yy"
                                        {
          if(yystack_[2].value.as < ValueType > () != yystack_[0].value.as < ValueType > ())
            yy::parser::error(drv.location, "type not matched on array\n" );
      }
#line 1002 "parser.cc"
    break;

  case 60: // expressions: "-" expressions
#line 253 "parser.yy"
                                                      {
                if(yystack_[0].value.as < ValueType > () == ValueType::INTEGER || yystack_[0].value.as < ValueType > () == ValueType::FLOAT) yylhs.value.as < ValueType > () = yystack_[0].value.as < ValueType > ();
                else yy::parser::error(drv.location, "expression not arithmetic\n");
           }
#line 1011 "parser.cc"
    break;

  case 61: // expressions: expressions "*" expressions
#line 257 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match") yylhs.value.as < ValueType > () = yystack_[2].value.as < ValueType > ();
                else yy::parser::error(drv.location, m);
           }
#line 1020 "parser.cc"
    break;

  case 62: // expressions: expressions "/" expressions
#line 261 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match") yylhs.value.as < ValueType > () = yystack_[2].value.as < ValueType > ();
                else yy::parser::error(drv.location, m);
           }
#line 1029 "parser.cc"
    break;

  case 63: // expressions: expressions "+" expressions
#line 265 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match") yylhs.value.as < ValueType > () = yystack_[2].value.as < ValueType > ();
                else yy::parser::error(drv.location, m);
           }
#line 1038 "parser.cc"
    break;

  case 64: // expressions: expressions "-" expressions
#line 269 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match") yylhs.value.as < ValueType > () = yystack_[2].value.as < ValueType > ();
                else yy::parser::error(drv.location, m);
           }
#line 1047 "parser.cc"
    break;

  case 65: // expressions: expressions "<" expressions
#line 273 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match")
                    yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
           }
#line 1057 "parser.cc"
    break;

  case 66: // expressions: expressions "<=" expressions
#line 278 "parser.yy"
                                                {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match")
                    yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
           }
#line 1067 "parser.cc"
    break;

  case 67: // expressions: expressions "==" expressions
#line 283 "parser.yy"
                                                {
                if(yystack_[2].value.as < ValueType > () == yystack_[0].value.as < ValueType > ()) yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, "type not match\n");
           }
#line 1076 "parser.cc"
    break;

  case 68: // expressions: expressions ">=" expressions
#line 287 "parser.yy"
                                                {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match")
                    yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
           }
#line 1086 "parser.cc"
    break;

  case 69: // expressions: expressions ">" expressions
#line 292 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match")
                    yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
           }
#line 1096 "parser.cc"
    break;

  case 70: // expressions: expressions "!=" expressions
#line 297 "parser.yy"
                                                {
                if(yystack_[2].value.as < ValueType > () == yystack_[0].value.as < ValueType > ()) yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, "type not match\n");
           }
#line 1105 "parser.cc"
    break;

  case 71: // expressions: "!" expressions
#line 301 "parser.yy"
                                        {
                if(yystack_[0].value.as < ValueType > () == ValueType::BOOLEAN) yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "! required boolean expression\n");
           }
#line 1114 "parser.cc"
    break;

  case 72: // expressions: expressions "&&" expressions
#line 305 "parser.yy"
                                                 {
                if(yystack_[2].value.as < ValueType > () == ValueType::BOOLEAN && yystack_[0].value.as < ValueType > () == ValueType::BOOLEAN) yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "&& required boolean expression\n");
           }
#line 1123 "parser.cc"
    break;

  case 73: // expressions: expressions "||" expressions
#line 309 "parser.yy"
                                                  {
                if(yystack_[2].value.as < ValueType > () == ValueType::BOOLEAN && yystack_[0].value.as < ValueType > () == ValueType::BOOLEAN) yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "|| required boolean expression\n");
           }
#line 1132 "parser.cc"
    break;

  case 74: // expressions: CONSTANT_BOOLEAN
#line 313 "parser.yy"
                              { yylhs.value.as < ValueType > () = ValueType::BOOLEAN; }
#line 1138 "parser.cc"
    break;

  case 75: // expressions: CONSTANT_INTEGER
#line 314 "parser.yy"
                              { yylhs.value.as < ValueType > () = ValueType::INTEGER; }
#line 1144 "parser.cc"
    break;

  case 76: // expressions: CONSTANT_FLOAT
#line 315 "parser.yy"
                            { yylhs.value.as < ValueType > () = ValueType::FLOAT; }
#line 1150 "parser.cc"
    break;

  case 77: // expressions: CONSTANT_CHAR
#line 316 "parser.yy"
                           { yylhs.value.as < ValueType > () = ValueType::CHAR; }
#line 1156 "parser.cc"
    break;

  case 78: // expressions: CONSTANT_STRING
#line 317 "parser.yy"
                             { yylhs.value.as < ValueType > () = ValueType::STRING; }
#line 1162 "parser.cc"
    break;

  case 79: // expressions: data_type_id
#line 318 "parser.yy"
                              {
                const DataType& id_data_type = drv.symtab.get_data_type(yystack_[0].value.as < std::string > ());
                if(id_data_type.is_array)
                    yy::parser::error(drv.location, "id: " + yystack_[0].value.as < std::string > () + " is array type\n");
                else yylhs.value.as < ValueType > () = id_data_type.value_type;
           }
#line 1173 "parser.cc"
    break;

  case 80: // expressions: function_invocation
#line 324 "parser.yy"
                                 { yylhs.value.as < ValueType > () = yystack_[0].value.as < ValueType > (); }
#line 1179 "parser.cc"
    break;

  case 81: // expressions: array_reference
#line 325 "parser.yy"
                             { yylhs.value.as < ValueType > () = yystack_[0].value.as < ValueType > (); }
#line 1185 "parser.cc"
    break;

  case 82: // array_reference: data_type_id "[" integer_expression "]"
#line 328 "parser.yy"
                                                             {
                    const DataType& id_data_type = drv.symtab.get_data_type(yystack_[3].value.as < std::string > ());
                    if(!id_data_type.is_array)
                        yy::parser::error(drv.location, "id: " + yystack_[3].value.as < std::string > () + " is not array\n");
                    else yylhs.value.as < ValueType > () = id_data_type.value_type;
               }
#line 1196 "parser.cc"
    break;

  case 83: // data_type_id: ID
#line 336 "parser.yy"
                 {
                const ClassType& id_class = drv.symtab.lookup(yystack_[0].value.as < std::string > ());
                if(id_class == ClassType::NIL)
                    yy::parser::error(drv.location, "id: " + yystack_[0].value.as < std::string > () + " is not declared\n");
                else if(id_class != ClassType::DATA)
                    yy::parser::error(drv.location, "id: " + yystack_[0].value.as < std::string > () + " is not a data\n");
                else yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
            }
#line 1209 "parser.cc"
    break;

  case 84: // integer_expression: expressions
#line 346 "parser.yy"
                                { 
                    if(yystack_[0].value.as < ValueType > () == ValueType::INTEGER) yylhs.value.as < ValueType > () = ValueType::INTEGER;
                    else yy::parser::error(drv.location, "expression not integer\n");
                  }
#line 1218 "parser.cc"
    break;

  case 85: // function_invocation: ID "(" comma_separated_expressions ")"
#line 352 "parser.yy"
                                                                    {
                        if(std::string m(std::move(drv.symtab.match_function(yystack_[3].value.as < std::string > (), yystack_[1].value.as <  std::vector<ValueType>  > ()))); m != "match")
                            yy::parser::error(drv.location, m);
                        else yylhs.value.as < ValueType > () = drv.symtab.get_type(yystack_[3].value.as < std::string > ());
                   }
#line 1228 "parser.cc"
    break;

  case 86: // comma_separated_expressions: comma_separated_expressions "," expressions
#line 359 "parser.yy"
                                                                                 {
                                yylhs.value.as <  std::vector<ValueType>  > ().swap(yystack_[2].value.as <  std::vector<ValueType>  > ()); yylhs.value.as <  std::vector<ValueType>  > ().push_back(yystack_[0].value.as < ValueType > ());
                           }
#line 1236 "parser.cc"
    break;

  case 87: // comma_separated_expressions: expressions
#line 362 "parser.yy"
                                         { yylhs.value.as <  std::vector<ValueType>  > ().push_back(yystack_[0].value.as < ValueType > ()); }
#line 1242 "parser.cc"
    break;

  case 88: // comma_separated_expressions: %empty
#line 363 "parser.yy"
                                    { }
#line 1248 "parser.cc"
    break;

  case 89: // constant_exp: CONSTANT_BOOLEAN
#line 366 "parser.yy"
                               { yylhs.value.as < Data > () = { ValueType::BOOLEAN, yystack_[0].value.as < bool > () }; }
#line 1254 "parser.cc"
    break;

  case 90: // constant_exp: CONSTANT_INTEGER
#line 367 "parser.yy"
                               { yylhs.value.as < Data > () = { ValueType::INTEGER, yystack_[0].value.as < int > () }; }
#line 1260 "parser.cc"
    break;

  case 91: // constant_exp: CONSTANT_FLOAT
#line 368 "parser.yy"
                             { yylhs.value.as < Data > () = { ValueType::FLOAT, yystack_[0].value.as < float > () }; }
#line 1266 "parser.cc"
    break;

  case 92: // constant_exp: CONSTANT_CHAR
#line 369 "parser.yy"
                            { yylhs.value.as < Data > () = { ValueType::CHAR, yystack_[0].value.as < char > () }; }
#line 1272 "parser.cc"
    break;

  case 93: // constant_exp: CONSTANT_STRING
#line 370 "parser.yy"
                              { yylhs.value.as < Data > () = { ValueType::STRING, yystack_[0].value.as < std::string > () }; }
#line 1278 "parser.cc"
    break;


#line 1282 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", ",", ":", ".", ";", "(", ")",
  "[", "]", "{", "}", "+", "-", "*", "/", "%", "<-", "=", "<", "<=", ">=",
  ">", "==", "!=", "&&", "||", "!", "BOOLEAN", "INT", "FLOAT", "CHAR",
  "STRING", "DO", "WHILE", "FOR", "CONTINUE", "REPEAT", "IF", "ELSE",
  "CASE", "BREAK", "EXIT", "CLASS", "OBJECT", "DEF", "NULL", "PRINT",
  "PRINTLN", "RETURN", "TO", "TYPE", "VAL", "VAR", "READ", "ID",
  "CONSTANT_BOOLEAN", "CONSTANT_INTEGER", "CONSTANT_FLOAT",
  "CONSTANT_CHAR", "CONSTANT_STRING", "UMINUS", "$accept", "program",
  "$@1", "methods", "method", "$@2", "formal_arguments_optional",
  "formal_arguments", "formal_argument", "conditions", "loops", "$@3",
  "boolean_expr", "block_or_simple", "block", "$@4",
  "constant_and_variable_declarations",
  "constant_and_variable_declaration", "constant_declaration",
  "variable_declaration", "assign_type_optional", "assign_type", "type",
  "declaring_id", "statements_optional", "statements", "statement",
  "procedure_invocations", "simple", "expressions", "array_reference",
  "data_type_id", "integer_expression", "function_invocation",
  "comma_separated_expressions", "constant_exp", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -134;

  const signed char parser::yytable_ninf_ = -84;

  const short
  parser::yypact_[] =
  {
     -17,   -13,    46,    36,  -134,  -134,  -134,    29,    10,    10,
      10,    -9,  -134,  -134,  -134,  -134,  -134,    60,    65,    -2,
    -134,  -134,    14,    67,    52,  -134,    79,     1,    65,    76,
      91,  -134,  -134,  -134,  -134,  -134,  -134,  -134,    79,  -134,
    -134,  -134,  -134,  -134,  -134,    48,    79,  -134,    65,    14,
    -134,    97,  -134,   100,  -134,  -134,  -134,  -134,    77,  -134,
     101,   108,   121,   122,   127,    63,    90,     6,  -134,  -134,
    -134,   131,   124,  -134,  -134,  -134,   125,     7,  -134,    63,
      92,    63,    63,    63,    63,    63,   140,  -134,  -134,  -134,
    -134,  -134,   197,  -134,   141,  -134,  -134,    63,  -134,  -134,
      63,    63,    63,    77,   143,   197,   134,   145,   162,   182,
    -134,   226,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,   197,    41,   197,   197,   139,
     197,   106,    37,    99,    37,  -134,  -134,    87,    -4,    -4,
    -134,  -134,    88,    88,    88,    88,    88,    88,   226,   212,
      63,  -134,  -134,  -134,  -134,  -134,  -134,  -134,   107,   126,
    -134,   197,   109,    37,   156,  -134,  -134,    37,  -134
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     2,    24,     0,     0,     0,
       0,     0,     5,    23,    25,    26,    41,     0,    34,    32,
       3,     4,     9,     0,     0,    33,     0,    30,     0,     0,
       8,    11,    36,    37,    38,    39,    40,    35,     0,    89,
      90,    91,    92,    93,    31,     0,     0,    12,    34,     0,
      27,     0,    28,     0,    10,    29,     6,    24,    43,    21,
       0,     0,     0,     0,     0,    59,     0,    52,    48,    49,
      47,     0,    42,    45,    50,    46,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,    83,    74,    75,    76,
      77,    78,    58,    81,    79,    80,    57,    88,     7,    44,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
      60,    71,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,    54,    84,     0,
      53,     0,     0,     0,     0,    55,    56,     0,    63,    64,
      61,    62,    65,    66,    68,    69,    67,    70,    72,    73,
       0,    51,    82,    22,    83,    15,    19,    20,     0,    13,
      85,    86,     0,     0,     0,    14,    16,     0,    17
  };

  const short
  parser::yypgoto_[] =
  {
    -134,  -134,  -134,  -134,   154,  -134,  -134,  -134,   119,  -134,
    -134,  -134,   110,  -133,  -125,  -134,   -49,  -134,  -134,  -134,
     123,    -1,  -134,    22,  -134,    66,   -66,  -134,   -99,   -61,
     -58,   -53,  -134,  -134,    69,    34
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     6,    11,    12,    57,    29,    30,    31,    68,
      69,   167,   104,   155,    70,    78,     7,    13,    14,    15,
      24,    25,    37,    17,    71,    72,    73,    74,    75,   105,
      93,    94,   129,    95,   126,    44
  };

  const short
  parser::yytable_[] =
  {
      76,   159,    23,    20,    92,    77,    99,   156,    58,   156,
      45,   115,   116,    97,    76,   -83,   101,    26,    27,    77,
      46,   108,   109,   110,   111,   -83,   102,    47,     1,   103,
     165,    18,    19,   157,   168,   157,   125,     8,   156,   127,
     128,   130,   156,     3,   150,    76,     4,     5,    59,   151,
      77,   125,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   157,    99,    16,    22,   157,    23,
      28,    38,    50,    76,    76,     8,    76,    84,    77,    77,
      52,    77,     9,    10,    48,    63,    64,    65,    59,   161,
     150,    85,    66,   154,    49,   160,    32,    33,    34,    35,
      36,   113,   114,   115,   116,    76,    51,    55,    79,    76,
      77,    56,    60,    61,    77,    80,    62,    59,   153,    86,
      87,    88,    89,    90,    91,    63,    64,    65,    81,    82,
       9,    10,    66,    67,    83,    59,    39,    40,    41,    42,
      43,    60,    61,    98,   100,    62,    96,   112,   106,   152,
     101,   132,   133,   134,    63,    64,    65,   158,   162,    60,
      61,    66,    67,    62,   166,    21,   163,   164,    54,   131,
     135,    53,    63,    64,    65,   113,   114,   115,   116,    66,
      67,   137,   117,   118,   119,   120,   121,   122,   123,   124,
     136,   107,     0,     0,     0,   113,   114,   115,   116,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     113,   114,   115,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   113,   114,   115,   116,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   113,
     114,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122
  };

  const short
  parser::yycheck_[] =
  {
      58,   134,     4,    12,    65,    58,    72,   132,    57,   134,
       9,    15,    16,     7,    72,     9,     9,    19,    19,    72,
      19,    82,    83,    84,    85,    19,    19,    28,    45,    78,
     163,     9,    10,   132,   167,   134,    97,    46,   163,   100,
     101,   102,   167,    56,     3,   103,     0,    11,    11,     8,
     103,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   163,   131,    56,     7,   167,     4,
      56,    19,    38,   131,   132,    46,   134,    14,   131,   132,
      46,   134,    53,    54,     8,    48,    49,    50,    11,   150,
       3,    28,    55,    56,     3,     8,    29,    30,    31,    32,
      33,    13,    14,    15,    16,   163,    58,    10,     7,   167,
     163,    11,    35,    36,   167,     7,    39,    11,    12,    56,
      57,    58,    59,    60,    61,    48,    49,    50,     7,     7,
      53,    54,    55,    56,     7,    11,    57,    58,    59,    60,
      61,    35,    36,    12,    19,    39,    56,     7,    56,    10,
       9,     8,    18,     8,    48,    49,    50,    58,    51,    35,
      36,    55,    56,    39,     8,    11,    40,    58,    49,   103,
       8,    48,    48,    49,    50,    13,    14,    15,    16,    55,
      56,   112,    20,    21,    22,    23,    24,    25,    26,    27,
       8,    81,    -1,    -1,    -1,    13,    14,    15,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      13,    14,    15,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    13,    14,    15,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    13,
      14,    15,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25
  };

  const signed char
  parser::yystos_[] =
  {
       0,    45,    64,    56,     0,    11,    65,    79,    46,    53,
      54,    66,    67,    80,    81,    82,    56,    86,    86,    86,
      12,    67,     7,     4,    83,    84,    19,    84,    56,    69,
      70,    71,    29,    30,    31,    32,    33,    85,    19,    57,
      58,    59,    60,    61,    98,     9,    19,    84,     8,     3,
      98,    58,    98,    83,    71,    10,    11,    68,    79,    11,
      35,    36,    39,    48,    49,    50,    55,    56,    72,    73,
      77,    87,    88,    89,    90,    91,    93,    94,    78,     7,
       7,     7,     7,     7,    14,    28,    56,    57,    58,    59,
      60,    61,    92,    93,    94,    96,    56,     7,    12,    89,
      19,     9,    19,    79,    75,    92,    56,    75,    92,    92,
      92,    92,     7,    13,    14,    15,    16,    20,    21,    22,
      23,    24,    25,    26,    27,    92,    97,    92,    92,    95,
      92,    88,     8,    18,     8,     8,     8,    97,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
       3,     8,    10,    12,    56,    76,    77,    91,    58,    76,
       8,    92,    51,    40,    58,    76,     8,    74,    76
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    63,    65,    64,    66,    66,    68,    67,    69,    69,
      70,    70,    71,    72,    72,    73,    74,    73,    75,    76,
      76,    78,    77,    79,    79,    80,    80,    81,    82,    82,
      82,    82,    82,    83,    83,    84,    85,    85,    85,    85,
      85,    86,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    94,    95,    96,    97,    97,    97,    98,
      98,    98,    98,    98
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     7,     2,     1,     0,    11,     1,     0,
       3,     1,     2,     5,     7,     5,     0,    10,     1,     1,
       1,     0,     5,     2,     0,     1,     1,     5,     5,     6,
       3,     4,     2,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     4,     4,     2,     2,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     4,     3,     1,     0,     1,
       1,     1,     1,     1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    93,    93,    93,    96,    97,   101,   100,   110,   111,
     114,   117,   120,   126,   127,   130,   131,   131,   136,   142,
     143,   146,   146,   150,   151,   154,   155,   158,   165,   170,
     173,   174,   175,   178,   179,   182,   184,   185,   186,   187,
     188,   191,   198,   199,   202,   203,   206,   207,   208,   209,
     210,   213,   217,   224,   242,   246,   247,   248,   249,   250,
     253,   257,   261,   265,   269,   273,   278,   283,   287,   292,
     297,   301,   305,   309,   313,   314,   315,   316,   317,   318,
     324,   325,   328,   336,   346,   352,   359,   362,   363,   366,
     367,   368,   369,   370
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1980 "parser.cc"

#line 373 "parser.yy"


void yy::parser::error (const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
