#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

set<string> dic[41];

ll diff(string a,string b){
  ll n=SZ(a),m=SZ(b);

  ll dp[n+1][m+1];

  fr(i,0,n+1){
    fr(j,0,m+1){
      if(i==0) dp[i][j]=j;
      else if(j==0) dp[i][j]=i;
      else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
      else dp[i][j]=1+MIN(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]);
    }
  }

  return dp[n][m];
}

ll bfs(string src,string dst){
  queue<pair<string,ll> > q;
  q.push(MP(src,0));

  string word;
  ll dist;

  while(SZ(q)){
    word=q.front().fi;
    dist=q.front().se;
    q.pop();
    dic[SZ(word)].erase(word);

    if(word==dst) return dist;

    for(auto x:dic[SZ(word)-1]){
      if(diff(word,x)==1) q.push(MP(x,dist+1));
    }

    for(auto x:dic[SZ(word)]){
      if(diff(word,x)==1) q.push(MP(x,dist+1));
    }

    for(auto x:dic[SZ(word)+1]){
      if(diff(word,x)==1) q.push(MP(x,dist+1));
    }
  }

  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;

  do{
    cin>>s;
    if(s!="END") dic[SZ(s)].insert(s);
  }while(s!="END");

  string src,dst;
  cin>>src>>dst;

  cout<<bfs(src,dst);

  return 0;
}
