// Copyright 2023 Kudryashov Nikita
#include "include/Encoder.h"


string Base64Encoder::strToBase64(string str) {
    string binaryString, res;
    char symbols[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int equalsCount = 0;

    for (char c : str) {
        string binChar = intToBin(static_cast<int>(c));
        while (binChar.length() < 8) {
            binChar = "0" + binChar;
        }
        binaryString += binChar;
    }

    while (binaryString.length() % 6 != 0) {
        binaryString += "00000000";
        equalsCount++;
    }

    int index = 0;
    int blockNum = binaryString.length() / 6;
    while (index != blockNum - equalsCount) {
        string subStr = binaryString.substr(index * 6, 6);
        int newChar = binToInt(subStr);

        res += symbols[newChar];
        index++;
    }
    for (int i = 0; i < equalsCount; i++) {
        res += "=";
    }

    return res;
}

string Base64Encoder::base64ToStr(string str) {
    string binaryString, res;
    char symbols[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    for (char c : str) {
        if (c != '=') {
            int index = std::find(std::begin(symbols), std::end(symbols), c)
                - std::begin(symbols);
            string binChar = intToBin(static_cast<int>(c));

            while (binChar.length() < 6) {
                binChar = "0" + binChar;
            }
            binaryString += binChar;
        } else {
            binaryString += "000000";
        }
    }

    int index = 0;
    int blockNum = binaryString.length() / 8;
    while (index != blockNum) {
        string subStr = binaryString.substr(index * 8, 8);
        int newChar = binToInt(subStr);
        res += static_cast<char>(newChar);
        index++;
    }

    return res;
}

string Base64Encoder::intToBin(int num) {
    string res;
    while (num > 0) {
        int ost = num % 2;
        res += std::to_string(ost);
        num /= 2;
    }
    reverse(res.begin(), res.end());

    return res;
}

int Base64Encoder::binToInt(string num) {
    int res = 0;
    reverse(num.begin(), num.end());
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '1') {
            res += pow(2, i);
        }
    }
    return res;
}
