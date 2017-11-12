ll binpow(ll a, ll b){
    ll res = 1;
    while (b > 0){
        if (b & 1) res = res * a % INF;
        a = a * a % INF;
        b >>= 1;
    }
    return res;
}

ll factorial[N] = {1};
inline ll fact (const int &x){
    for(static int i = 1; i <= x; i++)
        factorial[i] = factorial[i-1] * i % INF;
    return factorial[x];
}

ll cnk(const int &n, const int &k){
    if(k > n) return 0;
    return fact(n) * binpow(fact(n - k) * fact(k) % INF, INF - 2) % INF;
}
