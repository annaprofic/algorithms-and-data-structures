#include <iostream>
#include <chrono> 

class CountingSort {
    
    public:  
    void get_data(int* data, int size) { 
        int el = 0; 
        std::string arg; 
        for (int i = 0; i < size; i++ ){
            std::cin >> arg; 
            el = stoi(arg); 
            data[i] = el; 
        }
    }

    void sort(int* data, int size) {
        int min = 0, max = data[0]; 
        for (int i = 0; i < size - 1; i++){ 
            if (data[i] > data[i + 1] && data[i] >= max) max = data[i]; 
            if (data[i] < data[i + 1] && data[i] <= min) min = data[i]; 
        }

        int range = max - min + 1; 
        int* output = new int[size];
        
        int* count = new int[range]; 
        for (int i = 0; i < range; i++) { //wypelniamy zerami
            count[i] = 0; 
            output[i] = 0; 
        }
    
        for (int i = 0; i < size; i++) ++count[data[i]]; // wypelniamy jedynkami jesli element sie pojawia

        for(int i = 1; i < range; i++) count[i]+=count[i-1]; // sumujemy elementy 

        for(int i = size - 1; i >= 0; i--){
            output[count[data[i]] - 1] = data[i];
            --count[data[i]];
        }

        for (int i = 0; i < size; i++) data[i] = output[i];
    }

    void print_sorted_data(int* data, int size) { 
        for (int i = 0 ; i < size ; i ++ ){ 
            std::cout << data[i] << std::endl;
        }
    }

};

int main(int argc, char *argv[]) {
    CountingSort sort1;
    int size = atoi(argv[1]); 
    int* data = new int[size];
    sort1.get_data(data, size); 
    auto start = std::chrono::high_resolution_clock::now();
    sort1.sort(data, size);   
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
    //sort1.print_sorted_data(data, size);   

}