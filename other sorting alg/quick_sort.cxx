#include <iostream>
#include <algorithm>
#include <chrono> 

// unsigned int count_max; 
// unsigned int count_min; 

class QuickSort {

    private: 
        int size; 
        int* data; 
        int* temp; 
        int top; 

    public: 

        QuickSort(int size) { 
            this->size = size; 
            data = new int[size]; 
            temp = new int[size]; 
            top = -1; 
        }

        ~QuickSort() {
            delete data; 
            delete temp; 
        }

        void get_data() { 
            int el = 0; 
            std::string arg; 
            for (int i = 0; i < size; i++ ){
                std::cin >> arg; 
                el = stoi(arg); 
                data[i] = el; 

                // count_max++; 
                // count_min++; 
            }
        }

        void sort(int start, int end) {
            auto start_ = std::chrono::high_resolution_clock::now();

            int stack[ end - start + 1 ]; 

            // count_max += 2; 
            // count_min += 2; 

            stack[++top] = start; 
            stack[++top] = end; 

            // Dopoki nie jest pusty to sciagamy elementy 
            while (top >= 0) { 
                // count_max++; 
                // count_min++; 

                // count_max++; 
                // count_min++; 
                end = stack[top--]; 
                start = stack[top--]; 
                //wybieramy pivot  
                int middle = (start + end) / 2;

                // count_max += 3; 
                // count_min += 3; 
                std::swap(data[end], data[middle]); 
                int x = data[end]; // nasz pivot 
                int i = start; //zaczynamy od pierwszego elementu 
                int p; 

                for (int j = start; j <= end - 1; j++) { 
                    // count_max += 2; 
                    // count_min += 2; 
                    if (data[j] <= x) { 
                        // count_max += 3; 
                        std::swap(data[i], data[j]); 
                        i++; //pierwszy wiekszy element od pivota 
                    } 
                } 
                // count_max += 3;
                // count_min += 3;
                std::swap(data[i], data[end]); 
                p = i; 
        
                // If there are elements on left side of pivot, 
                // then push left side to stack 

                // count_max++; 
                // count_min++; 
                if (p > start) { 
                    // count_max += 2; 
                    stack[ ++top ] = start; 
                    stack[ ++top ] = p - 1; 
                } 
        
                // If there are elements on right side of pivot, 
                // then push right side to stack 
                // count_max++; 
                // count_min++;
                if (p + 2 < end) { 
                    // count_max += 2; 
                    stack[ ++top ] = p + 1; 
                    stack[ ++top ] = end; 
                } 
            }  
            auto end_ = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end_ - start_;
            std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
        } 

        void print() { 
            for(int i = 0; i < size; i++) {
                std::cout << data[i] << std::endl;
            }
        }
}; 

int main(int argc, char* argv[]) {
    int size = atoi(argv[1]); 
    QuickSort qs(size); 
    qs.get_data(); 
    qs.sort(0, size - 1); 
    // std::cout <<  count_max << std::endl; 
    // std::cout << count_min << std::endl;
    //qs.print(); 
}
