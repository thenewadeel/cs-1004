#include "BinaryStore.h"

int getLength(char *str) {
  int i = 0;
  if (str) {
    while (str[i++]) {
    }
    return i - 1;
  }
  return 0;
}
char *fill(char *tgt, char c, int len) {
  int lengthTgt;
  if (len == 0)
    lengthTgt = getLength(tgt);
  else
    lengthTgt = len;
  char *result = new char[lengthTgt];
  for (int i = 0; i < lengthTgt; i++) {
    result[i] = c;
  }
  return result;
}
char *concat(char *a, char *b) {
  int lengthA = getLength(a);
  int lengthB = getLength(b);
  char *result = new char[lengthA + lengthB];
  for (int i = 0; i < lengthA; i++) {
    result[i] = a[i];
  }
  for (int i = 0; i < lengthB; i++) {
    result[lengthA + i] = b[i];
  }
  // cout << endl << a << " + " << b << " = " << result;
  return result;
}
char *push_left(char *tgt, char *load) {
  int lengthTgt = getLength(tgt);
  int lengthLoad = getLength(load);
  // cout << endl << tgt << " < " << load; //<< " = " << result;
  char *result = new char[lengthTgt + lengthLoad];
  return concat(load, tgt);
}

// class BinaryStore:: {
// int ByteSize = 8, filledAddresses, lengthMax;
// add suitable member attributes
// char **addresses, **values;

// public:
// constructor which creates the store of length len.
BinaryStore::BinaryStore(int len) {
  lengthMax = len;
  filledAddresses = 0;
  addresses = new char *[len];
  values = new char *[len];
}
// add a new address in the list of Binary store.
void BinaryStore::add_Address(char *s) {
  if (filledAddresses < lengthMax) {
    addresses[filledAddresses++] = s;
    cout << "Address(" << s << ") added, filled/total:" << filledAddresses
         << "/" << lengthMax;
  }
}
// add the byte at newly added address
// here the first parameter is address and second is byte// Similarly the
// following code adds byte address and later byte // if address not found add
// address and byte both // function also overrides the data given at
// particular byte address.
void BinaryStore::set_Byte(char *address, char *value) {
  int i = 0;
  bool found = 0;
  for (i = 0; i < filledAddresses; i++) {
    if (comp_EQUAL(address, (addresses[i]))) {
      found = 1;
      break;
    }
  }
  if (found) {
    values[i] = value;
  } else {
    add_Address(address);
    values[filledAddresses] = value;
  }
}
// Get function will retrieve the byte at a give address ,
char *BinaryStore::Get(char *address) {
  int i = 0;
  bool found = 0;
  for (i = 0; i < filledAddresses; i++) {
    if (comp_EQUAL(address, (addresses[i]))) {
      found = 1;
      break;
    }
  }
  if (found) {
    cout << "Returning(" << address << "):" << values[i];
    return values[i];
  } else
    return "Not Found";
}
// return the BinaryStore as character dynamic array.
char *BinaryStore::ToString() {
  int dimension = lengthMax * 20;
  // cout << "Dim:" << dimension;
  // cout << "\nAdds(n):" << filledAddresses;
  char *s = new char[dimension];
  int k = 0;
  for (int i = 0; i < filledAddresses; i++) {
    char *address = addresses[i];
    cout << "\nAd:" << address;
    int address_Length = getLength(address);
    // cout << "\nAdds(l):" << address_Length;
    for (int j = 0; j < address_Length; j++) {
      s[i + j + k] = (address[j] != '\0') ? address[j] : ' ';
      cout << "\nijk:" << i + j + k;
      cout << "s:" << s;
    }
    k += address_Length - 1;
  }
  return s;
}
// ADD function will take two strings as input parameters and given the binary
// equivalent in form of string.
char *BinaryStore::Add(char *a, char *b) {
  // If the length of string A is greater than the length
  // of B then just swap the string by calling the
  // same function and make sure to return the function
  int lengthA = getLength(a);
  int lengthB = getLength(b);
  if (lengthA > lengthB)
    return Add(b, a);
  // Calculating the difference between the length of the
  // two strings.
  int diff = lengthB - lengthA;
  char *res;
  char carry = '0';

  for (int i = lengthA - 1; i >= 0; i--) {
    // This condition solves 110 111 possible cases
    if (a[i] == '1' && b[i] == '1') {
      if (carry == '1')
        res = push_left(res, "1"), carry = '1';
      else
        res = push_left(res, "0"), carry = '1';
      // res.push_back('0'), carry = '1';
    }
    // This condition solves 000 001 possible cases
    else if (a[i] == '0' && b[i] == '0') {
      if (carry == '1')
        res = push_left(res, "1"), carry = '0';
      // res.push_back('1'), carry = '0';
      else
        res = push_left(res, "0"), carry = '0';
      // res.push_back('0'), carry = '0';
    }
    // This condition solves 100 101 010 011 possible cases
    else if (a[i] != b[i]) {
      if (carry == '1')
        res = push_left(res, "0"), carry = '1';
      // res.push_back('0'), carry = '1';
      else
        res = push_left(res, "1"), carry = '0';
      // res.push_back('1'), carry = '0';
    }
  }

  // If at the end there is carry then just add it to the
  // result
  if (carry == '1')
    res = push_left(res, "1"); //, carry = '0';
  // cout << endl
  //  << a << "+" << b << "=" << res << "(" << getLength(res) << ")" << endl;
  res[8] = '\0';
  return res;
}
//  comp_EQUAL, comp_AND, and comp_OR function will take two strings as input
//  parameters and given the binary equivalent in form of string.
bool BinaryStore::comp_EQUAL(char *a, char *b) {
  // cout << "\nComparing " << a << " & " << b;
  int lengthA = getLength(a);
  int lengthB = getLength(b);
  if (lengthA == lengthB) {
    for (int i = 0; i < lengthA; i++) {
      // cout << "\nCharCheck:" << a[i] << "/" << b[i] << ":" << (a[i] ==
      // b[i]);
      if (a[i] == b[i]) {
        continue;
      } else {
        // cout << "NOPE";
        return false;
      }
    }
    // cout << "YAY";
    return true;
  }
  // cout << "NOPE";
  return false;
}
char *BinaryStore::comp_AND(char *a, char *b) {
  char *result = new char[10];
  int lengthA = getLength(a);
  for (int i = lengthA - 1; i >= 0; i--) {
    result[i] = char_AND(a[i], b[i]);
  }
  return result;
}
char *BinaryStore::comp_OR(char *a, char *b) {
  char *result = new char[10];
  int lengthA = getLength(a);
  for (int i = lengthA - 1; i >= 0; i--) {
    result[i] = char_OR(a[i], b[i]);
  }
  return result;
}
char *BinaryStore::comp_NOT(char *a, char *b) { return comp_NOT(a); }
char *BinaryStore::comp_NOT(char *a) {
  char *result = new char[10];
  int lengthA = getLength(a);
  for (int i = lengthA - 1; i >= 0; i--) {
    // cout << i << ":" << result[i] << ":" << a[i] << ":" << char_NOT(a[i])
    //  << endl;
    result[i] = char_NOT(a[i]);
  }
  return result;
}
BinaryStore::~BinaryStore() { ; }

// private:
char BinaryStore::char_OR(char a, char b) {
  if (a == '1' || b == '1')
    return '1';
  else
    return '0';
}
char BinaryStore::char_AND(char a, char b) {
  if (a == '1' && b == '1')
    return '1';
  else
    return '0';
}
char BinaryStore::char_NOT(char a) {
  if (a == '1')
    return '0';
  else
    return '1';
}
