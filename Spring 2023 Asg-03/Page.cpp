#include "Page.h"

Page::Page() {
  if (DEBUG)
    cout << "Def Pg constructor called";
  lines = new Line[maxLines];
  lineIndex = 0;
}
Page::Page(int nLines) {
  if (DEBUG)
    cout << "Pg constructor nLines called:" << nLines;
  lines = new Line[nLines <= maxLines ? nLines : maxLines];
  lineIndex = 0;
}
Page Page::operator+=(const Page &rhs){};
Page Page::operator+=(const Line &rhs) {
  if (DEBUG)
    cout << "Pg op+=2 rhs:";
  rhs.debugOut();
  cout << "/-";
  lines[lineIndex++] += rhs;
};
Page Page::operator+=(const char *rhs) {
  if (DEBUG) {
    colorOut(magenta, "Pg op+=3 rhs:");
    cout << rhs << endl;
    debugOut(1);
  }
  int i = 0;
  int strLength = getLength(rhs);
  int lineSpace = lines[lineIndex].remainingSpace();
  if (lineSpace > strLength) {
    colorOut(blue, "Space of entire str is aval");
    lines[lineIndex] += rhs;
  } else {
    colorOut(yellow, "Space of entire str is NOT aval");
    char *str = copyString(rhs);
    for (int x = 0; x < getLength(str) - 1; x += 2) {
      // colorOut(red, "WWW");
      // cout << avalSpace << "/" << str[x];
      if (lines[lineIndex].remainingSpace() >= 2) {
        lines[lineIndex] += concat(str[x], str[x + 1]);
        // cout << x;
      } else {
        // cout << ":" << x;
        x -= 2;
        lineIndex++;
        continue;
      }
    }
    // char *str=remove_substring(rhs,token);
  }
  // str[i] = '\0';
  // bool skipToken = false;
  // char *token = tokenPop(str);
  // do {
  //   if (remainingStrLength > 0 &&
  //       lines[lineIndex].remainingSpace() >= getLength(token)) {
  //     cout << "\nStr/Length:" << str << "/" << getLength(str);
  //     cout << "\nToken/Length:" << token << "/" << getLength(token);
  //     lines[lineIndex] += token;
  //     colorOut(red, "AAA");
  //     lines[lineIndex].debugOut(1);
  //     // lines[lineIndex] += " ";
  //     str = remove_substring(str, token);
  //     cout << "\nStr/Length:" << str << "/" << getLength(str);
  //     token = tokenPop(str);
  //     cout << "\nPoppedToken/Length:" << token << "/" << getLength(token);
  //     remainingStrLength = getLength(str);
  //   } else {
  //     lineIndex++;
  //     colorOut(red, "CP:::::::::::::::::");
  //     cout << "\nStr/Length:" << str << "/" << getLength(str);
  //     cout << "\nToken/Length:" << token << "/" << getLength(token);
  //     skipToken = true;
  //   }

  // } while (lineIndex < maxLines && remainingStrLength > 0);
  // debugOut(1);
};
Line &Page::operator[](int lineNumber) { return lines[lineNumber]; };
void Page::debugOut(int clean = 0) const {
  // if (!clean) {
  colorOut(blue, "\n-------Pg---(");
  cout << lineIndex;
  colorOut(blue, ")-------\n");
  if (DEBUG) {
    cout << "Page Meta:";
    cout << "Number of Lines:" << lineIndex;
    cout << "\tMax Lines:" << maxLines;
  }
  // }
  for (int i = 0; i < maxLines; i++) {
    cout << i << ":";
    lines[i].debugOut(clean);
  }
  colorOut(blue, "\n-------End Pg------\n");
}