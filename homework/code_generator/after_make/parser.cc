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
#line 28 "parser.yy"

    #include "driver.hh"
    std::string object_id;
    auto get_label = [count = 0]() mutable { 
        return std::string("L") + std::to_string(++count); 
    };
    std::vector<std::string> Lfalse, Lexit, Lbegin;
    std::string params_str;

#line 56 "parser.cc"


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
#line 148 "parser.cc"

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
      case symbol_kind::S_function_invocation: // function_invocation
        value.YY_MOVE_OR_COPY< ValueType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_BOOLEAN: // CONSTANT_BOOLEAN
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_CHAR: // CONSTANT_CHAR
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
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
      case symbol_kind::S_function_invocation: // function_invocation
        value.move< ValueType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_BOOLEAN: // CONSTANT_BOOLEAN
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT_CHAR: // CONSTANT_CHAR
        value.move< char > (YY_MOVE (that.value));
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
      case symbol_kind::S_function_invocation: // function_invocation
        value.copy< ValueType > (that.value);
        break;

      case symbol_kind::S_CONSTANT_BOOLEAN: // CONSTANT_BOOLEAN
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_CONSTANT_CHAR: // CONSTANT_CHAR
        value.copy< char > (that.value);
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
      case symbol_kind::S_function_invocation: // function_invocation
        value.move< ValueType > (that.value);
        break;

      case symbol_kind::S_CONSTANT_BOOLEAN: // CONSTANT_BOOLEAN
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_CONSTANT_CHAR: // CONSTANT_CHAR
        value.move< char > (that.value);
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
      case symbol_kind::S_function_invocation: // function_invocation
        yylhs.value.emplace< ValueType > ();
        break;

      case symbol_kind::S_CONSTANT_BOOLEAN: // CONSTANT_BOOLEAN
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_CONSTANT_CHAR: // CONSTANT_CHAR
        yylhs.value.emplace< char > ();
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
#line 99 "parser.yy"
                { drv.fout << "class "; }
#line 743 "parser.cc"
    break;

  case 3: // $@2: %empty
#line 100 "parser.yy"
            { drv.fout << yystack_[0].value.as < std::string > () << std::endl; object_id = yystack_[0].value.as < std::string > (); }
#line 749 "parser.cc"
    break;

  case 4: // $@3: %empty
#line 101 "parser.yy"
             { drv.symtab.enter_block(); drv.fout << "{" << std::endl; }
#line 755 "parser.cc"
    break;

  case 5: // program: OBJECT $@1 ID $@2 "{" $@3 global_declarations methods "}"
#line 103 "parser.yy"
             { drv.symtab.exit_block(); drv.fout << "}" << std::endl; }
#line 761 "parser.cc"
    break;

  case 9: // $@4: %empty
#line 114 "parser.yy"
                                              { 
            drv.symtab.insert(yystack_[5].value.as < std::string > (), {yystack_[3].value.as <  std::vector<ValueType>  > (), yystack_[1].value.as < ValueType > ()});
            drv.symtab.enter_block();
            //jasm
            drv.fout << "  method public static " << type_str(yystack_[1].value.as < ValueType > ()) 
                     << ' ' << yystack_[5].value.as < std::string > () << '(' << (yystack_[5].value.as < std::string > () == "main" ? "java.lang.String[]" : params_str) << ')' << std::endl
                     << "  max_stack 15" << std::endl 
                     << "  max_locals 15" << std::endl
                     << "  {" << std::endl;
            params_str.clear();
      }
#line 777 "parser.cc"
    break;

  case 10: // method: DEF declaring_id "(" formal_arguments_optional ")" assign_type_optional "{" $@4 constant_and_variable_declarations statements_optional "}"
#line 125 "parser.yy"
                                                                   { 
            drv.symtab.exit_block(); 
            //jasm
            drv.fout << "    " << (yystack_[5].value.as < ValueType > () == ValueType::VOID ? "return" : "ireturn") << std::endl;
            drv.fout << "  }" << std::endl;
      }
#line 788 "parser.cc"
    break;

  case 11: // formal_arguments_optional: formal_arguments
#line 133 "parser.yy"
                                            { yylhs.value.as <  std::vector<ValueType>  > ().swap(yystack_[0].value.as <  std::vector<ValueType>  > ()); }
#line 794 "parser.cc"
    break;

  case 12: // formal_arguments_optional: %empty
#line 134 "parser.yy"
                                  { }
#line 800 "parser.cc"
    break;

  case 13: // formal_arguments: formal_arguments "," formal_argument
