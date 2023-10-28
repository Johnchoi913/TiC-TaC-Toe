CC = gcc
CFLAGS = -g -Wall -Werror
LDFLAGS = -lm
TARGET = main 
DEPS = ttt.h
#OBJ = 	drawEngine.o game.o main.o
BINDER = ../bin
OBJDIR = ../obj
SRCS = drawEngine.c game.c main.c
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all : $(BINDER)/$(TARGET)

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

$(BINDER)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS) $(LDFLAGS)