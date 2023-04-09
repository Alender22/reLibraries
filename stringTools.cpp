#include "stringTools.h"

//Make empty tokens list
//make empty token string
//loop through original string.
//if current index is start of substring matching splitMarker
//  push token to back of list
//  increment i by lengthOfSplitMarker - 1
//  set token to empty string 
//otherwise
//  append current char to end of token string
//check if current i does not allow for further substring matches
//  if so, append remainder of main string to token string 
//  and append token string to tokens list
//  return tokens list
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

//split main string at replace string
//append token to formatted string
//for token in tokens
//  if appended token is not the last token
//    append replace string to formatted string
//return formatted string
string replaceSubtsring(string main, string replace, string newString)
{
    vector<string> tokens = splitStringAt(main, replace);
    string formatted = "";

    for(int i = 0; i < tokens.size(); i++)
    {
        formatted += tokens[i];
        if(i < tokens.size() - 1)
        {
            formatted += newString;
        }
    }

    return formatted;
}

template<typename a, typename b>
string replaceSubtsring(string main, a replaceChars, b newChars)
{
    string replaceString = "";
    replaceString += replaceChars;

    string newString = "";
    newString += newChars;
    return replaceSubtsring(main, replaceString, newString);
}

//Split main string at toDelete string.
//make an empty formatted string
//append each token to the formatted string
//return formatted string
string deleteSubstring(string main, string toDelete)
{
    vector<string> tokens = splitStringAt(main, toDelete);
    string formattedString = "";

    for(int i = 0; i < tokens.size(); i++)
    {
        formattedString += tokens[i];
    }

    return formattedString;
}

string deleteSubstring(string main, char toDeleteChar)
{
    string toDeleteString = "";
    toDeleteString += toDeleteChar;
    return deleteSubstring(main, toDeleteString);
}
