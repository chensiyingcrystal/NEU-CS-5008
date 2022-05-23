#include <stdio.h>
#include <stdlib.h>

int main(){
    int numbers[3] = {1, 2, 3};

    print("%p\n", &numbers[0]);
    print("%p\n", &numbers[1]);
    print("%p\n", &numbers[2]);
}