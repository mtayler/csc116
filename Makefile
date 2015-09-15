CXX=clang++
CXXFLAGS=-Wall -pedantic 
LDFLAGS=
SOURCES=turtle.cpp svg_file.cpp
EXECUTABLE1=

all: 1 2 3

1:
	$(CXX) $(LDFLAGS) $(CXXFLAGS) $(SOURCES) part1_tester.cpp -g -o part1

2:
	$(CXX) $(LDFLAGS) $(CXXFLAGS) $(SOURCES) part2.cpp -g -o part2

3:
	$(CXX) $(LDFLAGS) $(CXXFLAGS) $(SOURCES)3 part3.cpp -g -o part3

clean:
	-rm -fr *.dSYM
	-rm -f $(EXECUTABLE)1 $(EXECUTABLE)2 $(EXECUTABLE)3
