// #include <stdio.h>
// int main(void){
//     for(int i=1;i<=20;i++){         //use semicolons in loops not commas, Commas are used for sseparating multiple declarations, like int a, b, c;
//         if (i%2!=0 )continue;       // always put conditions in ()
//         printf("%d ",i);
//     }
// return 0;
// }

// #include <stdio.h>
// int max(int a,int b){
//     if(a>b){
//         return a;
//     }
//     else{
//         return b;
//     }
// }

// int main(void){
//     // int num;
//     // do{
//     //     printf("enter a number: ");
//     //     scanf("%d", &num);

//     // } while(num<=0);
//     //     printf("you entered %d",num);

//     int result=max(7,5);
//     printf("%d",result);
    
// return 0;

// }



#include <stdio.h>
void printSquares(int n){
    for(int i=1;i<=n;i++){
        printf("%d\n",i*i);
    }
}
int main(void){
    printSquares(5);
    return 0;
}