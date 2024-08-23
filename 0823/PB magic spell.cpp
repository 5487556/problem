#include<bits/stdc++.h>
#define SZ(x) x.size()
#define ALL(x)  x.begin(),x.end()
#define for(i,s,t) for(int i=s;i<t;i++)
#define pb(x)  push_back(x)
#define lys1004  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

string found(vector<int> arr, int num, bool fi){
    int l = 0;
    int r = SZ(arr)-1;
    int mid;
    while(l<=r){
        mid = (l+r)/2;
        if(arr[mid]==num) return to_string(mid);
        else if(arr[mid]>num) r = mid-1;
        else l = mid+1;
    }
    if(fi) return to_string(mid);
    return "臥操";
}

int main(){
    lys1004
    int n;
    cin>>n;
    vector<int> arr(n);
    for(i,0,n){
        cin>>arr[i];
    }
    sort(ALL(arr));
    int m;
    cin>>m;
    for(i,0,m){
        bool fi = false;
        int num;
        cin>>num;
        if(found(arr, num, fi) != "臥操"){
            cout<<num<<"\n";
        }
        else{
            if(num <  arr[0]){
                cout<<"no "<<arr[0];
            }
            else if(num > arr[SZ(arr)-1]){
                cout<<arr[SZ(arr)-1]<<" no";
            }
            else{
                fi = true;
                sort(ALL(arr));
                int x = stoi(found(arr, num, fi));
                cout<<arr[x-1]<<" "<<arr[x];

            }
            cout<<"\n";
        }
    }
}
