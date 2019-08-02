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
#define N 8
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

char b[N][N];

bool valid(ll r,ll c){
  if(r<N && r>=0 && c<N && c>=0) return true;
  else return false;
}

bool queen_promotion(ll c){
  ll i,j;

  // checking horizontally left
  rf(j,c-1,-1){
    if(b[0][j]=='#') continue;
    else if(b[0][j]=='k') return true;
    else break;
  }

  // checking horizontally right
  fr(j,c+1,N){
    if(b[0][j]=='#') continue;
    else if(b[0][j]=='k') return true;
    else break;
  }

  // checking vertically down
  i=2;
  while(i<N){
    if(b[i][c]=='k') return true;
    else if(b[i][c]!='#') break;
    else {}
    i++;
  }

  // checking lower left diagonal
  i=1;
  j=c-1;
  while(i<N && j>=0){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i++;
    j--;
  }

  // checking lower right diagonal
  i=1;
  j=c+1;
  while(i<N && j<N){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i++;
    j++;
  }

  return false;
}

bool bishop_promotion(ll c){
  ll i,j;

  // checking lower left diagonal
  i=1;
  j=c-1;
  while(i<N && j>=0){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i++;
    j--;
  }

  // checking lower right diagonal
  i=1;
  j=c+1;
  while(i<N && j<N){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i++;
    j++;
  }

  return false;
}

bool rook_promotion(ll c){
  ll i,j;

  // checking horizontally left
  rf(j,c-1,-1){
    if(b[0][j]=='#') continue;
    else if(b[0][j]=='k') return true;
    else break;
  }

  // checking horizontally right
  fr(j,c+1,N){
    if(b[0][j]=='#') continue;
    else if(b[0][j]=='k') return true;
    else break;
  }

  // checking vertically down
  i=2;
  while(i<N){
    if(b[i][c]=='k') return true;
    else if(b[i][c]!='#') break;
    else {}
    i++;
  }

  return false;
}

bool knight_promotion(ll c){
  if(valid(1,c-2) && b[1][c-2]=='k') return true;
  if(valid(1,c+2) && b[1][c+2]=='k') return true;
  if(valid(2,c-1) && b[2][c-1]=='k') return true;
  if(valid(2,c+1) && b[2][c+1]=='k') return true;

  return false;
}

// Normal Moves

bool queen_move(ll r,ll c){
  ll i,j;

  // checking horizontally left
  rf(j,c-1,-1){
    if(b[r][j]=='#') continue;
    else if(b[r][j]=='k') return true;
    else break;
  }

  // checking horizontally right
  fr(j,c+1,N){
    if(b[r][j]=='#') continue;
    else if(b[r][j]=='k') return true;
    else break;
  }

  // checking vertically down
  i=r+1;
  while(i<N){
    if(b[i][c]=='k') return true;
    else if(b[i][c]!='#') break;
    else {}
    i++;
  }

  // checking vertically up
  i=r-1;
  while(i>=0){
    if(b[i][c]=='k') return true;
    else if(b[i][c]!='#') break;
    else {}
    i--;
  }

  // checking lower left diagonal
  i=r+1;
  j=c-1;
  while(i<N && j>=0){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i++;
    j--;
  }

  // checking lower right diagonal
  i=r+1;
  j=c+1;
  while(i<N && j<N){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i++;
    j++;
  }

  // checking upper left diagonal
  i=r-1;
  j=c-1;
  while(i>=0 && j>=0){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i--;
    j--;
  }

  // checking upper right diagonal
  i=r-1;
  j=c+1;
  while(i>=0 && j<N){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i--;
    j++;
  }

  return false;
}

