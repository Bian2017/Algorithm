
#ifndef SELECTONSORT_SORTTESTHELPER_H
#define SELECTONSORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {
  // 生成有n个元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
  int *generateRandomArray(int n, int rangeL, int rangeR) {
    assert(rangeL <= rangeR);
    int *arr = new int[n];

    srand(time(NULL)); //设置随机种子，将当前的时间作为种子

    for (int i = 0; i < n; i++)
    {
      arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }

    return arr;
  }

  template <typename T>
  void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;

    return;
  }

  template <typename T>
  bool isSorted(T arr[], int n) { // 测试排序算法是否成功

    for (int i = 0; i < n - 1; i++)
      if (arr[i] > arr[i + 1])
        return false;

    return true;
  }

  template <typename T>
  void testSort(string sortName, void (*sort)(T[], int), T arr[], int n) { //传递函数指针
    clock_t startTime = clock();
    sort(arr, n);
    clock_t endTime = clock();

    assert(isSorted(arr, n));
    
    // 时间差值为时钟周期，所以需要除以(1s中有多少个时钟周期)
    cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    return;
  }
} // namespace SortTestHelper
#endif