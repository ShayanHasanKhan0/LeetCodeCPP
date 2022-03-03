#include <iostream>
using namespace std;

void stringBreak(string str, int size){
    if(size == 1){
        cout << "{" << str << "}";
        return;
    }
    
    cout << "{" << str << "}" << endl;
    cout << "{" << str[0] << "}";
    stringBreak(str.substr), size-1);
}

int main(){
    string str = "ABC";
    stringBreak(str, str.length());
    return 0;
}
