#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;

    if(n >= 4 || n == 1) {
        vector<long long> even;
        vector<long long> odd;

        for(long long i = 1; i <= n; i++){
            if(i % 2 == 0) even.push_back(i);
            else odd.push_back(i);
        }

        for(long long i = 0; i < even.size(); i++)
            cout << even[i] << " ";

        for(long long i = 0; i < odd.size(); i++)
            cout << odd[i] << " ";
        //cout << odd[0] << endl;

    } else cout << "NO SOLUTION" << endl;

    return 0;
}