#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

ll n,c;

bool fn(ll dist,ll a[]){
  ll last_pos=a[0],cnt=1;
  fr(1,n){
    if(a[i]-last_pos>=dist){
      cnt++;
      if(cnt==c) return true;
      last_pos=a[i];
    }
  }
  return false;
}

ll bs(ll a[]){
  ll md=0,l=a[0],r=a[n-1],mid;

  while(l<r){
    mid=(l+r)/2;
    if(fn(mid,a)){
      md=max(md,mid);
      l=mid+1;
    }
    else r=mid;
  }

  return md;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>n>>c;
    ll a[n];
    fr(0,n) cin>>a[i];
    sort(a,a+n);
    cout<<bs(a)<<"\n";
  }

  return 0;
}
