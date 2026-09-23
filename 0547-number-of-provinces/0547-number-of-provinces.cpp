class Solution {
public:
    void dfs(int node , vector<vector<int>>& con, vector<int> &visited)
    {
        visited[node] = 1;

        int n = con.size();

        for (int j = 0; j < n; j++)
        {
            if (con[node][j] == 1 && !visited[j])
            {
                dfs(j, con,visited);
            }
            
        }
        


    }



    int findCircleNum(vector<vector<int>>& con) {
        int n = con.size();

        vector<int> visited(n, 0);

        int ans = 0;
        for (int  i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(i, con, visited );
            }
            
        }

        return ans;
        
    }
};