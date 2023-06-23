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
public:
    void addHeader (const string header)
   {
    this->headers.insert(header);
   }
   vector<string> getHeaders()
   {
    vector<string> vc(headers.size());
    copy(headers.begin(), headers.end(), headers.begin());
   }
};