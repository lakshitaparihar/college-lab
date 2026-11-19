#include<stdio.h>
# define SIZE 10
int top=-1;
int stack[SIZE];

void push(int element){
    if(top==SIZE-1){
        printf("stack overflow!\n");
    }
    else{
        stack[top+1]=element;
        top+=1;
    }
}

void pop(){
    if(top==-1){
        printf("stack underflow!\n");
    }
    else{
        top-=1;              
    }
}

int isempty(){
    if (top==-1){
        printf("stack is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}

void isfull(){
    if (top==SIZE-1){
        printf("stack is full\n");
    }
}

void display(){
    if(!isempty()){
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
int main(void){
    pop();
    isempty();
    push(10);
    printf("%d\n",stack[top]);
    push(20);
    printf("%d\n",stack[top]);
    push(30);
    printf("%d\n",stack[top]);
    pop();
    printf("%d\n",stack[top]);
    pop();
    printf("%d\n",stack[top]);
    isfull();
    display();
    push(52);
    push(53);
    push(54);
    push(5);
    push(55);
    push(5);
    push(5955);
    push(5);
    push(555555);
    display();
    push(50);
    return 0;
}



//MISTAKES MADE:
/*
 * Format:  WRONG  ->  RIGHT  :  WHY
 *
 * ====================================================================
 *  A. STACK CONCEPTS
 * ====================================================================
 *
 * 1. No 'top' variable at all
 *      RIGHT: int top = -1;
 *      WHY:   A C array is never "empty" - every box always holds some
 *             value (often garbage). The array alone cannot tell how
 *             many elements are real. 'top' stores the index of the
 *             top element, so every operation is O(1):
 *               push    -> goes to top + 1
 *               pop     -> top - 1
 *               empty   -> top == -1
 *               full    -> top == SIZE - 1
 *             Number of elements = top + 1.
 *             -1 = "just before box 0" -> no elements.
 *
 * 2. Checking empty with NULL:  stack[0] == NULL
 *      RIGHT: top == -1
 *      WHY:   NULL is for POINTERS, not ints. An int box can't be
 *             "nothing". Use top, not the array values.
 *
 * 3. Clearing the value on pop:  stack[top] = 0;
 *      RIGHT: just  top -= 1;
 *      WHY:   After pop, that box is above top, so it is outside the
 *             stack. Nobody reads it; the next push overwrites it.
 *             (Harmless, but pointless - examiner may ask why.)
 *
 * 4. Invalid pop line:  stack[top==0;]
 *      RIGHT: delete it; pop = move top down.
 *
 * ====================================================================
 *  B. PYTHON HABITS THAT DON'T WORK IN C
 * ====================================================================
 *
 * 5. Negative index:  stack[-1]  to mean "last element"
 *      WHY:   In C, stack[-1] reads memory OUTSIDE the array -> bug.
 *             C has no "last element" shortcut. That's what top is for.
 *
 * 6. 'and' keyword:  if a == b and c == d
 *      RIGHT: if (a == b && c == d)
 *      WHY:   C uses && (and), || (or), ! (not).
 *
 * 7. if without brackets:  if top == -1 { ... }
 *      RIGHT: if (top == -1) { ... }
 *
 * 8. Then swapped them:  if top == -1 ( ... )
 *      RIGHT: if ( condition ) { body }
 *      WHY:   ( ) goes around the CONDITION (the question)
 *             { } goes around the BODY (what to do)
 *             You need BOTH, each in its own place.
 *
 * ====================================================================
 *  C. ARRAYS & SCOPE
 * ====================================================================
 *
 * 9. Array declared inside a function:
 *        void createstack(int size){ int stack[size-1]; }
 *      RIGHT: declare stack and top GLOBALLY (outside all functions)
 *      WHY:   Local variables exist only inside their function. They
 *             disappear when it returns, and push/pop/isempty can't
 *             see them -> "undeclared" error.
 *
 * 10. Wrong array size:  int stack[size-1];
 *      RIGHT: int stack[SIZE];
 *      WHY:   int a[n] makes n boxes, indexes 0 .. n-1.
 *             The -1 applies to the LAST INDEX, not the declaration.
 *
 * 11. Global array with a size typed by the user at runtime
 *      WHY:   A global array's size must be known BEFORE the program
 *             runs (compile time). Use #define for it.
 *
 * ====================================================================
 *  D. #define
 * ====================================================================
 *
 * 12. # define size=10
 *      RIGHT: #define SIZE 10
 *      WHY:   #define is pure find-and-replace. The first word is the
 *             name, EVERYTHING after it is pasted in exactly.
 *               #define SIZE=10  -> int stack[=10];  error
 *               #define SIZE 10; -> int stack[10;];  error
 *             No '=' and no ';'.
 *
 * 13. #define name same as a variable:  #define size 10  +  int size;
 *      WHY:   Replacement happens everywhere -> "int 10;"  error.
 *      RULE:  #define names in CAPITALS (SIZE, MAX), variables in
 *             lowercase (size, top). They never clash.
 *
 * 14. Mixed Option A and Option B
 *      WHY:   Fixed size in code (#define) AND asking the user.
 *             Pick one: A = programmer fixes size, B = user enters it.
 *
 * ====================================================================
 *  E. printf / scanf
 * ====================================================================
 *
 * 15. scanf("%d", size);
 *      RIGHT: scanf("%d", &size);
 *      WHY:   scanf must STORE into the variable, so it needs its
 *             ADDRESS (&). Without & -> crash (segmentation fault).
 *
 * 16. printf("%d", &stack[top]);
 *      RIGHT: printf("%d", stack[top]);
 *      WHY:   printf needs the VALUE, not the address.
 *               scanf  -> address  (&x)   "where to store"
 *               printf -> value    (x)    "what to show"
 *             gcc warning: expects 'int', got 'int *' (= an address)
 *
 * 17. printf(stack);   /   printf("%d", &stack);
 *      WHY:   printf needs a format string, and %d prints ONE int.
 *             You can't print a whole array at once -> use a loop.
 *
 * 18. print(...)
 *      RIGHT: printf(...)
 *
 * 19. No \n in printf
 *      WHY:   Output gets stuck together: "stack is empty1020302010"
 *      RIGHT: printf("%d\n", x);
 *
 * ====================================================================
 *  F. GENERAL C SYNTAX
 * ====================================================================
 *
 * 20. Parameter without type:  void push(element)
 *      RIGHT: void push(int element)
 *      WHY:   Every parameter needs a type in C.
 *
 * 21. == instead of =:  stack[top+1] == element;
 *      RIGHT: stack[top+1] = element;
 *      WHY:   =  STORES a value   (assignment)
 *             == COMPARES values  (gives true/false, changes nothing)
 *             gcc warning: "statement with no effect" = you probably
 *             used == where you meant =.
 *
 * 22. size vs SIZE
 *      WHY:   C is CASE-SENSITIVE. size and SIZE are different names.
 *
 * 23. Missing semicolons:  printf("...")   pop()
 *      RIGHT: every statement ends with ;
 *
 * ====================================================================
 *  G. WORKFLOW
 * ====================================================================
 *
 * 24. Compiling without saving (tab showed ●)
 *      WHY:   gcc compiles the SAVED file, not what's on screen.
 *      RULE:  Ctrl+S  ->  gcc stacks.c -o output && ./output
 *             Read errors by line number:  stacks.c:17:8 -> line 17
 *
 * ====================================================================
 *  H. OVERFLOW / UNDERFLOW
 * ====================================================================
 *
 * 25. pop acted FIRST, checked AFTER:
 *        stack[top] = 0;  top -= 1;  if (top < -1) printf("underflow");
 *      RIGHT: if (top == -1) { underflow message }
 *             else          { top -= 1; }
 *      WHY:   On an empty stack (top = -1) it wrote to stack[-1] and
 *             made top = -2 BEFORE the check. The message printed but
 *             the damage was already done.
 *      RULE:  Like a ticket checker: CHECK FIRST, act only if safe.
 *             Same pattern as push:  full?  -> overflow,  else push
 *                                    empty? -> underflow, else pop
 *
 * 26. Underflow condition  top < -1
 *      RIGHT: top == -1  (checked BEFORE changing top)
 *      WHY:   top < -1 can only be true after top already went wrong.
 *
 * ====================================================================
 *  I. display() AND for LOOPS
 * ====================================================================
 *
 * 27. Loop from SIZE down to -1:  for (i = SIZE; i >= -1; i--)
 *      RIGHT: start at top, stop after index 0
 *      WHY:   stack[SIZE] and stack[-1] are OUTSIDE the array
 *             (valid indexes: 0 .. SIZE-1). Boxes above top are not
 *             in the stack - just garbage/leftovers.
 *             Printed 12 values when the stack had only 1 element:
 *             "0000000000100"
 *      RULE:  Real elements = index top DOWN TO 0.
 *
 * 28. Loop condition  i = SIZE-1   (assignment!)
 *      WHY:   = stores 9 into i every time. 9 is non-zero = TRUE,
 *             so the loop NEVER ends -> infinite loop printing 0s.
 *             gcc warned: "suggest parentheses around assignment used
 *             as truth value" -> means you used = where you meant ==.
 *             (Same = vs == mistake as #21.)
 *
 * 29. Thinking the middle part of for = "stop when"
 *      WHY:   for (start; CONDITION; step)  runs WHILE the condition
 *             is TRUE. It is "keep going while...", not "stop when...".
 *             Even  i == SIZE-1  would be wrong: when top = 0,
 *             0 == 9 is false -> the loop runs zero times.
 *
 * ====================================================================
 *  J. FUNCTIONS: RETURN VALUES
 * ====================================================================
 *
 * 30. Function name without ():  if (!isempty)
 *      RIGHT: if (!isempty())
 *      WHY:   isempty   = the function's ADDRESS in memory (not a call)
 *             isempty() = actually RUNS the function
 *             An address is never 0 -> always TRUE -> !TRUE = FALSE,
 *             so display's loop NEVER ran. Output: nothing.
 *             gcc warned: "the address of 'isempty' will always
 *             evaluate as 'true'"
 *
 * 31. Using a void function inside if:
 *        void isempty() { printf("stack is empty"); }
 *        if (isempty()) ...    -> error
 *      RIGHT: int isempty() { if (top == -1) return 1; return 0; }
 *      WHY:   void = gives NOTHING back. if() needs a yes/no answer.
 *               printing  -> shows text on screen, if() gets nothing
 *               returning -> hands back 1 or 0,   if() can use it
 *             C convention: 1 = true/yes, 0 = false/no.
 *
 * 32. (style) A function doing TWO jobs: isempty prints AND returns
 *      BETTER: isempty only returns 1/0; the CALLER decides to print:
 *                if (isempty()) printf("stack is empty\n");
 *      WHY:   One function = one job. Easier to reuse (push/pop/display
 *             can all call it without unwanted messages printing).
 *
 * ====================================================================
 *  STILL TO DO
 * ====================================================================
 *   [done] push: check full first  -> overflow
 *   [done] pop:  check empty first -> underflow
 *   [done] edge case tests in main (pop on empty, 11th push)
 *   [done] display(): top down to 0, empty check, \n between values
 *   [done] \n on "stack overflow!"
 *   - (optional) isfull() -> return 1/0 like isempty
 *   - (optional) use if (isfull()) in push, if (isempty()) in pop
 *   - (optional) replace single printfs in main with display()
 *   - NEXT: Option B - user enters the size
 */