#line 137 "parser.yy"
                                                             {
                    yylhs.value.as <  std::vector<ValueType>  > ().swap(yystack_[2].value.as <  std::vector<ValueType>  > ()); yylhs.value.as <  std::vector<ValueType>  > ().push_back(yystack_[0].value.as < ValueType > ());
                    //jasm
                    params_str += std::string(", ") + type_str(yystack_[0].value.as < ValueType > ());
                }
#line 810 "parser.cc"
    break;

  case 14: // formal_arguments: formal_argument
#line 142 "parser.yy"
                                  { 
                    yylhs.value.as <  std::vector<ValueType>  > ().push_back(yystack_[0].value.as < ValueType > ());
                    //jasm
                    params_str += type_str(yystack_[0].value.as < ValueType > ());
                }
#line 820 "parser.cc"
    break;

  case 15: // formal_argument: ID assign_type
#line 149 "parser.yy"
                                { 
                    drv.symtab.default_variable(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ValueType > ());
                    yylhs.value.as < ValueType > () = yystack_[0].value.as < ValueType > ();
               }
#line 829 "parser.cc"
    break;

  case 16: // $@5: %empty
#line 155 "parser.yy"
                                    {
                //jasm
                Lfalse.emplace_back(get_label());
                Lexit.emplace_back(get_label());
                drv.fout << "    ifeq " << Lfalse.back() << std::endl;
          }
#line 840 "parser.cc"
    break;

  case 17: // $@6: %empty
#line 160 "parser.yy"
                            {
                //jasm
                drv.fout << "    goto " << Lexit.back() << std::endl
                         << Lfalse.back() << ": " << std::endl;
                Lfalse.pop_back();
          }
#line 851 "parser.cc"
    break;

  case 18: // conditions: IF "(" boolean_expr ")" $@5 block_or_simple $@6 else_optional
#line 165 "parser.yy"
                          {
                //jasm
                drv.fout << Lexit.back() << ": " << std::endl;
                Lexit.pop_back();
          }
#line 861 "parser.cc"
    break;

  case 21: // $@7: %empty
#line 176 "parser.yy"
                 {
        //jasm
        Lbegin.emplace_back(get_label());
        Lexit.emplace_back(get_label());
        drv.fout << Lbegin.back() << ": " << std::endl;
     }
#line 872 "parser.cc"
    break;

  case 22: // $@8: %empty
#line 181 "parser.yy"
                        {
        //jasm
        drv.fout << "    ifeq " << Lexit.back() << std::endl;
     }
#line 881 "parser.cc"
    break;

  case 23: // loops: WHILE "(" $@7 boolean_expr ")" $@8 block_or_simple
#line 184 "parser.yy"
                       {
        //jasm
        drv.fout << "    goto " << Lbegin.back() << std::endl
                 << Lexit.back() << ": " << std::endl;
        Lbegin.pop_back(); Lexit.pop_back();
     }
#line 892 "parser.cc"
    break;

  case 24: // $@9: %empty
#line 190 "parser.yy"
                                                                {
            drv.symtab.default_variable(yystack_[5].value.as < std::string > ()); 
     }
#line 900 "parser.cc"
    break;

  case 26: // boolean_expr: expressions
#line 195 "parser.yy"
                          {
                if(yystack_[0].value.as < ValueType > () != ValueType::BOOLEAN)
                    yy::parser::error(drv.location, "expression not boolean\n");
            }
#line 909 "parser.cc"
    break;

  case 29: // $@10: %empty
#line 205 "parser.yy"
           { drv.symtab.enter_block(); }
#line 915 "parser.cc"
    break;

  case 30: // block: "{" $@10 constant_and_variable_declarations statements "}"
#line 206 "parser.yy"
                                                         { drv.symtab.exit_block(); }
#line 921 "parser.cc"
    break;

  case 35: // constant_declaration: VAL declaring_id assign_type_optional "=" constant_exp
#line 217 "parser.yy"
                                                                                             {
                        if(yystack_[2].value.as < ValueType > () == ValueType::VOID || yystack_[2].value.as < ValueType > () == yystack_[0].value.as < Data > ().value_type)
                            drv.symtab.insert(yystack_[3].value.as < std::string > (), yystack_[0].value.as < Data > ().value, yystack_[0].value.as < Data > ().value_type);
                        else yy::parser::error(drv.location, std::string(yystack_[3].value.as < std::string > ()) + " type not matched\n");
                    }
#line 931 "parser.cc"
    break;

  case 36: // variable_declaration: VAR declaring_id assign_type "=" constant_exp
