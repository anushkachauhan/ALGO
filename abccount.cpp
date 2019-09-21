#include<bits/stdc++.h>

using namespace std;

void count_abc(string str)
{
    int ca =0;// count a
    int cb =0;// count b
    int cc =0;// count c

    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == 'a')
        {
           ca = 2*ca +1;
        }
        else if(str[i] == 'b')
        {
           cb = 2*cb +ca;
        }
        else if(str[i] == 'c')
        {
           cc = cb +2*cc;       
        }
    }

    cout<<"count : "<<cc<<endl;

}

int main(int argc, char** argv)
{
    string str = "abcabc";
    count_abc(str);
}