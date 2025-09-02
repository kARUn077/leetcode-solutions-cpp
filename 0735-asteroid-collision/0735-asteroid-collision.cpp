class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        int n=v.size();
        stack<int>st;
        for (int a : v) {
            bool destroyed = false;

            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(a) > st.top()) {
                    st.pop();  // Destroy top and continue checking
                } else if (abs(a) == st.top()) {
                    st.pop();  // Both destroy each other
                    destroyed = true;
                    break;
                } else {
                    // Incoming is smaller and destroyed
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(a);  // Safe to push
            }
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;

    }
};