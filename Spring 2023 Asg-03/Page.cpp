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
Page Page::operator+=(const char *rhs) {
  if (DEBUG) {
    cout << "Pg op+=3 rhs:" << rhs;
  }
  int i = 0, lineNo = lineIndex;
  int l = getLength(rhs);
  char *str = new char[l];
  for (i = 0; i < l; i++) {
    str[i] = rhs[i];
  }
  str[i] = '\0';
  int remainingStrLength = getLength(str);
  // bool skipToken = false;
  char *token = tokenPop(str);
  str = remove_substring(str, token);
  remainingStrLength = getLength(str);
  do {
    if (lines[lineNo].remainingSpace() >= getLength(token)) {
      lines[lineNo] += token;
      lines[lineNo] += " ";
      token = tokenPop(str);
      str = remove_substring(str, token);
      remainingStrLength = getLength(str);
      debugOut(1);
      // skipToken = false;
    } else {
      lineNo++;
      // skipToken = true;
    }
  } while (lineNo < maxLines || remainingStrLength > 0);
};
Line &Page::operator[](int lineNumber){};
void Page::debugOut(int clean = 0) const {
  cout << "\n-------Pg---(" << lineIndex << ")-------\n";
  for (int i = 0; i < maxLines; i++) {
    cout << i << ":";
    if (!clean)
      lines[i].debugOut();
    else {
      cout << lines[i].getData() << endl;
    }
  }
  cout << "\n-------End Pg------\n";
}