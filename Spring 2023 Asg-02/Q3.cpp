#include <iostream>
using namespace std;

int getLength(char *str) {
  int i = 0;
  if (str) {
    while (str[i++]) {
    }
    return i - 1;
  }
  return 0;
}

class BinaryStore {
  int ByteSize = 8, filledAddresses, lengthMax;
  // add suitable member attributes
  char **addresses, **values;

public:
  // constructor which creates the store of length len.
  BinaryStore(int len = 16) {
    lengthMax = len;
    filledAddresses = 0;
    addresses = new char *[len];
    values = new char *[len];
  }
  // add a new address in the list of Binary store.
  void add_Address(char *s) {
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
  void set_Byte(char *address, char *value) {
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
  char *Get(char *address) {
    int i = 0;
    bool found = 0;
    for (i = 0; i < filledAddresses; i++) {
      if (comp_EQUAL(address, (addresses[i]))) {
        found = 1;
        break;
      }
    }
    if (found) {
      return values[i];
    } else
      return "Not Found";
  }
  // return the BinaryStore as character dynamic array.
  char *ToString() {
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
  char *Add(char *a, char *b);
  //  comp_EQUAL, comp_AND, and comp_OR function will take two strings as input
  //  parameters and given the binary equivalent in form of string.
  bool comp_EQUAL(char *a, char *b) {
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
  char *comp_AND(char *a, char *b) {
    char *result = "asd";
    return result;
  }
  char *comp_OR(char *a, char *b);
  char *comp_NOT(char *a, char *b);
  char *comp_NOT(char *a);
  ~BinaryStore() { ; }

private:
  char char_OR(char a, char b) {
    if (a == '1' || b == '1')
      return '1';
    else
      return '0';
  }
  char char_AND(char a, char b) {
    if (a == '1' && b == '1')
      return '1';
    else
      return '0';
  }
  char char_NOT(char a) {
    if (a == '1')
      return '0';
    else
      return '1';
  }
};
int main() {
  BinaryStore b(3);
  b.add_Address("123");
  b.set_Byte("123", "ewqweq");
  cout << "\nRetrieved:" << b.Get("123");
  b.add_Address("x0");
  b.set_Byte("x0", "ewqweq");
  cout << "\nRetrieved:" << b.Get("x0");
  b.add_Address("Q");
  b.set_Byte("Q", "ewqweq");
  cout << "\nRetrieved:" << b.Get("qw");
  // cout << "a:" << b.comp_EQUAL(" ", " ");
  cout << "a:" << b.ToString();
}