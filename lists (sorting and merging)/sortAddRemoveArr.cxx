#include <iostream>
#include "sortedArrayList.hxx"
#include "sortedLinkedList.hxx"

const int n = 50000; 
int main(int argc, char *argv[]){ 
    clock_t start = clock();
    SortedArrayList arraylist(n); 
    //adding 50k random elements
    for (int i = 0; i < n; i++) {
        arraylist.push((rand() % n-25000)); 
    }
     //removing all of elements from random positions
    for (int i = 0; i < n; i++) {
        arraylist.erase((rand() % n-i)); 
    }
    printf( "Sorted Array List. Adding&Removing elements.\nProgram execution time: %lu ms\n", clock() - start );

}