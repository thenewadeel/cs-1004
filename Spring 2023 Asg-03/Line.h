// Line.h
#ifndef LINE
#define LINE
#include <iostream>
using namespace std;

class Line {
private:
public:
  Line();
  Line(const char *);
  Line operator+=(const Line &rhs);
  Line operator=(const char *rhs);
};

#endif