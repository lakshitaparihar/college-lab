#include <stdio.h>
int main() {
    printf("enter your name,please\n");
    char name[50];
    scanf("%s", name);
    int age;
    printf("enter your age, please:\n");
    scanf("%d", &age);
    printf("hi %s your age is %d, isn't it?", name, age);

}