class Solution {
public:
    bool issafe(int row,int col,int n,vector<string>&board){
        bool ans=true;
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                ans=false;
                break;
            }
            if(board[row][i]=='Q'){
                ans=false;
                break;
            }
            if(row+i<n && col+i<n && board[row+i][col+i]=='Q'){
                ans=false;
                break;
            }
            if(row-i>=0 && col+i<n && board[row-i][col+i]=='Q'){
                ans=false;
                break;
            }
            if(row+i<n && col-i>=0 && board[row+i][col-i]=='Q'){
                ans=false;
                break;
            }
            if(row-i>=0 && col-i>=0 && board[row-i][col-i]=='Q'){
                ans=false;
                break;
            }
        }
        return ans;
    }
    void rec(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(i,col,n,board)){
                board[i][col]='Q';
                rec(col+1,board,ans,n);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        if(n==2 || n==3){
            return ans;
        }
        string s(n,'.');
        vector<string>board(n,s);
        rec(0,board,ans,n);
        return ans;
    }
};