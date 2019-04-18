#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    float x[10],y[10][10],sum,p,u,temp;
    int i,n,j,k=0,f,m;
    float fact(int);

    cout<<"How many record you will be enter: ";
    cin>>n;

    cout<<"\nX\tY\n";
    for(i = 0;i<n;i++)
    {
        cin>>x[i]>>y[k][i];
    }

    cout<<"\n\nEnter X for finding x: ";
    cin>>p;

    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            y[i][j]=y[i-1][j+1]-y[i-1][j];
        }
    }

    cout<<"\n_____________________________________________________\n";
    cout<<"\n  x(i)\t   y(i)\t    y1(i)    y2(i)    y3(i)    y4(i)";
    cout<<"\n_____________________________________________________\n";

    for(i=0;i<n;i++)
    {
        cout<<"\n"<<x[i];
        for(j=0;j<n-i;j++)
        {
            cout<<"   ";
            cout<<" "<<y[j][i];
        }

        cout<<"\n";
    }

    i=0;

    do
    {
        if(x[i]<p && p<x[i+1])
            k=1;
        else
            i++;
    }while(k != 1);

    f=i;
    u=(p-x[f])/(x[f+1]-x[f]);
    cout<<"\n\nu="<<u;

    n=n-i+1;
    sum=0;
    for(i=0;i<n-1;i++)
    {
        temp=1;
        for(j=0;j<i;j++)
        {
            temp = temp * (u - j);
        }

        m=fact(i);
        sum = sum + temp*(y[i][f]/m);
    }

    cout<<"\n\n"<<"y("<<p<<")= "<<sum<<endl;

    return 0;
}

float fact(int a)
{
    float fac = 1;

    if (a == 0)
        return (1);
    else
        fac = a * fact(a-1);

    return(fac);
}
