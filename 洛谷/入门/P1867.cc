#include<bits/stdc++.h>
using namespace std;
int n,x,sum;
double blood=10,t;
int main(){
    cin>>n;
    while(n--){
        cin>>t>>x;
        blood=min(blood-t,10.0);
        if(blood<=0) break;
        sum+=x;
    }
    cout<<floor(log(sum+1)/log(2))<<" "<<sum+1-pow(2,floor(log(sum+1)/log(2)));
    return 0;
}
