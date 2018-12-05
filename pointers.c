#include <stdio.h>
#include <stdlib.h>

/**********************************************/
/*             POINTERS PROJECT               */
/****  ----------------------------------- ****/

/********** REQUIREMENTS **********/
		// Create a pointer for built-in data types int, char, array
	
		// Create functions to read from stdin and display pointer details

		// Free memory as needed

int charptr();
void swapints(int *a, int *b);
int arrayptr();

int main(void)
{	
	int x, y;	

	printf("Enter val x: ");
	scanf("%d", &x);
	getc(stdin); // Attempt to remove \n from stdin

	printf("Enter val y: ");
	scanf("%d", &y);
	getc(stdin); // Attempt to remove \n from stdin

	printf("Before swap: x=%i y=%i\n",x,y);
	swapints(&x,&y);
	printf("After swap: x=%i y=%i\n",x,y);

	if(charptr() > 0)
	{
		return 1;
	}

	if (arrayptr() > 0)
	{
		return 1;
	}

	return 0;
}

int charptr ()
{
	char *c = malloc(sizeof(char) * 256);

	if (!c)
	{
		printf("Memory error. Allocation failure\n");
		return 1;
	}

	printf("Enter your name: ");
	
	if(!(gets(c)))
	{
		printf("Error receiving input\n");
		free(c);
		return 1;
	}

	printf("STRING: %s\n", c);

	free(c);

	return 0;
}

void swapints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int arrayptr ()
{
	// Initialization
	int i[4] = {0,0,0,0};

	printf("Enter an index [0-3]: ");
	// I'm aware this is a terrible line of code. Just did it to see if it works
	int index = atoi(gets((char *)malloc(9)));
	
	printf("Enter a number: ");
	int num = atoi(gets((char *)malloc(9)));

	int *p = &i[0];
	p = p + index;
	*p = num;
	printf("{ ");
	for (int j = 0; j < 4; j++)
	{
		printf("%i ", i[j]);
	}
	printf("}\n");

	free(p);
}

