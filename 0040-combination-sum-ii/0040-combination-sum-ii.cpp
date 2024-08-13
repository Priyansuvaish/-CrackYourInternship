class Solution {
public:
    // map<vector<int>, int> ans;
    vector<vector<int>>ans;
    void solve(int i, int n, int t, vector<int> temp, vector<int> candidate) {
        if (t == 0) {
            // ans[temp]++;
            ans.push_back(temp);
            return;
        }
        if (t < 0 || i >= n || i < 0)
            return;
        for(int j=i;j<n&&t >= candidate[i];j++){
            if (i ==j||candidate[j]!=candidate[j-1]) {
                temp.push_back(candidate[j]);
                solve(j + 1, n, t - candidate[j], temp, candidate);
                temp.pop_back();
            }

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        
        solve(0, candidates.size(), target, temp, candidates);
        vector<vector<int>> a;
        // for (auto it : ans)
        //     a.push_back(it.first);
        return ans;
    }
};