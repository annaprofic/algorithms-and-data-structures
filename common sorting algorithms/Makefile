CPPFLAGS := -O2 -Wall -c -Wno-c++11-extensionsRM := rm -f

.PHONY: clean

.PHONY: all

all: genRandom.x insertion_sort.x bubble_sort.x selection_sort.x std_sort.x counting_sort.x

%.x: %.o 
	g++ -std=c++11 -o $@ $^


%.o: %.cxx 
	g++ -std=c++11 $(CPPFLAGS) -o $@ $^


clean:
	$(RM) *.o *.x *.txt
