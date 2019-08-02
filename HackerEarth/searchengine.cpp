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
#define N 26
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

struct Trie{
  struct Trie *child[N]; // reference to a to z alphabets(N=26)
  ll val[N]; // weight val for each alphabet
  bool is_EOW; // flag for indicating end of word or not
};

struct Trie *get_node(){
  struct Trie *ptr = new Trie;

  ptr->is_EOW=false;

  fr(i,0,N){
    ptr->child[i]=NULL;
    ptr->val[i]=0;
  }

  return ptr;
}

void insert(struct Trie *root,string word,ll weight){
  struct Trie *ptr=root;

  ll pos;
  fr(i,0,word.size()){
    pos=word[i]-'a';
    if(ptr->child[pos]==NULL) ptr->child[pos]=get_node();
    ptr->val[pos]=max(ptr->val[pos],weight);
    ptr=ptr->child[pos];
  }

  ptr->is_EOW=true;
}

ll search(struct Trie *root,string word){
  ll ans;
  struct Trie *ptr=root;

  ll pos;
  fr(i,0,word.size()){
    pos=word[i]-'a';
    if(ptr->child[pos]==NULL) return -1;
    ans=ptr->val[pos];
    ptr=ptr->child[pos];
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,q,w;
  string x;
  cin>>n>>q;
  struct Trie *root=get_node();
  fr(i,0,n){
    cin>>x>>w;
    insert(root,x,w);
  }
  fr(i,0,q){
    cin>>x;
    cout<<search(root,x)<<"\n";
  }

  return 0;
}
