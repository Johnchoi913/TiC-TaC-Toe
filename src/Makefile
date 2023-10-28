CC = gcc
CFLAGS = -g -Wall -Werror
LDFLAGS = -lm
TARGET = main 
DEPS = ttt.h
OBJ = drawEngine.o game.o main.o

all : $(TARGET)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)