#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t, q, x, y;

  cin >> t;

  string n, m;

  for(int itr = 1; itr <= t; itr++)
  {
    cin >> m >> n >> q;

    char c[n.size() + 1][m.size() + 1];

    if(m[0] == '0'){
      c[1][1] = 'A';
    }

    else if(n[0] == '0'){
      c[1][1] = 'A';
    }

    else
    {
      c[1][1] = 'B';
    }

    for(int i = 2; i <= m.size(); i++)
    {
      if(m[i - 1] == '0')
      {
        c[1][i] = 'A';
      }

      else if(c[1][i - 1] == 'B')
      {
        c[1][i] = 'A';
      }

      else
      {
        c[1][i] = 'B';
      }
    }

    for(int i = 2; i <= n.size(); i++)
    {
      if(n[i - 1] == '0')
      {
        c[i][1] = 'A';
      }

      else if(c[i - 1][1] == 'B')
      {
        c[i][1] = 'A';
      }

      else
      {
        c[i][1] = 'B';
      }
    }

    for(int i = 2; i <= n.size(); i++)
    {
      for(int j = 2; j <= m.size(); j++)
      {
        if(c[i - 1][j] == 'B')
        {
          c[i][j] = 'A';
        }

        else if(c[i][j - 1] == 'B')
        {
          c[i][j] = 'A';
        }

        else
        {
          c[i][j] = 'B';
        }
      }
    }

    /*

    cout << "\t\t";

    for(int i = 1; i <= m.size(); i++)
    {
      cout << "\t" << i;
    }

    cout << "\n\n\t\t";

    for(int i = 0; i < m.size(); i++)
    {
      cout << "\t" << m[i];
    }

    cout << "\n\n";

    for(int i = 1; i <= n.size(); i++)
    {
      cout << "\t" << i << "\t" << n[i-1];

      for(int j = 1; j <= m.size(); j++)
      {
        cout << "\t" << c[i][j];
      }

      cout << "\n\n";
    }

    cout<<"\n\n";

    */

    for(int i = 1; i <= q; i++)
    {
      cin >> x >> y;

      if(c[x][y] == 'A'){
        cout << 1;
      }

      else
      {
        cout << 0;
      }
    }

    cout << "\n";
  }

  return 0;
}
