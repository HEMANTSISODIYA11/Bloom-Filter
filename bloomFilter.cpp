#include<bits/stdc++.h>
using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

long long generateHash(string key) {
    return static_cast<long long>(std::hash<std::string>{}(key));
}

void insertInFilter(
    string key, 
    vector<int> &bitArray1, 
    vector<int> &bitArray2,
    vector<int> &bitArray3
) {
    
    long long hashValue = generateHash(key);
    bitArray1[(hashValue%(bitArray1.size()))] = 1;
    bitArray2[(hashValue%(bitArray2.size()))] = 1;
    bitArray3[(hashValue%(bitArray3.size()))] = 1;
    return;
}

bool valueIsPresentInFilter(
    string key, 
    vector<int> &bitArray1, 
    vector<int> &bitArray2,
    vector<int> &bitArray3
) {
    
    long long hashValue = generateHash(key);
    
    if(bitArray1[(hashValue%(bitArray1.size()))] == 0) {
        return false;
    }
    
    if(bitArray2[(hashValue%(bitArray2.size()))] == 0) {
        return false;
    }
    
    if(bitArray3[(hashValue%(bitArray3.size()))] == 0) {
        return false;
    }
    
    return true;
}

int main()
{
    int n = 31;
    int m = 53;
    int p = 97;
    string userInput;
    
    vector<int> bitArray1 = vector<int>(n,0);
    vector<int> bitArray2 = vector<int>(m,0);
    vector<int> bitArray3 = vector<int>(p,0);
    
    while (true) {
        std::cout << "\nEnter your command or message: ";
        std::getline(std::cin, userInput);

        std::string lowerCaseInput = userInput;
        
        vector<string> parts = split(lowerCaseInput, ',');
        
        if(parts[0] == "get") {
            cout<<"found in filter :"<<valueIsPresentInFilter(parts[1], bitArray1, bitArray2, bitArray3)<<endl;
            continue;
        }
        
        if(parts[0] == "add") {
            insertInFilter(parts[1], bitArray1, bitArray2, bitArray3);
            continue;   
        }
        
        if(parts[0] == "exit") {
            break;
        }
        
    }
    
    return 0;
}
