#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9

ll n,m;
bool adj[10001][10001];

void topological_sort(){
  vector<ll> a;
  bool visited[n+1];
  ll in_degree[n+1];

  fr(i,1,n+1){
    in_degree[i]=0;
    visited[i]=false;
  }

  fr(i,1,n+1){
    fr(j,1,n+1){
      if(adj[i][j]) in_degree[j]++;
    }
  }

  set<ll> mh; // acts as a min-heap

  fr(i,1,n+1){
    if(in_degree[i]==0){
      mh.insert(i);
      visited[i]=true;
    }
  }

  while(!mh.empty()){
    ll v=(*mh.begin());
    mh.erase(mh.begin());
    a.PB(v);
    fr(j,1,n+1){
      if(adj[v][j] && !visited[j]){
        in_degree[j]--;
        if(in_degree[j]==0){
          mh.insert(j);
          visited[j]=true;
        }
      }
    }
  }

  if(a.size()<n){
    //printf("%s","Sandro fails.");
    cout<<"Sandro fails.";
  }
  else{
    fr(i,0,a.size()){
      //printf("%lld ",a[i]);
      cout<<a[i]<<" ";
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  //scanf("%lld%lld",&n,&m);
  cin>>n>>m;

  ll x,y;
  fr(i,0,m){
    //scanf("%lld%lld",&x,&y);
    cin>>x>>y;
    adj[x][y]=true;
  }

  topological_sort();

  return 0;
}
