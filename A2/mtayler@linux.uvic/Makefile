CXXFLAGS=-Wall -pedantic
LDFLAGS=-std="c++98"
PART1_SOURCES=array_list.cpp array_list_tester.cpp
PART1_EXECUTABLE=array_list
PART2_SOURCES=linked_list.cpp linked_list_tester.cpp
PART2_EXECUTABLE=linked_list

all: array_list linked_list

array_list:
	$(CXX) $(CXXFLAGS) $(PART1_SOURCES) -g -o $(PART1_EXECUTABLE)

linked_list:
	$(CXX) $(CXXFLAGS) $(PART2_SOURCES) -g -o $(PART2_EXECUTABLE)

