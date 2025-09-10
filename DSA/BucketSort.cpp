#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<float> &buck){
    for(int i = 1; i < buck.size(); i++){
        float k = buck[i];
        int j = i - 1;
        
        while(j >= 0 && buck[j] > k) 
            buck[j + 1] = buck[j], j--;
        
        buck[j + 1] = k;
    }
}

void bucketSort(vector<float> &a, int n){
    vector<float> b[n];

    for(int i = 0; i < n; i++){
        int bi = n * a[i];
        b[bi].push_back(a[i]);
    }

    for(int i = 0; i < n; i++) insertionSort(b[i]);

    int ind = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < b[i].size(); j++)
            a[ind++] = b[i][j];
    }
}

int main()
{
    vector<float> a = {0.897, 0.565, 0.534, 0.635, 0.1343, 0.876, 0.3432};
    int n = a.size();

    cout << "Before Bucket sort : ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    bucketSort(a, n);

    cout << "Sorted Array : " ;
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}