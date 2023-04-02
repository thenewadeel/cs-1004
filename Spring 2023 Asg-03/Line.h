// Line.h
#ifndef LINE
#define LINE
#include <iostream>
using namespace std;

class Line {
private:
  int maxLength = 40;
  int charIndex;
  char *data;

public:
  Line();
  Line(const char *);
  Line(int length);
  // void setData(char *str);
  void setData(const char *str);
  Line operator+=(const Line &rhs);
  Line operator=(const char *rhs);
  void debugOut() const;
};

#endif