#line 224 "parser.yy"
                                                                        {
                        if(yystack_[2].value.as < ValueType > () == yystack_[0].value.as < Data > ().value_type)
                            drv.symtab.insert(yystack_[3].value.as < std::string > (), yystack_[2].value.as < ValueType > ());
                        else yy::parser::error(drv.location, std::string(yystack_[3].value.as < std::string > ()) +  " type not matched\n");
                        // jasm
                        if(drv.symtab.in_global())
                            drv.fout << "  field static " << type_str(yystack_[2].value.as < ValueType > ()) << ' ' << yystack_[3].value.as < std::string > () << std::endl;
                        else
                            drv.fout <<"  " << datasm(yystack_[0].value.as < Data > ()) 
                                     << "    istore " << drv.symtab.get_number(yystack_[3].value.as < std::string > ()) << std::endl;
                    }
#line 947 "parser.cc"
    break;

  case 37: // variable_declaration: VAR declaring_id assign_type
#line 235 "parser.yy"
                                                       { 
                        drv.symtab.insert(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ValueType > ()); 
                        // jasm
                        if(drv.symtab.in_global())
                            drv.fout << "  field static " << type_str(yystack_[0].value.as < ValueType > ()) << ' ' << yystack_[1].value.as < std::string > () << std::endl;
                    }
#line 958 "parser.cc"
    break;

  case 38: // variable_declaration: VAR declaring_id "=" constant_exp
#line 241 "parser.yy"
                                                            { 
                        drv.symtab.insert(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Data > ().value_type); 
                        // jasm
                        if(drv.symtab.in_global())
                            drv.fout << "  field static " << type_str(yystack_[0].value.as < Data > ().value_type) << ' ' << yystack_[2].value.as < std::string > () << std::endl;
                        else 
                            drv.fout << "  " << datasm(yystack_[0].value.as < Data > ()) 
                                     << "    istore " << drv.symtab.get_number(yystack_[2].value.as < std::string > ()) << std::endl;
                    }
#line 972 "parser.cc"
    break;

  case 39: // variable_declaration: VAR declaring_id
#line 250 "parser.yy"
                                           { 
                        drv.symtab.insert(yystack_[0].value.as < std::string > ());
                        // jasm
                        if(drv.symtab.in_global())
                            drv.fout << "  field static " << "int " << yystack_[0].value.as < std::string > () << std::endl;
                    }
#line 983 "parser.cc"
    break;

  case 40: // assign_type_optional: assign_type
#line 258 "parser.yy"
                                  { yylhs.value.as < ValueType > () = yystack_[0].value.as < ValueType > (); }
#line 989 "parser.cc"
    break;

  case 41: // assign_type_optional: %empty
#line 259 "parser.yy"
                             { yylhs.value.as < ValueType > () = ValueType::VOID; }
#line 995 "parser.cc"
    break;

  case 42: // assign_type: ":" type
#line 262 "parser.yy"
                      { yylhs.value.as < ValueType > () = yystack_[0].value.as < ValueType > (); }
#line 1001 "parser.cc"
    break;

  case 43: // type: BOOLEAN
#line 264 "parser.yy"
                { yylhs.value.as < ValueType > () = ValueType::BOOLEAN; }
#line 1007 "parser.cc"
    break;

  case 44: // type: INT
#line 265 "parser.yy"
             { yylhs.value.as < ValueType > () = ValueType::INTEGER; }
#line 1013 "parser.cc"
    break;

  case 45: // type: CHAR
#line 266 "parser.yy"
             { yylhs.value.as < ValueType > () = ValueType::CHAR; }
#line 1019 "parser.cc"
    break;

  case 46: // type: STRING
#line 267 "parser.yy"
                 { yylhs.value.as < ValueType > () = ValueType::STRING; }
#line 1025 "parser.cc"
    break;

  case 47: // declaring_id: ID
#line 270 "parser.yy"
                 {
                if( drv.symtab.is_declared(yystack_[0].value.as < std::string > ()) ) 
                yy::parser::error(drv.location, std::string(yystack_[0].value.as < std::string > ()) + " redeclared\n");
                yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
            }
#line 1035 "parser.cc"
    break;

  case 57: // procedure_invocations: ID "(" comma_separated_expressions ")"
#line 292 "parser.yy"
                                                                      {
                        if(std::string m(std::move(drv.symtab.match_procedure(yystack_[3].value.as < std::string > (), yystack_[1].value.as <  std::vector<ValueType>  > ()))); m != "match")
                            yy::parser::error(drv.location, m);
                        //jasm
                        drv.fout << "    invokestatic " << type_str(drv.symtab.get_type(yystack_[3].value.as < std::string > ()))
                                 << ' ' << object_id << '.' << yystack_[3].value.as < std::string > () << '(' << params_str << ')' << std::endl;
                        params_str.clear();
                     }
#line 1048 "parser.cc"
    break;

  case 58: // procedure_invocations: ID
#line 300 "parser.yy"
                          {
                        if(std::string m(std::move(drv.symtab.match_procedure(yystack_[0].value.as < std::string > (), {}))); m != "match")
                            yy::parser::error(drv.location, m);
                     }
