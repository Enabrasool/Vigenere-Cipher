#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    cout<<"--------------this program depicting the implementation of Vigenere cipher-----------";
    char table[26][26],x,msg[100]={},cmsg[100]={},dmsg[100]={},key[100]={},keystream[100]={};
    int counter=0,i=0,j=0;
    cout<<"\n Making the Table\n";
    for(i=0;i<26;i++)
    {    for(j=0;j<26;j++)
        {
            x='A'+i+j;
            if(x>90)
            {
                x=x-i-j+counter;
                counter++;
            }
            table[i][j]=x;
        }
        counter=0;
    }
    cout<<"\n Enter the Message to Encrypt. Use Capitals only \n ";
    cin>>msg;
    cout<<"\n Enter the Key to be Used for Encryption. Use Capitals only \n ";
    cin>>key;
     i=0;
    for(j=0;j<strlen(msg);j++,i++)
        {
            if(strlen(key)>i)
             keystream[j]=key[i];
            else
             {
                 i=0;
                keystream[j]=key[i];
             }
        }
    cout<<"\n Key stream is "<<keystream;
    cout<<"\n The Cipher Text For Your Message is \n ";
    for(i=0;i<strlen(msg);i++)
    {
            int col=msg[i]-65;
            int row=keystream[i]-65;
            cmsg[i]=table[row][col];
    }
    cout<<cmsg;
    cout<<"\n \n ------------------DECRYPTING THE MESSAGE-----------------------\n";
    j=0;
      for(i=0;i<strlen(msg);i++)
    {
            int row=keystream[i]-65;
            for(j=0;j<26;j++)
            {           if(cmsg[i]==table[row][j])
                        break;
            }
            dmsg[i]=j+65;
    }
    cout<<dmsg;
    return 0;
}
