#include <iostream>
#include <string>
#include "stringTools.h"

using namespace std;

int main()
{
    string text = "mymy";
    string marker = "my";

    cout << "Enter your plainText: ";
    getline(cin, text);

    cout << "Enter the split marker: ";
    getline(cin, marker);

    vector<string> tokens = splitStringAt(text, marker);

    for(int i = 0; i < tokens.size(); i++)
    {
        cout << "|" << tokens[i] << "|" << endl;
    }

    return 0;
}