#line 1057 "parser.cc"
    break;

  case 59: // simple: data_type_id "=" expressions
#line 307 "parser.yy"
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
                    // jasm
                    drv.fout << (drv.symtab.in_global() ? "  " : "    ");  
                    if( drv.symtab.is_global(yystack_[2].value.as < std::string > ()) )
                        drv.fout << "putstatic " << type_str(id_data_type.value_type)
                                 << ' ' << object_id << '.' << yystack_[2].value.as < std::string > () << std::endl;
                    else 
                        drv.fout << "istore " << drv.symtab.get_number(yystack_[2].value.as < std::string > ()) << std::endl;
                }
            }
      }
#line 1087 "parser.cc"
    break;

  case 60: // $@11: %empty
#line 332 "parser.yy"
                  {
            //jasm
            drv.fout << "    getstatic java.io.PrintStream java.lang.System.out" << std::endl;
      }
#line 1096 "parser.cc"
    break;

  case 61: // simple: PRINT "(" $@11 expressions ")"
#line 335 "parser.yy"
                              {
            //jasm
            drv.fout << "    invokevirtual void java.io.PrintStream.print(";
            if(yystack_[1].value.as < ValueType > () == ValueType::STRING) drv.fout << "java.lang.String)" << std::endl;
            else drv.fout << type_str(yystack_[1].value.as < ValueType > ()) << ")" << std::endl;
      }
#line 1107 "parser.cc"
    break;

  case 62: // $@12: %empty
#line 341 "parser.yy"
                    {

            drv.fout << "    getstatic java.io.PrintStream java.lang.System.out" << std::endl;
      }
#line 1116 "parser.cc"
    break;

  case 63: // simple: PRINTLN "(" $@12 expressions ")"
#line 344 "parser.yy"
                              {
            //jasm
            drv.fout << "    invokevirtual void java.io.PrintStream.println(";
            if(yystack_[1].value.as < ValueType > () == ValueType::STRING) drv.fout << "java.lang.String)" << std::endl;
            else drv.fout << type_str(yystack_[1].value.as < ValueType > ()) << ")" << std::endl;
      }
#line 1127 "parser.cc"
    break;

  case 66: // expressions: "-" expressions
#line 354 "parser.yy"
                                                      {
                if(yystack_[0].value.as < ValueType > () == ValueType::INTEGER || yystack_[0].value.as < ValueType > () == ValueType::FLOAT) yylhs.value.as < ValueType > () = yystack_[0].value.as < ValueType > ();
                else yy::parser::error(drv.location, "expression not arithmetic\n");
                //jasm
                drv.fout << "    ineg" << std::endl;
           }
#line 1138 "parser.cc"
    break;

  case 67: // expressions: expressions "*" expressions
#line 360 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match") yylhs.value.as < ValueType > () = yystack_[2].value.as < ValueType > ();
                else yy::parser::error(drv.location, m);
                //jasm
                drv.fout << "    imul" << std::endl;
           }
#line 1149 "parser.cc"
    break;

  case 68: // expressions: expressions "/" expressions
#line 366 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match") yylhs.value.as < ValueType > () = yystack_[2].value.as < ValueType > ();
                else yy::parser::error(drv.location, m);
                //jasm
                drv.fout << "    idiv" << std::endl;
           }
#line 1160 "parser.cc"
    break;

  case 69: // expressions: expressions "+" expressions
#line 372 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match") yylhs.value.as < ValueType > () = yystack_[2].value.as < ValueType > ();
                else yy::parser::error(drv.location, m);
                //jasm
                drv.fout << "    iadd" << std::endl;
           }
#line 1171 "parser.cc"
    break;

  case 70: // expressions: expressions "-" expressions
#line 378 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match") yylhs.value.as < ValueType > () = yystack_[2].value.as < ValueType > ();
                else yy::parser::error(drv.location, m);
                //jasm
                drv.fout << "    isub" << std::endl;
           }
#line 1182 "parser.cc"
    break;

  case 71: // expressions: expressions "<" expressions
#line 384 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match")
                    yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    iflt " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
#line 1201 "parser.cc"
    break;

  case 72: // expressions: expressions "<=" expressions
