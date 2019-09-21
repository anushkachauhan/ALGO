#include<bits/stdc++.h>

using namespace std;

int counter = 0;

int fib(int n)
{

    if(n==0 || n==1)
    {
        return n;
    }
    
    ++counter;
    int f1 = fib(n-1);
    int f2 = fib(n-2);
    int fn = f1+f2;

   cout<<counter<<". F"<<" - "<<f1<<" " <<f2<< n<<endl;

    return fn;
}

int fib_memo(int n, int qb[])
{
    if(n==0 || n==1)
    {
        return n;
    }

    if(qb[n] != 0)
    {
        return qb[n];
    }

    ++counter;
    
    int f1 = fib_memo(n-1, qb);
    int f2 = fib_memo(n-2, qb);
    int fn = f1+f2;

    qb[n] = fn;
    cout<<counter<<". F"<<n<<" - "<<fn<<endl;
    return fn;

}

int fib_bottom_up(int n)
{
    // make a table/pad
    int dp[1000] = {}; // empty ---> plus don't go out of index it'll give garbage or will not compute
    
    dp[0] =0;
    dp[1] = 1;

    for(int curnum =2 ; curnum<= n; curnum++)
    {
        dp[curnum] = dp[curnum-1] + dp[curnum-2];
    }
    return dp[n];
}

int main()
{
    int n =10;
    int qb[n+1];

    cout<<fib(n)<<endl;
    cout<<fib_memo(n, qb)<<endl;
}