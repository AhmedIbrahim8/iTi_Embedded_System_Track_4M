build:file.c
	gcc file.c -o file.exe
	gcc -E -P file.c -o file.i
	gcc -S file.c -o file.asm
	gcc -c file.c -o file.o
	
pre:file.c file1.c file2.c file3.c
	gcc -E -P file.c -o file.i
	gcc -E -P file1.c -o file1.i
	gcc -E -P file2.c -o file2.i
	gcc -E -P file3.c -o file3.i