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

struct Trie{
  struct Trie *child[26]; // reference to a to z alphabets(N=26)
  bool is_EOW; // flag for indicating end of word or not
};

Trie* get_node(){
  Trie* ptr = new Trie;

  ptr->is_EOW=false;

  fr(i,0,26) ptr->child[i]=NULL;

  return ptr;
}

// inserts a word in the trie data structure
void insert(Trie*& root,string word){
  if(root==NULL) root=get_node();

  Trie* ptr=root;

  ll pos;
  fr(i,0,word.size()){
    pos=word[i]-'a';
    if(ptr->child[pos]==NULL) ptr->child[pos]=get_node();
    ptr=ptr->child[pos];
  }

  ptr->is_EOW=true;
}

string solve(Trie* root,string s){
  string res="";
  Trie* ptr=root;

  ll pos;
  fr(i,0,SZ(s)){
    pos=s[i]-'a';
    if(ptr->child[pos]==NULL) break;
    res+=s[i];
    ptr=ptr->child[pos];
  }

  while(ptr->is_EOW==false){
    fr(i,0,26){
      if(ptr->child[i]!=NULL){
        res+=(i+'a');
        ptr=ptr->child[i];
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

  Trie* root=NULL;

  ll ind=0;
  fr(i,0,m){
    while(ind+1<=q[i].r){
      insert(root,words[ind]);
      ind++;
    }
    q[i].ans=solve(root,q[i].s);
  }

  sort(q,q+m,cmpInd);
  fr(i,0,m) cout<<q[i].ans<<"\n";

  return 0;
}
