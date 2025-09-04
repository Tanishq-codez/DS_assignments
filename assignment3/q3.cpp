#include <iostream>
#include <stack>
using namespace std;

bool bal(string x){
    stack<char> st;
    for(char c:x){
        if(c=='('||c=='{'||c=='[') st.push(c);
        else if(c==')'||c=='}'||c==']'){
            if(st.empty()) return 0;
            char t=st.top(); st.pop();
            if((c==')'&&t!='(')||(c=='}'&&t!='{')||(c==']'&&t!='[')) return 0;
        }
    }
    return st.empty();
}

int main(){
    string s; cin>>s;
    cout<<(bal(s)?1:0);
}
