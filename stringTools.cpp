#include "stringTools.h"

vector<string> splitStringAt(string toSplit, string splitAt)
{
    vector<string> tokens;
    string token = "";

    for(int i = 0; i < toSplit.length() - (splitAt.length() - 1); i++)
    {
        if(splitAt == toSplit.substr(i, splitAt.length()))
        {
            tokens.push_back(token);
            token = "";
            i += splitAt.length() - 1;
        }
        else 
        {
            token += toSplit[i];
        }
        if(i >= (toSplit.length() - (splitAt.length() - 1)) - 1)
        {
            token += toSplit.substr(i + 1);
            tokens.push_back(token);
        }
    }

    return tokens;
}

vector<string> splitStringAt(string toSplit, char splitAt)
{
    string marker = "";
    marker += splitAt;
    return splitStringAt(toSplit, marker);
}