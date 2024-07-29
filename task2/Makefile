SRC = cli.c sum.c min.c max.c multip.c

BIN = cli sum min max multip

CC = gcc

CFLAGS = -Wall

all: $(BIN)

# Компиляция каждого .c файла в отдельное приложение
cli: cli.c
	$(CC) $(CFLAGS) -o cli cli.c

sum: sum.c
	$(CC) $(CFLAGS) -o sum sum.c

min: min.c
	$(CC) $(CFLAGS) -o min min.c

max: max.c
	$(CC) $(CFLAGS) -o max max.c

multip: multip.c
	$(CC) $(CFLAGS) -o multip multip.c

# Очистка созданных файлов
clean:
	rm -f $(BIN)