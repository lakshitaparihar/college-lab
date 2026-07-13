// #include <stdio.h>
// int main(void){
//     // int grid[3][4];   // 3 rows, 4 columns — think of it as a table
//     int grid[3][4] = {0};   // initializes EVERY element to 0

//     grid[0][0] = 1;
//     grid[1][2] = 99;

// // Common pattern: nested loops to visit every cell
//     for (int row = 0; row < 3; row++) {
//         for (int col = 0; col < 4; col++) {
//             printf("%d ", grid[row][col]);
//         }
//         printf("\n");
//     }
// }


// #include <stdio.h>
// int sumArray(int arr[], int size){
//     int sum=0;
//     for(int i=0;i<size;i++){
//         sum+=arr[i];     //recived wrong output earlier since used 'i' instead of 'arr[i]'
//     }
//     return sum;
// }

// int main(void){
//     int num[7]={1,2,3,4,5,6,7};
//     printf("%d", sumArray(num,7));
// return 0;
// }

// #include<stdio.h>
// int findMax(int arr[], int size){
//     int max=arr[0];
//     for(int i=0;i<size;i++){
//         if(arr[i]>=max){
//             max=arr[i];
//         }
//     }
//     return max;   //returned arr[0] earlier since tthis statement was inside the loop
// }
// int main(void){
//     int num[4]={6,14,56,9};
//     printf("%d",findMax(num,4));
// return 0;
// }

#include<stdio.h>
void swap(int *a, int *b){

}
int main(void){

return 0;
}