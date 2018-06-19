#include <iostream>
#include <algorithm>
#include <string>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template <typename T> //声明成模板函数
void insertionSort(T arr[], int n)
{
  // 对于插入排序，第0个元素不需要考虑，故i从1开始
  for (int i = 1; i < n; i++)
  {
    // 寻找元素arr[i]合适的插入位置
    T e = arr[i];
    int j;            //j保存元素e应该插入的位置
    for (j = i; j > 0 && arr[j - 1] > e; j--)
    {
      arr[j] = arr[j - 1];            //改进：将交换操作改成赋值操作。一次交换操作，相当于三次赋值。
    }
    arr[j] = e;
  }
}

int main()
{
  int n = 20000;
  // int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);    // 对于近似有序的数组，插入排序的性能要远远优于选择排序
  int *arr2 = SortTestHelper::copyIntArray(arr, n);

  SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
  SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

  delete[] arr;     //将空间释放出来
  delete[] arr2;
  return 0;
}