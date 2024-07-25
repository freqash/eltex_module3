CC = gcc
CFLAGS = -Wall -g
SRCS = cli.c max.c min.c multip.c sum.c
OBJS = $(SRCS:.c=.o)
TARGET = cli
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)
.PHONY: clean