bool rook_move(ll r,ll c){
  ll i,j;

  // checking horizontally left
  rf(j,c-1,-1){
    if(b[r][j]=='#') continue;
    else if(b[r][j]=='k') return true;
    else break;
  }

  // checking horizontally right
  fr(j,c+1,N){
    if(b[r][j]=='#') continue;
    else if(b[r][j]=='k') return true;
    else break;
  }

  // checking vertically down
  i=r+1;
  while(i<N){
    if(b[i][c]=='k') return true;
    else if(b[i][c]!='#') break;
    else {}
    i++;
  }

  // checking vertically up
  i=r-1;
  while(i>=0){
    if(b[i][c]=='k') return true;
    else if(b[i][c]!='#') break;
    else {}
    i--;
  }

  return false;
}

bool bishop_move(ll r,ll c){
  ll i,j;
  // checking lower left diagonal
  i=r+1;
  j=c-1;
  while(i<N && j>=0){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i++;
    j--;
  }

  // checking lower right diagonal
  i=r+1;
  j=c+1;
  while(i<N && j<N){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i++;
    j++;
  }

  // checking upper left diagonal
  i=r-1;
  j=c-1;
  while(i>=0 && j>=0){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i--;
    j--;
  }

  // checking upper right diagonal
  i=r-1;
  j=c+1;
  while(i>=0 && j<N){
    if(b[i][j]=='k') return true;
    else if(b[i][j]!='#') break;
    else {}
    i--;
    j++;
  }

  return false;
}

bool knight_move(ll r,ll c){
  if(valid(r+1,c-2) && b[r+1][c-2]=='k') return true;
  if(valid(r+1,c+2) && b[r+1][c+2]=='k') return true;
  if(valid(r-1,c-2) && b[r-1][c-2]=='k') return true;
  if(valid(r-1,c+2) && b[r-1][c+2]=='k') return true;
  if(valid(r+2,c-1) && b[r+2][c-1]=='k') return true;
  if(valid(r+2,c+1) && b[r+2][c+1]=='k') return true;
  if(valid(r-2,c-1) && b[r-2][c-1]=='k') return true;
  if(valid(r-2,c+1) && b[r-2][c+1]=='k') return true;

  return false;
}

bool king_move(ll r,ll c){
  if(valid(r-1,c-1) && b[r-1][c-1]=='k') return true;
  if(valid(r+1,c+1) && b[r+1][c+1]=='k') return true;
  if(valid(r-1,c+1) && b[r-1][c+1]=='k') return true;
  if(valid(r+1,c-1) && b[r+1][c-1]=='k') return true;
  if(valid(r,c-1) && b[r][c-1]=='k') return true;
  if(valid(r,c+1) && b[r][c+1]=='k') return true;
  if(valid(r+1,c) && b[r+1][c]=='k') return true;
  if(valid(r-1,c) && b[r-1][c]=='k') return true;

  return false;
}

bool discover_check(ll r,ll c){
  ll cnt=0;

  char tmp=b[r][c];
  b[r][c]='#';

  fr(i,0,N){
    fr(j,0,N){
      if(b[i][j]=='Q' && queen_move(i,j)) cnt++;
      if(b[i][j]=='R' && rook_move(i,j)) cnt++;
      if(b[i][j]=='N' && knight_move(i,j)) cnt++;
      if(b[i][j]=='B' && bishop_move(i,j)) cnt++;
      if(b[i][j]=='K' && king_move(i,j)) cnt++;
    }
  }

  b[r][c]=tmp;

  return cnt;
}

ll solve(){
  ll ans=0;

  fr(c,0,N){
    if(b[1][c]=='P'){
      //if(b[0][c]=='k') ans++;
      if(b[0][c]=='#'){
        ans+=discover_check(1,c);
        if(ans) return 4;
      }
      if(b[0][c]=='#' && queen_promotion(c)) ans++;
      if(b[0][c]=='#' && rook_promotion(c)) ans++;
      if(b[0][c]=='#' && bishop_promotion(c)) ans++;
      if(b[0][c]=='#' && knight_promotion(c)) ans++;
    }
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  while(t--){
    fr(r,0,N){
      fr(c,0,N){
        cin>>b[r][c];
      }
    }
    cout<<solve()<<"\n";
  }

  return 0;
}
