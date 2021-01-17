

all: cgol dynCGOL

cgol: cgol.o 
	gcc -ansi -Wall -o cgol cgol.o 

cgol.o: cgol.c
	gcc -ansi -Wall -c cgol.c

dynCGOL: dynCGOL.o 
	gcc -ansi -Wall -o dynCGOL dynCGOL.o 

dynCGOL.o: dynCGOL.c
	gcc -ansi -Wall -c dynCGOL.c



clean:
	rm cgol.o cgol dynCGOL.o dynCGOL
