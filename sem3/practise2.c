#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n;
    int target=0;
    int result[2] = {-1, -1};  //If no two numbers add up to the target, result[0] and result[1] contain garbage values, initialize them first.
    
    printf("enter the number of elements in the list: ");
    scanf("%d",&n);
    int *num=malloc(n*sizeof(int));

    printf("enter the target sum: ");
    scanf("%d",&target);

    for(int i=0;i<n;i++){
        int element;
        printf("enter element on index %d: ",i);
        scanf("%d",&element);
        num[i]=element;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[i]+num[j]==target){
                result[0]=i;
                result[1]=j;
                break;
            }
        }
    }

    // for(int i=0;i<2;i++){
    //     printf("%d,",result[i]);
    // }
    printf("[%d, %d]\n", result[0], result[1]);

    free(num);
return 0;
}

/* BUG 1: malloc BEFORE reading n
 *   int num = malloc(n * sizeof(int));  // n was garbage here!
 *   scanf("%d", &n);                    // ...read too late
 *   -> malloc used an uninitialized n = unknown allocation size.
 *   -> UNDEFINED BEHAVIOR.
 *   FIX: scanf n FIRST, then malloc.
 *   LESSON: never use a variable before it has a value.
 *
 * BUG 2: wrong type — int instead of pointer
 *   int num = malloc(...);   // malloc returns an ADDRESS
 *   FIX: int *num = malloc(...);
 *   LESSON: malloc gives memory's address; only a pointer can hold it.
 *
 * BUG 3: compared INDICES instead of ELEMENTS  (worst bug —
 *   compiles fine, runs fine, silently gives WRONG ANSWERS)
 *   if (i + j == target)
 *   FIX: if (num[i] + num[j] == target)
 *   LESSON: i is a position; num[i] is the value AT that position.
 *
 * BUG 4: scanf missing & (address-of)
 *   scanf("%d", element);
 *   FIX: scanf("%d", &element);
 *   LESSON: scanf needs WHERE to write, i.e. the address.
 *
 * BUG 5: wrong array-literal syntax + scope death
 *   int result[2] = [i, j];   // [] is not C; C uses {}
 *   Also declared INSIDE the if-block -> variable dies when
 *   the block ends -> unusable in the print loop below.
 *   FIX: declare result[2] at top of main; assign slots inside loop.
 *   LESSON: a variable only lives inside the { } it was born in.
 *
 * BUG 6: typo in loop header
 *   for (int i = 0; i < n < i++)   // second ; typed as 
 *   FIX: for (int i = 0; i < n; i++)
 *
 * ---------- VERSION 2 (first fix round) ----------
 *   Fixed: bugs 1, 2, 3, 4, 5, 6  ✓
 *
 * BUG 7: OUT-OF-BOUNDS print loop (survived into v3 too!)
 *   for (int i = 0; i < n; i++) printf("%d,", result[i]);
 *   result has exactly 2 slots, but loop reads n of them.
 *   If n > 2 -> reads memory that isn't ours -> garbage/crash.
 *   FIX: loop i < 2, or simply:
 *        printf("[%d, %d]\n", result[0], result[1]);
 *   LESSON: a loop's bound must match THAT array's size —
 *   different arrays in one program have different sizes.
 *
 * BUG 8 (efficiency, not correctness): no break after finding pair
 *   Kept scanning all remaining pairs after the answer was found.
 *   FIX: break (see bug 9 for the catch).
 *
 * BUG 9 (efficiency): break only exits the INNER loop
 *   The added break killed the j-loop, but the i-loop kept
 *   launching new inner loops anyway.
 *   FIX: int found = 0;
 *        for (int i = 0; i < n && !found; i++) { ... found = 1; break; }
 *   LESSON: C's break escapes exactly ONE loop level.
 *
 * BUG 10 (hygiene): malloc with no free
 *   FIX: free(num); before return.
 *   LESSON: every malloc needs a matching free.
 */