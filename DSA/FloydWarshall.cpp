#include <iostream>
using namespace std;

void printMatrix(int n, int W[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << W[i][j] << " ";
        }
        cout << endl;
    }
}

void warshall(int n, int M[10][10]) {
    int W[10][10];
    
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

    cout << "\nTransitive Closure of the given graph:\n";
    printMatrix(n, W);
}

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int M[10][10];

    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    warshall(n, M);

    return 0;
}