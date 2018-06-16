#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

class ZipCode
{   
    public:
        ZipCode(int z);
        ZipCode(string str);
        void getZip();
        void getCode();
    private:
        int zip;
        string code;
        void encodeCode();
        void decodeCode();
};

ZipCode::ZipCode(int z)
{
    cout << "Enter the zip code as an integer (5 digits):" << endl;
    cin >> z;
    zip = z;
}
ZipCode::ZipCode(string str)
{
    cout << "Enter the zip code as a bar code string of 0's and 1's:" << endl;
    cin >> str;
    code = str;
}
void ZipCode::getZip()
{
    decodeCode();
}
void ZipCode::getCode()
{
    encodeCode();
}
void ZipCode::encodeCode()
{
    int digit1 = (((code[1]-48)*7)+((code[2]-48)*4)+((code[3]-48)*2)+((code[4]-48)*1)+((code[5]-48)*0));
    if (digit1 == 11)
    {
        digit1 = 0;
    }
    int digit2 = (((code[6]-48)*7)+((code[7]-48)*4)+((code[8]-48)*2)+((code[9]-48)*1)+((code[10]-48)*0));
    if (digit2 == 11)
    {
        digit2 = 0;
    }
    int digit3 = (((code[11]-48)*7)+((code[12]-48)*4)+((code[13]-48)*2)+((code[14]-48)*1)+((code[15]-48)*0));
    if (digit3 == 11)
    {
        digit3 = 0;
    }
    int digit4 = (((code[16]-48)*7)+((code[17]-48)*4)+((code[18]-48)*2)+((code[19]-48)*1)+((code[20]-48)*0));
    if (digit4 == 11)
    {
        digit4 = 0;
    }
    int digit5 = (((code[21]-48)*7)+((code[22]-48)*4)+((code[23]-48)*2)+((code[24]-48)*1)+((code[25]-48)*0));
    if (digit5 == 11)
    {
        digit5 = 0;
    }
    cout << "The Zip Code is:" << digit1 << digit2 << digit3 << digit4 << digit5 << endl;
}
void ZipCode::decodeCode()
{
    int dig5 = (zip % 10);
    int dig4 = (zip / 10) % 10;
    int dig3 = (zip / 100) % 10;
    int dig2 = (zip / 1000) % 10;
    int dig1 = (zip / 10000) % 10;
    cout << "The Bar Code is: 1";
    if (dig1 == 0)
    {
        cout << "11000";  
    }
    else if (dig1 == 1)
    {
        cout << "00011";
    }
    else if (dig1 == 2)
    {
        cout << "00101";
    }
    else if (dig1 == 3)
    {
        cout << "00110";
    }
    else if (dig1 == 4)
    {
        cout << "01001";
    }
    else if (dig1 == 5)
    {
        cout << "01010";
    }
    else if (dig1 == 6)
    {
        cout << "01100";
    }
    else if (dig1 == 7)
    {
        cout << "10001";
    }
    else if (dig1 == 8)
    {
        cout << "10010";
    }
    else
    {
        cout << "10100";
    }
    
    if (dig2 == 0)
    {
        cout << "11000";  
    }
    else if (dig2 == 1)
    {
        cout << "00011";
    }
    else if (dig2 == 2)
    {
        cout << "00101";
    }
    else if (dig2 == 3)
    {
        cout << "00110";
    }
    else if (dig2 == 4)
    {
        cout << "01001";
    }
    else if (dig2 == 5)
    {
        cout << "01010";
    }
    else if (dig2 == 6)
    {
        cout << "01100";
    }
    else if (dig2 == 7)
    {
        cout << "10001";
    }
    else if (dig2 == 8)
    {
        cout << "10010";
    }
    else
    {
        cout << "10100";
    }
    
    if (dig3 == 0)
    {
        cout << "11000";  
    }
    else if (dig3 == 1)
    {
        cout << "00011";
    }
    else if (dig3 == 2)
    {
        cout << "00101";
    }
    else if (dig3 == 3)
    {
        cout << "00110";
    }
    else if (dig3 == 4)
    {
        cout << "01001";
    }
    else if (dig3 == 5)
    {
        cout << "01010";
    }
    else if (dig3 == 6)
    {
        cout << "01100";
    }
    else if (dig3 == 7)
    {
        cout << "10001";
    }
    else if (dig3 == 8)
    {
        cout << "10010";
    }
    else
    {
        cout << "10100";
    }
    
    if (dig4 == 0)
    {
        cout << "11000";  
    }
    else if (dig4 == 1)
    {
        cout << "00011";
    }
    else if (dig4 == 2)
    {
        cout << "00101";
    }
    else if (dig4 == 3)
    {
        cout << "00110";
    }
    else if (dig4 == 4)
    {
        cout << "01001";
    }
    else if (dig4 == 5)
    {
        cout << "01010";
    }
    else if (dig4 == 6)
    {
        cout << "01100";
    }
    else if (dig4 == 7)
    {
        cout << "10001";
    }
    else if (dig4 == 8)
    {
        cout << "10010";
    }
    else
    {
        cout << "10100";
    }
    
    if (dig5 == 0)
    {
        cout << "11000";  
    }
    else if (dig5 == 1)
    {
        cout << "00011";
    }
    else if (dig5 == 2)
    {
        cout << "00101";
    }
    else if (dig5 == 3)
    {
        cout << "00110";
    }
    else if (dig5 == 4)
    {
        cout << "01001";
    }
    else if (dig5 == 5)
    {
        cout << "01010";
    }
    else if (dig5 == 6)
    {
        cout << "01100";
    }
    else if (dig5 == 7)
    {
        cout << "10001";
    }
    else if (dig5 == 8)
    {
        cout << "10010";
    }
    else
    {
        cout << "10100";
    }
    cout << "1" << endl;
}

int main()
{
    ZipCode envelope("11111111111");
    envelope.getCode();
    ZipCode letter(12345);
    letter.getZip();
    return 0;
}