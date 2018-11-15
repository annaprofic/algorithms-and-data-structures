#include <iostream>
#include "sortedArrayList.hxx"
#include "sortedLinkedList.hxx"

const int n = 50000; 
int main(int argc, char *argv[]){ 
    clock_t start = clock();
    SortedLinkedList linkedlist; 
    //adding 50k random elements
    for (int i = 0; i < n; i++) {
        linkedlist.push((rand() % n-25000)); 
    }
    //removing all of elements from random positions 
    for (int i = 0; i < n; i++) {
        linkedlist.erase((rand() % n-i));  //Θ(n)
    } 

    printf( "Sorted Linked List. Adding&Removing elements.\nProgram execution time: %lu ms\n", clock() - start );

}