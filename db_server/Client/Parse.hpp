#ifndef PARSE_HPP
#define PARSE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "file_client.hpp"
using namespace std;

// Base class
class Parse
{
public:
    virtual ~Parse() {}
    virtual void parseString(const string &input) = 0;
    virtual string getData(int id) = 0;
};

#endif // PARSE HPP