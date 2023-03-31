#include "Page.h"

Page::Page() {}
Page Page::operator+=(const Page &rhs){};
Page Page::operator+=(const Line &rhs){};
Page Page::operator+=(const char *rhs){};
Line &Page::operator[](int lineNumber){};