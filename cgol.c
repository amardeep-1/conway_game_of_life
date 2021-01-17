

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>

#define COLS 40
#define ROWS 20
#define MAXLENGTH 20



int main ( int argc, char *argv[] ) {
	bool play = true;
	bool ask = true; 
	int ticks;
	int ticksDone = 0;
	int i, j;

	char fileName[100];

	if ( argc == 3 ) {
		ticks = atoi(argv[2]);
		strcpy(fileName, argv[1]);

	} else if ( argc == 2 ) {
		ticks = 50;
		strcpy(fileName, argv[1]);

	}else{
		printf("Usage: ./cgol <seed file> <ticks>\n");
		return(1);
	}

	int ticksAdd = ticks;

	int grid [ROWS][COLS] = {
		{0} 
	};
  
	char string[100];


	/* error checking for file content*/
	FILE *file; 
    if ( (file = fopen(fileName, "r")) != NULL){ 
    
       int lineCntr = 0;
       int columnCntr = 0; 

       char ch = getc(file); 

		while (ch != EOF)  /*checks till end of file*/
		{ 
			if (ch=='1' || ch=='0' ) {
		 	columnCntr++;
		 	lineCntr++; 
				
			}
			else if (ch==' ' ) {

			}
			else if (ch=='\n') {
				if (columnCntr != 40 && lineCntr!=800) {
					printf("Invalid file content.\n");
		    		return (1);
				}
		        columnCntr = 0;
			}
			else {
				printf("Invalid file content.\n");
		    	return (1);
			}
            ch = getc(file); 

		}

		if (lineCntr!=800)  /*if its not 800 then there are more or less 1s or 0s*/
		{
			printf("Invalid file content.\n");
		    return (1);
		}

	} else {
    	printf("Invalid file name.\n");
    	return(1);
    }

	fclose(file);

	/* adds file content to grid*/
 	if ( (file = fopen(fileName, "r")) != NULL) { 

    	for (i = 0; i < ROWS; ++i)
	    {
	       	for (j = 0; j < COLS; ++j)
	    	{
	    		fscanf(file,"%s",string); 
	    		
	    		grid[i][j] = atoi(string);
	    		
	    	}
	    }
    } else {
    	printf("Invalid file name.\n");
    	return(1);
    }
    fclose(file);

    /*turns 1s and 0s to Xs and spaces*/
    char gridX [ROWS][COLS];
    for (i = 0; i < ROWS; ++i)
    {
       	for (j = 0; j < COLS; ++j)
    	{ 
    		if (grid[i][j]==0)
    		{
    			gridX[i][j]=' ';
    		}
    		if (grid[i][j]==1)
    		{
    			gridX[i][j]='X';
    		}
    		
    	}
    }



    /*prints the grid with boarder around it*/
	printf(" ----------------------------------------\n");
 	for ( i=0; i<ROWS; i++ ) {
 		printf("|");
 		for ( j=0; j<COLS; j++ ) {
 			printf ( "%c", gridX[i][j]);
 		}
 		printf("|\n");
 	}
 	printf(" ----------------------------------------%d\n",ticksDone);

 	ask = true;
	char repeatInputOut[MAXLENGTH];


	while (ask == true){     /*while loop for error handling*/

		
		printf ( "Start? (y or n): " );
		fgets ( repeatInputOut, MAXLENGTH, stdin );
		repeatInputOut[strlen(repeatInputOut)-1] = 0;

		if (strcmp(repeatInputOut,"Y")==0 || strcmp(repeatInputOut,"y")==0)	
		{
			ask = false;

		}else if (strcmp(repeatInputOut,"N")==0 || strcmp(repeatInputOut,"n")==0)
		{
			return(1);

		} else {
			printf("Only the single characters y or n are acceptable.\n");
		}
	}


	int stop; /*used later to check if the grid is the same in 2 ticks*/


	int living = 0;
	ticksDone=0;

	while(play == true){

	 	for (ticksDone = ticksDone; ticksDone < ticks; ++ticksDone)
	 	{
	 	
	 		system("clear"); /*clears terminal to give animation effect*/
	 		
	 		
	 		int gridCopy [ROWS][COLS] = {
				{0}
			};

			for (i = 0; i < ROWS; ++i)
		    {
		    	/*checks for living x beside the current x*/
		    	/*stops checking at the boarder*/

		       	for (j = 0; j < COLS; ++j) 
		    	{
		    		living = 0;


		    		if (i==0 && j==0)
		    		{			    		
			    		if (grid[i-1][j+1] == 1)
			    		{
			    			living++;
			    		}			    		
			    		if (grid[i][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j+1] == 1)
			    		{
			    			living++;
			    		} 
		    		} else if (i==0 && j==(COLS-1))
		    		{
		    			if (grid[i-1][j-1] == 1)
			    		{
			    			living++;
			    		} 	    		
			    		if (grid[i][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    		
		    		} else if (i==(ROWS-1) && j==0)
		    		{
		    			if (grid[i-1][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i-1][j] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i-1][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    		
		    		} else if (i==(ROWS-1) && j==(COLS-1))
		    		{
			    		if (grid[i-1][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i-1][j] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i-1][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j-1] == 1)
			    		{
			    			living++;
			    		} 

		    		} else if (i==0)
		    		{
			    		if (grid[i][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j+1] == 1)
			    		{
			    			living++;
			    		} 
		    		} else if (i==(ROWS-1))
		    		{
		    			if (grid[i-1][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i-1][j] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i-1][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i][j+1] == 1)
			    		{
			    			living++;
			    		} 
		    		} else if (j==0)
		    		{
		    			if (grid[i-1][j] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i-1][j+1] == 1)
			    		{
			    			living++;
			    		}
			    		if (grid[i][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j+1] == 1)
			    		{
			    			living++;
			    		} 
		    		} else if (j==(COLS-1))
		    		{
		    			if (grid[i-1][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i-1][j] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i][j-1] == 1)
			    		{
			    			living++;
			    		} 			    		
			    		if (grid[i+1][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j] == 1)
			    		{
			    			living++;
			    		} 			    		
		    		}else{

			    		if (grid[i-1][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i-1][j] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i-1][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j-1] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j] == 1)
			    		{
			    			living++;
			    		} 
			    		if (grid[i+1][j+1] == 1)
			    		{
			    			living++;
			    		} 
			    	}

			    	/*acording to whats living it updates a future grid*/

			    	/*follows rules for living and dead cells*/
		    		if (grid[i][j] == 1)
		    		{
			    		if (living<2)
			    		{
			    			gridCopy[i][j]=0;

			    		} else if (living>1 && living<4)
			    		{
			    			gridCopy[i][j]=1;

			    		} else if (living>3)
			    		{
			    			gridCopy[i][j]=0;
			    		}
		    		} else {
			    		if (living==3)
			    		{
			    			gridCopy[i][j]=1;
			    		} else{
			    			gridCopy[i][j]=0;
			    		}
			    	}

		    	}
		    }

		    /*if the two grids are the same it stops after it prints them both*/
		    stop = 0;

	    	for (i = 0; i < ROWS; ++i)
		    {
		       	for (j = 0; j < COLS; ++j)
		    	{
		    		if (grid[i][j] == gridCopy[i][j])
		    		{
		    			stop++;
		    		}
		    		grid[i][j] = gridCopy[i][j];
		    	}
		    }



		    /*prints the new grid*/
		    char gridX [ROWS][COLS];
		    for (i = 0; i < ROWS; ++i)
		    {
		       	for (j = 0; j < COLS; ++j)
		    	{ 
		    		if (grid[i][j]==0)
		    		{
		    			gridX[i][j]=' ';
		    		}
		    		if (grid[i][j]==1)
		    		{
		    			gridX[i][j]='X';
		    		}
		    		
		    	}
		    }

	    	printf(" ----------------------------------------\n");
		 	for ( i=0; i<ROWS; i++ ) {
		 		printf("|");
		 		for ( j=0; j<COLS; j++ ) {
		 			printf ( "%c", gridX[i][j]);
		 		}
		 		printf("|\n");
		 	}
		 	printf(" ----------------------------------------%d\n",ticksDone+1);

		    system ( "sleep 0.1" );

		    /*the stop is placed here to make sure it prints both grids*/
		    /*a TA said it was fine if both the grids get printed bofore it stops*/
		    if (stop==800)
		    {
		    	return(0);
		    }
		}


		 
		ask = true;


		while (ask == true){     /*while loop for error handling*/

			
			printf ( "Continue? (y or n): " );
			fgets ( repeatInputOut, MAXLENGTH, stdin );
			repeatInputOut[strlen(repeatInputOut)-1] = 0;

			if (strcmp(repeatInputOut,"Y")==0 || strcmp(repeatInputOut,"y")==0)	
			{
				ask = false;
				
				ticks = ticks + ticksAdd;


			}else if (strcmp(repeatInputOut,"N")==0 || strcmp(repeatInputOut,"n")==0)
			{
				play = false;
				ask = false;

			} else {
				printf("Only the single characters y or n are acceptable.\n");
			}
		}

		

	}


	


	return (0);

}