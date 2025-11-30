

#ifndef Route_h
#define Route_h

#include <string>
using namespace std;

class Route {
public:
    Route(string s, string d): source(s), destination(d) {}
    string get_source()const { return source;}
    string get_destination()const { return destination;}

private:
    string source;
    string destination;
};

#endif