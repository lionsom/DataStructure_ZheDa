//
//  main.c
//  001_PrintN_Test
//
//  Created by linxiang on 2017/9/11.
//  Copyright © 2017年 minxing. All rights reserved.
//

#include <stdio.h>

#include <time.h>


clock_t start, stop;

double duration;


void printN_1 (int N) {
    
    for (int i = 1; i <= N; i++) {
        printf("%d\n",i);
    }
}

void printN_2 (int N) {
    if (N) {
        printN_2(N-1);
        printf("%d\n",N);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    start = clock();
    
//    printN_1(100000);
    printN_2(100000);
    
    stop = clock();

    duration = (double)(stop - start);
    
    printf("%f\n",duration);
    
    return 0;
}
