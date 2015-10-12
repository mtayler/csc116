CC=clang++
CFLAGS=-Wall -pedantic
LDFLAGS=-std="c++98"
PART1_SOURCES=array_list.cpp array_list_tester.cpp
PART1_EXECUTABLE=array_list
PART2_SOURCES=linked_list.cpp linked_list_tester.cpp
PART2_EXECUTABLE=linked_list

all: part1 part2

part1:
	$(CC) $(CXXFLAGS) $(PART1_SOURCES) -g -o $(PART1_EXECUTABLE)

part2:
	$(CC) $(CXXFLAGS) $(PART2_SOURCES) -g -o $(PART2_EXECUTABLE)

