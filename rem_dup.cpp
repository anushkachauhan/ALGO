#include<bits/stdc++.h>
// #include<bits/stdc++.h>

using namespace std;

// void rem_dup(string s[], int size)
// {
//     stack<string> st;

//     cout<<st.size();
//     if(st.size() == 0)
//     {
//         cout<<"0";
//     }
    
//     for(int i=0; i<size; i++)
//     {
//         if(st.empty())
//         {
//             st.push(s[i]);
//         }
//         else if(s[i] == st.top())
//         {
//             st.pop();
//         }
//         else 
//         {
//             st.push(s[i]);
//         }
//     }

//     cout<<st.size();
//     if(st.size() == 0)
//     {
//         cout<<"0";
//     }
    
//     while(st.size() > 0)
//     {
//         string str = st.top();
//         st.pop();
//         cout<<str<<"\n";
//     }
// }

int main(int argc, char** argv)
{
    string s[] = {"tom", "jerry","jerry", "jerry", "tom"};

    int size = sizeof(s)/sizeof(s[0]);
    // int size = *(&s + 1) - s;
    cout<<size;
    
    // rem_dup(s, 5);
    
}