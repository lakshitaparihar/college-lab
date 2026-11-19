#include<stdio.h>
#define SIZE 5
int front=-1;
int rear=-1;
int queue[SIZE];

int isempty(){
    if (front==-1 || front>rear){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(){
    if (rear==SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int element){
    if(isfull()){
        printf("queue overflow!\n");
    }
    else{
        if(front==-1){          // first element ever: front joins too
            front=0;
        }
        rear+=1;                // ALWAYS store (detour above, not a fork)
        queue[rear]=element;
    }
}

void dequeue(){
    if(isempty()){
        printf("queue underflow!\n");
    }
    else{
        printf("dequeued %d\n",queue[front]);
        front+=1;               // front moves FORWARD, toward rear
    }
}

void display(){
    if(isempty()){
        printf("queue is empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main(void){
    // 1. dequeue on an empty queue -> underflow
    display();
    dequeue();

    // 2. fill it completely, then one extra -> overflow
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    if(isfull()) printf("queue is full\n");
    display();
    enqueue(99);

    // 3. FIFO check: 10, 20, 30 must leave in that order
    dequeue();
    dequeue();
    dequeue();
    display();

    // 4. Q6: boxes 0,1,2 are free now... but watch this
    enqueue(60);
    display();

    // 5. empty it fully -> front > rear -> empty again
    dequeue();
    dequeue();
    display();
    dequeue();

    return 0;
}



//MISTAKES MADE:
/*
 * Format:  WRONG  ->  RIGHT  :  WHY
 *
 * ====================================================================
 *  A. QUEUE CONCEPTS
 * ====================================================================
 *
 * 1. front += 1 on EVERY enqueue
 *      RIGHT: change front ONLY for the first element:
 *               if (front == -1) front = 0;
 *      WHY:   front = "who leaves next". Adding people at the BACK
 *             of a line does not change who is at the FRONT.
 *             After enqueue 10,20,30 the old code had front = 2,
 *             so the next dequeue would remove 30, not 10 (broke FIFO).
 *
 * 2. front -= 1 in dequeue  (STACK THINKING)
 *      RIGHT: front += 1
 *      WHY:   Stack's top moves DOWN on pop. A queue's front moves
 *             FORWARD (toward rear) - when the front person is
 *             served, the person behind them becomes the front.
 *             Evidence: 3 dequeues gave "1 silent + 2 underflows",
 *             because front went 0 -> -1 and then looked "empty".
 *
 * 3. isempty only checked the START state:  front==-1 && rear==-1
 *      RIGHT: front == -1  ||  front > rear
 *      WHY:   A queue is empty in TWO situations:
 *               - nothing was ever added      (front == -1)
 *               - everything added was removed (front passed rear)
 *             e.g. enqueue 10,20  dequeue x2  -> front=2, rear=1
 *             Elements live from front to rear. If front > rear,
 *             that range has nothing in it.
 *
 * 4. display looped rear DOWN to 0  (copied from stack)
 *    then fixed direction but started at 0:  i = 0; i <= rear
 *      RIGHT: i = front; i <= rear; i++
 *      WHY:   (a) Queue prints in FIFO order: front -> rear.
 *             (b) Boxes BEFORE front are already dequeued. Their old
 *                 values are still in memory, but NOT in the queue.
 *                 Starting at 0 would print dequeued "ghosts".
 *             Same rule as stack #27: print only the REAL elements.
 *             Stack's real range = top..0, queue's = front..rear.
 *
 * ====================================================================
 *  B. if / else  (CONTROL FLOW)
 * ====================================================================
 *
 * 5. Fixing #1 with a FORK instead of a DETOUR:
 *        if (front == -1) { front += 1; }
 *        else             { store value; rear += 1; }
 *      RIGHT: if (front == -1) front = 0;     <- detour, no else
 *             rear += 1;  queue[rear] = element;   <- ALWAYS runs
 *      WHY:   if/else = fork in the road: you go one way OR the
 *             other, NEVER both. The first element needs BOTH
 *             (fix front AND be stored). Result: 10 was never
 *             stored -> output showed 20 30 40 50, no 10.
 *      RULE:  Use if/else when the cases EXCLUDE each other.
 *             Use a plain if (no else) for an EXTRA step that
 *             sometimes happens on the way.
 *
 * 6. Overflow check lost its else:
 *        if (rear == SIZE-1) printf("overflow");
 *        if (front == -1) ...   <- separate if, still runs!
 *      RIGHT: if (full) { overflow }  else { the whole enqueue }
 *      WHY:   The message printed, then the code kept going and
 *             wrote into queue[5] - OUTSIDE the array.
 *             Same lesson as stack #25: CHECK FIRST, act only if
 *             safe. Overflow and a real enqueue must never both run.
 *
 * ====================================================================
 *  C. COPYING FROM THE STACK PROGRAM
 * ====================================================================
 *
 * 7. Array named stack[], messages said "stack overflow!" etc.
 *      RIGHT: queue[], "queue overflow!", "queue underflow!"
 *      WHY:   An examiner reading stack[] in a queue program cuts
 *             marks. When you copy code, re-read EVERY line.
 *
 * 8. isfull was void and printed; isempty printed AND returned
 *      RIGHT: both return 1/0 only; the CALLER decides to print.
 *      WHY:   Stack note #32 (one function = one job). Now enqueue,
 *             dequeue, display and main can all use if(isfull()) /
 *             if(isempty()) without random messages appearing.
 *
 * 9. main() was empty at first
 *      WHY:   Untested code = unknown code. Always test the edges:
 *             dequeue on empty, enqueue on full, empty-again after
 *             removing everything.
 *
 * ====================================================================
 *  D. READING OUTPUT AS EVIDENCE
 * ====================================================================
 *
 * 10. Ran the program but didn't question the output
 *      The output had 3 clues:
 *        - 10 missing              -> enqueue skipped storing (#5)
 *        - no "queue is full"      -> rear only reached 3, not 4
 *        - 3 dequeues, 2 underflow -> front moved backwards (#2)
 *      RULE:  Before running, PREDICT the output. If it differs,
 *             trace front/rear on paper until you find why.
 *
 * ====================================================================
 *  E. VOCABULARY  (exam traps)
 * ====================================================================
 *
 * 11. Saying "DQ" for a stack pop
 *      RIGHT: stack -> push / pop      queue -> enqueue / dequeue
 *
 * 12. Saying a queue has a "top"
 *      RIGHT: stack has top. Queue has front and rear.
 *
 * 13. dequeue  vs  deque   (NOT the same thing!)
 *        dequeue ("dee-Q") = OPERATION: remove from queue's front
 *        deque   ("deck")  = DATA STRUCTURE: double-ended queue
 *
 * ====================================================================
 *  F. LIMITATION OF THIS (LINEAR) QUEUE   <- read the output of test 4
 * ====================================================================
 *
 *   After 5 enqueues + 3 dequeues, boxes 0,1,2 are FREE, yet
 *   enqueue(60) says "overflow!", because rear == SIZE-1.
 *   rear only moves forward and never comes back -> wasted space.
 *   The code is CORRECT; the DESIGN is the problem.
 *   -> This is exactly why the CIRCULAR QUEUE exists.
 *
 * ====================================================================
 *  STILL TO DO
 * ====================================================================
 *   [done] enqueue: front only for first element, always store
 *   [done] dequeue: front moves forward
 *   [done] isempty: front == -1 || front > rear
 *   [done] display: front -> rear
 *   [done] edge-case tests in main
 *   - NEXT: circular queue (fix the wasted-space problem in F)
 *   - THEN: deque (add/remove at BOTH ends)
 */
