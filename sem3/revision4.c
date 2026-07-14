// #include<stdio.h>
// #include <stdlib.h> //use this always while working w dynamic memory.
// int main(void){
//     int num;
//     printf("Enter a number: ");
//     scanf("%d",&num);
//     int *numbers=malloc(num*sizeof(int));
//     for(int i=0;i<num;i++){
//         numbers[i]=1+i;
//     }
//     for(int i=0;i<num;i++){
//         printf("%d\n",numbers[i]);
//     }
//     free(numbers);  //always free memory after using malloc()
// return 0;
// }

#include<stdio.h>
#include <stdlib.h> //use this always while working w dynamic memory.
int *getPointer(void) {
    int *x = malloc(sizeof(int));   // heap memory for one int
    *x = 42;                          // set its value (dereference to write through the pointer)
    return x;                          // just return x directly — it's ALREADY the address we need
}

int main(void) {
    int *p = getPointer();
    printf("%d\n", *p);               // dereference to read the value
    free(p);                            // clean up when done — main now owns this memory
    return 0;
}


/*
 * ORIGINAL BUGGY VERSION :
 *
 * int *getPointer(void) {
 *     int *x = malloc(sizeof(int));
 *     x[0] = 5;
 *     int *y = &x;        // BUG 1: &x takes the address of the POINTER x itself,
 *                          // giving int** (pointer-to-pointer), not int*.
 *                          // We already HAVE the address we need in x — no need for &.
 *     free(*x);            // BUG 2: *x is the VALUE stored (5), not an address.
 *                          // free() needs the actual address x holds, i.e. free(x), not free(*x).
 *                          // Also: freeing HERE, before returning, destroys the memory
 *                          // before main() ever gets to use it (use-after-free waiting to happen).
 *     return y;             // BUG 3: y is int** but function signature promises int* — type mismatch.
 * }
 */