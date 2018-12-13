CPPFLAGS := -O2 -Wall -c -Wno-c++11-extensions
RM := rm -f

.PHONY: clean

.PHONY: all

all: gen_random.x gen_sorted.x gen_sorted_first.x gen_sorted_last.x gen_reverse.x merge_sort.x quick_sort.x std_sort.x heap_sort.x heap_sort.x


%.x: %.o 
	g++ -std=c++11 -o $@ $^


%.o: %.cxx 
	g++ -std=c++11 $(CPPFLAGS) -o $@ $^


clean:
	$(RM) *.o *.x *.txt
