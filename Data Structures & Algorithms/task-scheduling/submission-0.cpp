class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_counts = vector<int>(26, 0);

        for (char c: tasks) {
            task_counts[c - 'A']++;
        }

        priority_queue<int> pq;
        for (int i=0; i<26; i++) {
            if (task_counts[i] != 0) {
                pq.push(task_counts[i]);
            }
        }

        queue<pair<int, int>> q; // { rem_count, when_begin }

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            while (!q.empty()) {
                if (time < q.front().second) break;
                pq.push(q.front().first);
                q.pop();
            }
            if (!pq.empty()) {
                int top = pq.top();
                pq.pop();
                if (top != 1)
                    q.push({top-1, time + n + 1});
            }
            time++;
        }
        return time;
    }
};
