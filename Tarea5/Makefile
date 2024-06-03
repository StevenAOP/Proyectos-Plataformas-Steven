CC = gcc
CFLAGS = -Wall

SRCS = double_list.c main.c
OBJS = $(SRCS:.c=.o)
TARGET = listaDoble

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o$

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f listaDoble $(OBJS)