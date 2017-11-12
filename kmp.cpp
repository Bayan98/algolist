inline void kmp(int *p, const string &s){
    for(int i=1; i<s.size(); i++){
        int j = p[i-1];
        while(j && s[i] != s[j]) j = p[j-1];
        p[i] = j + (s[i] == s[j]);
    }
}