#line 398 "parser.yy"
                                                {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match")
                    yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    ifle " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
#line 1220 "parser.cc"
    break;

  case 73: // expressions: expressions "==" expressions
#line 412 "parser.yy"
                                                {
                if(yystack_[2].value.as < ValueType > () == yystack_[0].value.as < ValueType > ()) yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, "type not match\n");
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    ifeq " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
#line 1238 "parser.cc"
    break;

  case 74: // expressions: expressions ">=" expressions
#line 425 "parser.yy"
                                                {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match")
                    yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    ifge " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
#line 1257 "parser.cc"
    break;

  case 75: // expressions: expressions ">" expressions
#line 439 "parser.yy"
                                               {
                if(std::string m = drv.symtab.arithmetic_match(yystack_[2].value.as < ValueType > (), yystack_[0].value.as < ValueType > ()); m == "match")
                    yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    ifgt " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
#line 1276 "parser.cc"
    break;

  case 76: // expressions: expressions "!=" expressions
#line 453 "parser.yy"
                                                {
                if(yystack_[2].value.as < ValueType > () == yystack_[0].value.as < ValueType > ()) yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, "type not match\n");
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    ifne " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
#line 1294 "parser.cc"
    break;

  case 77: // expressions: "!" expressions
#line 466 "parser.yy"
                                        {
                if(yystack_[0].value.as < ValueType > () == ValueType::BOOLEAN) yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "! required boolean expression\n");
                //jasm
                drv.fout << "    ixor" << std::endl;
           }
#line 1305 "parser.cc"
    break;

  case 78: // expressions: expressions "&&" expressions
#line 472 "parser.yy"
                                                 {
                if(yystack_[2].value.as < ValueType > () == ValueType::BOOLEAN && yystack_[0].value.as < ValueType > () == ValueType::BOOLEAN) yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "&& required boolean expression\n");
                //jasm
                drv.fout << "    iand" << std::endl;
           }
#line 1316 "parser.cc"
    break;

  case 79: // expressions: expressions "||" expressions
#line 478 "parser.yy"
                                                  {
                if(yystack_[2].value.as < ValueType > () == ValueType::BOOLEAN && yystack_[0].value.as < ValueType > () == ValueType::BOOLEAN) yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "|| required boolean expression\n");
                //jasm
                drv.fout << "    ior" << std::endl;
           }
#line 1327 "parser.cc"
    break;

  case 80: // expressions: CONSTANT_BOOLEAN
#line 484 "parser.yy"
                                 { 
                yylhs.value.as < ValueType > () = ValueType::BOOLEAN;
                //jasm
                drv.fout << "    iconst_" << (yystack_[0].value.as < bool > () ? '1' : '0' ) << std::endl;
           }
#line 1337 "parser.cc"
    break;

  case 81: // expressions: CONSTANT_INTEGER
#line 489 "parser.yy"
                                 { 
                yylhs.value.as < ValueType > () = ValueType::INTEGER;
                //jasm
                drv.fout << "    sipush " << yystack_[0].value.as < int > () << std::endl;
           }
#line 1347 "parser.cc"
    break;

  case 82: // expressions: CONSTANT_CHAR
#line 494 "parser.yy"
                           { yylhs.value.as < ValueType > () = ValueType::CHAR; }
#line 1353 "parser.cc"
    break;

  case 83: // expressions: CONSTANT_STRING
#line 495 "parser.yy"
                                { 
                yylhs.value.as < ValueType > () = ValueType::STRING;
                //jasm
                drv.fout << "    ldc \"" << yystack_[0].value.as < std::string > () << '\"' << std::endl;
           }
#line 1363 "parser.cc"
    break;

  case 84: // expressions: data_type_id
#line 500 "parser.yy"
                              {
                const DataType& id_data_type = drv.symtab.get_data_type(yystack_[0].value.as < std::string > ());
                if(id_data_type.is_array)
                    yy::parser::error(drv.location, "id: " + yystack_[0].value.as < std::string > () + " is array type\n");
                else yylhs.value.as < ValueType > () = id_data_type.value_type;
                //jasm
                if(id_data_type.is_const)
                    drv.fout << "    " << datasm(drv.symtab.get_data(yystack_[0].value.as < std::string > ()));
                else{
                    if(drv.symtab.is_global(yystack_[0].value.as < std::string > ()))
                        drv.fout << "    getstatic int " << object_id << '.' << yystack_[0].value.as < std::string > () << std::endl;
                    else
                        drv.fout << "    iload " << drv.symtab.get_number(yystack_[0].value.as < std::string > ()) << std::endl;
                }
           }
#line 1383 "parser.cc"
    break;

  case 85: // expressions: function_invocation
#line 515 "parser.yy"
                                 { yylhs.value.as < ValueType > () = yystack_[0].value.as < ValueType > (); }
#line 1389 "parser.cc"
    break;

  case 86: // data_type_id: ID
#line 518 "parser.yy"
                 {
                const ClassType& id_class = drv.symtab.lookup(yystack_[0].value.as < std::string > ());
                if(id_class == ClassType::NIL)
                    yy::parser::error(drv.location, "id: " + yystack_[0].value.as < std::string > () + " is not declared\n");
                else if(id_class != ClassType::DATA)
                    yy::parser::error(drv.location, "id: " + yystack_[0].value.as < std::string > () + " is not a data\n");
                else yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
            }
