#include <iostream>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

// long long型の累乗をしたい時に使う関数
ll ll_pow(ll x, ll a)
{
    ll ans = x;
    if (a == 0)
    {
        return 1;
    }
    for (int i = 1; i < a; i++)
    {
        ans *= x;
    }
    return ans;
}

// k進数の数字sを10進数に変換する関数
ll n_hex(std::string s, ll k)
{
    ll ans = 0;
    for (char x : s)
    {
        if (((int)x >= (int)'a' && (int)x <= (int)'f'))
        {
            ans *= k;
            ans += x - 87;
        }
        else if (((int)x >= (int)'A' && (int)x <= (int)'F'))
        {
            ans *= k;
            ans += x - 55;
        }
        else
        {
            ans *= k;
            ans += x - '0';
        }
    }
    return ans;
}

// x以下の素数を列挙して返す関数
std::vector<ll> S_O_E(ll x)
{
    std::vector<ll> tmp(x);
    std::vector<ll> ans(x - 1);
    ll ans_size = 0;
    for (int i = 1; i <= x; i++)
        tmp[i - 1] = i;
    tmp[0] = 0;
    for (int i = 2; i < std::sqrt(x); i++)
    {
        for (int j = i; j <= x; j++)
        {
            if (j != i && j % i == 0)
                tmp[j - 1] = 0;
        }
    }
    for (ll &v : tmp)
    {
        if (v != 0)
        {
            ans[ans_size] = v;
            ans_size++;
        }
    }
    ans.resize(ans_size);
    return ans;
}