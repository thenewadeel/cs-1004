#include "Line.h"
#include "helper.cpp"
bool DEBUG = false;
Line::Line() {
  if (DEBUG)
    cout << "\nLine constructor called";
  data = new char[maxLength];
  // length = maxLength;
  data[maxLength] = '\0';
  charIndex = 0;
}
Line::Line(int l) {
  if (DEBUG)
    cout << "\nLine constructorLength called, l:" << l;
  // if (l <= maxLength) {
  //   length = l;
  // } else {
  //   length = maxLength;
  // }
  data = new char[maxLength];
  data[maxLength] = '\0';
  charIndex = 0;
}
Line::Line(const char *str) {
  if (DEBUG)
    cout << "\nLine constructor2 called, *str:" << str;
  int l = getLength(str);
  // if (l + charIndex <= maxLength) {
  //   length = l;
  // } else {
  //   length = maxLength;
  // }
  data = new char[maxLength];
  int i;
  for (i = 0; i < maxLength && i < l; i++) {
    data[i] = str[i];
  }
  charIndex = i;
  data[charIndex] = '\0';
  if (DEBUG)
    cout << "\nData:" << data;
}
Line Line::operator+=(const char *str) {
  if (DEBUG)
    cout << "\nLine op+= char* called, *str:" << str;
  int l = getLength(str);
  if (l < remainingSpace()) {
    cout << "\nSpace is aval";
    setData(str);
  } else {
    cout << "\nSpace not aval";
  }
}
Line Line::operator+=(const Line &rhs) {
  if (DEBUG)
    cout << "\nLine op+= called, *rhs:" << rhs.data;
  int newLength;
  if (charIndex + rhs.charIndex <= maxLength) {
    newLength = charIndex + rhs.charIndex;
  } else {
    newLength = maxLength;
  }
  Line newline(newLength);
  newline.setData(concat(data, rhs.data));
  //   newline.length = newLength;
  //   newline.data[newLength] = '\0';

  setData(newline.data);

  if (DEBUG)
    cout << "\nData:" << data;
  return *this;
}
Line Line::operator=(const char *rhs) {
  if (DEBUG)
    cout << "\nLine op= called, *rhs:" << rhs;
  setData(rhs);
  return *this;
}
void Line::debugOut(int clean) const {
  // cout << "\nmL:" << maxLength;
  if (!clean) {
    cout << ", I:" << charIndex;
    cout << ", Rem:" << remainingSpace();
    cout << ", i/data:\n";
    for (int i = 0; i < maxLength; i++) {
      cout << i % 10;
    }
    cout << endl;
  }
  for (int i = 0; i < maxLength; i++) {
    cout << data[i];
  }
}
// void Line::setData(char *str) {
//   if (DEBUG)
//     cout << "\nSetData called, str:" << str;
//   int l = getLength(str);
//   if (l <= maxLength) {
//     length = l;
//   } else {
//     length = maxLength;
//   }
//   data = new char[length];
//   for (int i = 0; i < length; i++) {
//     data[i] = str[i];
//   }
//   data[length] = '\0';
//   if (DEBUG)
//     cout << "\nData:" << data;
// }
void Line::setData(const char *str) {
  if (DEBUG)
    cout << "\nSetData called, str:" << str;
  int l = getLength(str);
  // if (l <= maxLength) {
  //   length = l;
  // } else {
  //   length = maxLength;
  // }
  // data = new char[maxLength];
  int i;
  for (i = 0; i < l; i++) {
    data[i + charIndex] = str[i];
  }
  charIndex += i;
  data[charIndex + 1] = '\0';
  if (DEBUG)
    cout << "\nData:" << data;
}
int Line::remainingSpace() const {
  if (DEBUG) {
    cout << "\nRemaining Space Fn called";
  }
  return maxLength - charIndex;
}
char *Line::getData() { return data; }