#line 1402 "parser.cc"
    break;

  case 87: // function_invocation: ID "(" comma_separated_expressions ")"
#line 528 "parser.yy"
                                                                    {
                        if(std::string m(std::move(drv.symtab.match_function(yystack_[3].value.as < std::string > (), yystack_[1].value.as <  std::vector<ValueType>  > ()))); m != "match")
                            yy::parser::error(drv.location, m);
                        else yylhs.value.as < ValueType > () = drv.symtab.get_type(yystack_[3].value.as < std::string > ());
                        //jasm
                        drv.fout << "    invokestatic " << type_str(drv.symtab.get_type(yystack_[3].value.as < std::string > ()))
                                 << ' ' << object_id << '.' << yystack_[3].value.as < std::string > () << '(' << params_str << ')' << std::endl;
                        params_str.clear();
                   }
#line 1416 "parser.cc"
    break;

  case 88: // comma_separated_expressions: comma_separated_expressions "," expressions
#line 539 "parser.yy"
                                                                                 {
                                yylhs.value.as <  std::vector<ValueType>  > ().swap(yystack_[2].value.as <  std::vector<ValueType>  > ()); yylhs.value.as <  std::vector<ValueType>  > ().push_back(yystack_[0].value.as < ValueType > ());
                                //jasm
                                params_str += std::string(", ") + type_str(yystack_[0].value.as < ValueType > ());
                           }
#line 1426 "parser.cc"
    break;

  case 89: // comma_separated_expressions: expressions
#line 544 "parser.yy"
                                         { 
                               yylhs.value.as <  std::vector<ValueType>  > ().push_back(yystack_[0].value.as < ValueType > ());
                               //jasm
                               params_str += type_str(yystack_[0].value.as < ValueType > ());
                           }
#line 1436 "parser.cc"
    break;

  case 90: // comma_separated_expressions: %empty
#line 549 "parser.yy"
                                    { }
#line 1442 "parser.cc"
    break;

  case 91: // constant_exp: CONSTANT_BOOLEAN
#line 552 "parser.yy"
                               { yylhs.value.as < Data > () = { ValueType::BOOLEAN, yystack_[0].value.as < bool > () }; }
#line 1448 "parser.cc"
    break;

  case 92: // constant_exp: CONSTANT_INTEGER
#line 553 "parser.yy"
                               { yylhs.value.as < Data > () = { ValueType::INTEGER, yystack_[0].value.as < int > () }; }
#line 1454 "parser.cc"
    break;

  case 93: // constant_exp: CONSTANT_CHAR
#line 554 "parser.yy"
                            { yylhs.value.as < Data > () = { ValueType::CHAR, yystack_[0].value.as < char > () }; }
#line 1460 "parser.cc"
    break;

  case 94: // constant_exp: CONSTANT_STRING
#line 555 "parser.yy"
                              { yylhs.value.as < Data > () = { ValueType::STRING, yystack_[0].value.as < std::string > () }; }
#line 1466 "parser.cc"
    break;


