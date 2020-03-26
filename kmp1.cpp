#include <iostream>
#include <cstdlib>

using namespace std;
#define MAX_MATCHES 100

int FOUND[MAX_MATCHES];
static int l = 0;

void kmp_table(string W, int *T )
{
 int pos = 2;
 int cnd = 0;
 int length = W.length();
 
 T[0] = -1;
 T[1] = 0;
 
 while( pos < length)
 {
  if(W[pos-1] == W[cnd])
  {
   T[pos] = cnd + 1;
   cnd++;
   pos++;
  }
  else if( cnd > 0)
   cnd = T[cnd];
  else
  {
   T[pos] = 0;
   pos++;
  }
 }
}

void kmp_search(string S, string W)
{
 
 int m = 0; 
 int i = 0;
 int sizeS = S.length();
 int sizeW = W.length();
 
 int *T = new int[sizeof(int) * sizeW];
 
 kmp_table(W, T);
 
 while( (m + i) < sizeS)
 {
  if (W[i] == S[m + i]) 
  {
            if (i == (sizeW - 1))
            {
             FOUND[l++] = m;
   }
    
            i++;
        }
        else
        {
            if (T[i] > -1)
            {
                m = m + i - T[i];
    i = T[i];
            }
            else
            {
                m = m + 1;
    i = 0;
            }
        }
 }
 
 delete(T);
}

int main()
{
 string S; 
 string W;
 cout<<"Enter the text"<<endl;
 cin>>S;
 cout<<"enter the Pattern"<<endl;
 cin>>W;
 
 kmp_search(S,W);
  
 for (int i = 0 ; i < l; i++)
  cout<<"Pattern found at "<< FOUND[i] <<endl; 
}