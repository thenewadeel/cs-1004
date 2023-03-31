// Page.h
#ifndef PAGE
#define PAGE
#include "Line.cpp"
#include <iostream>
using namespace std;

class Page {
private:
  //   int b, a;

public:
  Page();
  Page operator+=(const Page &rhs);
  Page operator+=(const Line &rhs);
  Page operator+=(const char *rhs);
  Line &operator[](int lineNumber);
};

#endif