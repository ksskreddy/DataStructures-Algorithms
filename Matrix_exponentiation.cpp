#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int MAX = 3000;

struct matrix{
ll a[3000][3000];
int size;
matrix(int sz){
memset(a,0,sizeof(a));
size=sz;
}
matrix operator * (matrix b){
    matrix c = matrix(b.size);
    for (int i=0; i<size; ++i)
        for (int k=0; k<size; ++k)
            for (int j=0; j<size; ++j)
                c.a[i][j]=(c.a[i][j]+ (1LL*a[i][k]*b.a[k][j])%mod)%mod;
    return c;
}
};
matrix unit(int sz){
matrix z=matrix(sz);
for(int i=0; i<sz; ++i)
    z.a[i][i]=1LL;
return z;
}
 
matrix modpow(matrix m,ll n){
  if ( n == 0 )
    return unit(m.size);
  matrix half =modpow(m,n>>1);
  matrix out=half*half;
  if(n&1)
    out=out*m;
  return out;
}

int main() {
    sp;
    int n;
    cin>>n;
    matrix m=matrix(n);
    int b,c;
    for(int i=1;i<n;i++)
    {
        cin>>b>>c;
        b--,c--;
        m.a[b][c]=1;
        m.a[c][b]=1;
    }
    
    ll r,k;
    cin>>r>>k;
    r--;
    matrix prod = modpow(m,k);
    
    for(int i=0;i<n;i++)
        cout<<prod.a[r][i]<<" ";
    cout<<endl;
    
    return 0;
}
