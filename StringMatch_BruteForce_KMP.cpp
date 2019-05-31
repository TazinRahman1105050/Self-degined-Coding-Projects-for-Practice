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


void KMP(char *T, char *P,int n, int m)
{
    int *PI;
    PI = (int *)malloc((m) * sizeof(int));
    PI[0]=-1;
    int k;
    int q;
    for (int i = 1; i < m; i++)
    {
        k = PI[i - 1];
        while (k >= 0)
        {
            if (P[k] == P[i - 1])
                break;
            else
                k = PI[k];
        }
        PI[i] = k + 1;
    }
    int i = 0;
     k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (T[i] == P[k])
        {
            i++;
            k++;
            if (k == m)
                cout<<"found at"<<i<<"\n";
        }
        else
            k = PI[k];
    }

}


void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    while(i < M)
    {
       if(pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if( len != 0 )
         {

           len = lps[len-1];


         }
         else
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
void KMPSearch(char *pat, char *txt,int n,int m)
{
   // int M = strlen(pat);
   // int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*m);
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, m, lps);

    int i = 0;  // index for txt[]
    while(i < n)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == m)
      {
        printf("Found pattern at  %d \n", i-j+1);
        j = lps[j-1];
      }

      // mismatch after j matches
      else if(pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
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
  //  KMP(T,P,n,m);
  KMPSearch(P,T,n,m);
    //search(T,P,101,256);
    cout<<P<<"\n";
    return 0;
}

