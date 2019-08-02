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

ll cnt=0;

ll n;
string s;

char board[8][8];
bool visited[8][8];

vector<pair<ll,ll> > start_pos; // This will store all starting positions for tours

ll move_x[8]={0,0,-1,+1,+1,-1,+1,-1};
ll move_y[8]={-1,+1,0,0,+1,-1,-1,+1};

void initialize(ll p,ll q){
  fr(i,0,8) fr(j,0,8) {
    if(i==p && j==q) visited[i][j]=true;
    else visited[i][j]=false;
  }
}

bool validity_check(ll x,ll y,ll len){
  if(board[x][y]!=s[len]) return false;
  if(x<0 || y<0) return false;
  if(x>=8 || y>=8) return false;
  if(visited[x][y]) return false;
  return true;
}

bool solve(ll x,ll y,ll len){
  if(len==n-1 && board[x][y]==s[len]){
    cnt++;
    return true;
  }

  len++;
  ll next_x,next_y;
  fr(i,0,8){
    next_x=x+move_x[i];
    next_y=y+move_y[i];
    if(validity_check(next_x,next_y,len)==true){
      visited[next_x][next_y]=true;

      solve(next_x,next_y,len);

      visited[next_x][next_y]=false; // backtracking
    }
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;

  cin>>s;

  string line;
  fr(i,0,8){
    cin>>line;
    fr(j,0,line.size()){
      board[i][j]=line[j];
      if(board[i][j]==s[0]) start_pos.PB(MP(i,j));
    }
  }

  fr(i,0,start_pos.size()){
    initialize(start_pos[i].first,start_pos[i].second); // O(64) <- time complexity
    solve(start_pos[i].first,start_pos[i].second,0);
  }

  cout<<cnt;

  return 0;
}
