#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(int arr[], int n)
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
  int a[10] = {1, 3, 5, 10, 9, 7, 2, 6, 8, 4};

  selectionSort(a, 10);

  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";

  cout << endl;

  return 0;
}