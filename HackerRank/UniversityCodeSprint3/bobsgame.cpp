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

ll n;
bool visited[1000][1000];

void initialize(){
  fr(i,0,n) fr(j,0,n) visited[i][j]=false;
}

bool move(char board[1000][1000],ll x,ll y){
  if()
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>n;
    char board[n][n];

    vector< pair<ll,ll> > king_pos;

    fr(i,0,n)
      fr(j,0,n){
        cin>>board[i][j];
        if(board[i][j]=='K') king_pos.PB(MP(i,j));
      }

    initialize();
    ll cnt=0;
    fr(i,0,king_pos.size()){
      if(move(board,king_pos[i].first,king_pos[i].second)) cnt++;
    }
    if(cnt>0) cout<<"WIN "<<cnt<<"\n";
    else cout<<"LOSE\n";
  }

  return 0;
}
