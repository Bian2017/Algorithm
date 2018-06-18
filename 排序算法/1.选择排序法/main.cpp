#include <iostream>
#include <algorithm>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

template <typename T> //声明成模板函数
void selectionSort(T arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    // 寻找[i, n)区间里的最小值
    int minIndex = i;

    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }

    swap(arr[i], arr[minIndex]);
  }
}

int main()
{
  int n = 100;
  int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  selectionSort(arr, n);
  SortTestHelper::printArray(arr, n);

  delete[] arr;       //将空间释放出来

  // int a[10] = {1, 3, 5, 10, 9, 7, 2, 6, 8, 4};
  // selectionSort(a, 10);

  // float b[5] = {1, 4.2, 3.2, 5.55, 2.111};
  // selectionSort(b, 5);

  // string c[5] = {"D", "C", "F", "A", "P"};
  // selectionSort(c, 5);

  // Student d[5] = {{"D", 90}, {"C", 100}, {"F", 90}, {"A", 95}, {"P", 64}};
  // selectionSort(d, 5);

  // for (int i = 0; i < 10; i++)
  //   cout << a[i] << " ";
  // cout << endl;

  // for (int i = 0; i < 5; i++)
  //   cout << b[i] << " ";
  // cout << endl;

  // for (int i = 0; i < 5; i++)
  //   cout << c[i] << " ";
  // cout << endl;

  // for (int i = 0; i < 5; i++)
  //   cout << d[i] << " ";
  // cout << endl;

  return 0;
}