#line 1470 "parser.cc"

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
  ">", "==", "!=", "&&", "||", "!", "BOOLEAN", "INT", "CHAR", "STRING",
  "DO", "WHILE", "FOR", "CONTINUE", "REPEAT", "IF", "ELSE", "CASE",
  "BREAK", "EXIT", "CLASS", "OBJECT", "DEF", "NULL", "PRINT", "PRINTLN",
  "RETURN", "TO", "TYPE", "VAL", "VAR", "ID", "CONSTANT_BOOLEAN",
  "CONSTANT_INTEGER", "CONSTANT_CHAR", "CONSTANT_STRING", "UMINUS",
  "$accept", "program", "$@1", "$@2", "$@3", "global_declarations",
  "methods", "method", "$@4", "formal_arguments_optional",
  "formal_arguments", "formal_argument", "conditions", "$@5", "$@6",
  "else_optional", "loops", "$@7", "$@8", "$@9", "boolean_expr",
  "block_or_simple", "block", "$@10", "constant_and_variable_declarations",
  "constant_and_variable_declaration", "constant_declaration",
  "variable_declaration", "assign_type_optional", "assign_type", "type",
  "declaring_id", "statements_optional", "statements", "statement",
  "procedure_invocations", "simple", "$@11", "$@12", "expressions",
  "data_type_id", "function_invocation", "comma_separated_expressions",
  "constant_exp", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -137;

  const signed char parser::yytable_ninf_ = -87;

  const short
  parser::yypact_[] =
  {
     -39,  -137,     8,   -25,  -137,  -137,    24,  -137,  -137,    27,
     -34,   -13,   -11,  -137,   -13,   -13,  -137,  -137,  -137,  -137,
      62,  -137,  -137,    70,     7,    26,    52,    69,  -137,    68,
      82,    70,    95,   106,  -137,  -137,  -137,  -137,  -137,  -137,
      68,  -137,  -137,  -137,  -137,  -137,    68,  -137,    70,    26,
    -137,  -137,    99,  -137,  -137,  -137,    59,  -137,   113,   114,
     120,   123,   132,     3,    -5,  -137,  -137,  -137,   116,    51,
    -137,  -137,  -137,   131,  -137,  -137,    86,     3,  -137,  -137,
       3,     3,   144,  -137,  -137,  -137,  -137,   156,  -137,  -137,
       3,  -137,  -137,     3,    59,     3,   134,   145,   156,     3,
       3,  -137,   185,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,   156,    29,   156,    84,
     150,   103,  -137,   121,   141,    65,    60,    60,  -137,  -137,
     101,   101,   101,   101,   101,   101,   185,   171,     3,  -137,
    -137,  -137,   110,    17,  -137,  -137,  -137,   156,    17,   117,
    -137,  -137,  -137,  -137,  -137,   166,   136,  -137,    17,  -137,
      17,  -137,  -137
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     2,     0,     0,     1,     3,     0,     4,    32,     0,
       6,     0,     0,     8,     0,     0,    31,    33,    34,    47,
       0,     5,     7,    41,    39,    12,     0,     0,    40,     0,
      37,     0,     0,    11,    14,    43,    44,    45,    46,    42,
       0,    91,    92,    93,    94,    38,     0,    15,    41,     0,
      35,    36,     0,    13,     9,    32,    49,    29,     0,     0,
       0,     0,     0,    65,    58,    54,    55,    53,     0,    48,
      51,    56,    52,     0,    32,    21,     0,     0,    60,    62,
       0,     0,    86,    80,    81,    82,    83,    64,    84,    85,
      90,    10,    50,     0,     0,     0,     0,     0,    26,     0,
       0,    66,    77,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,    59,     0,
       0,     0,    16,     0,     0,     0,    69,    70,    67,    68,
      71,    72,    74,    75,    73,    76,    78,    79,     0,    57,
      30,    22,     0,     0,    61,    63,    87,    88,     0,     0,
      86,    17,    27,    28,    23,     0,    20,    24,     0,    18,
       0,    19,    25
  };

  const short
  parser::yypgoto_[] =
  {
    -137,  -137,  -137,  -137,  -137,  -137,  -137,   176,  -137,  -137,
    -137,   140,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
     107,   -81,  -136,  -137,   -51,  -137,  -137,  -137,   142,   -15,
    -137,    76,  -137,   109,   -63,  -137,  -133,  -137,  -137,   -60,
     -56,  -137,   108,    -4
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     6,     8,     9,    12,    13,    55,    32,
      33,    34,    65,   143,   156,   159,    66,    95,   148,   160,
      97,   151,    67,    74,    10,    16,    17,    18,    27,    28,
      39,    20,    68,    69,    70,    71,    72,    99,   100,    98,
      88,    89,   117,    45
  };

  const short
  parser::yytable_[] =
  {
      73,    21,    90,    87,    56,     1,    92,   152,     4,    30,
     153,    26,   152,    73,   -86,   153,    47,    80,    14,    15,
     101,   102,   152,    94,   152,   153,    29,   153,    57,     5,
     116,    81,   138,   118,    11,     7,    50,   139,    73,   123,
     124,    19,    51,   116,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    92,    82,    83,    84,
      85,    86,    57,    73,    61,    62,    63,   154,   138,    25,
      57,   150,    11,   146,    26,   106,   107,   161,   147,   162,
      31,    35,    36,    37,    38,    58,    59,    73,    40,    60,
      23,    24,    73,    58,    59,    57,   140,    60,    61,    62,
      63,    46,    73,    48,    73,    64,    61,    62,    63,    49,
      54,    14,    15,    64,   104,   105,   106,   107,    58,    59,
      75,    76,    60,    41,    42,    43,    44,    77,    91,   144,
      78,    61,    62,    63,   104,   105,   106,   107,    64,    79,
      96,   108,   109,   110,   111,   112,   113,   114,   115,   145,
      93,   103,   121,   122,   104,   105,   106,   107,   141,   142,
     149,   108,   109,   110,   111,   112,   113,   114,   115,   104,
     105,   106,   107,   155,   157,   158,   108,   109,   110,   111,
     112,   113,   114,   115,   104,   105,   106,   107,    22,    53,
      52,   108,   109,   110,   111,   112,   113,   114,   104,   105,
     106,   107,   120,   119,     0,   108,   109,   110,   111,   112,
     113,   125
  };

  const short
  parser::yycheck_[] =
  {
      56,    12,     7,    63,    55,    44,    69,   143,     0,    24,
     143,     4,   148,    69,    19,   148,    31,    14,    52,    53,
      80,    81,   158,    74,   160,   158,    19,   160,    11,    54,
      90,    28,     3,    93,    45,    11,    40,     8,    94,    99,
     100,    54,    46,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   119,    54,    55,    56,
      57,    58,    11,   119,    47,    48,    49,   148,     3,     7,
      11,    54,    45,     8,     4,    15,    16,   158,   138,   160,
      54,    29,    30,    31,    32,    34,    35,   143,    19,    38,
      14,    15,   148,    34,    35,    11,    12,    38,    47,    48,
      49,    19,   158,     8,   160,    54,    47,    48,    49,     3,
      11,    52,    53,    54,    13,    14,    15,    16,    34,    35,
       7,     7,    38,    55,    56,    57,    58,     7,    12,     8,
       7,    47,    48,    49,    13,    14,    15,    16,    54,     7,
      54,    20,    21,    22,    23,    24,    25,    26,    27,     8,
      19,     7,    18,     8,    13,    14,    15,    16,     8,    56,
      50,    20,    21,    22,    23,    24,    25,    26,    27,    13,
      14,    15,    16,    56,     8,    39,    20,    21,    22,    23,
      24,    25,    26,    27,    13,    14,    15,    16,    12,    49,
      48,    20,    21,    22,    23,    24,    25,    26,    13,    14,
      15,    16,    95,    94,    -1,    20,    21,    22,    23,    24,
      25,   103
  };

  const signed char
  parser::yystos_[] =
  {
       0,    44,    61,    62,     0,    54,    63,    11,    64,    65,
      84,    45,    66,    67,    52,    53,    85,    86,    87,    54,
      91,    12,    67,    91,    91,     7,     4,    88,    89,    19,
      89,    54,    69,    70,    71,    29,    30,    31,    32,    90,
      19,    55,    56,    57,    58,   103,    19,    89,     8,     3,
     103,   103,    88,    71,    11,    68,    84,    11,    34,    35,
      38,    47,    48,    49,    54,    72,    76,    82,    92,    93,
      94,    95,    96,   100,    83,     7,     7,     7,     7,     7,
      14,    28,    54,    55,    56,    57,    58,    99,   100,   101,
       7,    12,    94,    19,    84,    77,    54,    80,    99,    97,
      98,    99,    99,     7,    13,    14,    15,    16,    20,    21,
      22,    23,    24,    25,    26,    27,    99,   102,    99,    93,
      80,    18,     8,    99,    99,   102,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,     3,     8,
      12,     8,    56,    73,     8,     8,     8,    99,    78,    50,
      54,    81,    82,    96,    81,    56,    74,     8,    39,    75,
      79,    81,    81
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    60,    62,    63,    64,    61,    65,    66,    66,    68,
      67,    69,    69,    70,    70,    71,    73,    74,    72,    75,
      75,    77,    78,    76,    79,    76,    80,    81,    81,    83,
      82,    84,    84,    85,    85,    86,    87,    87,    87,    87,
      88,    88,    89,    90,    90,    90,    90,    91,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    95,    95,    96,
      97,    96,    98,    96,    96,    96,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,   100,   101,   102,   102,
     102,   103,   103,   103,   103
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     0,     0,     9,     1,     2,     1,     0,
      11,     1,     0,     3,     1,     2,     0,     0,     8,     2,
       0,     0,     0,     7,     0,    10,     1,     1,     1,     0,
       5,     2,     0,     1,     1,     5,     5,     3,     4,     2,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       0,     5,     0,     5,     2,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     1,
       0,     1,     1,     1,     1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    99,    99,   100,   101,    99,   106,   109,   110,   114,
     113,   133,   134,   137,   142,   149,   155,   160,   155,   172,
     173,   176,   181,   176,   190,   190,   195,   201,   202,   205,
     205,   209,   210,   213,   214,   217,   224,   235,   241,   250,
     258,   259,   262,   264,   265,   266,   267,   270,   277,   278,
     281,   282,   285,   286,   287,   288,   289,   292,   300,   307,
     332,   332,   341,   341,   350,   351,   354,   360,   366,   372,
     378,   384,   398,   412,   425,   439,   453,   466,   472,   478,
     484,   489,   494,   495,   500,   515,   518,   528,   539,   544,
     549,   552,   553,   554,   555
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
#line 2162 "parser.cc"

#line 558 "parser.yy"


void yy::parser::error (const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
