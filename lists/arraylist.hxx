#ifndef Arraylist_HXX
#define Arraylist_HXX
#include <iostream>

using position_t = int;

class Arraylist {

    private:
        int max_size, length;
        int *arr;

    public: 
        Arraylist(int s): max_size(s), length(0) { 
            arr = new int[s];
            for ( int i = 0; i < s; i++){
                arr[i] = 0; 
            }
        }
        ~Arraylist(){ 
            delete arr; 
        }

        void push_front(int x) { 
            if (length < max_size) {  
                for (int i = length; i > 0; i--) { 
                    arr[i] = arr[i-1];  
                }              
                arr[0] = x; 
                ++ length; 
            }
        }  

        void push_back(int x) {
            if (length < max_size) {
                arr[length++] = x;  
            }
        } 

        int pop_front() { 
            int del = arr[0]; 
            for (int i = 1; i < length; i++) { 
                arr[i-1] = arr[i]; 
            } 
            length --; 
            return del; 
          
        }       

        int pop_back() {       
            if (!empty())    
                return arr[--length]; 
            return -1; 
        }

        position_t find(int x) { 
            for(int i = 0; i < length; i++ ) {
                if((arr[i]) == x) {
                    return i; 
                }
            }
            return -1; 
        }    
                  
        position_t erase(position_t pos) { 
            if (!empty() && pos < length && pos >= 0) {
                for (int i = pos; i < length; i ++) { 
                    arr[i] = arr[i + 1]; 
                }  
                length --;  
                return pos + 1;
            } 
            return -1;
        }       

        position_t insert(position_t pos, int x) {
            if (length < max_size) {
                for (int i = length; i >= pos; i--) { 
                    arr[length] = arr[length - 1]; 
                }

                arr[pos - 1] = x; 
                length ++; 
                return pos - 1;   
            }
            return -1; 
        }  

        int size() {
            return length; 
        }   

        bool empty(){ 
            if (length == 0) { 
                return true; 
            }
            return false; 
        }   
                               
                            
};

#endif