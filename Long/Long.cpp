const ll base = (ll)1e18;
class Long {
public:
    vector <ll> a;
    Long() {
        a.push_back(0);
    }
    Long(vector <ll> a) : a(a) {}
    Long(string b) {
        for (int i = b.size(); i > 0; i -= 18) {
            if (i < 18)
                a.push_back(atoll(b.substr(0, i).c_str()));
            else
                a.push_back(atoll(b.substr(i - 18, 18).c_str()));
        }
    }
    Long operator * (int b) {
        vector <ll> c = a;
        for (int i = 0, carry = 0; i < c.size() || carry; i++) {
            if (i == c.size())
                c.push_back(0);
            ll cur = carry + 1ll * c[i] * b;
            c[i] = cur % base;
            carry = cur / base;
        }
        while(c.size() > 1 && c.back() == 0)
            c.pop_back();
        return c;
    }
    Long operator * (Long b) {
        vector <ll> c(a.size() + b.a.size());
        for (int i = 0; i < a.size(); i++)
            for (int j = 0, carry = 0; j < b.a.size() || carry; j++) {
                long long cur = c[i + j] + 1ll * a[i] * (j < b.a.size() ? b.a[j] : 0) + carry;
                c[i + j] = cur % base;
                carry = cur / base;
            }
        while(c.size() > 1 && c.back() == 0)
            c.pop_back();
        return c;
    }
    Long operator + (Long b) {
        vector <ll> c = a;
        for (int i = 0, carry = 0; i < max(c.size(), b.a.size()) || carry; i++) {
            if (i == c.size())
                c.push_back(0);
            c[i] += carry + (i < b.a.size() ? b.a[i] : 0);
            carry = c[i] >= base;
            if (carry)
                c[i] -= base;
        }
        return c;
    }
    Long operator - (Long b) {
        vector <ll> c = a;
        for (int i = 0, carry = 0; i < b.a.size() || carry; i++) {
            c[i] -= carry + (i < b.a.size() ? b.a[i] : 0);
            carry = c[i] < 0;
            if (carry)
                c[i] += base;
        }
        while(c.size() > 1 && c.back() == 0)
            c.pop_back();
        return c;
    }
    Long operator / (ll b) {
        vector <ll> c = a;
        for (int i = c.size() - 1, carry = 0; i >= 0; i--) {
            long long cur = c[i] + 1ll * carry * base;
            c[i] = cur / b;
            carry = cur % b;
        }
        while(c.size() > 1 && c.back() == 0)
            c.pop_back();
        return c;
    }
    void out() {
        printf("%lld", a.empty() ? 0 : a.back());
        for (int i =  a.size() - 2; i >= 0; i--)
            printf("%018lld", a[i]);
    }
};
