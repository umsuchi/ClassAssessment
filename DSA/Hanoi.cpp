#include <iostream>
using namespace std;

void tower(int n , char B , char A , char E){
    if(n == 1) {
        cout << "Move disk from " << B << " to " << E << endl;
        return ;
    }

    tower(n - 1 , B , E , A);

    cout << "Move disk from " << B << " to " << E << endl;

    tower(n - 1 , A , B , E);
}

int main()
{
    cout << "Enter no of disk : ";
    int n;
    cin >> n;

    tower(n ,'B' , 'A' , 'E');

    return 0;
}