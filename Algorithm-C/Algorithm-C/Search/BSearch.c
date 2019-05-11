//
//  BSearch.c
//  Algorithm-C
//
//  Created by xiao fan on 2019/5/6.
//  Copyright © 2019 Giga. All rights reserved.
//

#include "BSearch.h"

// 二分查找
int binSearch(int arr[], int size, int value) {
    
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            
            return mid;
        }
        else if (arr[mid] < value) {
            
            low = mid + 1;
        }
        else {
            
            high = mid - 1;
        }
    }
    return -1;
}

// 二分查找迭代
int binSearchInternally(int arr[], int low, int high, int value) {
    
    if (low > high) {
        
        return -1;
    }
    
    int mid = low + ((high - low) / 2);
    if (arr[mid] == value) {
        
        return mid;
    }
    else if (arr[mid] < value) {
        
        return binSearchInternally(arr, mid + 1, high, value);
    }
    else {
        
        return binSearchInternally(arr, low, mid - 1, value);
    }
}

int binSearch2(int arr[], int size, int value) {
    
    return binSearchInternally(arr, 0, size - 1, value);
}

// MARK: - 变种的二分查找

// 查找第一个值等于给定值的元素

int binSearchChange1(int arr[], int size, int value) {
    
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        
        int mid = low + ((high - low) / 2);
        if (arr[mid] > value) {
            
            high = mid - 1;
        }
        else if (arr[mid] < value) {
            
            low = mid + 1;
        }
        else {
            
            if ((mid == 0) || arr[mid - 1] != value) {
                
                return mid;
            }
            else {
             
                high = mid - 1;
            }
        }
    }
    return -1;
}

// 查找最后一个值等于给定值的元素

// 查找第一个大于等于给定值的元素

// 查找最后一个小于等于给定值的元素

void bSearchTest(void) {
    
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int value = 3;
    int ret = binSearch2(arr, len, value);
    printf("查询结果：%d\n", ret);
    
    int arr1[] = { 1, 3, 4, 5, 6, 8, 8, 8, 11, 18 };
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int value1 = 8;
    
    
}
