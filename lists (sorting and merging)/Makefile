CPPFLAGS := -O2 -Wall -c
RM := rm -f

.PHONY: clean

.PHONY: all

all: sortedArrayList.x sortedLinkedList.x genLists.x merging.x sortAddRemoveArr.x sortAddRemoveLink.x

%.x: %.o 
	g++ -std=c++11 -o $@ $^


%.o: %.cxx 
	g++ -std=c++11 $(CPPFLAGS) -o $@ $^


clean:
	$(RM) *.o *.x *.txt
