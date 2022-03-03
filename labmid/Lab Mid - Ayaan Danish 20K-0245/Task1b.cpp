#include <iostream>
using namespace std;

int main(){
    cout << "Enter a number to find the sum combinations for: ";
    int num;
    cin >> num;
    bool jDone = false;
    bool kDone = false;
    for(int i=1; i<=num; i++){
        if(i== num)
            cout << i;
        for(int j=1; j<=num; j++){
            if((i+j) == num && jDone == false){   
                cout << i << " " << j << endl;
                jDone = true;
            }
            for(int k=1; k<=num; k++){
                if((i+j+k) == num && kDone == false){
                    cout << i << " " << j << " " << k << endl;
                    kDone = true;
                }
            }
        }
    }

    return 0;
}