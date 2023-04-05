#include "iostream"
using namespace std;

int getLength(const char *str) {
  int i = 0;
  if (str) {
    while (str[i++]) {
    }
    return i - 1;
  }
  return 0;
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
char *tokenPop(char *&str, char seperator = ' ') {
  // cout << "\n*&str/len" << str << "/" << getLength(str);
  char *token, *strResult, *tgt;
  tgt = str;
  int i = 0, len = getLength(tgt);
  strResult = new char[len];
  for (i = 0; i < len; i++) {
    if ((tgt)[i] == seperator) {
      // cout << "tgti:" << (tgt)[i];
      break;
    } else
      continue;
  }
  // condition chk
  if (i == len || i == 0) {
    str[0] = '\0';
    return NULL;
  }
  token = new char[i];
  // cout << "\ntok init:" << token << ", len:" << i;
  for (int j = 0; j < i; j++) {
    token[j] = tgt[j];
  }
  token[i] = '\0';
  // cout << "------tgt:" << tgt;
  str = leftShift(str, i + 1);
  // cout << "111111111111111111111";
  // cout << "\nstr:" << str;
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
}
