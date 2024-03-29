#include <iostream>
using namespace std;

class BigInt {
  int *arr;
  int size; // think about the private data members
public:
  BigInt(int val = 0) {
    if (val == 0) {
      size = 1;
      arr = new int[size];
      arr[0] = 0;
    }

    else {
      int temp;
      temp = val;
      size = 0;
      while (temp != 0) {
        temp = temp / 10;
        size++;
      }
      arr = new int[size];
      for (int i = size - 1; i >= 0; i--) {
        arr[i] = val % 10;
        val = val / 10;
      }
    }
  }

  BigInt(const string &text) {
    size = 0;
    while (text[size] != '\0') {
      size++;
    }
    arr = new int[size];
    for (int i = 0; i < size; i++) {
      arr[i] = text[i] - '0';
      // cout<<arr[i]<<" ";
    }
  }

  BigInt(const BigInt &copy) {
    size = copy.size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
      arr[i] = copy.arr[i];
    }
  }
  // copy constructor
  // Binary Operators
  // Arithmetic Operators

  BigInt operator+(const BigInt &val) const {
    // cout << "Op+ called val:";
    // val.debugOut();
    // cout << ":" << val.size;
    // cout << ", this:";
    // debugOut();
    // cout << ":" << size;
    BigInt result;
    int carry = 0;
    int maxlength;
    int sum;

    if (size > val.size)
      maxlength = size;
    else
      maxlength = val.size;
    // cout << "maxLen:" << maxlength;
    result.arr = new int[maxlength];
    for (int i = 0; i <= maxlength; i++) {
      //   cout << "I:" << i;
      //   cout << ", val[arr]:" << val.arr[i];
      //   cout << ", arr:" << arr[i];
      //   cout << ", Sum:" << sum;
      //   cout << ", carry:" << carry;
      //   cout << ", REsult[i]:" << result.arr[i];
      //   cout << endl;
      sum = carry;
      if (i <= val.size)
        sum += val.arr[val.size - i];
      if (i <= size)
        sum += arr[size - i];
      result.arr[maxlength - i] = sum % 10;
      carry = sum / 10;
      //   cout << "i:" << i;
      //   cout << "val[arr]:" << val.arr[maxlength - i];
      //   cout << ", arr:" << arr[maxlength - i];
      //   cout << ", Sum:" << sum;
      //   cout << ", carry:" << carry;
      //   cout << ", REsult[i]:" << result.arr[maxlength - i];
      //   cout << endl;
    }

    if (carry == 1) {
      //   cout << "****************************";
      int *temp = new int[maxlength + 1];
      temp[0] = carry;

      for (int i = 0; i < maxlength; i++) {
        temp[i + 1] = result.arr[i];
      }

      delete[] result.arr;
      result.arr = new int[maxlength + 1];
      for (int i = 0; i < maxlength + 1; i++) {
        result.arr[i] = temp[i];
        // cout << "temp[i]:" << temp[i];
        // cout << ", REsult[i]:" << result.arr[i];
      }
      result.size = maxlength + 1;
    } else {
      result.size = maxlength;
    }
    // for (int i = 0; i < result.size; i++) {
    //   cout << i << ":";
    //   cout << result.arr[i];
    //   cout << endl;
    // }
    // cout << *result.arr;
    // cout << " ";
    return result;
  }

  // BigInt operator+(int val) const;

  // BigInt operator-(const BigInt& val) const;
  // BigInt operator-(int val) const;

  // BigInt operator+=(const BigInt& rhs);
  // BigInt operator-=(const BigInt& rhs);
  // BigInt operator*=(const BigInt& rhs);

  // Logical Operators
  bool operator==(const BigInt &val) const {
    if (size != val.size)
      return false;

    for (int i = 0; i < size; i++) {
      if (arr[i] != val.arr[i])
        return false;
    }
    return true;
  }
  bool operator==(const char *val) const {
    int length = 0;
    while (val[length] != '\0')
      length++;

    if (size != length)
      return false;

    for (int i = 0; i < size; i++) {
      if (arr[i] != val[i] - '0')
        return false;
    }
    return true;
  }
  bool operator!=(const BigInt &val) const {
    if (size != val.size)
      return true;

    for (int i = 0; i < size; i++) {
      if (arr[i] != val.arr[i])
        return true;
    }
    return false;
  }
  bool operator<(const BigInt &val) const {
    if (size > val.size)
      return false;

    for (int i = 0; i < size; i++) {
      if (arr[i] < val.arr[i])
        return true;
    }
    return false;
  }
  bool operator<=(const BigInt &val) const {
    if ((size > val.size) && (size != val.size))
      return false;

    for (int i = 0; i < size; i++) {
      if (arr[i] >= val.arr[i])
        return true;
    }
    return false;
  }
  bool operator>(const BigInt &val) const {
    if (size < val.size)
      return false;

    for (int i = 0; i < size; i++) {
      if (arr[i] > val.arr[i])
        return true;
    }
    return false;
  }
  bool operator>=(const BigInt &val) const {
    if ((size < val.size) && (size != val.size))
      return false;

    for (int i = 0; i < size; i++) {
      if (arr[i] <= val.arr[i])
        return true;
    }
    return false;
  }
  /*
  // Unary Operators
  BigInt& operator++()
  {

  } // Pre-increment Operator
  BigInt operator++(int)
  {
  for(int i = 0 ; i< size ; i++)
          {
          arr[i]++ ;
          }
          return *this;
  }// Post-increment Operator
  BigInt& operator--(); // Pre-decrement Operator
  BigInt operator--( int ); // Post-decrement Operator
  */
  // Conversion Operator
  operator string() {

    char *ary = new char[size + 1];
    for (int i = 0; i < size; i++) {
      ary[i] = arr[i] + '0';
    }
    ary[size] = '\0';
    return ary;
  }
  void debugOut() const {
    for (int i = 0; i < size; i++) {
      cout << arr[i];
    }
  }

}; // return value of the BigInt as string
// Operator int(); // return the number of digits in big Integer
//~BigInt(); // destructor
// };
