#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll node=0;

struct Trie{
  ll child[26]; // reference to a to z alphabets(N=26)
  bool is_EOW; // flag for indicating end of word or not

  Trie(){
    fr(i,0,26) child[i]=-1;
    is_EOW=false;
  }
}trie[1<<20];

// inserts a word in the trie data structure
void insert(string word){
  ll ptr=0,pos;

  fr(i,0,SZ(word)){
    pos=word[i]-'a';
    if(trie[ptr].child[pos]==-1) trie[ptr].child[pos]=++node;
    ptr=trie[ptr].child[pos];
  }

  trie[ptr].is_EOW=true;
}

string solve(string s){
  string res="";
  ll ptr=0,pos;

  fr(i,0,SZ(s)){
    pos=s[i]-'a';
    if(trie[ptr].child[pos]==-1) break;
    res+=s[i];
    ptr=trie[ptr].child[pos];
  }

  while(trie[ptr].is_EOW==false){
    fr(i,0,26){
      if(trie[ptr].child[i]!=-1){
        res+=(i+'a');
        ptr=trie[ptr].child[i];
        break;
      }
    }
  }
  return res;
}

struct Queries{
  string s,ans;
  ll r,ind;
};

bool cmpR(Queries q1,Queries q2){
  return q1.r<q2.r;
}

bool cmpInd(Queries q1,Queries q2){
  return q1.ind<q2.ind;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;

  cin>>n;
  string words[n];
  fr(i,0,n) cin>>words[i];

  cin>>m;
  Queries q[m];
  fr(i,0,m){
    cin>>q[i].r>>q[i].s;
    q[i].ind=i;
  }

  sort(q,q+m,cmpR);

  ll ind=0;
  fr(i,0,m){
    while(ind+1<=q[i].r){
      insert(words[ind]);
      ind++;
    }
    q[i].ans=solve(q[i].s);
  }

  sort(q,q+m,cmpInd);
  fr(i,0,m) cout<<q[i].ans<<"\n";

  return 0;
}
