#include<iostream>
#include<cstring>
using namespace std;
string between(string,int);
main(){
    int i=0;
string str,temp;
cin>>str;
temp=between(str,i);
for(i=0;temp[i]!='\0';i++)
    cout<<temp[i];
}
string between(string str,int i){
    char temp[10000000];
    if(str[i]=='('){
        int j=0;
        for(int k=i+1;str[k]!=')';k++){
            temp[j]=str[k];
    j++;
        }
        temp[j]='\0';
        string s=temp;
        return s;
       }
       else{
        return(between(str,i+1));
       }
}
