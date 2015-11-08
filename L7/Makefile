CXXFLAGS=-Wall -Wextra -Werror -pedantic-errors
LDFLAGS=
SOURCES=test_queue.cpp
EXECUTABLE=test_queue

all: test_queue messaging

test_queue: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -g -o $(EXECUTABLE)

messaging: message_filter.cpp message_simulation.cpp
	$(CXX) $(CXXFLAGS) message_filter.cpp message_simulation.cpp -g -o messaging
