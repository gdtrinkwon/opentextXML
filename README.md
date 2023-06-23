# Running the code:
From terminal, run 
```console
make
```
to build the dependencies and executable file converter.exe
The executable requires the path to an xml file containing a list of CDs e.g.
```console
.\converter.exe .\cd_catalog.xml
```
This will create the file table.html with the list of CDs provided in an HTML table.
```console
make clean
```
will remove the executable and object files.

# Design:
I used an existing library for XML parsing (https://rapidxml.sourceforge.net/) as it is a sufficiently common problem that the potential benefits of building a custom tool were outweighed by the efficiency and stability of choosing a widely used third party tool. 
**Representation of CDs:**
My first implementation was parsing CDs into a predetermined structure for validation and other internal processing e.g. enforcing two digit precision for price, positive years etc.
```c++
struct CD {
   string title;
   string artist;
   string country;
   string company;
   float price;
   unsigned short int year;
};  
```
For the requested functionality it didn't seem worth the extra complexity introduced by parsing each field instead of iterating through the properties, and the apparent underlying structure may be subject to change, such as introducing currency symbols to the price column.
The simplest approach of a vector to construct each row ran into the problem of inconsistent ordering of fields, so I opted for a map to preserve the key-value pairs of the data.
For column headers the most efficient way to parse this specific file would be hard coding the constant list of columns, but I opted for the more flexible approach of collecting them in a set during parsing. This allows translation of a new or inconsistent schema at the cost of redundant insertions into the set, but given the relatively small size and log(n) cost per call it seemed an acceptable cost and is easily reversible.
For missing data I opted to leave the cell blank and log an error to indicate that there was an issue and which column to check, if partial data is not wanted in this scenario I would instead log the incomplete row and omit it from the table.
