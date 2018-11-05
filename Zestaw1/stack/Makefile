CPPFLAGS := -O2 -Wall -c
RM := rm -f

.PHONY: clean

.PHONY: all

all: genList.x stack.x stdstack.x


%.x: %.o 
	g++ -std=c++11 -o $@ $^


%.o: %.cxx 
	g++ -std=c++11 $(CPPFLAGS) -o $@ $^


clean:
	$(RM) *.o *.x *.txt
