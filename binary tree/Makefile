CPPFLAGS := -O2 -Wall -c -Wno-c++11-extensions
RM := rm -f

.PHONY: clean

.PHONY: all

all: binary_tree.x tree_iterative.x


%.x: %.o 
	g++ -std=c++11 -o $@ $^


%.o: %.cxx 
	g++ -std=c++11 $(CPPFLAGS) -o $@ $^


clean:
	$(RM) *.o *.x *.txt
