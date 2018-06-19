#include <iostream>
#include <algorithm>
#include <string>
#include "SortTestHelper.h"

using namespace std;

template <typename T> //声明成模板函数
void insertionSort(T arr[], int n)
{
  // 对于插入排序，第0个元素不需要考虑，故i从1开始
  for (int i = 1; i < n; i++)
  {
    // 寻找元素arr[i]合适的插入位置
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
    {
      swap(arr[j], arr[j - 1]);
    }
  }
}

int main()
{
  int n = 20000;
  int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  int *arr2 = SortTestHelper::copyIntArray(arr, n);

  SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
  SortTestHelper::testSort("Selection Sort", insertionSort, arr2, n);

  delete[] arr;   //将空间释放出来
  delete[] arr2; 
  return 0;
}