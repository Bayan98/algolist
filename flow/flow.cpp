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

using namespace std;

using pii = pair<int, int>;
using ll = long long;

const int INF = (int)1e9+7, N = (int)1e5+123;
const double eps = 1e-9;

struct edge{
    int to, from, flow, cost;
    edge(int a, int b, int c): from(a), to(b), cost(c), flow(0){}
};
int n, m;
vector<edge> e;
vector<unsigned long> a[102];
inline void add_edge(const int u, const int v, const int cost){
    e.pb(edge(u, v, cost));
    a[u].pb(e.size() - 1);
    e.pb(edge(v, u, cost));
    a[v].pb(e.size() - 1);
}
bitset<102> used;
int push(int v, int flow = INF){
    if(v == n || !flow) return flow;
    used[v] = 1;
    for(auto i : a[v]){
        if(!used[e[i].to] && e[i].cost - e[i].flow){
            int res = push(e[i].to, min(flow, e[i].cost - e[i].flow));
            if(res){
                e[i].flow += res;
                e[i ^ 1].flow -= res;
                return res;
            }
        }
    }
    return 0;
}
ll flow(const int s){
    ll ans = 0, add = 0;
    while(add = push(s)){
        used.reset();
        ans += add;
    }
    return ans;
}
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    
    
    
    return 0;
}


