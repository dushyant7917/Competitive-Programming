#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
bool adj[26][26];
bool visited[26];
bool cycle;
bool rec_stack[26];
vector<ll> ans;
ll in_degree[26];

bool cycle_dfs(ll v){
  visited[v]=true;
  rec_stack[v]=true;

  fr(u,0,26){
    if(adj[v][u]){
      if(!visited[u] && cycle_dfs(u)) return true;
      else if(rec_stack[u]) return true;
      else{
        // pass
      }
    }
  }

  rec_stack[v]=false;
  return false;
}

void topological_sort(){
  queue<ll> q;

  fr(i,0,26){
    if(!in_degree[i]){
      q.push(i);
      visited[i]=true;
    }
  }

  ll v;
  while(q.size()){
    v=q.front();
    q.pop();
    ans.PB(v);

    fr(u,0,26){
      if(v!=u && adj[v][u] && !visited[u]){
        in_degree[u]--;
        if(!in_degree[u]){
          q.push(u);
          visited[u]=true;
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  string s[n];
  fr(i,0,n){
    cin>>s[i];
  }


  bool flag=true;
  MS(adj,false);
  bool found;
  MS(in_degree,0);

  fr(i,0,n-1){
    fr(j,i+1,n){

      found=false;
      fr(k,0,min(SZ(s[i]),SZ(s[j]))){
        if(s[i][k]!=s[j][k]){
          if(!adj[s[i][k]-'a'][s[j][k]-'a']) in_degree[s[j][k]-'a']++;
          adj[s[i][k]-'a'][s[j][k]-'a']=true;
          found=true;
          break;
        }
      }

      if(!found && SZ(s[i])>=SZ(s[j])) flag=false;
    }
  }

  if(!flag) cout<<"Impossible";
  else{
    cycle=false;
    MS(visited,false);
    MS(rec_stack,false);
    fr(i,0,26){
      if(!visited[i] && cycle_dfs(i)){
        flag=false;
        break;
      }
    }

    if(!flag) cout<<"Impossible";
    else{
      MS(visited,false);

      topological_sort();

      fr(i,0,SZ(ans)) cout<<(char)(ans[i]+'a');
    }
  }



  return 0;
}
