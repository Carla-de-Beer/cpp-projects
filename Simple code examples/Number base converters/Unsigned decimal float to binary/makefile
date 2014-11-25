OBJECTS = main.o BinaryConversions.o
CC = g++
COMPILE_FLAGS = -c -g -Wall -Werror -pedantic
LINK_FLAGS = -static
TARGET = main

all: $(OBJECTS) 
	$(CC) $(LINK_FLAGS) -Wall -Werror -pedantic $(OBJECTS) -o $(TARGET)

main.o: main.cpp BinaryConversions.o 
	$(CC) $(COMPILE_FLAGS) main.cpp

BinaryConversions.o: BinaryConversions.cpp  
	$(CC) $(COMPILE_FLAGS) BinaryConversions.cpp
