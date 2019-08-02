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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n;
ll tree[2*N][2];

void build(ll a[]){
  fr(i,n,2*n){
    tree[i][0]=a[i-n];
    tree[i][1]=i-n;
  }

  for(ll i=n-1;i>=1;i--){
    tree[i][0]=min(tree[i*2][0],tree[(i*2)+1][0]);

    if(tree[i*2][0]<tree[(i*2)+1][0]) tree[i][1]=tree[i*2][1];
    else tree[i][1]=tree[(i*2)+1][1];
  }
}

ll range_min_query(ll left,ll right){
  ll min_val=INF;
  ll min_ind=INF;
  left+=n;
  right+=n;

  while(left<right){
    if(left%2==1){
      if(tree[left][0]<=min_val){
        min_ind=tree[left][1];
        min_val=tree[left][0];
      }
      left++;
    }
    if(right%2==1){
      right--;
      if(tree[right][0]<=min_val){
        min_ind=tree[right][1];
        min_val=tree[right][0];
      }
    }
    left=left/2;
    right=right/2;
  }

  return min_ind;
}

ll solve(ll a[],ll l,ll r){
  if(r<=-1 || r<l) return -INF;
  if(l>=n || l>r) return -INF;
  if(l==r) return a[l];

  ll mid=range_min_query(l,r+1);
  ll left_val=solve(a,0,mid-1);
  ll right_val=solve(a,mid+1,r);

  return MAX(left_val,a[mid]*(r-l+1),right_val);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(cin>>n && n!=0){
    ll a[n];
    fr(i,0,n) cin>>a[i];

    build(a);

    cout<<solve(a,0,n-1)<<"\n";
  }

  return 0;
}
