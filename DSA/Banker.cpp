#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, p; 
    cout << "Enter number of processes: "; cin >> n;
    cout << "Enter number of resources: "; cin >> p;
    
    vector<int> avail(p);
    vector<vector<int>> max(n, vector<int>(p));
    vector<vector<int>> alloc(n, vector<int>(p));
    vector<vector<int>> need(n, vector<int>(p));

    cout << "Enter max : " << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
            cin >> max[i][j];
        
    cout << "Enter allocation(A  B  C) : " << endl;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
            cin >> alloc[i][j];

    cout << "Enter available resources : " << endl;
    for(int j = 0; j < p; j++) cin >> avail[j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    vector<bool> finish(n, false);
    vector<int> safe;
    int count = 0;
    while(count < n){
        bool found = false;
        for(int i = 0; i < n; i++){
            if(!finish[i]){
                int j;
                for(j = 0; j < p; j++){
                    if(need[i][j] > avail[j])
                        break;
                }
                if(j == p){
                    for(int k = 0; k < p; k++)
                        avail[k] += alloc[i][k];
                    safe.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }
        if(!found){
            cout << "System is not in safe state." << endl;
            return 0;
        }
    }

    cout << "System is in safe state.\nSafe sequence is: ";
    for(int i = 0; i < safe.size(); i++)
        cout << "P" << safe[i] << "->";
    cout << endl;

    return 0;
}