#include <iostream>
using namespace std;

void merge(int a[] , int l , int mid , int h);
void print(int a[] , int n){
    for(int i = 0 ; i < n ; i++) cout << a[i] << "  " ;
    cout << endl;
}

void merge_sort(int a[] , int l , int h){
    if(l < h){
        int mid = l + (h - l) / 2;
        merge_sort(a , l , mid);
        merge_sort(a , mid + 1 , h);
        merge(a , l , mid , h);
    }
}

void merge(int a[] , int l , int m , int h){
    int i , j , k;
    int n1 = m - l + 1;
    int n2 = h - m;

    int left[n1] , right[n2];

    for(i = 0 ; i < n1 ; i++) left[i] = a[l + i];
    for(j = 0 ; j < n2 ; j++) right[j] = a[m + j + 1];

    i = 0 , j = 0 , k = l;

    while(i < n1 && j < n2){
        if(left[i] <= right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];
    }

    while(i < n1) a[k++] = left[i++];

    while(j < n2) a[k++] = right[j++];
}

int main()
{
    int n;
    cout << "Enter the array size: ";
    cin >> n;

    int a[n];
    cout << "Enter the array elements: ";
    for(int i = 0 ; i < n; i++) cin >> a[i] ;

    cout << "Array before Sorting: ";
    print(a , n);

    merge_sort(a , 0 , n - 1);
    cout << "Array after Sorting: ";
    print(a , n);

    return 0;
}