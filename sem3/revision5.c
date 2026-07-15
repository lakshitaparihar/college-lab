// #include<stdio.h>
// struct point{
//     int x;
//     int y;
// };
// void printpoint(struct point *pt){      // didnt add * earlier!!
//     printf("(%d,%d)",pt->x,pt->y);
// }
// int main(void){
//     struct point pt={4,6};
//     struct point *ptr=&pt;
//     printpoint(ptr);                     // or printpoint(&pt);
// return 0;
// }


#include <stdio.h>
struct number{
    int x;
    int y;
};

void movePoint(struct number *p, int dx, int dy){
    p->x += dx; 
    p->y += dy;
    printf("updated values: (%d,%d)\n",p->x,p->y);
}

int main(void){
    struct number num={8,3};
    struct number *p=&num;
    printf("current values: (%d,%d)\n",num.x,num.y);
    int r=1,s=1;
    movePoint(p,r,s);
return 0;
}