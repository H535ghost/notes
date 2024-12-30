#include <iostream>
#include<vector>
using namespace std;
int add(vector<int>& height,int n,int k,int count){
    int sum=0;
    if(0<=n+k&&n+k<=height.size()-1){
    if(height[n]<=height[n+k]) {sum =(height[n+k]-height[n])*count;
    count++;
                     sum=sum+add(height,n+k,k,count);
    return sum;}
    }
     return 0;
}
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),sum=0;
        for(int i=1;i<n-1;i++){
               if(height[i-1]>=height[i]&&height[i]<=height[i+1]){
                if(height[i]!=height[i-1])
                sum=sum+add(height,i,-1,1)+add(height,i+1,1,2)+height[i+1]-height[i-1];
               }
        }
        return sum;
    }
};