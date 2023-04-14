// Page.h
#ifndef PAGE
#define PAGE
#include "Line.cpp"
#include <iostream>
using namespace std;

class Page {
private:
  const int maxLines = 20;
  int lineIndex = 0;
  Line *lines;
  //   int b, a;

public:
  Page();
  Page(int nLines);
  Page operator+=(const Page &rhs);
  Page operator+=(const Line &rhs);
  Page operator+=(const char *rhs);
  Line &operator[](int lineNumber);
  void debugOut(int) const;
};

#endif