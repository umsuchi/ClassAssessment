#include <iostream>
using namespace std;

void print(int a[] , int n){
    for(int i = 0 ; i < n ; i++) cout << a[i] << "  " ;
    cout << endl;
}

void insertion_sort(int a[] , int n){
    for(int i = 1 ; i < n ; i++){
        int key = a[i];
        int j = i - 1;

        while(j >= 0 & key < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; 
    }
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

    insertion_sort(a , n);
    cout << "Array after Sorting: ";
    print(a , n);

    return 0;
}