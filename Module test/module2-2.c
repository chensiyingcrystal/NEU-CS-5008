#include <stdio.h>
#include <stdlib.h>

void updateArray1(int array[]) {
    array[0] = 10;
    *array = 10;
}

void updateArray2(int* array) {
    *array = 6;
    *(array + 2) = 8;  //pointer arithmetic
    array[0] = 10;

}

int main(){
    int numbers[3] = {1, 2, 3};

    updateArray1(numbers);

    // printf("%p\n", &numbers[0]);
    // printf("%p\n", &numbers[1]);
    // printf("%p\n", &numbers[2]);
    
    printf("%d\n", numbers[0]);
    printf("%d\n", numbers[1]);
    printf("%d\n", numbers[2]);

    printf("---------------\n");
    updateArray2(numbers);

    printf("%p\n", &numbers[0]); //access the value and take its address
    printf("%p\n", &numbers[1]);
    printf("%p\n", &numbers[2]);
    
    printf("%p\n", numbers);  //it contains the address of the first element
    printf("%p\n", numbers + 1);
    printf("%p\n", numbers + 2);

    printf("%p\n", *numbers);  //dereference the address and access the value that stores in this address
    printf("%p\n", *(numbers + 1));//offset -> dereference -> access the value
    printf("%p\n", *(numbers + 2));// offset by 2 times 4 bytes from the starting address; high efficient

    printf("%d\n", numbers[0]); //bracket gives us equivalent notation as above
    printf("%d\n", numbers[1]);
    printf("%d\n", numbers[2]);

    return 0;
}