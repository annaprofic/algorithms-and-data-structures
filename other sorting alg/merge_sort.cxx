#include <iostream>
#include <chrono> 
// unsigned int count_max; 
// unsigned int count_min; 

class MergeSort {

    private: 
        int size; 
        int* data; 
        int* temp; 

    public: 

        MergeSort(int size) { 
            this->size = size; 
            data = new int[size]; 
            temp = new int[size]; 
        }
        ~MergeSort(){ 
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
           
            int mid, left, right, i;

            // count_max++;
            // count_min++;
 
            mid = (start + end + 1) / 2; //dzielimy na polowe 

            // count_max++;
            // count_min++; 

            // od [start, mid - 1]
            if(mid - start > 1) {  // jezeli mozna podzielic lewa strone jeszcze raz 
                sort(start, mid - 1);
            }

            // count_max++;
            // count_min++;

            if(end - mid > 0) { // od [mid, end]
                sort(mid, end);
            }

            // count_max += 2;
            // count_min += 2;

            left = start; 
            right = mid;

            for(i = start; i <= end; i++) {
                // count_max += 5; 
                // count_min += 4; 
  
                temp[i] = ((left == mid) || ((right <= end) && (data[left] > data[right]))) ? data[right++] : data[left++];
            }

            for(i = start; i <= end; i++) {
                // count_max++; 
                // count_min++; 
                data[i] = temp[i];
            }
            
        }

        void print() { 
            for(int i = 0; i < size; i++) {
                std::cout << data[i] << std::endl;
            }
        } 
}; 

int main(int argc, char* argv[]) {
    int size = atoi(argv[1]); 
    MergeSort ms(size); 
    ms.get_data(); 
    auto start = std::chrono::high_resolution_clock::now();
    ms.sort(0, size - 1); 
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
    // std::cout <<  count_max << std::endl; 
    // std::cout << count_min << std::endl; 
    ms.print(); 
}