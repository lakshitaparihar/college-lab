#include<stdio.h>

int main(void){

    // int a=10;
    // float b=20;
    // char c='K';
    // printf("a is %d with size of %zu\n",a,sizeof(a));
    // printf("b is %f with size of %zu\n",b,sizeof(b));
    // printf("c is %c with size of %zu\n",c,sizeof(c));

    // int i = -1;
    // unsigned int j = 1;
    // printf("%d\n", i < j);  //Comparing int vs unsigned int → C converts the signed value to unsigned first (never the reverse). -1 reinterpreted as unsigned → becomes max unsigned value (4294967295). Real comparison run: 4294967295 < 1 → false → 0.
                               //Rule: never mix signed/unsigned in comparisons — the signed one silently converts and breaks "obvious" math. Common bug source in loops with size_t/array indices.


     /* BUG: unsigned wraparound in backward loop

    size_t len = 5;
    for (size_t i = len - 1; i >= 0; i--) {
    printf("%zu\n", i);
    }
    */


    /* size_t is unsigned -> can never go below 0.
    * When i == 0 and i-- runs, it can't become -1,
    * so it wraps to the MAX size_t value instead
    * (huge number) -> "i >= 0" is now ALWAYS true -> infinite loop.
    *
    * FIX: loop i from len down to 1, print (i - 1).
    * i never needs to go below 0, so no wraparound happens.
    */

    size_t len = 5;
    for (size_t i = len; i > 0; i--) {
        printf("%zu\n", i - 1);
    }




    return 0;
}