#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "mpc.h"

static char buffer[2048];

int main(int argc, char const *argv[])
{
  mpc_parser_t* Number = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expression = mpc_new("expression");
  mpc_parser_t* Hlisp = mpc_new("hlisp");

  mpca_lang(MPCA_LANG_DEFAULT,
    /* 
    Here we define the grammar for our Lisp (reverse Polish notation, in this case).
    In order, we say:
    - numbers are values from 0-9
    - operators are any of +, -, / or *
    - expressions are either a number or an operator followed by
      an expression in parens
    - finally, a valid command is a line starting with an operator
      and ending with some number of expressions
    */
    "number : /-?[0-9]+/ ; \
    operator : '+' | '-' | '/' | '*' ; \
    expression : <number> | '(' <operator> <expression>+ ')' ; \
    hlisp : /^/ <operator> <expression>+ /$/ ; \
    ",
    Number, Operator, Expression, Hlisp
  );

  while (1) { // loop
    char* input = readline("\nhlisp> ");
    add_history(input);

    mpc_result_t result;
    if (mpc_parse("<stdin>", input, Hlisp, &result)) {
      mpc_ast_print(result.output);
      mpc_ast_delete(result.output);
    } else {
      puts("oh no");
    }
  }


  // undefine and clean up the parsers
  mpc_cleanup(4, Number, Operator, Expression, Hlisp);
  return 0;
}
