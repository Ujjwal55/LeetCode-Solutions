// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends


pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> p;
    p.first = INT_MAX;
    p.second = INT_MIN;
    
    for(long long i = 0 ; i < n ; i++){
        if(a[i] < p.first) p.first = a[i];
        if(a[i] > p.second) p.second = a[i];
    }
    return p;
    
}