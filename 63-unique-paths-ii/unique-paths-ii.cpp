class Solution {
public:
 int UniquePathWithObstacles(int StRow,int StCol,int m,int n,vector<vector<int>>&Grid,vector<vector<int>>&Dp){
     // First Base Case :
     if(StRow>=m || StCol >=n) return 0;

     // Second Base Case :
     if(StRow==m-1 && StCol==n-1) return 1;

     // Third Base Case :
      if(Grid[StRow][StCol]==1) return 0;

      // Step 2 : Avoid Recompution...
       if(Dp[StRow][StCol]!=-1) return Dp[StRow][StCol];

      // The Robot Going To The Right Ways To Reach Destination .Finded Possible Ways.
      int RightWays=UniquePathWithObstacles(StRow+1,StCol,m,n,Grid,Dp); 

      // The Robot Going To The Down Ways To Reach Destination .Finded Possible Ways.
      int DownWays=UniquePathWithObstacles(StRow,StCol+1,m,n,Grid,Dp); 

      // Find All Possiable Ways Robot Going To Right And Down Ways..

        // Step 3 : Save A Results..
      return Dp[StRow][StCol]=RightWays + DownWays;
 }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        // Fourth Base CAse :
        if(Grid[0][0]==1) return 0;

        // Five BAse Case : 
        if(Grid[Grid.size()-1][Grid[0].size()-1]==1) return 0;

         // Step 1 : Create 2D Vector Store a Results..
          vector<vector<int>>Dp(Grid.size()+1,vector<int>(Grid[0].size()+1,-1));

        // Call a Robot Start a engine.. 
        return UniquePathWithObstacles(0,0,Grid.size(),Grid[0].size(),Grid,Dp);
    }
};