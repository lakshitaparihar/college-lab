// Program in c++ to understand the working of class and objects.

#include<iostream>
using namespace std;

class rectangle{
    int length,breadth;
    public:
    void getdata(int len, int bred){
        length=len;
        breadth=bred;
        cout<<"length:"<<length<<endl;
        cout<<"breadth:"<<breadth<<endl;
    }
    void area();
};

void rectangle::area(){
    cout<<"area:"<<length*breadth<<endl;
}

int main(void){
    rectangle rec1, rec2;
    rec1.getdata(8,4);
    rec1.area();

return 0;
}