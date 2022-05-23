#include <stdio.h>
#include <stdlib.h>  //in order to use malloc

typedef struct student {
    int id;
    int age;
}student_t;

void printStudent(student_t* aStudent) {
    printf("Student ID: %d, Age %d\n", aStudent->id, aStudent->age);
}

student_t* makeStudent(int age, int id) {
    //undefined behavior: cannot return address of a local variable on the stack
    //malloc create specific bytes on the heap and return a general address(we need to cast it into the type of address we need)
    //advantage: the student is no longer created on the stack, but instead on the heap
    //the heap will not be automatically deleted; it will exists until we free that memory
    //we have to do that otherwise it will leak memory and cause bad security problems
    student_t* p_aStudent = (student_t*)malloc(sizeof(student_t));

    p_aStudent->age = age;
    p_aStudent->id = id;
    return p_aStudent;
}


int main(){


    student_t* s1 = makeStudent(23, 1001);
    student_t* s2 = makeStudent(24, 1002);
    
    printStudent(s1);
    printStudent(s2);
    
    free(s1);
    free(s2);

}