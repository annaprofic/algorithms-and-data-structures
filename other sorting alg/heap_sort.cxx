#include <iostream>
#include <vector>
#include <chrono> 

// unsigned int count_max; 
// unsigned int count_min; 

class Heap {
    private:   
        void heapify_iter(int);    // Wersja iteracyjna
        void heapify_rec(int);     // Wersja rekurencyjna
        std::vector<int> data;
        int end; 

    public:
        void build(int*, int);
        void push(int x);         // Wstawia element do kopca
        int pop();                // Usuwa element z kopca
        int& top();               // Zwraca referncję do ostatniego elementu
        int size();               // Zwraca liczbę elementów w kopcu
        bool empty();             // Sprawdza czy kopiec jest pusty
        bool check();             // Sprawdza czy właściwość kopca jest zachowana
        void sort_rec(int*, int);
        void sort_iter(int*, int);
        void print(); 
}; 

void Heap::heapify_iter(int i) {
    int largest, left_c, right_c;
    // count_max++; 
    // count_min++;
    while(i < end) {
        largest = i;
        left_c = 2 * i;
        right_c = left_c + 1;

        // count_max += 4; 
        // count_min++;
        if(left_c < end && data[left_c] > data[largest]) 
            largest = left_c;

        // count_max += 4; 
        // count_min++;
        if(right_c < end && data[right_c] > data[largest]) 
            largest = right_c;

        // count_max++; 
        // count_min++;
        if(largest == i) return;
        
        // count_max += 3; 
        // count_min += 3; 
        std::swap(data[i],data[largest]);

        // count_max++; 
        // count_min++;
        i = largest;
    }
}

void Heap::heapify_rec(int i) {
    int largest, left_c, right_c;

        // count_max++; 
        // count_min++;
        while(i < end) {
            largest = i;
            left_c = 2 * i;
            right_c = left_c + 1;

            // count_max += 4; 
            // count_min++;
            if(left_c < end && data[left_c] > data[largest]) 
                largest = left_c;

            // count_max += 4; 
            // count_min++;        
            if(right_c < end && data[right_c] > data[largest]) 
                largest = right_c;

            // count_max++; 
            // count_min++;
            if(largest == i) return;

            // count_max += 3; 
            // count_min += 3; 
            std::swap(data[largest], data[i]);
            heapify_rec(largest);
        }

}

void Heap::build(int *arr, int size) {
    data.clear();

    // count_max++; 
    // count_min++;
    data.push_back(-1);
    for(int i = 0; i < size; i++) {
        // count_max++; 
        // count_min++;
        data.push_back(arr[i]);
    }
    this->end = size + 1; // nie ma posortowanych elementow 
    for(int i = size/2; i > 0; i--) {
        // count_max++; 
        // count_min++;
        heapify_iter(i);
    }
}


void Heap::push(int x) {

    int i = data[0]++;   // zwieksza ilość elementow w tablicy
    end = data[0];
    data[i] = x;

    int middle = i / 2;

    while(i > 1 && data[i] > data[middle]) {
  
        std::swap(data[i], data[middle]);
        i = middle;
        middle = i / 2;
    }
}

int Heap::pop() {
    if(!empty()) {
        int start = data[1];
        data.erase(++data.begin());
        std::swap(data[1], data[data.size()-1]);    
        
        for(int i = size()/2; i >= 1; i--) {
            heapify_iter(i);
        }    
        end--;
        return start;
    }
    return -1;
}  

int& Heap::top() {
     return this->data[size()-1];
}
     
int Heap::size() {
     return data.size()-1;
}

bool Heap::empty() {
     return data.size()==1;
}

bool Heap::check() {
    int size_ = size();
    int middle = size_ / 2; 
    int left;

    for(int i = 1; i <= middle; i = left) {
        left = 2 * i;
        if(left <= size_ && (data[i] < data[left])) 
            return false;
        if(left + 1 <= size_ && (data[i] < data[left + 1])) 
            return false;
    }
    return true;
}

void Heap::sort_rec(int * arr, int size_) {
    build(arr, size_); 
    for(int i = size(); i > 1; i--) {
        // count_max += 4; 
        // count_min += 4;
        std::swap(data[1], data[i]);
        end--; //staje sie pierwszym posortowanym 
        heapify_rec(1);
    }   
}

void Heap::sort_iter(int * arr, int size_) {
    build(arr, size_);

    for(int i = size(); i > 1; i--) {
        // count_max += 4; 
        // count_min += 4;
        std::swap(data[1], data[i]);
        end--; //staje sie pierwszym posortowanym   
        heapify_iter(1);
    }
}

void Heap::print() {
    for(int i = 1; i <= size(); i++) {
        std::cout << data[i] << std::endl;
    }
}

int main(int argc, char *argv[]) {
    int size = atoi(argv[1]); 
    int * data = new int[size];  
    int el = 0; 
    std::string arg; 
    for (int i = 0; i < size; i++){
        std::cin >> arg; 
        el = stoi(arg); 
        data[i] = el; 
    }
    Heap hp; 
    auto start = std::chrono::high_resolution_clock::now();
    hp.sort_iter(data,size);   
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
    hp.print();  
    // std::cout <<  count_max << std::endl; 
    // std::cout << count_min << std::endl; 
    // count_max = 0; 
    // count_min = 0; 
    std::cout << std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    hp.sort_rec(data,size);   
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;
    std::cerr << "Elapsed time[s] = " << elapsed2.count() << std::endl;
     hp.print(); 

    // std::cout <<  count_max << std::endl; 
    // std::cout << count_min << std::endl; 

    return 0;
}