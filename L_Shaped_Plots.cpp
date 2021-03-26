#include<iostream>
#include<vector>

using namespace std;

//Finds out the number of L Shapes
int count(int x, int y) {
    if (x == 1 || y == 1)
        return 0;
    return std::min(x / 2, y) + std::min(y / 2, x) - 2;
}


int main() {
    int  t,row, col;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> row >> col;
        
        //Geting input of matrix
        vector<vector<long long>> mat(row, vector<long long>(col, 0));
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                cin >> mat[r][c];
            }
        }

        long long ans = 0;
        
        vector < vector <  long long >> top(row, vector<long long>(col, 0));
        vector < vector <  long long >> left(row, vector<long long>(col, 0));
        vector < vector <  long long >> bot(row, vector<long long>(col, 0));
        vector < vector <  long long >> right(row, vector<long long>(col, 0));

   
    //Constructing top and left Matrices
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (mat[r][c] == 0)
                    continue;
                if(r-1>=0)
                top[r][c] = top[r - 1][c] + mat[r][c];
                else {
                    top[r][c] = 1;
                }
                if(c-1>=0)
                left[r][c] = left[r][c - 1] + mat[r][c];
                else {
                    left[r][c] = 1;
                }
            }
        }

        //Constructing bottom and right matrices
        for (int r = row - 1; r >= 0; r--) {
            for (int c = col - 1; c >= 0; c--) {
                if (mat[r][c] == 0)
                    continue;
                if (r + 1 < row)
                   bot[r][c] = mat[r][c] + bot[r + 1][c];
                else {
                    bot[r][c] = 1;
                }
                if (c + 1 < col)
                    right[r][c] = mat[r][c] + right[r][c + 1];
                else {
                    right[r][c] = 1;
                }

            }
        }
      
        // Passing (top,left) , (top,right) , (bottom,left) , (bottom,right) to Count(x,y) function to find out the number of L-shapes
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if(mat[r][c] ==0)
                    continue;
                if(r!=0&& c!=0)
                ans += count(top[r][c], left[r][c]);
                if(r!=0&&c!=col-1){
                ans += count(top[r][c], right[r][c]);
            }
                if(r!=row-1&&c!=0)
                ans += count(bot[r][c], left[r][c]);
                if(r!=row-1 && c!=col-1)
                ans += count(bot[r][c], right[r][c]);
            }
        }
        cout << "Case #" << (i + 1) << ": " << ans << '\n';
    }

}
