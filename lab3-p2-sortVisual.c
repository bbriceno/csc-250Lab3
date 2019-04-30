#include <stdio.h>
#include "myGfxShapesLib.h"
#include "myFunctionsLib.h"
#include "gfx2.h"
#include <stdlib.h>


int main(int argc, char *argv[])
{

	FILE *userTxtFile, *outputTxtFile;;
	int i = 0, n;
	double myArr[100];
	double currNum;

	userTxtFile = fopen(argv[1], "r");

	if (userTxtFile == NULL)
	{
		printf("Sorry the file does not extist");
		exit(0);
	}

	printf("Input file found: %s\n\n", argv[1]);

	while (!feof(userTxtFile))
	{
		fscanf(userTxtFile, "%lf", &currNum);
		myArr[i] = currNum;
		i++;
	}
	fclose(userTxtFile);

	sortVisualize(myArr, i);

}
