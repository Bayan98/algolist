struct bor{
    unordered_map<char, int> to;
    int link, end;
    inline void clear(){
        link = end = 0;
        to.clear();
    }
    bor() {clear();}
}t[N];

inline void add_str(const string &s)
{
    static int sz = 0;
    int v = 0;
    for(auto c: s)
    {
        if(!t[v].to.count(c)) t[v].to[c] = ++sz;
        v = t[v].to[c];
    }
    t[v].end ++;
}

inline void push_links()
{
    queue<int> q;
    t[0].link = -1;
    q.push(0);
    while(q.size())
    {
        int v = q.front();
        for(auto c : t[v].to){
            int j = t[v].link;
            while(j != -1 && !t[j].to[c.f]) j = t[j].link;
            if(j != -1)t[c.s].link = t[j].to[c.f];
            q.push(c.s);
        }
        q.pop();
    }
}
