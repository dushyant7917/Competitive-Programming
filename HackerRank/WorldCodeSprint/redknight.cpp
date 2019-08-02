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
#define N 201
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n,is,js,ie,je;
ll nx[6]={-2,-2,0,2,2,0};
ll ny[6]={-1,1,2,1,-1,-2};
ll len[6]={1,2,3,4,5,6};
string mov[6]={"UL","UR","R","LR","LL","L"};
ll visited[N][N],dist[N][N];
pair<ll,ll> parent[N][N];
vector<string> moves;

bool valid(ll r,ll c){
  if(r<0 || c<0) return false;
  if(r>=n || c>=n) return false;
  if(visited[r][c]==1) return false;
  return true;
}

string move(ll x,ll y,ll px,ll py){
  if(x-px==-2 && y-py==-1) return "UL";
  if(x-px==-2 && y-py==1) return "UR";
  if(x-px==2 && y-py==-1) return "LL";
  if(x-px==2 && y-py==1) return "LR";
  if(x-px==0 && y-py==-2) return "L";
  if(x-px==0 && y-py==2) return "R";
  else return "";
}

void path(ll x,ll y){
  if(parent[x][y].first==-1 && parent[x][y].second==-1) return;
  path(parent[x][y].first,parent[x][y].second);
  moves.PB(move(x,y,parent[x][y].first,parent[x][y].second));
}

void dijkstras(ll x,ll y){
  fr(i,0,n){
    fr(j,0,n) {
      visited[i][j]=0;
      dist[i][j]=INF;
    }
  }

  dist[is][js]=0;
  parent[is][js]=MP(-1,-1);

  multiset<pair<ll,pair<ll,ll> > > mpq;
  mpq.insert(MP(0,MP(x,y)));

  pair<ll,pair<ll,ll> > p;
  pair<ll,ll> current_node,neighbour_node;
  ll edge_weight;
  while(!mpq.empty()){
    p=(*mpq.begin());
    mpq.erase(mpq.begin());
    current_node=p.second;
    if(visited[current_node.first][current_node.second]==false){
      visited[current_node.first][current_node.second]=true;
      for(ll i=5;i>=0;i--){
        neighbour_node=MP(current_node.first+nx[i],current_node.second+ny[i]);
        edge_weight=len[i];
        if(dist[current_node.first][current_node.second]+edge_weight<dist[neighbour_node.first][neighbour_node.second]){
          dist[neighbour_node.first][neighbour_node.second]=dist[current_node.first][current_node.second]+edge_weight;
          mpq.insert(MP(dist[neighbour_node.first][neighbour_node.second],MP(neighbour_node.first,neighbour_node.second)));
          parent[neighbour_node.first][neighbour_node.second]=MP(current_node.first,current_node.second);
        }
      }
    }
  }

  if(dist[ie][je]==INF) cout<<"Impossible";
  else{
    path(ie,je);
    cout<<moves.size()<<"\n";
    fr(i,0,moves.size()) cout<<moves[i]<<" ";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  cin>>is>>js>>ie>>je;

  dijkstras(is,js);

  return 0;
}
