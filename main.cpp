/*
 Created by Saidolda Bayan.
 LANG: C++
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <iterator>
#include <map>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cassert>
#include <queue>
#include <deque>
#include <unordered_map>

#define _USE_MATH_DEFINES
#define y1 yy1
#define pb push_back
#define mp make_pair
#define f first
#define s second

using pii = std::pair<int, int>;
using ll = long long;

ll INF = (int)1e9+7, N = (int)1e5+123;
double eps = 1e-9;

void setINF(ll x){INF = x;}
void setN(int n){N = n;}

ll binpow(ll a, ll b, ll _INF = INF){
    ll res = 1;
    while (b > 0){
        if (b & 1) res = res * a % _INF;
        a = a * a % _INF;
        b >>= 1;
    }
    return res;
}

inline ll fact (const int x){
    static std::vector<ll> factorial (1, 1);
    for(static int i = 1; i <= x; i++){
        factorial.pb(factorial[i-1] * i % INF);
    }
    return factorial[x];
}

ll cnk(const int n, const int k){
    if(k > n) return 0;
    return fact(n) * binpow(fact(n - k) * fact(k) % INF, INF - 2) % INF;
}

//DSU disjoint-set-union
template<size_t N, class type = int>
class DSU{
private:
    type lvl[N];
public:
    type parent[N];
    DSU(){
        for(int i=0; i<N; i++){
            make_set(i);
        }
    }
    void make_set (type v) {
        parent[v] = v;
        lvl[v] = 1;
    }
    type find_set(const type x){
        return (parent[x] == x) ? x : parent[x] = find_set(parent[x]);
    }
    void add(type x, type y){
        x = find_set(x);
        y = find_set(y);
        if(x != y){
            if(lvl[x] < lvl[y]) std::swap(x, y);
            lvl[x] += lvl[y];
            parent[y] = x;
        }
    }
};

int factmod (ll n, int p) {
    ll res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
        for (int i=2; i<=n%p; i++)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}

void feelgood(int *a, pii *d, int n){
    std::vector<int> q;
    for(int i=1; i<=n; i++){
        d[i].f = i;
        while(q.size() && a[i] >= a[*q.rbegin()]){
            d[i].f = d[*q.rbegin()].f;
            q.pop_back();
        }
        q.pb(i);
    }
    q.resize(0);
    for(int i=n; i>=1; i--){
        d[i].s = i;
        while(q.size() && a[i] > a[*q.rbegin()]){
            d[i].s = d[*q.rbegin()].s;
            q.pop_back();
        }
        q.pb(i);
    }
}

template <size_t N>
class fenwick{
private:
    ll t[N];
public:
    ll get(int i){
        ll res = 0;
        for(; i>=0; i = (i & (i+1)) - 1)
            res += t[i];
        return res;
    }
    ll get(int l, int r){
        return get(r) - get(l-1);
    }
    void upd(int i, ll x){
        for(; i<N; i |= i+1)
            t[i] += x;
    }
};

ll gcd(ll x,ll y){
    return (y ? gcd(y, x%y) : x);
}

template<size_t n>
struct matrix{
    ll a[n][n];
    matrix(){
        memset(a, 0, sizeof a);
    }
    inline matrix operator * (const matrix b)
    {
        matrix c;
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k)
                for (int j = 0; j < n; ++j)
                    c.a[i][j] += a[i][k] * b.a[k][j],
                    c.a[i][j] %= INF;
        return c;
    }
    
};
template<size_t N>
matrix<N> binpow(matrix<N> a, matrix<N> b, int n){
    while (n > 0){
        if(n & 1) a = a * b;
        b = b * b;
        n >>= 1;
    }
    return a;
}

struct node{
    int res, a[100];
    node(){}
    node(int d[100]){
        res = 0;
        for(int i=0; i<100; i++)
            a[i] = d[i];
    }
    void calc();
}now, next;
void otjig(){
    long double T = 32;
    while(next.res > 0){
        next = now;
        std::swap(next.a[rand() % n + 1], next.a[rand() % n + 1]);
        next.calc();
        ll d = next.res - now.res;
        if(d < 0 || exp(-d / T) > double(rand() % 1024) / 1024.){
            now = next;
        }
        T *= 0.97;
    }
}

inline int readInt()
{
    int s = 1, x = 0, c = getc(stdin);
    while (c <= 32)
        c = getc(stdin);
    if (c == '-')
        s = -1, c = getc(stdin);
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getc(stdin);
    return x * s;
}

inline void writeInt( int x )
{
    if (x < 0)
        putc('-', stdout), x = -x;
    
    char s[20];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        putc(s[n], stdout);
}

/***
 * Word
 */

inline void readWord( char *s )
{
    int c = getc(stdin);
    while (c <= 32)
        c = getc(stdin);
    while (c > 32)
        *s++ = c, c = getc(stdin);
    *s = 0;
}

inline void writeWord( char *s )
{
    while (*s)
        putchar(*s++);
}

template<size_t N>
struct SparseTable{
    int d[N][N];
    SparseTable(int n, int *a){
        for (int i=1; i<=n; i++) d[0][i] = a[i];
        int k = 1;
        while((1<<k) <= n){
            for (int i=1; i<=n; i++){
                if (i + (1<<(k-1)) > n) d[k][i] = d[k-1][i];
                else d[k][i] = min(d[k-1][i], d[k-1][i + (1<<(k-1))]);
            }
            k++;
        }
    }
    int get(const int l, const int r){
        const int k = log2(r-l+1);
        const int x = (1 << k);
        return min(d[k][l], d[k][r-x+1]);
    }
};

int main ()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    
    
    
    return 0;
}


