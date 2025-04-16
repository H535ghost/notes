#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
long long ex(string a)
{
    if (a == "b")
        return 1 * 1LL;
    if (a == "B")
        return 8 * 1LL;
    if (a =="Kib")
        return 1024 * 1LL;
    if (a == "KiB")
        return 1024 * 8 * 1LL;
    if (a == "Kb")
        return 1000 * 1LL;
    if (a == "KB")
        return 1000 * 8 * 1LL;
    if (a == "Mb")
        return 1000 * 1000 * 1LL;
    if (a == "MB")
        return 1000 * 1000 * 8 * 1LL;
    if (a == "Mib")
        return 1024 * 1024 * 1LL;
    if (a == "MiB")
        return 1LL * 1024 * 1024 * 8;
    if (a == "Gb")
        return 1LL * 1000 * 1000 * 1000;
    if (a == "GB")
        return 1LL * 1000 * 1000 * 1000 * 8;
    if (a == "Gib")
        return 1LL * 1024 * 1024 * 1024;
    if (a == "GiB")
        return 1LL * 1024 * 1024 * 1024 * 8;
    if (a == "Tb")
        return 1LL * 1000 * 1000 * 1000 * 1000;
    if (a == "Tib")
        return 1LL * 1024 * 1024 * 1024 * 1024;
    if (a == "TB")
        return 1LL * 1000 * 1000 * 1000 * 1000 * 8;
    if (a == "TiB")
        return 1LL * 1024 * 1024 * 1024 * 1024 * 8;
    return 0;
}
char com(vi a,vi b){
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]<b[i]) return 'T';
        if(a[i]>b[i]) return 'L';
    }
    return '=';
}
vi cl(vi &ans){
    for(int i=0;i<ans.size();i++){
        ans[i]=0;
    }
    return ans;
}
vi muti(ll k,vi ans){
    for(int i=0;i<25;i++){
        ans[i]=ans[i]*k;
        if(i>=1){
            ans[i]+=ans[i-1]/10;
            ans[i-1]=ans[i-1]%10;
        }
    }
    return ans;
}
vi add(vi u,vi v){
    for(int i=0;i<u.size();i++){
        u[i]+=v[i];
        if(i>=1){
            u[i]+=u[i-1]/10;
            u[i-1]=u[i-1]%10;
        }
    }
    return u;
}
vi solu(string a,vi ans){
    string x;
    vi k(25,0);
    vi p;

    for(int i=0;i<a.size();i++){
        if('0'<=a[i]&&a[i]<='9') {p.push_back(a[i]-'0');}
        else{
            if(a[i]=='+') {
            for(int i=p.size()-1;i>=0;i--){
                k[p.size()-1-i]=p[i];
            }
            k=muti(ex(x),k);ans=add(ans,k);
          
            x.clear();p.clear();cl(k);
            }
            else{x.push_back(a[i]);}
        }   
    }
    for(int i=p.size()-1;i>=0;i--){
        k[p.size()-1-i]=p[i];
    }
    k=muti(ex(x),k);
    ans=add(ans,k);
    return ans;
}
int main()
{
    ll n;
    string a,b;
    vi u(25,0),v(25,0);
    cin>>n;
    while(n){
        cin>>a>>b;
        cl(u);cl(v);
        u=solu(a,u);
        v=solu(b,v);
        cout<<com(u,v)<<"\n";
        n--;
    }
}