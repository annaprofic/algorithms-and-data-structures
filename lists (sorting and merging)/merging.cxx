#include <iostream>
#include "sortedArrayList.hxx"
#include "sortedLinkedList.hxx"
#include <list>

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list) {
    for (auto &i : list) {
        ostr << i << " " <<std::flush;
    }
    return ostr;
}


int main(int argc, char *argv[]) { 

    std::string arg;

    int el = 0; 
    std::cin >> arg; 
    int size1 = stoi(arg); 
    SortedArrayList arraylist1(size1); 
    SortedLinkedList linkedlist1; 
    std::list<int> stdlist1; 

    for (int i = 0; i < size1; i++){ 
        std::cin >> arg; 
        el = stoi(arg); 
        arraylist1.push(el); 
        linkedlist1.push(el);
        stdlist1.push_back(el); 
    } 

    std::cin >> arg; 
    int size2 = stoi(arg);  
    SortedArrayList arraylist2(size2);
    SortedLinkedList linkedlist2; 
    std::list<int> stdlist2; 

    for (int i = 0; i < size2; i++){ 
        std::cin >> arg; 
        el = stoi(arg); 
        arraylist2.push(el); 
        linkedlist2.push(el); 
        stdlist2.push_back(el); 
    }

    std::cout << "Array lists afer merging: " << std::endl;
    SortedArrayList newarraylist = SortedArrayList::merge(arraylist1, arraylist2); 
    newarraylist.print();
    std::cout << "\nUnique array list: " << std::endl;
    newarraylist.unique(); 
    newarraylist.print(); 

    std::cout << "\n\nLinked lists afer merging: " << std::endl;
    SortedLinkedList newlinkedlist = SortedLinkedList::merge(linkedlist1, linkedlist2); 
    newlinkedlist.print();
    std::cout << "\nUnique linked list: " << std::endl;
    newlinkedlist.unique(); 
    newlinkedlist.print();

    std::cout << "\n\nstd lists afer merging: " << std::endl;
    stdlist1.merge(stdlist2); 
    std::cout << stdlist1 << std::endl;
    std::cout << "\nUnique std list: " << std::endl;
    stdlist1.unique(); 
    std::cout << stdlist1 << std::endl;

}