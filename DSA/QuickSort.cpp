#include <iostream>
using namespace std;

int partition(int a[] , int low , int high){
    int pivot = a[high];

    int i = (low - 1);

    for(int j = low ; j < high ; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i] , a[j]);
        }
    }
    i++;
    swap(a[i] , a[high]);
    return i;
}

void quick_sort(int a[] , int low , int high){
    if(low < high){
        int pi = partition(a , low , high);
        quick_sort(a , low , pi - 1);
        quick_sort(a , pi + 1 , high);
    }
}

void print(int a[] , int n){
    for(int i = 0 ; i < n ; i++) cout << a[i] << "  " ;
    cout << endl;
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

    quick_sort(a , 0 , n - 1);
    cout << "Array after Sorting: ";
    print(a , n);

    return 0;
}
