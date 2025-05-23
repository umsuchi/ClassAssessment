#include <iostream>
using namespace std;

void selection_sort(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    
    int min_idx = i;

    for (int j = i + 1; j < size; j++) 
      if (array[j] < array[min_idx])
        min_idx = j;
    
    swap(array[min_idx] , array[i]);
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

    selection_sort(a , n);
    cout << "Array after Sorting: ";
    print(a , n);

    return 0;
}
