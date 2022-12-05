// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 7 SHA-1

#include <bits/stdc++.h>
using namespace std;

/***************************/
//CONVERSION OF DECIMAL TO HEXADECIMAL
/***************************/

vector<int> decToBinary(int n)
{
    vector<int>binarr; 
    int binaryNum[64];
    int i = 0;
    while (n > 0) 
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = 64; j >= 0; j--)
    {
        if(j>i-1)
        {
           binarr.push_back(0); 
        }
        else
        {
            binarr.push_back(binaryNum[j]);
        }
    }
    return binarr;
}
/**************************/
//CONVERSION TO THE BINARY
/***************************/
vector<int> tobinary(string msg)
{
    vector<int> binarr;
    int var;
    int len = msg.length();
    for(int i=0;i<len;i++)
    {
        bitset<8> b(msg[i]);
        string temp = b.to_string();
        
        
        for(int j=0;j<temp.length();j++)
        {
            if(temp[j]==48)
            {
                var = temp[j]-48;
                binarr.push_back(var);
            }
            else
            {
                var = temp[j]-48;
                binarr.push_back(var);
            }
        }
    }
  return binarr;
}
/***************************/
//CONVERSION  OF BINARY TO  HEXADECIMAL 
/***************************/
string tohex(vector<int> binarr)
{
    int start = binarr.size()-4;
    int end = binarr.size()-1;
    string hex ="";
    int n =3;
    int res;
    char ch;
    while(end!=-1)
    {
        n =3;
        res =0;
        for(int i=start;i<=end;i++)
        {
            res = res+ binarr[i] * (pow(2,n));
            n--;
        }
        
        
        if(res>=0 && res<=9)
        {
            ch = res + 48;
            hex = hex + ch;
        }
        else
        {
            ch = res + 65-10;
            hex = hex + ch;
        }
        start = start-4;
        end = end -4;
    }
    reverse(hex.begin(),hex.end());
    return hex;
    
    
}
/***************************/
// MESSEGE PADDING
/***************************/
vector<int> msgpadding(vector<int> binarr ,vector<int>msgsizebin )
{
    if(binarr.size() < 448)
    {
        binarr.push_back(1);
        for(int i=binarr.size();i<448;i++)
        {
           binarr.push_back(0); 
        }
    }
    int rem = binarr.size();
    int j=0;
    
    for(int i=binarr.size();i<512;i++)
    {
           binarr.push_back(msgsizebin[j++]); 
    }
    return binarr;
  
}
uint32_t leftRotate32bits(uint32_t 	n, int	rotate )
{
    return (n << rotate) | (n >> (32 - rotate));
}
/***************************/
int main()
{
    cout << "Name: Anish Tilloo" << endl;
    cout << "Section: A  Roll No. 34" << endl;
    cout << "Batch: A2" << endl; 
    cout << "Practical-7" <<endl;
    cout << endl;


    string msg;
    cout<<"Enter the Message: ";
    cin>>msg;

    // converted the bits into binary
    vector<int> binarr = tobinary(msg);
    
    // calculated the msg size in bytes
    int msg_size = (msg.length())*8;

    // converting the message size in binary
    vector<int> msgsizebin = decToBinary(msg_size);
    cout<<endl;
    cout<<"Msg in bits is: "<<endl;

    // printing the message in bits
    for(int i=0;i<binarr.size();i++)
    {
        cout<<binarr[i];
    }
    cout<<endl;
    cout<<"Msg in hexadecimal is: "<<endl;

    // converting the message into hexadecimal
    cout<<tohex(binarr);
    cout<<endl;

    // if the size of data is less than 448 bits then we are adding padding
    vector<int> newmsg = msgpadding(binarr,msgsizebin); 
    cout<<endl;
/***************************/
// BLOCK CREATION
/***************************/

    // 80 for 80 rounds and 32 for the size of block
    int blocks[80][32];
    int count =0;

    // actual loops for breaking the message into blocks
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<32;j++)
        {
            blocks[i][j] = newmsg[count++];
        }

    }

    // after 16 round to generate unique key we are using this loop
    for(int i=16;i<80;i++)
    {
        for(int j=0;j<32;j++)
        {
            blocks[i][j] = ((((blocks[i-16][j])^(blocks[i-14][j]))^(blocks[i-8][j]))^(blocks[i-3][j]));
        }
    }
    cout<<endl;
    
/***************************/
//ROUND STAGE OPERATION
/***************************/
    
    // uint32_t :- it is a numeric type that guarantees 32 bits it is also unsinged i.e its value is from 0 to 231
    // initial hexadecimal inputs for R0 in 160 bits
    uint32_t a,h0 = 0x67452301;
    uint32_t b,h1 = 0xEFCDAB89; 
    uint32_t c,h2 = 0x98BADCFE; 
    uint32_t d,h3 = 0x10325476; 
    uint32_t e,h4 = 0xC3D2E1F0; 
    a =h0;
    b =h1;
    b =h2;
    d =h3;
    e =h4;

        // individual opreations to perform in a single round based on the group of rounds
        // 0 - 19, 20 -39, 40 - 59, 60 - 79 :- these are four groups
        for (int i = 0; i < 80; i++) 
        {
            uint32_t F = 0, k = 0;
            if (i>=0 && i< 20) 
            {
                F = (b & c) | ((~b) & d);
                k = 0x5A827999;
            } 
            else if (i>=20 && i < 40) 
            {
                F = b ^ c ^ d;
                k = 0x6ED9EBA1;
            } 
            else if (i>=40 && i < 60) 
            {
                F = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            } 
            else 
            {
                F = b ^ c ^ d;
                k = 0xCA62C1D6;
            }
            vector<int> blocks_bin;
            for(int j=0;j<32;j++)
            {
                blocks_bin.push_back(blocks[i][j]);
            }
            string temp2 = tohex(blocks_bin);
            uint32_t x;   
            stringstream ss;
            ss <<hex << temp2;
            ss >> x;
            // left rotating 5 times for a
            uint32_t temp = leftRotate32bits(a, 5) + F + e + k + x;
            e = d;
            d = c;
            // left rotating 30 times for b
            c = leftRotate32bits(b, 30);
            b = a;
            a = temp;

            // updating the values for h0, h1, h2, h3, h4
            h0 += a;
            h1 += b;
            h2 += c;
            h3 += d;
            h4 += e;
        }
        cout<<endl;
        cout<<hex <<"h0 : "<<h0<<endl;
        cout<<hex <<"h1 : "<<h1<<endl;
        cout<<hex <<"h2 : "<<h2<<endl;
        cout<<hex <<"h3:  "<<h3<<endl;
        cout<<hex <<"h4 : "<<h4<<endl;
        uint32_t hash_digest[] = {h0,h1,h2,h3,h4};

        // printing the hash values
        cout<<"\n HASH DIGEST IS : "<<endl;
        for(int i=0;i<5;i++)
        {
            cout<<hash_digest[i];
        }
        
        
    return 0;
}