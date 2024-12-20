#include <bits/stdc++.h>
using namespace std;

int countXMAS(const vector<string>& grid, int n, int m) {
    int count=0;

    for (int i=0; i<n-2; i++) {
        for (int j=0; j<m-2; j++) {
            if (grid[i][j] == 'M' && grid[i+1][j+1] == 'A' && grid[i+2][j+2] == 'S' &&
                    grid[i][j+2] == 'M' && grid[i+2][j] == 'S') {
                    count++;
                }
                if (grid[i][j] == 'M' && grid[i+1][j+1] == 'A' && grid[i+2][j+2] == 'S' &&
                    grid[i][j+2] == 'S' && grid[i+2][j] == 'M') {
                    count++;
                }
                if (grid[i][j+2] == 'M' && grid[i+1][j+1] == 'A' && grid[i+2][j] == 'S' &&
                    grid[i][j] == 'S' && grid[i+2][j+2] == 'M') {
                    count++;
                }
                if (grid[i][j+2] == 'S' && grid[i+1][j+1] == 'A' && grid[i+2][j] == 'M' &&
                    grid[i][j] == 'S' && grid[i+2][j+2] == 'M') {
                    count++;
                }    
        }
    }

    return count;
}

int main() {
    int n=140, m=140; //input grid parameters.
    vector<string> grid(n);
    for (int i=0; i<n; i++) {
        cin >> grid[i];
    }

    int result = countXMAS(grid, n, m);
    cout << result << endl;

    return 0;
}
