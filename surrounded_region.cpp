class Solution {
public:
    
    void floodFill(vector<vector<char>>& mat, int x, int y, char prev, char newer){
        if (x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size()) 
            return; 
        if (mat[x][y] != prev) 
            return; 

        // Replace the color at (x, y) 
        mat[x][y] = newer; 

        // Recur for north, east, south and west 
        floodFill(mat, x+1, y, prev, newer); 
        floodFill(mat, x-1, y, prev, newer); 
        floodFill(mat, x, y+1, prev, newer); 
        floodFill(mat, x, y-1, prev, newer); 
    }
    
    void solve(vector<vector<char>>& board) {
        
        if(board.size()!=0){  
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='-';
                }
            }
        }
        
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
            if(board[i][0]=='-')
                floodFill(board,i,0,'-','O');
        
        for(int i=0;i<m;i++)
            if(board[i][n-1]=='-')
                floodFill(board,i,n-1,'-','O');
        
        for(int i=0;i<n;i++)
            if(board[0][i]=='-')
                floodFill(board,0,i,'-','O');
        
        for(int i=0;i<n;i++)
            if(board[m-1][i]=='-')
                floodFill(board,m-1,i,'-','O');
        
        for (int i=0; i<board.size(); i++) 
            for (int j=0; j<board[i].size(); j++) 
                if (board[i][j] == '-') 
                    board[i][j] = 'X'; 
        
        
        for(int i=0;i<board.size();i++){
            cout<<endl;
            for(int j=0;j<board[i].size();j++){
                cout<<board[i][j]<<" ";
            }
        }  
        }   
    }
};
