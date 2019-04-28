//
//  Sort.c
//  Algorithm-C
//
//  Created by liyoucheng on 2019/4/27.
//  Copyright © 2019年 Giga. All rights reserved.
//

#include "Sort.h"
#include <stdbool.h>
#include <stdlib.h>

void printArray(int* array, int size) {
    
    for (int i = 0; i < size; i++) {
        
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *x, int *y) {
    
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*
 冒泡排序
 
 原理：每次冒泡操作都会对相邻的两个元素进行比较，看是否满足大小关系要求。如果不满足就让它俩互换。一次冒泡会让至少一个元素移动到它应该在的位置，重复n次，就完成了n个数据的排序工作。
 
 原地排序
 稳定
 时间复杂度:
 最好 O(n)
 最坏 O(n^2)
 平均 O(n^2)
 空间复杂度：
 O(1)
 */
void bubbleSort(int *array, int size) {
    
    if (size <= 1) {
        
        return;
    }
    
    for (int i = 0; i < size; i++) {
        
        bool has_swap = false;
        for (int j = 0; j < size - 1 - i; j++) {
            
            if (array[j] > array[j + 1]) {
                
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                has_swap = true;
            }
        }
        
        if (!has_swap) {
            
            break;
        }
    }
}

/*
 插入排序
 
 原理：取未排序区间中的元素，在已排序区间中找到合适的插入位置将其插入，并保证已排序区间数据一直有序。重复这个过程，直到未排序区间中元素为空，算法结束。
 
 原地排序
 稳定
 时间复杂度:
 最好 O(n)
 最坏 O(n^2)
 平均 O(n^2)
 空间复杂度：
 O(1)
 */
void insertSort(int *array, int size) {
    
    if (size <= 1) {
        
        return;
    }
    
    for (int i = 1; i < size; i++) {
        
        int value = array[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            
            if (array[j] > value) {
                
                array[j + 1] = array[j];
            }
            else {
                
                break;
            }
        }
        array[j + 1] = value;
    }
}

/*
 选择排序
 
 原理：每次会从未排序区间中找到最小/最大的元素，将其放到已排序区间的末尾。
 
 原地排序
 稳定
 时间复杂度:
 最好 O(n)
 最坏 O(n^2)
 平均 O(n^2)
 空间复杂度：
 O(1)
 */
void selectArray(int *array, int size) {
    
    for (int i = 0; i < size - 1; i++) {
        
        int index = i;
        for (int j = i + 1; j < size; j++) {
            
            if (array[j] > array[index]) {
                
                index = j;
            }
        }
        
        if (index == i) {
            
            continue;
        }
        
        int temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
}

/*
 归并排序
 
 原理：先把数组从中间分成前后两部分，然后对前后两部分分别排序，再将排序的两部分合并在一起，这样整个数组就都有序了
 
 分治思想，递归实现
 非原地排序算法
 稳定
 时间复杂度:
 最好 O(nlog(n))
 最坏 O(nlog(n))
 平均 O(nlog(n))
 空间复杂度:
 O(n)
 
 // 归并排序算法, A 是数组，n 表示数组大小
 merge_sort(A, n) {
    merge_sort_c(A, 0, n-1)
 }
 
 // 递归调用函数
 merge_sort_c(A, p, r) {
    // 递归终止条件
    if p >= r  then return
 
    // 取 p 到 r 之间的中间位置 q
    q = (p+r) / 2
    // 分治递归
    merge_sort_c(A, p, q)
    merge_sort_c(A, q+1, r)
    // 将 A[p...q] 和 A[q+1...r] 合并为 A[p...r]
    merge(A[p...r], A[p...q], A[q+1...r])
 }
 */
void merge(int *array, int p, int q, int r) {
    
    int *tmp = (int *)malloc(sizeof(int) * (r - p + 1));
    int i = p;
    int j = q + 1;
    int k = 0;
    while (i <= q && j<= r) {
        
        if (array[i] <= array[j]) {
            
            tmp[k++] = array[i++];
        }
        else {
            
            tmp[k++] = array[j++];
        }
    }
    
    // 判断那个子数组中有剩余的数据
    int start = i;
    int end = q;
    if (j <= r) {
        
        // 后部分剩余
        start = j;
        end = r;
    }
    
    // 将剩余部分数据拷贝到临时数组 tmp
    while (start <= end) {
        
        tmp[k++] = array[start++];
    }
    
    // 将tmp中的数组拷贝回 Array[p...r]
    for (int i = 0; i <= (r - p); i++) {
        
        array[p + i] = tmp[i];
    }
}

void mergeSortC(int *array, int p, int r) {
    
    if (p >= r) {
        
        return;
    }
    int q = (p + r) / 2;
    mergeSortC(array, p, q);
    mergeSortC(array, q + 1, r);
    merge(array, p, q, r);
}

void mergeSort(int *array, int size) {
    
    mergeSortC(array, 0, size - 1);
}

/*
 快速排序
 
 原理：要排序数组中下标从p到r之间的一组数据，我们选择p到r之间的任意一个数据作为pivot(分区点)，遍历p到r之间的数据，将小于pivot的放到左边，将大于pivot的放到右边，重复此过程，直到区间为1
 
 分治思想，递归实现
 原地排序算法
 不稳定
 时间复杂度:
 最好 O(nlog(n))
 最坏 O(nlog(n))
 平均 O(nlog(n))
 空间复杂度:
 O(n)
 
 // 快速排序，A 是数组，n 表示数组的大小
 quick_sort(A, n) {
    quick_sort_c(A, 0, n-1)
 }
// 快速排序递归函数，p,r 为下标
 quick_sort_c(A, p, r) {
    if p >= r then return
 
    q = partition(A, p, r) // 获取分区点
    quick_sort_c(A, p, q-1)
    quick_sort_c(A, q+1, r)
 }

 */
int partition(int *array, int p, int r) {
    
    int pivot = array[r];
    int i = p;
    for (int j = p; j <= r - 1; j++) {
        
        if (array[j] < pivot) {
            
            // 交换数据
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
    }
    
    int temp = array[i];
    array[i] = array[r];
    array[r] = temp;
    
    return i;
}

void quickSortC(int *array, int p, int r) {
    
    if (p >= r) {
        
        return;
    }
    // 获取分区点
    int q = partition(array, p, r);
    quickSortC(array, p, q - 1);
    quickSortC(array, q + 1, r);
}

void quickSort(int *array, int size) {
    
    quickSortC(array, 0, size - 1);
}

void testSort() {
    
    int arr[] = { 4, 5, 6, 3, 2, 1 };
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("排序前:");
    printArray(arr, len);
//    bubbleSort(arr, len);
//    insertSort(arr, len);
//    selectArray(arr, len);
//    mergeSort(arr, len);
    quickSort(arr, len);
    printf("排序后:");
    printArray(arr, len);
    
}
