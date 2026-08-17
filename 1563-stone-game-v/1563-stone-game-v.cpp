#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        
        vector<vector<long long>> dp(
            n, vector<long long>(n, 0)
        );

        
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                
                for (int k = i; k < j; k++) {

                    long long left =
                        prefix[k + 1] - prefix[i];

                    long long right =
                        prefix[j + 1] - prefix[k + 1];

                    if (left < right) {
                        dp[i][j] = max(
                            dp[i][j],
                            left + dp[i][k]
                        );
                    }
                    else if (left > right) {
                        dp[i][j] = max(
                            dp[i][j],
                            right + dp[k + 1][j]
                        );
                    }
                    else {
                        dp[i][j] = max(
                            dp[i][j],
                            left + max(
                                dp[i][k],
                                dp[k + 1][j]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};