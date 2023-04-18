#include <math.h>
#include "heap.h"
#ifndef length
#define length 0
#endif

#define Bubble "bubble"
#define Insertion "insertion"
#define Selection "selection"
#define Heap "heap"
#define Quick "quick"
#define Intro "intro"

void bubble_sort(int* arr){
    for(int i = 0; i < length - 1; i++)
        for(int j = 0; j < length - i - 1; j++)
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1], sizeof(int));
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
        print_array(arr);
    }
}

void selection_sort(int* arr){
    for(int i = 0; i < length - 1; i++){
        int min = length - 1;
        for(int j = length - 2; j >= i; j--) if(arr[min] > arr[j]) min = j;
        swap(&arr[i], &arr[min], sizeof(int));
        print_array(arr);
    }
}

void heap_sort(int* arr){
    heap_from(arr);
    for(int i = length - 1; i > 0; i--){
        swap(&arr[0], &arr[i], sizeof(int));
        heapify(arr, 0, i);
        print_array(arr);
    }
}

void quick_sort(int* arr){

}

void intro_sort(int* arr){
    int depth = floor(log2(length));
    if(length < 16) return insertion_sort(arr);
    if(depth == 0) return heap_sort(arr);
    return quick_sort(arr);
}

void* find_algorithm(char* n){
    if(!strcmp(n, Bubble)) return &bubble_sort;
    if(!strcmp(n, Insertion)) return &insertion_sort;
    if(!strcmp(n, Selection)) return &selection_sort;
    if(!strcmp(n, Heap)) return &heap_sort;
    return &fallback;
}