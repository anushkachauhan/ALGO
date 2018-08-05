#include <iostream>
using namespace std;

void partition(int *a, int s, int e)
{
    //a is the array, s is the starting and e is the ending
    int i = s-1;
    int j =s;
    int pivot = a[e];//pivot acn be any element either a[s] or a[e]
    for( ; j<e; j++)
    {  // bringing smaller elements to the LHS to the pivot
    	if(a[j]<= pivot){
    		i++;
    		swap(a[i], a[j]);
    	}
    }
    //Bring pivot to it's sorted position
    swap(a[i+1], a[e]);
    return i+1;
}

void quiksort(int *a, int s, int e)
{
	if(s>= e)
		return;
	int p = partition(a,s,e);
	quicksort(a,s,p-1);
	quicksort(a,p+1,e);

}

int main(){
	int a[1000];
	int n;
	cin>>n;// no. of elements to be sorted
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	for(int i =0; i<n;i++){
		cout<<a[i]<<",";	
	}
	return 0;
}
