#include <stdlib.h>
#include <string.h>
#ifndef length
#define length 0
#endif

void swap(void* a, void* b, size_t size){
    void* temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void print_array(int* arr){
    printf("{ ");
    for(int i = 0; i < length; i++) printf("%d, ", arr[i]);
    printf("\b\b }\n");
}

void fallback(int* arr){
    printf("Could not find algorithm.\n");
}