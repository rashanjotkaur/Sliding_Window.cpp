// Method 1-Using doubly ended queue
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
void findMaximum(ll arr[],ll n,ll k){
    deque <ll> dq;
    for(ll i=0;i<k;i++){
        while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for(ll i=k;i<n;i++){
        cout<<arr[dq.front()]<<" ";
        while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
        while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
}
int main(){
	ll t;
	cin>>t;
	while(t--){
	    ll n,k;
	    cin>>n>>k;
	    ll arr[n];
	    for(ll i=0;i<n;i++)
	        cin>>arr[i];
	    findMaximum(arr,n,k);
	    cout<<endl;
	}
	return 0;
}
