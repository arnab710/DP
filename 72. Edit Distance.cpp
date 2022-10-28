class Solution {
// private:
//     int solver(int i,int j,string &word1,string &word2,vector<vector<int>>& dp){
//         if(i==word1.size()) return (word2.size() - j);
//         if(j==word2.size()) return (word1.size() - i);
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int ans = 0;
//         if(word1[i]==word2[j])  ans = solver(i+1,j+1,word1,word2,dp);
//         else{
            
//             int ans1 = 1 + solver(i+1,j+1,word1,word2,dp);
//             int ans2 = 1 + solver(i,j+1,word1,word2,dp);
//             int ans3 = 1 + solver(i+1,j,word1,word2,dp);
            
//              ans = min(ans1,min(ans2,ans3)); 
//         }
//         return dp[i][j] = ans;
 //   }
public:
    int minDistance(string word1, string word2) {
            
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       // return solver(0,0,word1,word2,dp);
        
        for(int i = n;i>=0;i--){
            for(int j = m;j>=0;j--){
                
                if(i==n) dp[i][j] = m-j;
                else if(j==m) dp[i][j] = n-i;
                else{
                        int ans = 0;
                    if(word1[i]==word2[j]) ans = dp[i+1][j+1];
                    else{
                        
                        int ans1 = 1 + dp[i+1][j];
                        int ans2 = 1 + dp[i][j+1];
                        int ans3 = 1 + dp[i+1][j+1];
                        
                        ans = min(ans1,min(ans2,ans3));
                    }
                    
                    dp[i][j] = ans; 
                }
                
            }
        }
        return dp[0][0];
    }
};
