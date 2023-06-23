#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "XMLParser.cpp"

#include "table.h"

using namespace std;

const vector<string> columns = {"TITLE", "ARTIST", "COMPANY", "COUNTRY", "PRICE", "YEAR"};

void writeTable(Table table)
{
    // Open a file and write the HTML code to the file
   ofstream outFile("table.html");
   outFile << table;
   outFile.close();
}


Table parseXML(string fileName)
{   
    XMLParser parser;
    return parser.parseXML(fileName);
}
   
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Please input a single file name.";
        return -1;
    }
    
    // Read the cd_catalog file
    Table cds = parseXML(argv[1]);
    writeTable(cds);
   
    return 0;
}







