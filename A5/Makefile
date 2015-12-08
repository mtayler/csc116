CXXFLAGS=-Wall -Wextra
LDFLAGS=
SOURCES=
EXECUTABLE=output

.PHONY: all, clean

all: bst dictionary contactlist

bst: bst.h bst_tester.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) bst_tester.cpp -g -o bst

dictionary: dictionary.h dictionary_tester.cpp bst
	$(CXX) $(CXXFLAGS) $(LDFLAGS) dictionary_tester.cpp -g -o dictionary

contactlist: contactlist.h contactlist_tester.cpp dictionary
	$(CXX) $(CXXFLAGS) $(LDFLAGS) contactlist_tester.cpp -g -o contactlist

clean:
	rm -rf *.dSYM
	rm -rf bst
	rm -rf dictionary
	rm -rf contactlist
