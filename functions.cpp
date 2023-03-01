#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include "output.h"

using namespace std;

string Lcs(string& s1, string& s2, vector<int>& a, vector<int>& b) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    string lcs = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            a[i - 1] = 1;
            b[j - 1] = 1;
            lcs += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(lcs.begin(), lcs.end());

    return lcs;
}

void remaining_Data(string& s, vector<int>& flag)
{
    for (int i = 0; i < flag.size(); i++)
    {
        if (flag[i] == 0)
        {
            outdata << s[i];
        }
    }
}

void print_Flags(vector<int>& v)
{
    for (auto& t : v)
    {
        outdata << t;
    }
}


