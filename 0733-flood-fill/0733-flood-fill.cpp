class Solution {
public:
    int m, n;
    int oldColor;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& image, int r, int c, int color){
        if(r < 0 || r >= m || c < 0 || c >= n)
            return;

        if(image[r][c] != oldColor)
            return;

        image[r][c] = color;

        for(auto [dr, dc] : dir){
            dfs(image, r + dr, c + dc, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        m = image.size();
        n = image[0].size();

        oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        dfs(image, sr, sc, color);

        return image;
    }
};