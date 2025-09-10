#include <iostream>
#include <algorithm>
using namespace std;

void count_sort(int a[], int n, int pos);

void radixSort(int a[], int n){
    int k = *max_element(a, a + n);

    for(int pos = 1; (k / pos) > 0; pos *= 10)
        count_sort(a, n, pos);
}

void count_sort(int a[], int n, int pos){
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(a[i] / pos) % 10]++;

    for(int i = 1; i < 10; i++) count[i] += count[i - 1];

    int ans[n];
    for(int i = n - 1; i >= 0; i--)
        ans[--count[(a[i] / pos) % 10]] = a[i];

    for(int i = 0; i < n; i++) a[i] = ans[i];
}

int main()
{
    int a[] = {34342, 93748, 298384, 3487, 586947, 37464, 34, 873864};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Array before Radix Sort : ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    radixSort(a, n);

    cout << "Array after sorting : ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}