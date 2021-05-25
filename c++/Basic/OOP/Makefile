
CC=g++
DEPS=Father.h Child.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

all: main.o Father.o Child.o
	$(CC) -o main main.o Father.o Child.o

clean:
	rm *.o

# this is a comment
# % is wildcard
# basic makefile template
# target: dependencies
# 	action