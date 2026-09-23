class Solution
{
public:
    void dfs(vector<vector<int>> &image, int i, int j, int color, int m, int n, int t)
    {
        if(i < 0 || j < 0 || i >= m || j >= n || image[i][j] != t || image[i][j] == color)
        {
            return;
        }
        image[i][j] = color;
        dfs(image, i , j+1 ,color, m , n, t);
        dfs(image, i + 1, j ,color, m , n, t);
        dfs(image, i , j - 1 ,color, m , n, t);
        dfs(image, i - 1 , j ,color, m , n, t);

    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();

        int t = image[sr][sc];

        dfs(image, sr, sc,color, m , n , t);
        return image;
    }
};