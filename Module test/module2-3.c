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

//construct a vector on the heap
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

int resize(vector_t* vector) {
    if (vector == NULL) return 0;

    vector->capacity *= 2;
    //malloc a new array that doubles the size
    int* newData = (int*)malloc(sizeof(int) * vector->capacity);
    //copy all elements in the original vector into the new array
    if (newData == NULL || vector->data == NULL) return 0;
    
    for (int i = 0; i < vector->size; i++) {
        newData[i] = (vector->data)[i];
    }
    //free the original vector memory
    free(vector->data);
    //bound this new array to the vector
    vector->data = newData;
    return 1;
}


int push_back(vector_t* vector, int element) {
    if (vector == NULL) return 0;

    if (vector->size == vector->capacity) { //when the vector is full, we have to double it
        int resizeSuccess = resize(vector);
        if (resizeSuccess == 0) return 0;
    }

    (vector->data)[vector->size] = element;
    (vector->size)++;
    return 1;
}

int insert(vector_t* vector, int pos, int element) {
    if (vector == NULL || pos < 0) {
        return 0;
    }

    if (pos == vector->size) {
        push_back(vector, element);
        return 1;
    }

    if (vector->size == vector->capacity) {
        int currSize = resize(vector);
        if (currSize == 0) return 0;
    }
    
    if (vector->data == NULL) return 0;

    for (int i = vector->size; i > pos; i--) {
        (vector->data)[i] = (vector->data)[i - 1];
    }

    (vector->data)[pos] = element;
    vector->size++;
    return 1;
}

int push_front(vector_t* vector, int element) {
    return insert(vector, 0, element);
}


int main() {
    vector_t* vector = makeVector(2);
    freeVector(vector);
    return 0;

}
