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
#define INF 2e15
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;

bool cmp(pii p1,pii p2){
	if(p1.fi==p2.fi) return p1.se<p2.se;
	return p1.fi<p2.fi;
}

bool valid(ll r,ll c){
	if(r<1 || r>n || c<1 || c>m) return false;
	return true;
}

ll BS(ll inv[],ll x){
	ll l=0,r=min(n,m),mid,ans=0;

	while(l<=r){
		mid=(l+r)/2;
		if(inv[mid]<=x){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}

	return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

	string s;
	char board[n+1][m+1];

	fr(i,1,n+1){
		cin>>s;
		fr(j,1,m+1){
			board[i][j]=s[j-1];
		}
	}

	// black -> 0
	// white -> 1

	ll rb[n+1][m+1],rw[n+1][m+1],cb[n+1][m+1],cw[n+1][m+1];

	fr(i,0,n+1){
		fr(j,0,m+1){
			if(!i || !j) rb[i][j]=rw[i][j]=cb[i][j]=cw[i][j]=0;
			else{
				rb[i][j]=rb[i][j-1];
				if(j%2==1 && board[i][j]!='0') rb[i][j]++;
				if(j%2==0 && board[i][j]!='1') rb[i][j]++;

				rw[i][j]=rw[i][j-1];
				if(j%2==1 && board[i][j]!='1') rw[i][j]++;
				if(j%2==0 && board[i][j]!='0') rw[i][j]++;

				cb[i][j]=cb[i-1][j];
				if(i%2==1 && board[i][j]!='0') cb[i][j]++;
				if(i%2==0 && board[i][j]!='1') cb[i][j]++;

				cw[i][j]=cw[i-1][j];
				if(i%2==1 && board[i][j]!='1') cw[i][j]++;
				if(i%2==0 && board[i][j]!='0') cw[i][j]++;
			}
		}
	}

	ll dp[2][n+1][m+1][min(n,m)+1];
	ll inv[min(n,m)+1];

	inv[0]=0;
	inv[1]=1;

	fr(i,1,n+1){
		fr(j,1,m+1){
			dp[0][i][j][1]=(board[i][j]=='0')?0:1;
			dp[1][i][j][1]=(board[i][j]=='1')?0:1;
			inv[1]=MIN(inv[1],dp[0][i][j][1],dp[1][i][j][1]);
		}
	}

	fr(i,2,min(n,m)+1) inv[i]=INF;

	fr(k,2,min(n,m)+1){
		fr(i,1,n+1){
			fr(j,1,m+1){
				if(i+k-1>n || j+k-1>m) continue;

				dp[0][i][j][k]=dp[0][i][j][k-1];
				if((i+k-1)%2==i%2){
					if(j&1) dp[0][i][j][k]+=rb[i+k-1][j+k-1]-rb[i+k-1][j-1];
					else dp[0][i][j][k]+=rw[i+k-1][j+k-1]-rw[i+k-1][j-1];
				}
				else{
					if(j&1) dp[0][i][j][k]+=rw[i+k-1][j+k-1]-rw[i+k-1][j-1];
					else dp[0][i][j][k]+=rb[i+k-1][j+k-1]-rb[i+k-1][j-1];
				}
				if((j+k-1)%2==j%2){
					if(i&1) dp[0][i][j][k]+=cb[i+k-1][j+k-1]-cb[i-1][j+k-1];
					else dp[0][i][j][k]+=cw[i+k-1][j+k-1]-cw[i-1][j+k-1];
				}
				else{
					if(i&1) dp[0][i][j][k]+=cw[i+k-1][j+k-1]-cw[i-1][j+k-1];
					else dp[0][i][j][k]+=cb[i+k-1][j+k-1]-cb[i-1][j+k-1];
				}
				if(board[i+k-1][j+k-1]!='0') dp[0][i][j][k]--;

				dp[1][i][j][k]=dp[1][i][j][k-1];
				if((i+k-1)%2==i%2){
					if(j&1) dp[1][i][j][k]+=rw[i+k-1][j+k-1]-rw[i+k-1][j-1];
					else dp[1][i][j][k]+=rb[i+k-1][j+k-1]-rb[i+k-1][j-1];
				}
				else{
					if(j&1) dp[1][i][j][k]+=rb[i+k-1][j+k-1]-rb[i+k-1][j-1];
					else dp[1][i][j][k]+=rw[i+k-1][j+k-1]-rw[i+k-1][j-1];
				}
				if((j+k-1)%2==j%2){
					if(i&1) dp[1][i][j][k]+=cw[i+k-1][j+k-1]-cw[i-1][j+k-1];
					else dp[1][i][j][k]+=cb[i+k-1][j+k-1]-cb[i-1][j+k-1];
				}
				else{
					if(i&1) dp[1][i][j][k]+=cb[i+k-1][j+k-1]-cb[i-1][j+k-1];
					else dp[1][i][j][k]+=cw[i+k-1][j+k-1]-cw[i-1][j+k-1];
				}
				if(board[i+k-1][j+k-1]!='1') dp[1][i][j][k]--;

				inv[k]=MIN(inv[k],dp[0][i][j][k],dp[1][i][j][k]);
			}
		}
	}

	ll q,c;
	cin>>q;
	fr(i,0,q){
		cin>>c;
		cout<<BS(inv,c)<<"\n";
	}

  return 0;
}
