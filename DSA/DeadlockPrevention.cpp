#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n; 
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<string> name(n);
    vector<int> time(n);

    cout << "Enter name and execution time for each job:\n";
    for (int i = 0; i < n; ++i) {
        cin >> name[i] >> time[i];
    }

    int avail;
    cout << "Enter the available resources: ";
    cin >> avail;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = i;

    sort(v.begin(), v.end(), [&](int a, int b) {
        return time[a] < time[b];
    });

    vector<int> sequen;
    for (int i = 0; i < n; ++i) {
        int job_idx = v[i];
        if (time[job_idx] <= avail) {
            sequen.push_back(job_idx);
            avail -= time[job_idx];
        } else {
            cout << "No safe sequence possible.\n";
            return 0;
        }
    }

    cout << "Safe sequence is: ";
    for (int i = 0; i < sequen.size(); ++i) {
        cout << name[sequen[i]];
        if (i != sequen.size() - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
