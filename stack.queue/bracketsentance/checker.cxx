#include <iostream>
#include <ctime>
#include <vector>

bool check_line(std::string line) {

    std::vector<char>brackets; 
    int line_length = line.size(); 
    

    for (int i = 0; i < line_length; i ++) { 

        switch(line[i]) { 
            case '(': 
                brackets.push_back('('); 
                break;
            case '[': 
                brackets.push_back('[');
                break; 
            case ')': 
                if (!brackets.empty() && brackets.back() == '(') { 
                        brackets.pop_back(); 
                } else 
                    return false; 
                break; 
            case ']': 
                if (!brackets.empty() && brackets.back() == '[') { 
                        brackets.pop_back(); 
                } else 
                    return false; 
                break; 

        }
    }

    if (brackets.empty()) { 
        return true;
    } 
    else
    return false; 

}


int main() { 

    std::string bracket_sentence; 

    while (std::cin >> bracket_sentence) { 

        std::cout << bracket_sentence << " ->     " << std::flush;

        if (check_line(bracket_sentence)) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect." << std::endl;
        }
            
    }
}

