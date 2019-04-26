//
//  main.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/4/26.
//  Copyright © 2019 Giga. All rights reserved.
//

#include <stdio.h>

#include "Array_gp.h"

int main(int argc, const char * argv[]) {
    
    Array *array = arrayCreate();
    arrayInit(array, 10, sizeof(int));

    for (int i = 0; i < 10; i++) {
        
        arrayInsert(array, 1, &i);
    }
    
    for (int i = 0; i < arrayLen(array); i++) {
        
        int *a = arrayIndex(array, i + 1);
        printf("index = %d, value=>%d\n", i, *a);
    }
    
    return 0;
}
