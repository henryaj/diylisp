// all variables in C have an explicit type.
// variable declaration is a statement. all statements end with a ;.

int count; // declaring an int
int count = 10; // declaring and setting an int

char initial = 'H';
int age = 28;
long big_number = 4289043;
float liters_per_pint = 0.568f;
double speed_of_swallow = 0.00483902;

// function declarations include the type the function returns,
// the name of the function, and then its typed arguments.

int sum_these_nums(int x, int y) {
	int result = x + y;
	return result;
}

// calling a function:

int sum = sum_these_nums(5, 6);

// structs are used to hold a bunch of variables.
// to declare new kinds of structs, use the `typedef` and
// `struct` keywords.

typedef struct {
	float x;
	float y;
} point; // <- name of the new type goes here!

// this definition needs to go ABOVE any functions that wish to use it.

point p
p.x = 5.0;
p.y = 2.3;

// use an asterisk to declare a pointer.

int* y; // a pointer to an integer
char** argv; // a pointer to pointers to characters

// strings are represented by the pointer type char*.
// the final character in the list is the null terminator.

// while loops:

int i = 10;
while (i > 0) {
	puts("Hello!");
	i = i - 1;
}

// for loops:

for (int i = 0; i < 98; i++) {
	puts("bottles of beer");
}

