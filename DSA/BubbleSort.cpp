#include <iostream>
using namespace std;

void print(int a[] , int n){
    for(int i = 0 ; i < n ; i++) cout << a[i] << "  " ;
    cout << endl;
}

void bubble(int a[] , int n){
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(a[j] > a[j + 1]) swap(a[j] , a[j + 1]);
        }
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

    bubble(a , n);
    cout << "Array after Sorting: ";
    print(a , n);

    return 0;
}