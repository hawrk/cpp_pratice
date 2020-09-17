#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

void vectorTest() {
    vector<int> vec;
    for(int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    vector<int>::iterator  iter;
    for(iter = vec.begin(); iter != vec.end(); iter++) {
        if(*iter == 3) {
            vec.erase(iter);
        }
    }
    for(iter = vec.begin(); iter != vec.end(); iter++) {
        cout<< *iter << endl;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    vectorTest();
    return 0;
}

int BinarySearch(int arr[], int n , int target) {
    if (n <= 0) {
        return -1;
    }
    int left = 0;
    int right = n;
    int middle = 0;
    while (left <= right) {
        middle = (left + right)/2;
        if (target == arr[middle]) {
            return middle;
        } else if( target < arr[middle]) {
            right = middle -1;
        } else if (target > arr[middle]) {
            left = middle + 1;
        }
    }
    return -1;
}


int BinarySearch2(int arr[], int left, int right, int target) {
    int middle = (left + right)/2;
    if (arr[middle] == target) {
        return target;
    } else if (arr[middle] > target) {
        return BinarySearch2(arr, left, middle -1, target);
    } else if (arr[middle] < target) {
        return BinarySearch2(arr, middle + 1, right, target);
    }
    return -1;
}

void QuickSort(int left, int right, vector<int>& vec) {
    if (left >= right) {
        return;
    }
    int i = left;
    int j = right;
    // 设置基准点
    int base = vec[left];
    while ( i <= j) {
        while (base <= vec[j] && i < j) {
            j--;
        }
        while (base >= vec[i] && i < j) {
            i--;
        }
        // 区间内已搜索完毕, 交换 两个位置
        if (i < j) {
            int temp = vec[i];
            vec[j] = temp;
            vec[i] = vec[j];
        }
    }

    // 基准数和第一个数交换
    vec[left] = vec[i];
    vec[i] = base;

    QuickSort(left, i - 1, vec);  // 递归左边
    QuickSort(i + 1, right, vec);
}