#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &a, int l, int mid, int h){
    vector<int> t;
    int i=l, j=mid+1;
    int count = 0;

    while(i <= mid && j <= h){
        if(a[i] <= a[j]){
            t.push_back(a[i]);
            i++;
        }
        else{
            t.push_back(a[j]);
            count += (mid - i + 1);
            j++;
        }
    }

    while(i <= mid){
        t.push_back(a[i]);
        i++;
    }

    while(j <= h){
        t.push_back(a[j]);
        j++;
    }

    for(int ind=0; ind<t.size(); ind++){
        a[l + ind] = t[ind];
    }

    return count;
}

int mergesort(vector<int> &a, int l, int h){
    if(l < h){
        int mid = (l + h) / 2;

        int left = mergesort(a, l, mid);
        int right = mergesort(a, mid + 1, h);
        int count = merge(a, l, mid, h);
        
        return left + right + count;
    }

    return 0;
}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int c = mergesort(a, 0, n - 1);

    cout << c << endl;

    return 0;
} 
    