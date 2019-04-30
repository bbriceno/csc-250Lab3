#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myFunctionsLib.h"

int main(int argc, char* argv[])
{
	FILE *userTxtFile, *outputTxtFile;
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
	
	sortNumbers(myArr, i);

	outputTxtFile = fopen(argv[2], "w");

	for (n = 0; n<i; n++) {
		fprintf(outputTxtFile, "%lf\n", myArr[n]);
	}
	
	fclose(outputTxtFile);
	printf("Sorted file has been printed to : %s\n", argv[2]);
	
	return 0;
}


