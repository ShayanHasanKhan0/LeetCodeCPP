#include <iostream>
#include <stack>

using namespace std;

void postfixEvaluation(string str) {

    stack<int> st;

    for(int i=0; i<str.length(); i++) {
        if (str[i]>='0' && str[i]<='9') {
            st.push(str[i]);
        } else {
            int var1 = st.top();
            st.pop();
            int var2 = st.top();
            st.pop();

            switch (expression) {
                case '+':
                    st.push(var1+var2)
                    break;
// blahblahblah

        }
        
    }
}
    return st.top();   
}


void main() {

}