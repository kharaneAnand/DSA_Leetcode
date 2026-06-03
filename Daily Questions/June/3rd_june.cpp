class Solution {
public:
    
    int solve(vector<int>& Astart, vector<int>& Adur,
              vector<int>& Bstart, vector<int>& Bdur) {

        int n = Bstart.size();

        vector<pair<int,int>> b;

        for (int i = 0; i < n; i++) {
            b.push_back({Bstart[i], Bdur[i]});
        }

        sort(b.begin(), b.end());

        vector<int> start(n);

        for (int i = 0; i < n; i++) {
            start[i] = b[i].first;
        }

        // prefix minimum duration
        vector<int> prefMinDur(n);

        prefMinDur[0] = b[0].second;

        for (int i = 1; i < n; i++) {
            prefMinDur[i] = min(prefMinDur[i-1], b[i].second);
        }

        // suffix minimum (start + duration)
        vector<int> suffMinFinish(n);

        suffMinFinish[n-1] = b[n-1].first + b[n-1].second;

        for (int i = n-2; i >= 0; i--) {
            suffMinFinish[i] = min(
                suffMinFinish[i+1],
                b[i].first + b[i].second
            );
        }

        int ans = INT_MAX;

        for (int i = 0; i < Astart.size(); i++) {

            int finishA = Astart[i] + Adur[i];

            // last index where Bstart <= finishA
            int idx = upper_bound(start.begin(), start.end(), finishA)
                      - start.begin() - 1;

            // Case 1: already started
            if (idx >= 0) {
                ans = min(ans, finishA + prefMinDur[idx]);
            }

            // Case 2: starts later
            int nextIdx = idx + 1;

            if (nextIdx < n) {
                ans = min(ans, suffMinFinish[nextIdx]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans1 = solve(
            landStartTime,
            landDuration,
            waterStartTime,
            waterDuration
        );

        int ans2 = solve(
            waterStartTime,
            waterDuration,
            landStartTime,
            landDuration
        );

        return min(ans1, ans2);
    }
};