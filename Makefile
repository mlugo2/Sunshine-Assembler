
OBJS=main.cpp

CC=gcc
TARGET = sasm

all: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

run:
	./sasm example.sun
