class Solution {
public:
    string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        if (n == 0 || m < n) return "";

        vector<int> t_hash('z' + 1, 0);
        vector<int> window_hash('z' + 1, 0);

        int min_window_length = INT_MAX;
        int best_left = -1;

        for (char c : t)
        {
            t_hash[c]++;
        }
        
        int required = 0, formed = 0;
        for (int i=0; i<t_hash.size(); i++) {
            if (t_hash[i] > 0) required++;
        }

        int l = 0, r = 0;

        while (r < m)
        {
            char curr = s[r];
            window_hash[curr]++;
            if (window_hash[curr] == t_hash[curr]) formed++;
            r++;
            while (required == formed)
            {
                if (r - l < min_window_length)
                {
                    min_window_length = r - l;
                    best_left = l;
                }
                char curr_remove = s[l];
                window_hash[curr_remove]--;
                if (window_hash[curr_remove] < t_hash[curr_remove]) formed--;
                l++;
            }
        }
        if (best_left == -1) return "";
        return s.substr(best_left, min_window_length);
    }
};
