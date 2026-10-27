CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

bst: bst.cc bst.h binarysearchtree.h btree.h node.h
	$(CXX) $(CXXFLAGS) bst.cc -o bst

clean:
	rm -f bst

.PHONY: clean