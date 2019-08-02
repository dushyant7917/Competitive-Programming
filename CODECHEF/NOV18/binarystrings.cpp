#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define INF 2e9
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

struct Trie {
    struct Trie *child[2]; // reference to 0 or 1 digit
    struct Trie *nxt; // used for trie compression
    vector<ll> indices; // stores indices
    ll depth; // depth of node
};

Trie* getNode() {
    Trie* ptr=new Trie;

    ptr->child[0]=NULL;
    ptr->child[1]=NULL;
    ptr->nxt=NULL;
    ptr->depth=0;

    return ptr;
}

map<ll,Trie*> mp;

void pre_process(Trie*& root,ll mx) {
    Trie* ptr=root;
    mp[0]=ptr;

    fr(i,1,mx+1) {
        ptr->child[0]=getNode();
        ptr=ptr->child[0];
        mp[i]=ptr;
    }
}

void insert(string word,ll pad,ll ind) {
    Trie* ptr=mp[pad];
    ll pos;

    fr(i,0,SZ(word)){
        pos=word[i]-'0';
        if(ptr->child[pos]==NULL) ptr->child[pos]=getNode();
        ptr=ptr->child[pos];
    }

    ptr->indices.PB(ind);
}

void compress(Trie* root){
    if(root->child[0]==NULL && root->child[1]==NULL) {
        root->nxt=root;
        return;
    }

    if(root->child[0]) {
        root->child[0]->depth=root->depth+1;
        compress(root->child[0]);
    }

    if(root->child[1]) {
        root->child[1]->depth=root->depth+1;
        compress(root->child[1]);
    }

    if(root->child[0]==NULL || SZ(root->child[0]->nxt->indices)==0) {
        root->child[0]=NULL;

        if(root->child[1]==NULL) {
            root->child[1]=NULL;
            root->nxt=root;
            return;
        }

        root->nxt=root->child[1]->nxt;
        return;
    }

    if(root->child[1]==NULL) {
        root->nxt=root->child[0]->nxt;
        return;
    }

    root->indices.assign(SZ(root->child[0]->nxt->indices)+SZ(root->child[1]->nxt->indices),-1);
    merge(root->child[0]->nxt->indices.begin(),root->child[0]->nxt->indices.end(),root->child[1]->nxt->indices.begin(),root->child[1]->nxt->indices.end(),root->indices.begin());
    root->nxt=root;
}

ll query(Trie* root,string word,ll l,ll r,ll pad){
    Trie* ptr=root;
    ll pos,ind;

    while(true) {
        if(ptr->child[0]==NULL && ptr->child[1]==NULL) break;

        if(ptr->depth<pad) pos=1;
        else pos=1-(word[ptr->depth-pad]-'0');

        if(ptr->child[pos]==NULL) ptr=ptr->child[1-pos]->nxt;
        else {
            ind=lower_bound(ptr->child[pos]->nxt->indices.begin(),ptr->child[pos]->nxt->indices.end(),l)-ptr->child[pos]->nxt->indices.begin();
            if(ptr->child[pos]->nxt->indices[ind]>r || ind>=SZ(ptr->child[pos]->nxt->indices)) ptr=ptr->child[1-pos]->nxt;
            else ptr=ptr->child[pos]->nxt;
        }
    }

    ind=lower_bound(ptr->indices.begin(),ptr->indices.end(),l)-ptr->indices.begin();
    return ptr->indices[ind];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,q;
    cin>>n>>q;

    string a[n];
    ll mx=0;

    fr(i,0,n){
        cin>>a[i];
        mx=max(mx,SZ(a[i]));
    }

    Trie* root=getNode();

    pre_process(root,mx);

    fr(i,0,n) insert(a[i],mx-SZ(a[i]),i+1);

    compress(root);

    ll l,r;
    string x,s;
    fr(i,0,q){
        cin>>l>>r>>x;
        s="";
        if(SZ(x)>mx) fr(i,SZ(x)-mx,SZ(x)) s+=x[i];
        else fr(i,0,SZ(x)) s+=x[i];
        cout<<query(root,s,l,r,mx-SZ(s))<<"\n";
    }

    return 0;
}
