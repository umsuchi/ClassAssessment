#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int> &a, vector<int> &ans, int i){
    if(i == a.size()){
        for(int v : ans) cout << v << " ";
        cout << endl;

        return;
    }

    // include
    ans.push_back(a[i]);
    printSubsets(a, ans, i+1);

    // backtrack
    ans.pop_back();
    // exclude 
    printSubsets(a, ans, i+1);
}

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> ans;

    printSubsets(a, ans, 0);

    return 0;
}