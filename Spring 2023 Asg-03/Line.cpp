#include "Line.h"
// #include "helper.cpp"
bool DEBUG = false;
// HELPER FUNCTIONS

int getLength(const char *str) {
  int i = 0;
  if (str) {
    while (str[i++]) {
    }
    return i - 1;
  }
  return 0;
}
char *copyString(const char *S) {
  int l = getLength(S);
  char *temp = new char[l];
  int i = 0;
  for (i = 0; i < l; i++)
    temp[i] = S[i];
  temp[i] = '\0';
  return temp;
}
char *cutstr(char *str, int startIndex, int endIndex) {
  char *result;
  int l = getLength(str);
  if (startIndex < l && endIndex < l && startIndex < endIndex) {
    int newl = l - endIndex + startIndex;
    result = new char[newl];
    int i = 0;
    for (i = 0; i < startIndex; i++) {
      result[i] = str[i];
    }
    for (int j = endIndex; j < l; j++) {
      result[i++] = str[j];
    }
    result[newl] = '\0';
    return result;
  } else {
    return str;
  }
}
char *leftShift(char *str, int positions) {
  // cout << "OOOOOOOOOOOOOOOOOOOOO";
  if (positions < getLength(str)) {
    char *res;
    int l = getLength(str);
    if (l > 0 && positions < l) {
      int newL = l - positions;
      res = new char[newL];
      for (int i = 0; i < newL; i++) {
        res[i] = str[i + positions];
      }
      res[newL] = '\0';
    }
    // cout << "\nLS:" << str << "=>" << res << endl;
    // cout << "22222222222222222";
    return res;
  } else
    return "\0";
}
char *tokenPop(const char *str, char seperator = ' ') {
  // cout << "\n*&str/len" << str << "/" << getLength(str);
  char *token, *strResult, *tgt;
  // tgt = str[0];
  int i = 0, len = getLength(str);
  // tgt = new char[len];
  for (i = 0; i < len; i++) {
    if ((str)[i] == seperator) {
      // cout << "tgti:" << (tgt)[i];
      break;
    } else
      continue;
  }
  // condition chk
  if (i == len || i == 0 || i == 1) {
    // str[0] = '\0';
    return copyString(str);
  }
  i += 1;
  token = new char[i];
  // cout << "\ntok init:" << token << ", len:" << i;
  for (int j = 0; j < i; j++) {
    token[j] = str[j];
  }
  token[i] = '\0';
  // cout << "------tgt:" << tgt;
  // str = leftShift(str, i + 1);
  // cout << "111111111111111111111";
  cout << "\nT/S:" << token << "/" << str;
  // str = *tgt;
  return token;
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
};
char *concat(char a, char b) {
  // int lengthA = getLength(a);
  // int lengthB = getLength(b);
  char *result = new char[2];
  result[0] = a;
  result[1] = b;
  return result;
};
// returns the start index of the c-string being searched
int index_at(char *str, char *substr) {
  // if (GLOBAL_DEBUG)
  // cout << "Calling index_at Fn with args:" << str << ", " << substr << endl;
  //  << " of length:" << getLength(substr)
  int i = 0, j = 0;
  int lStr = getLength(str);
  int lSubstr = getLength(substr);
  for (i = 0; i < lStr; i++) {
    if (str[i] == substr[0]) {
      for (j = 0; j < lSubstr; j++) {
        if (str[i + j] == substr[j]) {

          continue;
        } else
          break;
      }
      if (j == lSubstr) {
        // cout << "<== returning index:" << i;
        return i;
      }
    }
  }
  // cout << "<== returning index:" << -1;
  return -1;
};
char *remove_substring(char *str, char *substr) {
  // if (DEBUG)
  // cout << "Calling remove_string_main Fn with args:" << str << ", " << substr
  //  << endl;
  // cout << "strLength:" << getLength(str);
  int sp = index_at(str, substr);
  if (sp >= 0) {
    int lStr = getLength(str);
    int lSubstr = getLength(substr);
    int l2 = lStr - lSubstr;
    char *temp;
    temp = new char[l2];
    // cout << "\ninit  DATA:" << temp;
    // cout << "\nStr/lStr:" << str << "/" << lStr << " | ";
    // cout << "subStr/lsubStr:" << substr << "/" << lSubstr << " | ";
    // cout << "L2:" << l2;
    int i = 0, j = 0;
    // cout << "\nCP2(i/str[i]):" << i << "\t" << str[i + lSubstr];
    for (i = 0; i < l2; i++) {
      // cout << "i:" << i;
      //   temp[i] = str[i];
      // }
      if (i < sp) {
        // cout << "\ncp1:" << str[i];
        temp[j++] = str[i];
        // cout << "\n=>  DATA:" << temp;
      } else if (i >= sp) {
        temp[j++] = str[i + lSubstr];
        // cout << "\n==>  DATA:" << i;
        // cout << ":" << temp[i];
        // cout << "\nCP2(i/str[i]):" << i << "\t" << str[i + lSubstr];
        // }else{
        //   temp[i]=
      }
      // i++;
      // for (j = sp + lSubstr; j < lStr; j++) {
      //   cout << "cp2";
      //   temp[i + j] = str[j];
      // }
    }
    temp[j] = '\0';
    // char *data = new char[l2];
    // int i = 0;
    // for (i = 0; i < lStr; i++) {
    //   str[i] = temp[i];
    // }
    // cout << "Returned  DATA:" << temp << endl;
    return temp;
    // assign_string_main(data);
  } else
    // cout << "Returned  DATA:xxx" << endl;
    return NULL;
};
enum colors {
  red = 31,
  green = 32,
  yellow = 33,
  blue = 34,
  magenta = 35,
  cyan = 36,
};
void colorOut(colors color, char *text) {
  cout << "\033[1;" << color << "m";
  cout << text;
  cout << "\033[0m";
}

Line::Line() {
  if (DEBUG)
    cout << "\n\n\n\t\t\tLine constructor called";
  data = new char;
  // length = maxLength;
  charIndex = 0;
  data[charIndex] = '\0';
}
Line::Line(int l) {
  if (DEBUG)
    cout << "\n\n\n\t\t\tLine constructorLength called, l:" << l;
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
  // colorOut(red, " char *text");
  int l = getLength(str);
  if (l <= remainingSpace()) {
    if (DEBUG) {
      colorOut(green, "\nSpace is aval");
    }
    setData(str);
  } else {
    if (DEBUG) {
      colorOut(red, "\nSpace not aval");
    }
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
  if (DEBUG) {
    cout << "CharIndex:" << charIndex;
    cout << ", Rem:" << remainingSpace();
    cout << ", i/data:";
  }
  if (!clean) {
    for (int i = 0; i < maxLength; i++) {
      cout << i % 10;
    }
    cout << endl;
  }
  for (int i = 0; i < maxLength; i++) {
    cout << data[i];
  }
  cout << endl;
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
  for (i = 0; i <= l; i++) {
    data[i + charIndex] = str[i];
  }
  charIndex += i;
  // data[charIndex] = '\0';
  if (DEBUG)
    cout << "\nData:" << data;
}
int Line::remainingSpace() const {
  if (DEBUG) {
    cout << "\nRemaining Space Fn called:" << maxLength << "/" << charIndex
         << "=" << maxLength - charIndex;
  }
  return maxLength - charIndex;
}
char *Line::getData() { return data; }