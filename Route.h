

#ifndef Route_h
#define Route_h

#include <string>
using namespace std;

class Route {
public:
    Route(string s, string d): source(s), destination(d) {}
    string get_source() { return source;}
    string get_destination() { return destination;}

private:
    string source;
    string destination;
};

#endif