#include <stdio.h>

static char input_buf[2048];

int main(int argc, char** argv) {
	puts("HLisp -- version 0.0.1");
	puts("Press Ctrl-C to exit\n");

	while (1) {
		fputs("hlisp> ", stdout); // print prompt
		fgets(input_buf, 2048, stdin);
		printf("No u %s", input_buf);
	}

	return 0;
}
