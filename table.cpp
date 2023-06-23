#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

#include "table.h"

using namespace std;

void Table::writeHeaders (ostream &out)
    {
        out << "<tr>\n";
        for (string column : headers)
        {
            out << "<th> "<< column << " </th> ";
        }
        out << "\n</tr>\n";
    }

void Table::writeRow (ostream &out, map<string, string> row)
    {
        out << "<tr>\n";
        for (string column : headers)
        {
                auto it = row.find(column);
                out << "<td> "<< (it != row.end()? it->second : "") << " </td> ";
        }
        out << "\n</tr>\n";
    }

//******************************************************
// Overloaded stream output operator <<                *
//******************************************************
ostream & operator << (ostream &out, Table htmlTable)
{
   out << "<table border = \"1\">\n";
   
   // Write the headers
   htmlTable.writeHeaders(out);
   
   // Write the rows of the table
   for (unsigned int r = 0; r < htmlTable.rows.size(); r++)
   {
      htmlTable.writeRow(out, htmlTable.rows[r]);
   }
   // Write end tag for table
   out << "</table>\n";
   return out;
}