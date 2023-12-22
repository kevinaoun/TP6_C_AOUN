CC= gcc
CFLAGS= -Wall -Wextra -fsanitize=address -g

all: main exe

main: fonctions.o main.o header.h
	@$(CC) $(CFLAGS) -o main main.o fonctions.o

main.o: main.c header.h
	@$(CC) -o main.o -c main.c

fonctions.o: fonctions.c header.h
	@$(CC) -o fonctions.o -c fonctions.c

exe:
	@./main

clean:
	@rm main
	@rm *.o