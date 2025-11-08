#include <iostream>
using namespace std;

int main()
{
    long t; cin >> t;
    while(t != 1){
        cout << t << " ";

        t = (t & 1) ? t*3 + 1 : t / 2;
    }
    cout << t << endl;

    return 0;
}