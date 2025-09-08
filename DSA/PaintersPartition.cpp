#include <iostream>
#include <vector>
using namespace std;

bool ispossible(vector<int> &a, int n, int m, int mid){
    int num = 1, time = 0;

    for(int i = 0 ; i < n ; i++){
        if(time + a[i] <= mid) time += a[i];
        else num++, time = a[i];
    }

    return num <= m ;
}

int mintime(vector<int> &a, int n, int m){
    int sum = 0, maxval = INT16_MIN;
    for(int i = 0 ; i < n ; i++) sum += a[i], maxval = max(maxval, a[i]);

    int l = maxval, h = sum, ans = -1;

    while(l <= h){
        int mid = l + (h - l)/2;

        if(ispossible(a, n, m, mid)) ans = mid, h = mid - 1;
        else l = mid + 1;
    }
}

int main()
{
    vector<int> a = {40, 30, 10, 20};
    int n = 4, m = 2;

    cout << mintime(a, n, m) << endl;

    return 0;
}







// Painter's Partition Problem :

// Given are N boards of length of each given in the form of array,
// and M painters, such thata each painter takes 1 unit of time to 
// paint 1 unit of the board.

// The task is to find the minimum thime to paint all boards under the
// constraints that any painter will only paint continuous sections of
// boards.