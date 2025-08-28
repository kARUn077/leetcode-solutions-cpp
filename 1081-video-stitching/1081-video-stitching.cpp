class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int n = clips.size();
        int end = 0, farthest = 0, ans = 0, i = 0;

        while (end < time) {
            while (i < n && clips[i][0] <= end) {
                farthest = max(farthest, clips[i][1]);
                i++;
            }
            if (farthest == end) return -1; // no progress
            end = farthest;
            ans++;
        }

        return ans;
    }
};
