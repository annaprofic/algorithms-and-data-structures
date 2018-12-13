#include <iostream>
#include "sortedArrayList.hxx"

int main(int argc, char *argv[]) { 

    std::string arg;

    int el = 0; 
    std::cin >> arg; 
    int size1 = stoi(arg); 
    SortedArrayList list1(size1); 

    for (int i = 0; i < size1; i++){ 
        std::cin >> arg; 
        el = stoi(arg); 
        list1.push(el); 
    }

    std::cin >> arg; 
    int size2 = stoi(arg);  
    SortedArrayList list2(size2); 
    for (int i = 0; i < size2; i++){ 
        std::cin >> arg; 
        el = stoi(arg); 
        list2.push(el); 
    }

    std::cout << "Lists afer merging: " << std::endl;
    SortedArrayList newlist = SortedArrayList::merge(list1, list2); 
    newlist.print();
    std::cout << "Unique list: " << std::endl;
    newlist.unique(); 
    newlist.print(); 
}