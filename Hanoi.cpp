#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define EMPTY 0
#define DISKS 4

int pos[3][DISKS];

char code[3] = { 'A', 'B', 'C' };

//Function Prototypes

void towers(int n, int origin, int temp, int next);

void moveDisk(int origin, int next);

//Main(int, char)

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int hold = 0;

	cout << "\n\n WELCOME TO THE TOWER OF HANOI PUZZLE!! \2  \3  \1 \n\n";
	printf("\n\n  The Towers of Hanoi: %d Disks\n\n", DISKS);

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < DISKS; ++j)
		{
			if (i == 0)
			{
				pos[i][j] = j + 1;
			}
			else
			{
				pos[i][j] = EMPTY;
			}
		}
	}

	printf("\n\n          A B C\n");
	printf("          - - -\n");

	for (j = 0; j < DISKS; ++j)
	{
		printf("%11.1d %d %d\n", pos[0][j], pos[1][j], pos[2][j]);
	}

	cout << endl;

	towers(DISKS, 0, 1, 2);

	cout << "THANKS FOR THE WONDERFUL TIME, THANK YOU! \3  \3  \3" << endl << endl;

	return 0;
}

//Function Definitions

void towers(int n, int origin, int temp, int next)
{
	if (n == 1)
	{
		moveDisk(origin, next);
	}
	else
	{
		towers(n - 1, origin, next, temp);
		moveDisk(origin, next);
		towers(n - 1, temp, origin, next);
	}

	return;
}

void moveDisk(int origin, int next)
{
	int i = 0;
	int j = 0;

	//Finding original location
	while (pos[origin][i] == EMPTY)
	{
		i++;
	}

	//Determine the next location
	while ((pos[next][j] == EMPTY) && (j < DISKS))
	{
		j++;
	}

	j -= 1;

	//Moving disk
	printf("\n  Move disk #%d from %c to %c:\n\n", pos[origin][i], code[origin], code[next]);
	pos[next][j] = pos[origin][i];
	pos[origin][i] = EMPTY;

	//Printing disk location
	printf("\n\n          A B C\n");
	printf("          - - -\n");

	for (j = 0; j < DISKS; ++j)
	{
		printf("%11.1d %d %d\n", pos[0][j], pos[1][j], pos[2][j]);
	}
	printf("\n");

	return;
}

