#ifndef FILE_TOOLS
#define FILE_TOOLS

#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Description: Reads each line of a file into a string vector
vector<string> readFileLineByLine(string fileName);

//Description: Returns the contents of a file as a single string
string readFileToString(string fileName);

//Description: Writes a string to a file
void writeStringToFile(string fileName, string fileContents);

//Description: Reads the contents of a file to a char vector in binary mode
vector<char> readBinaryFile(string fileName);

//Description: Writes to contents of a char vector to a file in binary mode
void writeBinaryFile(string fileName, vector<char> contents);

#endif