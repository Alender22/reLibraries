#ifndef STRING_TOOLS
#define STRING_TOOLS

#include <string>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

//Description: Takes a main string, and a marker string. 
//  returns a vector of the substrings of the main strings,
//  which were sepereated by the marker string
//Pre: A string to split, and a string to split at
//Post: A vector of the resulting substrings
vector<string> splitStringAt(string toSplit, string splitAt);

//Alias for splitStringAt(string, string) with splitAt char
vector<string> splitStringAt(string toSplit, char splitAt);

//Description: Replaces given substring with a new string
//Pre:A string, subtring to replace, new substring
//Post:string with the replaced substring
string replaceSubtsring(string main, string replace, string newString);

//Allows replaceSubtsring to be called with any combination of string and char for replace and newString
template<typename a, typename b>
string replaceSubtsring(string main, a replaceChar, b newString);

//Description: Deletes a given substring from a given string
//Pre: A string, and a substring to remove
//Post: String with all instances of the substring removed
string deleteSubstring(string main, string toDelete);

//Alias for deleteSubstring with char as deletion substring
string deleteSubstring(string main, char toDeleteChar);

//Description: returns whether the main string contains the sub string
//Pre: a main and sub string
//Post: true if substring is contained, else false
bool containsSubstring(string main, string sub);

//alias for containsSubstring with char as subString
bool containsSubstring(string main, char sub);

//Description: Pads string to given length with pad char, in designated mode
//Pre:String to pad, pad char, target length and padmode [1 : padLeft, 2 : padRigth, 3 : padCenter]
//Post:String padded in desired manner
string padString(string original, char padChar, int targetLength, int padMode);

//Alias for padString function
string padRight(string original, char padChar, int targetLength);

//Alias for padString function
string padLeft(string original, char padChar, int targetLength);

//Alias for padString function
string padCenter(string original, char padChar, int targetLength);

#endif 