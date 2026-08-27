#include<iostream>
#include<stack>
using namespace std;

int main(void){
    stack<int>s;
    s.push(10);
    s.push(20);
    cout<<"Top element:"<<s.top()<<endl;
    s.pop();
    cout<<"Top element now:"<<s.top()<<endl;
    return 0;
}