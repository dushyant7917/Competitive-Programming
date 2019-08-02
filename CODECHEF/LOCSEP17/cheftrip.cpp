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

struct tickets{
  ll start;
  ll end;
};

map<ll,string> name;
bool is_source[10001];

void dfs(vector<ll> adj[],ll num_adj[],ll k,ll source){
  bool visited[k];
  fr(i,1,k) visited[i]=false;
  stack<ll> s;
  s.push(source);
  visited[source]=true;
  cout<<name[source];

  ll v;
  while(!s.empty()){
    v=s.top();
    s.pop();
    fr(i,0,adj[v].size()){
      if(visited[adj[v][i]]==false){
        if(num_adj[adj[v][i]]==2) cout<<"-"+name[adj[v][i]]+" "+name[adj[v][i]];
        else{
          cout<<"-"+name[adj[v][i]];
        }
        s.push(adj[v][i]);
        visited[adj[v][i]]=true;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;

    struct tickets t[n];

    string s1,s2;
    map<string,ll> num;
    ll k=1;
    fr(i,0,n){
      cin>>s1;
      is_source[k]=true;
      if(num[s1]==0){
        t[i].start=k;
        name[k]=s1;
        is_source[k]=true;
        num[s1]=k++;
      }
      else{
        t[i].start=num[s1];
        name[num[s1]]=s1;
        is_source[num[s1]]=true;
      }
      cin>>s2;
      if(num[s2]==0){
        t[i].end=k;
        name[k]=s2;
        is_source[k]=false;
        num[s2]=k++;
      }
      else{
        t[i].end=num[s2];
        name[num[s2]]=s2;
        is_source[num[s2]]=false;
      }
    }

    vector<ll> adj[k];

    fr(i,0,n){
      adj[t[i].start].PB(t[i].end);
      adj[t[i].end].PB(t[i].start);
    }

    ll num_adj[k];
    ll source;
    fr(i,1,k){
      num_adj[i]=adj[i].size();
      if(is_source[i]==true && num_adj[i]==1) source=i;
    }

    dfs(adj,num_adj,k,source);

    cout<<"\n";
  }

  return 0;
}
