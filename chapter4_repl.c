#include <stdio.h>
#include <stdlib.h>

// #include <editline/readline.h>
// #include <editline/history.h>
#include <readline/readline.h>
#include <readline/history.h>

static char input_buf[2048];

int main(int argc, char** argv) {
	puts("HLisp -- version 0.0.1");
	puts("Press Ctrl-C to exit\n");

	while (1) {
		// use readline to read from the prompt
		char* input_buf = readline("hlisp> ");

		add_history(input_buf); // this comes from history.h

		printf("No u %s", input_buf);

		// free the memory used by the input buffer
		free(input_buf);
	}

	return 0;
}
