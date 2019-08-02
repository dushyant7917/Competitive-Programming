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
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n,c,b1,b2;
ll gender[N]={-1}; // 0 Male & 1 Female

void init(){
  fr(i,1,n+1) gender[i]=-1;
}

bool bfs(ll node,vector<ll> graph[]){
  queue<ll> q;
  q.push(node);
  gender[node]=1;

  ll v;
  while(!q.empty()){
    v=q.front();
    q.pop();
    //cout<<"v:"<<v<<"\n";

    fr(i,0,graph[v].size()){
      if(gender[graph[v][i]]==-1){
        gender[graph[v][i]]=!gender[v];
        q.push(graph[v][i]);
      }
      else{
        if(gender[graph[v][i]]==gender[v]) return false;
      }
      //cout<<v<<":"<<gender[v]<<" "<<graph[v][i]<<":"<<gender[graph[v][i]]<<"\n";
    }
  }

  return true;
}

bool fn(vector<ll> graph[]){
  fr(i,1,n+1){
    if(gender[i]==-1){
      //cout<<i<<"\n";
      if(bfs(i,graph)==false) return false;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll cnt=0;

  while(t--){
    cin>>n>>c;

    vector<ll> graph[n+1];
    fr(i,0,c){
      cin>>b1>>b2;
      graph[b1].PB(b2);
      graph[b2].PB(b1);
    }

    init();

    cout<<"Scenario #"<<(++cnt)<<":\n";
    if(fn(graph)) cout<<"No suspicious bugs found!\n";
    else cout<<"Suspicious bugs found!\n";
  }

  return 0;
}
