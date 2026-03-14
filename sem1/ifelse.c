#include <stdio.h>
int main(){
    int n;
    printf("enter a no:");
    scanf("%d", &n);
    if(n > 10 || n % 2 == 0){
        printf("entered number is either greater than 10 or divisible by 2");
    }
    else{
        printf("this doesn't satisfy the condition");
    }

}