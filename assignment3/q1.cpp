#include <iostream>
using namespace std;

#define SIZE 5
int st[SIZE], top=-1;

bool isFull(){ return top==SIZE-1; }
bool isEmpty(){ return top==-1; }

void push(int x){ if(!isFull()) st[++top]=x; }
void pop(){ if(!isEmpty()) top--; }
int peek(){ return isEmpty()? -1: st[top]; }
void display(){ for(int i=top;i>=0;i--) cout<<st[i]<<" "; cout<<endl; }

int main(){
    int ch,v;
    do{
        cin>>ch;
        if(ch==1){cin>>v; push(v);}
        else if(ch==2) pop();
        else if(ch==3) cout<<(isEmpty()?1:0)<<endl;
        else if(ch==4) cout<<(isFull()?1:0)<<endl;
        else if(ch==5) display();
        else if(ch==6) cout<<peek()<<endl;
    }while(ch!=0);
}
