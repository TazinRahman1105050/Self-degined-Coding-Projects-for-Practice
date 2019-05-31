#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

char*  reorder(string FromString, int len)
{
    int n= 0;
    char *ToString;
    ToString = (char *)malloc((len+1) * sizeof(char));
    while(n<=len/2)
    {
        ToString[n*2]= FromString[n];
        ToString[n*2+1]= FromString[len-n-1];
        n++;
    }
    ToString[n*2] = '\0';
    return ToString;
}

int main(){
  string newInput;
  cout<< "Enter a string to encode:\n";
  getline(cin, newInput);
  char *reoderedString = reorder(newInput,newInput.size());
  cout<<"Encoded string:\n";
  for(int i=0;i<newInput.size();i++)
  {
      cout<<reoderedString[i];
  }
  cout<<"\n";

  return 0;
}
