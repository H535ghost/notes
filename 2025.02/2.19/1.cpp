#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int main()
{
    int y = 2000, m = 1, d = 0;
    int k = 0;
    long long ans=0,p=0,q=0;
    map<int, int> a;
    a[0] = 13;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 5;
    a[5] = 4;
    a[6] = 4;
    a[7] = 2;
    a[7] = 2;
    a[8] = 2;
    a[9] = 2;
    while (1)
    {   
        d++;
        if (y % 4 == 0 || y == 2000)
            k = 1;
        if (m == 2)
        {
            if (k)
            {
                if (d == 30)
                    {m++;d=1;}
            }
            else{
                if(d==29) {m++;d=1;}
            }
        }
        if((m<=7&&m%2==1)||(m>=8&&m%2==0)){
            if(d==32) {m++;d=1;}
        }
        else{
            if(d==31) {m++;d=1;}
        }
        if(m==13) {y++;m=1;}
        p=0;
        q=y;
        while(q>0){
            p+=a[q%10];
            q=q/10;
        }
        q=m;
        if(q>=10){
            while(q>0){
                p+=a[q%10];
                q=q/10;
            }
        }
        else{
            p+=a[q]+13;
        }
        q=d;
        if(q>=10){
        while(q>0){
            p+=a[q%10];
            q=q/10;
            }
        }
        else{
            p+=a[q]+13;
        }
        if(p>50) ans++;
        if(y==2024&&m==4&&d==13) break;
    }
    cout<<ans;
}