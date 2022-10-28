const ll mod = 1000000007;
void helper(){
        
        ll n,m;
        cin>>n>>m;
 
        vector<ll> dp(1e5+2,1);
 
        for(ll i = 1;i<=1e5;i++){
 
            dp[i] = dp[i-1];
            if(i>=m) dp[i] = (dp[i] + dp[i-m]);
 
            dp[i]%=mod; 
        }
 
        vector<ll> sum(1e5+2,0);
 
        for(ll i = 1;i<=1e5;i++) {  
            sum[i] = (sum[i-1] + dp[i]);
            sum[i] %= mod;
        }
        while(n--){
 
            ll a,b;
            cin>>a>>b;
 
            cout<<((sum[b]+mod) -sum[a-1])%mod;
            cout<<'\n';
        } 
        return ;
}
