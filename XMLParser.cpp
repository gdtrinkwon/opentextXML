#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class XMLParser
{
private:
    xml_document<> doc;
    xml_node<> * root_node = NULL;
public:
    vector<map<string, string>> parseXML(string fileName)
    {   
        // Read the sample.xml file
        ifstream inputFile (fileName);
        vector<char> buffer((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
        vector<map<string, string>> cds;
    
        buffer.push_back('\0');
    
        // Parse the buffer
        doc.parse<0>(&buffer[0]);
    
        // Find out the root node
        root_node = doc.first_node("CATALOG");
    
        // Iterate over the CDs
        for (xml_node<> * cd_node = root_node->first_node("CD");
                    cd_node; cd_node = cd_node->next_sibling())
        {
            //Using a map rather than a vector since ordering of elements is not guaranteed
            map<string, string> cdmap;
            for(xml_node<> * current_node = cd_node->first_node();
                    current_node; current_node = current_node->next_sibling())
            {
                cdmap[current_node->name()] = current_node->value();
            }

            cds.push_back(cdmap);
        }

        return cds;
    }
};