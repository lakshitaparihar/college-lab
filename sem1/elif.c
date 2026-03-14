#include <stdio.h>
int main(){
    int n;
    printf("enter a number:");
    scanf("%d", &n);
    if(n < 10){
        printf("entered number is less than 10\n");
    }
    else if(n < 20 && n > 10){
        printf("entered number is greater than 10 but less than 20\n");
    }
    else{
        printf("entered number is greater than 20");
    }

    
}