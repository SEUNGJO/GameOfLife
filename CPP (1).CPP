#include <iostream.h>	// input output stream header file
#include <stdio.h>	// standard input output header file
#include <stdlib.h>  	// standard library header file
#include <string.h>	// header file with string function
// #include <conio.h>	// console input output header file
#include <time.h>


// John H Conway's game of life simulation program in c++
// Birth Rules:
//	1. cell must be empty
//	2. Exactly 3 neighbors
// Life continuation rules:
//	1. minimum of 2 neighbors and a 
//		maximum of 3 neighbors
// Death rules:
//	1. Isolation if less than 2 neighbors
//	2. overcrowding if more than 3 neighbors
void funcFG(int organism[104][204], char option)	{  	// FG = First Generation
// a grid of 104 rows and 204 columns cells
int aux[104][204];	// aux = auxillary = temperory
int i,j,k, l,m,n;

for (m = 1; m< 103; m++)
	for (m=1; m< 203; m++)
		if ( option == 'n' ) // n = neighbor cell		
		{
			// confirm all the 8 eighbor cells
			int cellCount = 0;
			cellCount = organism[n-1 ][m] + 
				   organism[n-1 ] [ m-1] +
				   organism[ n ] [ m-1] +
				   organism[ n+1 ] [ m-1] +
				   organism[ n+1 ] [ m] +
				   organism[ n+1 ] [ m+1] +
				   organism[ n ] [m+1 ] +
				   organism[ n-1 ] [m+1 ] ;
			if ( cellCount < 2 || cellCount > 3  ) 
				// in this case the cell is not alive any more - because either isolated or over crowded
				aux[n][m] = 0;
			if (cellCount == 2)
				// life continues as it meets the rule of minimum 2 and maximum 3 neighbors
				aux[n][m] = organism[n][m];
			if ( cellCount == 3) 		
				// chance of a new birth and also continue life for old cells
				aux[n][m] = 1;
		} // end if of if (option = n)

	
		} // end if

} // end funcFG   first generation

void func4G()	{	// 4G 4 Generations

} // end func4G next 4 generations
int main()	// start main
{
// program to do:
//	function 1. Start with first generation of organisms
//	function 2. Generate the next 4 generations
//	Data file: LIFE.txt 
//		contents: First Generation data
//		
	FILE *fp; // file pointer
	fp = fopen("E:/Files/LIFE.txt", "r");
	// read the first generation data from LIFE.txt
	char dataFG[121]; // assume a 11 rows by 11 columns matrix
	// call functoin first gen
//	funcFG();
	fclose(fp);
return 0; // exit
} // end of main()


