#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ispossible(vector<int> &a, int n, int c, int mid){
    int cows = 1, position = a[0];

    for(int i = 1 ; i < n ; i++){
        if(a[i] - position >= mid) cows++, position = a[i];

        if(cows == c) return 1;
    }

    return 0;
}

int distance(vector<int> &a, int n, int c){
    sort(a.begin(), a.end());
    int l = 1, h = a[n - 1] - a[0], ans = -1;

    while(l <= h){
        int mid = l + (h - l)/2;

        if(ispossible(a, n, c, mid)) ans = mid, l = mid + 1; 
        else h = mid - 1;
    }

    return ans;
}

int main()
{
    int n = 5, c = 3;
    vector<int> a = {1, 2, 8, 4, 9};

    cout << distance(a, n, c) << endl;

    return 0;
}







// Aggressive Cows Problem :

// Assign C cows to N stalls such that min distance between
// them is largest possible. Return largest minimum distance.

// N = 5  array = {1, 2, 8, 4, 9}   C = 3