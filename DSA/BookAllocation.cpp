#include <iostream>
#include <vector>
using namespace std;

bool isvalid(vector<int> &a, int n, int m, int mid){
    int st = 1, pages = 0;

    for(int i = 0 ; i < n ; i++){
        if(a[i] > mid) return 0;

        if(pages + a[i] <= mid) pages += a[i];
        else st++, pages = a[i];
    }

    return st > m ? 0 : 1;
}

int allocate(vector<int> &a, int n, int m){
    int sum = 0;
    for(int i = 0 ; i < n ; i++) sum += a[i];

    int l = 0, h = sum, ans = -1;

    while(l <= h){
        int mid = l + (h - l)/2;

        if(isvalid(a, n, m, mid))
            ans = mid, h = mid - 1;
        else l = mid + 1;
        
    }

}

int main()
{
    vector<int> a = {2, 1, 3, 4};
    int n = a.size() , m = 2;

    cout << allocate(a, n, m) << endl;

    return 0;
}










// Book Allocation Problem :

// There are N books, each ith book has A[i] number of pages.

// You have to allocate books to M number of students so that the 
// maximum number of pages allocated to a student is maximum.

// • Each book should be allocated to a student.
// • Each student has to be allocated at least one book. 
// • Allotment should be in contiguous order.

// Calculate and return that minimum possible number.
// Return -1 if a balid asssignment is not possible.