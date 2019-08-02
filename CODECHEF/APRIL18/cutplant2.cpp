#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,a[N],b[N];
ll treeA[4*N],treeB[4*N];

struct Plant{
  ll a,b,ind;
};

bool cmp(Plant p1,Plant p2){
  if(p1.b==p2.b) return p1.ind<p2.ind;
  else return p1.b<p2.b;
}

void build(ll node,ll start,ll end){
  if(start==end){ // leaf node
    treeA[node]=a[start]; // or tree[node]=a[end] is also correct
    treeB[node]=b[start];
  }
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid); // recursion on left child
    build(node*2+1,mid+1,end); // recursion on right child
    treeA[node]=min(treeA[node*2],treeA[node*2+1]); // internal(parent) node values are calculated
    treeB[node]=max(treeB[node*2],treeB[node*2+1]);
  }
}

ll queryA(ll node,ll start,ll end,ll left,ll right){
  if(right<start || end<left){ // node range is completely outside the query range
    return INF;
  }
  if(left<=start && end<=right){ // node range is completely inside query range
    return treeA[node];
  }
  ll mid=(start+end)/2;
  ll s1=queryA(node*2,start,mid,left,right);
  ll s2=queryA(node*2+1,mid+1,end,left,right);
  return min(s1,s2);
}

ll queryB(ll node,ll start,ll end,ll left,ll right){
  if(right<start || end<left){ // node range is completely outside the query range
    return -INF;
  }
  if(left<=start && end<=right){ // node range is completely inside query range
    return treeB[node];
  }
  ll mid=(start+end)/2;
  ll s1=queryB(node*2,start,mid,left,right);
  ll s2=queryB(node*2+1,mid+1,end,left,right);
  return max(s1,s2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll ans,prv,ind;
  bool flag;

  while(t--){
    cin>>n;
    fr(i,0,n) cin>>a[i];
    fr(i,0,n) cin>>b[i];

    flag=false;

    fr(i,0,n){
      if(a[i]<b[i]){
        flag=true;
        break;
      }
    }

    if(flag){
      cout<<-1<<"\n";
      continue;
    }

    build(1,0,n-1);

    ans=0;
    vector<Plant> p;

    fr(i,0,n) p.PB({a[i],b[i],i});

    sort(p.begin(),p.end(),cmp);

    prv=-1;
    ind=-1;

    fr(i,0,n){
      if(p[i].a==p[i].b) continue;

      if(prv==-1 || p[i].b!=prv){
        ans++;
        prv=p[i].b;
        ind=p[i].ind;
      }
      else if(p[i].b==prv){
        if(queryA(1,0,n-1,ind,p[i].ind)<prv || queryB(1,0,n-1,ind,p[i].ind)>prv){
          ans++;
          prv=p[i].b;
          ind=p[i].ind;
        }
      }
      else {}
    }

    cout<<ans<<"\n";
  }

  return 0;
}
