Representation of CDs:
My first implementation was parsing CDs into a predetermined structure for validation and other internal processing e.g. enforcing two digit precision for price, positive years etc.
struct CD {
   string title;
   string artist;
   string country;
   string company;
   float price;
   unsigned short int year;
};  
For the requested functionality it didn't seem worth the extra complexity introduced by parsing each field instead of iterating through the properties, and the apparent underlying structure may be subject to change, such as introducing currency symbols to the price column.
I chose to store the data


https://cplusplus.com/forum/general/276345/
https://rapidxml.sourceforge.net/
