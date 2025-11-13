#include <iostream>
using namespace std;

int main()
{
    string s; cin >> s;
    long n=1, c=1;

    for(long i=1; i<s.size(); i++){
        (s[i] == s[i-1]) ? n++ : n=1;
        c = max(n, c);
    }

    cout << c << endl;

    return 0;
}