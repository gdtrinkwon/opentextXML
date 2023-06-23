
#include <vector>
#include <map>
#include "rapidxml.hpp"
#include "HTMLTable.cpp"


class HTMLTableMap : public HTMLTable
{
    public:
    // Added an overload for maps which will populate a vector with entries in the order given by the headers.
    
   void addRow(const map<string, string> &rowmap)
   {
        vector<string> row (headers.size());
        for (int i = 0; i < headers.size(); i++)
        {
            auto it = rowmap.find(headers[i]);
            if(it != rowmap.end())
            {
                row[i] = it->second;    
            }
            else
            {
                //If a field is missing, log the error but still return the partial row.
                cerr << "Missing entry for " << headers[i] << endl;
            }
        }
      rows.push_back (row);
   }
};