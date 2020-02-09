#include <bits/stdc++.h>
using namespace std;

bool board[10][10];
int cnt = 1;
vector<int> ans;
int srow,scol;

bool boom(int row,int col){
    return row < 1 || col < 1 || row > 8 || col > 8;
}

bool isfight(int row,int col){

    for(int i = 1;i <= 8;++i){
        if(board[row][i] && i != col) return 1;
        if(board[i][col] && i != row) return 1;
    }

    int r = row,c = col;

    while(!boom(r,c)){
        if(board[r][c] && (r != row || c != col)) return 1;
        r--;
        c--;
    }

    r = row;
    c = col;

    while(!boom(r,c)){
        if(board[r][c] && (r != row || c != col)) return 1;
        r++;
        c++;
    }

    r = row;
    c = col;

    while(!boom(r,c)){
        if(board[r][c] && (r != row || c != col)) return 1;
        r++;
        c--;
    }

    while(!boom(r,c)){
        if(board[r][c] && (r != row || c != col)) return 1;
        r--;
        c++;
    }
    
    return 0;
}

void dfs(int col){
    if(col == 9){
        printf("%2d     ",cnt++);

        for(int i = 0;i < ans.size();++i){
            printf(" %d",ans[i]);
        }
        printf("\n");

        return;
    }
    if(scol == col){
        if(isfight(srow,scol)) return;
        ans.push_back(srow);
        dfs(col + 1);
        ans.pop_back();
    } else {
        for(int i = 1;i <= 8;++i){
            if(!isfight(i,col)){
                board[i][col] = 1;
                ans.push_back(i);

                dfs(col + 1);

                board[i][col] = 0;
                ans.pop_back();
            }
        }
    }

}

int main(){
    int t;
    cin >> t;

    for(int tt = 0;tt < t;++tt){
        if(tt) printf("\n");

        cnt = 1;
        memset(board,0,sizeof(board));
        ans.clear();

        cin >> srow >> scol;
        
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        board[srow][scol] = 1;
        
        dfs(1);
    }

    return 0;
}
