#include <iostream>
using namespace std;

int main()
{
    int n,t1=0,t2=1,nextterm=0;

    cout<<"Enter Number of tearms : ";
    cin>>n;
        if(n==0)
        {
            cout<<t1;
        }
        else if(n==1)
        {
            cout<<t2;
        }
        else
        {
        for(int i=2 ; i<n+1;i++)
        {
            cout<<t1<<endl;
            nextterm=t1+t2;
            t2=t1;
            t1=nextterm;
          
        }
        
    }
    return 0;
}

