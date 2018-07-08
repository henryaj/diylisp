// lines starting with # are preprocessor commands.
#include <stdio.h>
#include <stdlib.h>

// if we are compiling on Windows...
#ifdef _WIN32

// compile these functions...
#include <string.h>

static char input_buf[2048];

char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(input_buf, 2048, stdin);

	char* cpt = malloc(strlen(buffer)+1); // +1 to account for null term byte
	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

void add_history(char* _) {} // no-op

#else
// otherwise just use readline
#include <readline/readline.h>
#include <readline/history.h>
#endif

// now this code is portable.
int main(int argc, char** argv) {
	puts("HLisp -- version 0.0.1");
	puts("Press Ctrl-C to exit\n");

	while (1) {
		// use readline to read from the prompt
		char* input_buf = readline("hlisp> ");

		add_history(input_buf); // this comes from history.h

		printf("No u %s\n", input_buf);

		// free the memory used by the input buffer
		free(input_buf);
	}

	return 0;
}
