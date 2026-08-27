// A program that reads and print in two integers where the first is a multiple of the second.

#include<iostream>
using namespace std;

void factor(int a, int b){
    if(a%b==0){
        cout<<a<<" is a multiple of "<<b<<endl;
    }
    else{
        cout<<"the first number is not a multiple of the second number."<<endl;
    }
}

int main(void){
    int num1,num2;
    cout<<"enter the first number: ";
    cin>>num1;
    cout<<"enter the second number: ";
    cin>>num2;
    factor(num1,num2);

    return 0;
}