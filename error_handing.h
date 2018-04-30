//#include <string>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
inline void error(const string& s)
{
	throw runtime_error(s);
}
