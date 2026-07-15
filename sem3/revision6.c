// #include <stdio.h>
// #include <stdlib.h>

// struct Box{
//     int num;
//     struct Box *address;
// };

// int main(void){
//     // BUG 1: sizeof(Box) is WRONG — without typedef, the type name is "struct Box", not just "Box"
//     // struct Box *b1 = malloc(sizeof(Box));      // <-- missing "struct"

//     struct Box *b1=malloc(sizeof(struct Box));    // FIX: always write "struct" keyword for the type
//     struct Box *b2=malloc(sizeof(struct Box));
//     struct Box *b3=malloc(sizeof(struct Box));
//     struct Box *b4=malloc(sizeof(struct Box));

//     b1->num=9;
//     b1->address=b2;
//     b2->num=8;
//     b2->address=b3;
//     b3->num=7;
//     b3->address=b4;
//     b4->num=6;
//     b4->address=NULL;

//     // BUG 2: checking temp->address (the NEXT node) instead of temp (the CURRENT node)
//     // means the LAST node's value never gets printed, because the loop exits
//     // right before reaching it (last node's ->address IS NULL, by design).
//     //
//     // struct Box *temp = b1;
//     // while (temp->address != NULL) {     // <-- wrong condition
//     //     printf("%d then ", temp->num);
//     //     temp = temp->address;
//     // }

//     struct Box *temp=b1;
//     while(temp!=NULL){
//         printf("%d-> ", temp->num);      // FIX: check temp itself, not temp->address
//         temp=temp->address;
//     }

// return 0;   
// }



#include<stdio.h>
#include<stdlib.h>

struct Corners{
    struct Corners *memo;
};

int countNodes(struct Corners *head){
    struct Corners *temp=head;
    int num=0;
    while(temp!=NULL){
        num+=1;
        temp = temp->memo;        // MISSING: temp = temp->memo;  -> infinite loop, temp never advances
    }
    return num;
}

int main(void){
    struct Corners *c1=malloc(sizeof(struct Corners));
    struct Corners *c2=malloc(sizeof(struct Corners));
    struct Corners *c3=malloc(sizeof(struct Corners));
    struct Corners *c4=malloc(sizeof(struct Corners));
    struct Corners *c5=malloc(sizeof(struct Corners));
    struct Corners *c6=malloc(sizeof(struct Corners));

    //one link was SKIPPED — went straight from c4 to setting c6->memo,
    // never linking c5 at all. c5->memo was left as GARBAGE (malloc does NOT
    // zero memory). Traversal walked off into invalid memory -> CRASH.

    c1->memo=c2;                                 // BUG: overwrote c1->memo repeatedly instead of chaining c2->memo, c3->memo, etc
    c2->memo=c3;
    c3->memo=c4;
    c4->memo=c5;
    c5->memo=c6;
    c6->memo=NULL;
                                              // BUG: no %d in format string
    printf("num is: %d",countNodes(c1));     // BUG: type declaration used when CALLING a function (should just pass c1)
return 0;    
}