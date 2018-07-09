all:
	cc -std=c99 -Ilib lib/mpc.c hlisp.c -ledit -o hlisp