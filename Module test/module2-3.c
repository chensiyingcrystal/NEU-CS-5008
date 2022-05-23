/**
 * Vector: dynamically resized array
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    int* data;
    int size;
    int capacity;
}vector_t;

vector_t* makeVector(int initCapacity) {
    vector_t* vector = (vector_t*)malloc(sizeof(vector_t)); 
    if (vector == NULL) {//malloc might not always successfully allocate the memory since sometimes it might run out of memory
        return NULL;
    } 
    //Allocate memory for our data array
    vector->data = (int*)malloc(sizeof(int) * initCapacity);
    vector->size = 0;
    vector->capacity = initCapacity;
    return vector;
}

//delete memory on the heap
void freeVector(vector_t* vector) {
    if (vector == NULL) {
        return;
    }
    //first delete the data array, then we can delete the struct
    if (vector->data != NULL) { //if we tried to free a null pointer, the program might run into crash
        free(vector->data);
    }

    free(vector);
    
}

int main() {

}
