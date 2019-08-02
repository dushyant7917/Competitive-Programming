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
#define N 10000
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll prime[N];
ll visited[N];
ll digit[10]={0,1,2,3,4,5,6,7,8,9};

void sieve(){
  fr(i,0,N) prime[i]=1;

  for(ll i=2;i*i<=N;i++){
    if(prime[i]==1){
      for(ll j=i*2;j<=N;j+=i){
        prime[j]=0;
      }
    }
  }

  prime[0]=prime[1]=0;
}

ll bfs(ll src,ll dst){
  visited[src]=1;
  queue<pair<ll,ll> > q;
  q.push(MP(src,0));

  ll node,dist,zero,ten,hundred,thousand,num;
  while(q.size()>0){
    node=q.front().first;
    dist=q.front().second;
    q.pop();
    visited[node]=1;

    if(node==dst) return dist;

    zero=(node/1)%10;
    ten=(node/10)%10;
    hundred=(node/100)%10;
    thousand=(node/1000)%10;

    // replacing zeroth digit
    fr(i,0,10){
      num=(thousand*1000)+(hundred*100)+(ten*10)+(digit[i]);
      if(visited[num]==0 && prime[num]==1) q.push(MP(num,dist+1));
    }

    // replacing tens digit
    fr(i,0,10){
      num=(thousand*1000)+(hundred*100)+(digit[i]*10)+(zero);
      if(visited[num]==0 && prime[num]==1) q.push(MP(num,dist+1));
    }

    // replacing hundreds digit
    fr(i,0,10){
      num=(thousand*1000)+(digit[i]*100)+(ten*10)+(zero);
      if(visited[num]==0 && prime[num]==1) q.push(MP(num,dist+1));
    }

    // replacing thousandth digit
    fr(i,1,10){
      num=(digit[i]*1000)+(hundred*100)+(ten*10)+(zero);
      if(visited[num]==0 && prime[num]==1) q.push(MP(num,dist+1));
    }
  }

  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  sieve();

  ll a,b,dist;
  while(t--){
    cin>>a>>b;

    fr(i,1000,N) visited[i]=0;
    dist=bfs(a,b);

    if(dist==-1) cout<<"Impossible\n";
    else cout<<dist<<"\n";
  }

  return 0;
}
