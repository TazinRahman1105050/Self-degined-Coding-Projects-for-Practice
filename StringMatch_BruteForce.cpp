#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
void BruteForce(char *T, char *P,int n, int m)
{
    for(int s=0;s<=(n-m);s++)
    {
        int k=0;
        while(k<m && k!=-100)
        {
            if(P[k]==T[s+k])
            {
                k++;
            }
            else
                k=-100;
        }
        if(k==m)
        {
            printf("pattern occurs at %d\n",s+1);
        }
    }
}





int main()
{
    char *T,*P;
    int n, m,i,j;
    cin>>n;

    T = (char *)malloc((n+1) * sizeof(char));
    P = (char *)malloc((m+1) * sizeof(char));
    for (i=0; i<n; i++)
       // cin>>T[i];
       T[i]=rand()%26+'a';
    T[i]='\0';
    cout<<T<<"\t";
    cin>>m;

    for (i=0; i<m; i++)
        cin>>P[i];
    P[i]='\0';
   // cin>>T;
   // cin>>P;

    BruteForce(T,P,n,m);

    cout<<P<<"\n";
    return 0;
}

