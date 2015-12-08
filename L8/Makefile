CXXFLAGS=-Wall -Wextra -Werror -pedantic-errors
LDFLAGS=
SOURCES=calculator.cpp main.cpp
EXECUTABLE=calculate

all: calculate

calculate: calculator.cpp main.cpp
	$(CXX) $(CXXFLAGS) $(SOURCES) -g -o $(EXECUTABLE)

.PHONY: clean
clean:
	rm -rf $(EXECUTABLE)
	rm -rf *.dSYM
