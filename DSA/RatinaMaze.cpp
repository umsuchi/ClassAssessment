#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans){
    int n = mat.size();

    if(r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1) 
        return;

    if(r == n-1 && c == n-1){
        ans.push_back(path);
        return;
    }

    mat[r][c] = -1;

    helper(mat, r+1, c, path+"D", ans); // down
    helper(mat, r-1, c, path+"U", ans); // up
    helper(mat, r, c-1, path+"L", ans); // left
    helper(mat, r, c+1, path+"R", ans); // right

    mat[r][c] = 1;
}

vector<string> findpath(vector<vector<int>> &mat){
    vector<string> ans;
    string path = "";

    helper(mat, 0, 0, path, ans);

    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> ans = findpath(mat);

    for(string path : ans) cout << path << endl;

    return 0;
}




// Rat in a Maze
// Backtracking Problem

// Suppose a rat placed at cell (0, 0) in a square matrix of order (N * N). It has to reach the destination 
// at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The 
// directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in 
// the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix 
// represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move 
// to any other cell.

// Input: N = 4
// {{1, 0, 0, 0},
// {1, 1, 0, 1},
// {1, 1, 0, 0},
// {0, 1, 1, 1}}
// Output: DDRDRR DRDDRR
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when 
// printed in sorted order we get DDRDRR DRDDRR.