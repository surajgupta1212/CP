int dp[11][2][20];
    int sz;

    int solve(string& s, int ind, int tight, int cnt) {
        if (ind >= sz)
            return cnt;

        int limit = (tight == 1 ? s[ind] - '0' : 9);

        if (dp[ind][tight][cnt] != -1)
            return dp[ind][tight][cnt];

        int ans = 0;
        for (int i = 0; i <= limit; i++) {
            int newcnt = cnt + (i == 1 ? 1 : 0);
            ans += solve(s, ind + 1, tight & (i == s[ind] - '0'), newcnt);
        }

        return dp[ind][tight][cnt] = ans;
    }
