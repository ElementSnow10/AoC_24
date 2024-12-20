#include <bits/stdc++.h>
using namespace std;

int countXMAS(const vector<string>& grid, int n, int m) {
    int count=0;
    string target = "XMAS";
    int len=target.length();
    // Directions: right, down, diagonal down-right, diagonal down-left
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (auto dir : directions) {
                int x=i, y=j;
                bool found=true;
                for (int k=0; k<len; k++) {
                    if (x<0 || x>=n || y<0 || y>=m || grid[x][y]!=target[k]) {
                        found=false;
                        break;
                    }
                    x+=dir.first;
                    y+=dir.second;
                }
                if(found){
                    count++;
                } 
                x=i, y=j;
                found=true;
                for (int k = 0; k < len; ++k) {
                    if (x<0 || x>=n || y<0 || y>=m || grid[x][y]!=target[len-1-k]) {
                        found=false;
                        break;
                    }
                    x+=dir.first;
                    y+=dir.second;
                }
                if (found) count++;
            }
        }
    }

    return count;
}

int main() {
    int n=140, m=140; //input grid parameters.
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int result = countXMAS(grid, n, m);
    cout << result << endl;

    return 0;
}
