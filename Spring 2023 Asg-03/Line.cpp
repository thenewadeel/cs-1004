#include "Line.h"
bool DEBUG = false;
int getLength(const char *str) {
  int i = 0;
  if (str) {
    while (str[i++]) {
    }
    return i - 1;
  }
  return 0;
}
char *concat(const char *a, const char *b) {
  int lengthA = getLength(a);
  int lengthB = getLength(b);
  char *result = new char[lengthA + lengthB];
  for (int i = 0; i < lengthA; i++) {
    result[i] = a[i];
  }
  for (int i = 0; i < lengthB; i++) {
    result[lengthA + i] = b[i];
  }
  result[lengthA + lengthB] = '\0';
  cout << endl << a << " + " << b << " = " << result;
  return result;
}

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
void Line::debugOut() const {
  // cout << "\nmL:" << maxLength;
  cout << ", I:" << charIndex;
  cout << ", i/data:\n";
  for (int i = 0; i < maxLength; i++) {
    cout << i % 10;
  }
  cout << endl;
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