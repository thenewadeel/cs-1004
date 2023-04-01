#include "Page.h"

Page::Page() {
  cout << "Def Pg constructor called";
  lines = new Line[maxLines];
}
Page::Page(int nLines) {
  cout << "Pg constructor nLines called";
  lines = new Line[nLines];
  lineIndex = 0;
}
Page Page::operator+=(const Page &rhs){};
Page Page::operator+=(const Line &rhs) {
  cout << "Pg op+=2 rhs:";
  rhs.debugOut();
  cout << "/-";
  lines[lineIndex++] += rhs;
};
Page Page::operator+=(const char *rhs) { cout << "Pg op+=3 rhs:" << rhs; };
Line &Page::operator[](int lineNumber){};
void Page::debugOut() const {
  cout << "\n-------Pg---(" << lineIndex << ")-------\n";
  for (int i = 0; i < maxLines; i++) {
    cout << i << ":";
    lines[i].debugOut();
  }
  cout << "\n-------End Pg------\n";
}