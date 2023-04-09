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
//  if so, append remainder of original string to token string 
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

//split original string at replace string
//append token to formatted string
//for token in tokens
//  if appended token is not the last token
//    append replace string to formatted string
//return formatted string
string replaceSubtsring(string original, string replace, string newString)
{
    vector<string> tokens = splitStringAt(original, replace);
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
string replaceSubtsring(string original, a replaceChars, b newChars)
{
    string replaceString = "";
    replaceString += replaceChars;

    string newString = "";
    newString += newChars;
    return replaceSubtsring(original, replaceString, newString);
}

//Split original string at toDelete string.
//make an empty formatted string
//append each token to the formatted string
//return formatted string
string deleteSubstring(string original, string toDelete)
{
    vector<string> tokens = splitStringAt(original, toDelete);
    string formattedString = "";

    for(int i = 0; i < tokens.size(); i++)
    {
        formattedString += tokens[i];
    }

    return formattedString;
}

string deleteSubstring(string original, char toDeleteChar)
{
    string toDeleteString = "";
    toDeleteString += toDeleteChar;
    return deleteSubstring(original, toDeleteString);
}

//compair every substring of length of sub in original with sub
//if a match is encountered, return true
//else return false
bool containsSubstring(string original, string sub)
{
    for(int i = 0; i <= original.length() - sub.length(); i++)
    {
        if(original.substr(i, sub.length()) == sub)
        {
            return true;
        }
    }
    return false;
}

bool containsSubstring(string original, char sub)
{
    string subString = "";
    subString += sub;
    return containsSubstring(original, subString);
}

//Check padding mode
//if pad left 
//  pad padChar to the left of the string, until original length is greater targetLength
//if pad right
//  pad padChar to the right of the string, until original length is greater targetLength
//if pad center
// pad padChar alternatingly to the right and left of the string, until original length is greater targetLength
string padString(string original, char padChar, int targetLength, int padMode)
{
    if(padMode == 1) //Left bound padding
    {
        while(original.length() < targetLength)
        {
            original = padChar + original;
        }
    }
    else if(padMode == 2) //Right bound padding
    {
        while(original.length() < targetLength)
        {
            original += padChar;
        }
    }
    else if(padMode == 3)
    {
        while(original.length() < targetLength)
        {
            if((original.length() - targetLength) % 2 == 0)
            {
                original += padChar;
            }
            else 
            {
                original = padChar + original;
            }
        }
    }
    else
    {
        cout << "padMode of: " << padMode << " is not recognized in padString function." << endl;
        cout << "Returning original unchanged." << endl;
        return original;
    }

    return original;
}

//See description of padString function
string padRight(string original, char padChar, int targetLength)
{
    return padString(original, padChar, targetLength, 2);
}

//See description of padString function
string padLeft(string original, char padChar, int targetLength)
{
    return padString(original, padChar, targetLength, 1);
}

//See description of padString function
string padCenter(string original, char padChar, int targetLength)
{
    return padString(original, padChar, targetLength, 3);
}
