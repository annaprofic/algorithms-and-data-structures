#include <iostream> 
#include <chrono> 

class SelectionSort { 

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

    void sort( int* data, int size) { 
        auto start = std::chrono::high_resolution_clock::now();

        int loc, min, temp;
        for (int i = 0; i < size - 1; i++) {
            min = data[i];
            loc = i;
            for(int j = i + 1; j < size; j++) {
                if(min > data[j])  {
                    min = data[j];
                    loc = j;
                }
            }
            temp = data[i];
            data[i] = data[loc];
            data[loc] = temp;
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
    }

    void print_sorted_data(int* data, int size) { 
        for (int i = 0 ; i < size ; i ++ ){ 
            std::cout << data[i] << std::endl;
        }
    }
};

int main ( int argc, char *argv[]) { 
    SelectionSort sort1;
    int size = atoi(argv[1]); 
    int *data = new int[size];
    
    sort1.get_data(data, size); 
    sort1.sort(data, size);   
    //sort1.print_sorted_data(data, size);   
}