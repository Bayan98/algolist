ll hashPowArray[M] = {1}, hashPowArray2[M] = {1};
const ll pw = 31, mod = (int)1e9 + 9, pw2 = 103, mod2 = (int)1e9+21;
inline const ll hashPow(const int n, const bool first = 1){
    if(first){
        for(static int i=1; i<=n; i++){
            hashPowArray[i] = (hashPowArray[i-1] * pw) % mod;
        }
        return hashPowArray[n];
    }
    else{
        for(static int j=1; j<=n; j++){
            hashPowArray2[j] = (hashPowArray2[j-1] * pw2) % mod2;
        }
        return hashPowArray2[n];
    }
}
//template <size_t N>
struct Hash{
    long long h[N + 5], h2[N + 5];
    int sz;
    void build(const string &s){
        sz = (int)s.size();
        h[0] = s[0];
        for(int i=1; i<s.size(); i++){
            h[i] = (h[i-1] * 1ll * pw + s[i]) % mod;
        }
        h2[0] = s[0];
        for(int i=1; i<s.size(); i++){
            h2[i] = (h2[i-1] * 1ll * pw2 + s[i]) % mod2;
        }
    }
    Hash(string s = ""){
        if(s.size()) build(s);
    }
    inline const int size() const {
        return sz;
    }
    ll get(const int l, const int r, const bool first = 1){
        if(first){
            if(l > r) return 0;
            return l ? ((h[r] - h[l-1] * hashPow(r-l+1)) % mod + mod) % mod : h[r];
        }
        else{
            if(l > r) return 0;
            return l ? ((h2[r] - h2[l-1] * hashPow(r-l+1, 0)) % mod2 + mod2) % mod2 : h2[r];
        }
    }
};
inline const ll mergeHash(const ll h1, const ll h2, const ll pw2, const bool first = 1) {
    if(!first) return (h1 * pw2 % mod2 + h2) % mod2;
    return (h1 * pw2 % mod + h2) % mod;
}
