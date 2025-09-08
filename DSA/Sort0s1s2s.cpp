#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    int n = nums.size();

    int l = 0, mid = 0, h = n - 1; // 3 pointers
    while(mid <= h){
        if(nums[mid] == 0) swap(nums[l], nums[mid]), mid++, l++;
        else if(nums[mid] == 1) mid++;
        else swap(nums[h], nums[mid]), h--;
    }

    for(int i = 0 ; i < n ; i++) cout << nums[i] << ' ';
    cout << endl;

    return 0;
}