#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "HTMLTableMap.cpp"
#include "XMLParser.cpp"

using namespace std;

const vector<string> columns = {"TITLE", "ARTIST", "COMPANY", "COUNTRY", "PRICE", "YEAR"};

void writeTable(vector<string> columns, vector<map<string, string>> rows)
{
    HTMLTableMap hTable;
    hTable.setHeaders(columns);
    for (int i = 0; i < rows.size(); i++)
        {
            hTable.addRow(rows[i]);
        }
    // Open a file and write the HTML code to the file
   ofstream outFile("table.html");
   outFile << hTable;
   outFile.close();
}


vector<map<string, string>> parseXML(string fileName)
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
    vector<map<string, string>> cds = parseXML(argv[1]);
    writeTable(columns, cds);
   
    return 0;
}







