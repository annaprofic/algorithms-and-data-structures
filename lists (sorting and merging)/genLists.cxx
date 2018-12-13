#include <iostream> 
#include <cstdlib>
#include <ctime>
const int max = 500; 

int main(int argc, char* argv[]) { 

    srand(time(NULL));
    if (argc < 2){ 
        std::cout << "Wrong program arguments, please enter ./genLists 'summa of size of first list and size of second list'" << std::endl;
        return -1; 
    }
    int fullsize = atoi(argv[1]); 

    //size of first list
    int size1 = (std::rand() % fullsize+1); 
    std::cout << size1 << std::endl;
    int arr1[size1]; 
    //random elements of first list
    for (int i = 0; i < size1; i++) {
        arr1[i] = (rand() % max-250); 
    }
    //sorting
    int n = sizeof(arr1)/sizeof(arr1[0]); 
    std::sort(arr1, arr1+n);

    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << " " << std::flush;
    }
    std::cout << std::endl;

    //size of second list
    int size2 = fullsize - size1; 
    std::cout << size2 << std::endl;
    int arr2[size2]; 
    //random elements of second list
    for (int i = 0; i < size2; i++) {
        arr2[i] = (rand() % max-250); 
    }
    //sorting 
    int n2 = sizeof(arr2)/sizeof(arr2[0]); 
    std::sort(arr2, arr2+n2);

    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << " " << std::flush;
    }

    return 0; 
}