#include <iostream>
#include <vector>
using namespace std;

void printMatrix(int n, vector<vector<int>> &W) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << W[i][j] << " ";
        }
        cout << endl;
    }
}

void warshall(int n, vector<vector<int>> &M) {
    vector<vector<int>> W(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            W[i][j] = M[i][j];

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                W[i][j] = W[i][j] || (W[i][k] && W[k][j]);
            }
        }
    }

    cout << "Transitive Closure of the given graph:" << endl;
    printMatrix(n, W);
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n, 0));

    cout << "Enter adjacency matrix (" << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> M[i][j];

    warshall(n, M);

    return 0;
}