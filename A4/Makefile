CXXFLAGS=-Wall -Wextra -Werror -pedantic
LDFLAGS=
SOURCESVECTOR=vector_stack_tester.cpp
SOURCESSLL=sll_stack_tester.cpp
SOURCESPART2=part2.cpp part2_tester.cpp
EXECUTABLEVECTOR=vector_stack
EXECUTABLESLL=sll_stack
EXECUTABLEPART2=part2

.PHONY: all clean
all: vector_stack sll_stack part2

vector_stack: $(SOURCESVECTOR) vector_stack.h
	$(CXX) $(CXXFLAGS) $(SOURCESVECTOR) -g -o $(EXECUTABLEVECTOR)

sll_stack: $(SOURCESSLL) sll_stack.h
	$(CXX) $(CXXFLAGS) $(SOURCESSLL) -g -o $(EXECUTABLESLL)

part2: $(SOURCESPART2)
	$(CXX) $(CXXFLAGS) $(SOURCESPART2) -g -o $(EXECUTABLEPART2)

clean:
	rm -rf *.dSYM
	rm -f $(EXECUTABLEVECTOR) $(EXECUTABLESLL) $(EXECUTABLEPART2)
