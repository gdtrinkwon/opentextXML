#ifndef TABLE
#define TABLE
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
class Table
{
private:
   set<string> headers;
   vector<map<string, string>> rows;
   void writeHeaders (ostream &out);
   void writeRow (ostream &out, map<string, string> row);
public:
    void addHeader (const string header)
   {
    this->headers.insert(header);
   }
   void addRow (map<string, string> row)
   {
    rows.push_back(row);
   }

   friend ostream &operator << (ostream &out, Table htmlTable);
};
#endif