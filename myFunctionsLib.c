
#include <stdio.h>
#include "myGfxShapesLib.h"
#include "gfx2.h"
#include <unistd.h>


//function to sort an array of double using bubble sort
void sortNumbers(double sortArray[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (sortArray[j] > sortArray[j + 1])
			{
				double temp = sortArray[j];
				sortArray[j] = sortArray[j + 1];
				sortArray[j + 1] = temp;
			}

		}
	}
}

//function to visually sort an array of double using bubble sort 
void sortVisualize(double sortArray[], int n)
{
	int xsize = 400;
	int ysize = 400;
	int i, j;

	//graphic window
	while (1) {

		gfx_open(xsize, ysize, "Sorting");
		gfx_color(100, 100, 100);

		//Initialis draw bars
		drawBars(sortArray, n, 50, 300, .75*(300 / n), .25*(300 / n));
		gfx_flush();

		//stop for user
		usleep(300000);

		//bubble sort implementation with visualization
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - i - 1; j++)
			{
				gfx_clear();
				drawBars(sortArray, n, 50, 300, .75*(300 / n), .25*(300 / n));
				gfx_flush();
				usleep(500000);

				if (sortArray[j] > sortArray[j + 1])
				{	
					double temp = sortArray[j];
					sortArray[j] = sortArray[j + 1];
					sortArray[j + 1] = temp;
				}

			}
		}

		i = gfx_wait();

		// Stop if it is the letter q.
		if (i == 'q') break;

	}
}
