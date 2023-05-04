#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Base64Encoder {
public:
    static string strToBase64(string);
    static string base64ToStr(string);
private: 
    static string intToBin(int num);
    static int binToInt(string num);
};