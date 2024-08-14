make: main.c
	gcc main.c -o main -g

run: main.c
	gcc main.c -o main && "./main.exe"
