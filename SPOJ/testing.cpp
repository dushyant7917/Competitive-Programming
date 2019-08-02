// SPOJ BACKPACK - Dab of Backpack
#include <iostream>
using namespace std;

int max (int a, int b)
{
    if (a > b)
       return a;
    return b;
}

int main ()
{
    int t;
    int vMax, n;
    int v[61];
    int c[61];
    int u[61];
    int attachmentOf[61][2];
    int dp[61][32001];
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        // Initialization
        for (int i = 0; i <= 60; i++)
        {
            attachmentOf[i][0] = 0;
            attachmentOf[i][1] = 0;
        }
        for (int i = 0; i <= 60; i++)
            for (int j = 0; j <= 32000; j++)
                dp[i][j] = 0;


        // Getting inputs
        cin >> vMax >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i] >> c[i] >> u[i];
            if (attachmentOf[u[i]][0] == 0)
               attachmentOf[u[i]][0] = i;
            else
               attachmentOf[u[i]][1] = i;
        }


        // Dynamic Programming
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= vMax; j++)
            {
                dp[i][j] = dp[i-1][j];
                if (u[i] == 0)
                {
                   if (j >= v[i])
                   {
                         dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]] + v[i] * c[i]);

                         if (attachmentOf[i][0] != 0)
                         {
                            if (j >= (v[i] + v[attachmentOf[i][0]]))
                               dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]-v[attachmentOf[i][0]]] + v[i] * c[i] + v[attachmentOf[i][0]] * c[attachmentOf[i][0]]);

                            if (attachmentOf[i][1] != 0)
                            {
                                if (j >= (v[i] + v[attachmentOf[i][1]]))
                                   dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]-v[attachmentOf[i][1]]] + v[i] * c[i] + v[attachmentOf[i][1]] * c[attachmentOf[i][1]]);

                                if (j >= (v[i] + v[attachmentOf[i][0]] + v[attachmentOf[i][1]]))
                                   dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]-v[attachmentOf[i][0]]-v[attachmentOf[i][1]]] + v[i] * c[i] + v[attachmentOf[i][0]] * c[attachmentOf[i][0]] + v[attachmentOf[i][1]] * c[attachmentOf[i][1]]);


                            }
                         }
                   }
                }
            }

        // Output ...
        cout << dp[n][vMax] << "\n";
    }
}
