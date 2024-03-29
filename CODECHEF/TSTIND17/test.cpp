/* Tran Dang Tuan Anh (problem setter)
   Solution: O(N + MLog(N))

    When sorted the vertices of a tree acording to the order they are visited in DFS,
    all the vertices of the sub-tree rooted at u will in a contiguous segment.
    We can use BIT or segment tree to implement the queries in log(n) each.
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

using namespace std;

vector <int> adj[122222];
int num[122222];
int pos[122222];
int node[122222];
int weight[122222];
int n;
int index__;

void dfs(int u) {
    num[u] = 1;
    pos[u] = ++index__;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == 0) {
            dfs(v);
            num[u] += num[v];
        }
    }
}

//BIT tree
void update(int pos, int diff) {
    while (pos <= n) {
        node[pos] += diff;
        pos += pos & -pos;
    }
}

int get (int pos) {
    int sum = 0;
    while (pos) {
        sum += node[pos];
        pos -= pos & -pos;
    }
    return sum;
}

int main() {
    int m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", weight + i);

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //find the dfs order
    //num[u] is the size of sub-tree rooted at u
    dfs(1);

    //initialize the BIT tree
    for (int i = 1; i <= n; i++)
        update(pos[i], weight[i]);

    for(int i=1;i<=n;i++){
      cout<<i<<":"<<node[i]<<"\n";
    }

    while (m--) {
        char c;
        cin >> c;
        if (c == 'Q') {
            int u;
            scanf("%d", &u);
            //find the sum of weight of Us in from pos[u] to (pos[u] + num[u] - 1) in the dfs order
            printf("%d\n", get(pos[u] + num[u] - 1) - get(pos[u] - 1));
        }
        else {
            int u, value;
            scanf("%d%d", &u, &value);

            update(pos[u], value - weight[u]);
            weight[u] = value;
        }
    }

    return 0;
}
