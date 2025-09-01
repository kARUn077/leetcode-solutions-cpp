class Solution {
public:
    bool valid(int row,int col ,vector<string>& board ,int n){
        //check its vertically upward
        for(int i=0;i<=row-1;i++){
            if(board[i][col]=='Q') return false;
        }

        //check right diagonal
        for(int i=row-1 ,j=col+1; i>=0 && j<n ;i-- ,j++){
            if(board[i][j]=='Q') return false;
        }

        //check left diagonal
        for(int i=row-1 ,j=col-1; i>=0 && j>=0 ;i-- ,j--){
            if(board[i][j]=='Q') return false;
        }        

        return true;
    }

    void solve(int row ,vector<string>& board ,int n, vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(valid(row ,col ,board ,n)){
                board[row][col]='Q';
                solve(row+1 ,board ,n ,ans);
                board[row][col]='.';
            }
        }
    }

    int totalNQueens(int n){
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n,'.');

        for(int i=0;i<n;i++){
            board[i]=s;
        }

        solve(0,board,n,ans);
        return ans.size();
    }
};