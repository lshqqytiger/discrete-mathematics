#include <stdlib.h>
#include <string.h>
#ifndef length
#define length 0
#endif

#define Bubble "bubble"
#define Insertion "insertion"
#define Heap "heap"
#define Intro "intro"

void print_array(int* arr){
    printf("{ ");
    for(int i = 0; i < length; i++) printf("%d, ", arr[i]);
    printf("\b\b }\n");
}

void swap(void* a, void* b, size_t size){
    void* temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

void bubble_sort(int* arr){
    for(int i = 0; i < length - 1; i++)
        for(int j = 0; j < length - i - 1; j++)
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1], sizeof(int));
                printf("now: ");
                print_array(arr);
            }
}

void insertion_sort(int* arr){
    for(int i = 1; i < length; i++){
        int j = 0;
        while(arr[i] > arr[j]) j++;
        int temp = arr[i];
        for(int k = 0; k < i - j; k++) arr[i - k] = arr[i - k - 1];
        arr[j] = temp;
        printf("now: ");
        print_array(arr);
    }
}

void heap_sort(int* arr){

}

void intro_sort(int* arr){
    
}

void fallback(int* arr){
    printf("Cannot find algorithm.\n");
}

void* find_algorithm(char* n){
    if(!strcmp(n, Bubble)) return &bubble_sort;
    if(!strcmp(n, Insertion)) return &insertion_sort;
    return &fallback;
}