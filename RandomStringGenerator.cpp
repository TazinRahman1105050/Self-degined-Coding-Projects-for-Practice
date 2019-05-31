#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

char*  randomString(string Pattern, int len)
{
    int n= 0;
    char *punctuation, *upper, *lower, *numeric;
    punctuation = "`~!@#$%^&.";
    upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    lower = "abcdefghijklmnopqrstuvwxyz";
    numeric = "0123456789";
    char *randomString;
    randomString = (char *)malloc((len+1) * sizeof(char));
    char *allowedChars;
    allowedChars = (char *)malloc((73) * sizeof(char));
    *allowedChars = '\0';
    cout<<allowedChars<"\n";
    while(n <= Pattern.size())
    {
        if (Pattern[n] == 'n')
        {
            strcat(allowedChars,numeric);
        }
        else if (Pattern[n] == 'u')
        {
            strcat(allowedChars,upper);
        }
        else if (Pattern[n] == 'l')
        {
            strcat(allowedChars,lower);
        }
        else if (Pattern[n] == 'c')
        {
            strcat(allowedChars,punctuation);
        }
        n++;
    }
    for (int i = 0; i < len; ++i) {
        randomString[i] = allowedChars[((rand() % (strlen(allowedChars) - 1)))];
    }
    strcat(randomString,"\0");
    return randomString;
}

int main(){
  int length;
  string Pattern;
  cout<< "Enter a pattern:\n";
  cin>>Pattern;
  cout<< "Enter size:\n";
  cin>>length;
  cout<<randomString(Pattern, length)<<"\n";

  return 0;
}
