class Solution {
private:

    vector<int> topoSort(int k, vector<vector<int>>& adj) {

        vector<int> indegree(k, 0);

        for(int i = 0; i < k; i++) {
            for(auto v : adj[i]) {
                indegree[v]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < k; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto v : adj[node]) {

                indegree[v]--;

                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // cycle detection
        if(topo.size() != k) {
            return {};
        }

        return topo;
    }

public:

    string findOrder(vector<string> &words) {

        int n = words.size();

        vector<vector<int>> adj(26);
        vector<bool> exists(26, false);

        // mark existing characters
        for(auto word : words) {
            for(char ch : word) {
                exists[ch - 'a'] = true;
            }
        }

        for(int i = 0; i < n - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            for(int j = 0; j < len; j++) {

                if(s1[j] != s2[j]) {

                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    adj[u].push_back(v);
                    break;
                }
            }
        }

        vector<int> topo = topoSort(26, adj);

        if(topo.empty()) {
            return "";
        }

        string ans = "";

        for(auto node : topo) {
            if(exists[node]) {
                ans += char(node + 'a');
            }
        }

        return ans;
    }
};