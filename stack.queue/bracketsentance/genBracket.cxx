#include <iostream>
#include <vector>
#include <ctime>

char get_random_bracket() { 

    switch (rand() % 4) { 
        case 0: 
            return '('; 
        case 1: 
            return '['; 
        case 2: 
            return ')'; 
        case 3:
            return ']'; 
        default: 
            return -1; 
    }
}

void good_sentence_generator (int s_size) { 

    if (s_size % 2 == 1) {
        s_size ++; 
    }
    std::vector<char>sentence;
    
    for (int i = 0; i < (s_size/2); i ++) { 
    
        switch (get_random_bracket()) { 
            
            case '(':
                switch (rand() % 3) { 

                    case 0: 
                        sentence.push_back('(');
                        sentence.push_back(')'); 
                    
                    default:
                        sentence.insert(sentence.begin(), '('); 
                        sentence.insert(sentence.begin() + 1, ')'); 
                      
                }
                    
            case '[': 
                switch (rand() % 2) {

                    case 0:  
                        sentence.push_back('[');
                        sentence.push_back(']'); 
                    case 1:
                        sentence.insert(sentence.begin(), '['); 
                        sentence.insert(sentence.begin() + 1, ']'); 
                }
                
            case ')': 
                switch (rand() % 3 ) {  

                    case 0:                                         
                        sentence.push_back(')'); 
                        sentence.insert(sentence.begin(), '(');
                    
                    default:
                        sentence.insert(sentence.begin(), ')');
                        sentence.insert(sentence.begin(), '(');
                }
                
            case ']':
                switch (rand() % 2 ) {  
     
                    case 0:                                         
                        sentence.push_back(']'); 
                        sentence.insert(sentence.begin(), '[');
                    
                    case 1: 
                        sentence.insert(sentence.begin(), ']');
                        sentence.insert(sentence.begin(), '[');
                }      
        }

    }
    switch(rand() % 2) {

        case 0: 
            for (int i = 0; i < sentence.size(); i ++) {     
                std::cout << sentence[i] << std::flush; 
            }
            std::cout << std::endl; 
    
        case 1: 
            for (int i = 0; i < sentence.size(); i ++) { 
                
                 std::cout << sentence[rand() % (i+1)]  << std::flush; 
            }
            std::cout << std::endl; 

    }
}


int main() { 

    srand(time(NULL));

    for(int i = 0; i < 8; i ++) {
        good_sentence_generator(4);
    }
    return 0; 
}
