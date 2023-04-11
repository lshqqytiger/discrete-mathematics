#include <stdio.h>
#define length 16
#include "search_algorithms.h"
#include "benchmark.h"

int main(int argc, char** argv){
    if(argc == 1){
        printf("Available algorithms: binary\n");
        return 0;
    }
    const int target = 19;
    int list[length] = { 1, 2, 3, 5, 6, 7, 8, 10, 12, 13, 15, 16, 18, 19, 20, 22 };
    double start, end;
    int(* algorithm)(int* arr, int target) = find_algorithm(argv[1]);
    printf("Searching Algorithm: %s\n", argv[1]);
    start = time();
    int result = algorithm(list, target);
    end = time();
    printf("Result: %d\nValidation: %s\nTime spent: %lfsec\n", result, result < 0 ? "-" : list[result] == target ? "PASS" : "FAIL", end - start);
    return 0;
}