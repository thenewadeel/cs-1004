#include <iostream>
#include <string>
using namespace std;

class Member {
private:
  int id;
  string name;
  string address;
  int phonenumber;
  string membership_type;

public:
  int issued_books_count;
  int max_issued_books = 5;
  int *issued_books;
  int memberid;
  // int issued_books;
  Member() {
    id = 0;
    name = "";
    address = "";
    phonenumber = 0;
    issued_books_count = 0;
    memberid = 0;
  }
  Member(int memberid, string membername, string memberaddress,
         int memberphonenumber, string Membership_type) {
    id = memberid;
    name = membername;
    address = memberaddress;
    phonenumber = memberphonenumber;
    membership_type = Membership_type;
    issued_books = new int[max_issued_books];
    memberid = 0;
    // issued_books = 0;
    // max_issued_books = 5;

    if (membership_type == "Student") {
      max_issued_books = 3;
    } else if (membership_type == "Faculty") {
      max_issued_books = 5;
    } else {
      max_issued_books = 0;
    }
  }
  void Issuedbooks(int bookid) {
    if (issued_books_count < max_issued_books) {
      issued_books[issued_books_count] = bookid;
      issued_books_count++;
    } else {
      cout << "max books already issued";
    }
  }
  void set_id(int memberid) { id = memberid; }
  int get_id() { return id; }
  void set_name(string membername) { name = membername; }
  string get_name() { return name; }
  void set_address(string memberaddress) { address = memberaddress; }
  string get_address() { return address; }
  void set_memberphonenumber(int memberphonenumber) {
    phonenumber = memberphonenumber;
  }
  int get_memberphonenumber() { return phonenumber; }
  void set_membership_type(string Membership_type) {
    membership_type = Membership_type;
  }
  string get_membership_type() { return membership_type; }
  int get_max_issued_books() { return max_issued_books; }
  int get_issued_books_count() { return issued_books_count; }
  void decrement_issued_books_count() { issued_books_count--; }
  void display() {
    cout << "MemberID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phonenumber << endl;
  }
};
class Student : public Member {
private:
  int issuance_limit = 3;
  string duedate = "1month"; // 1 month
public:
  Student(string stdname) { set_name(stdname); }
  Student(int stdid = 0, string stdname = "", string stdaddress = "",
          int stdphonenumber = 0) {
    set_id(stdid);
    set_address(stdaddress);
    set_name(stdname);
    set_memberphonenumber(stdphonenumber);
  }
  int get_issuancelimit() { return issuance_limit; }
  string get_duedate() { return duedate; }
  void display() {
    Member::display();
    cout << "Issuance Limit: " << issuance_limit << endl;
    cout << "Due Date: " << duedate << endl;
  }
};
class Faculty : public Member {
private:
  int issuance_limit = 5;
  string duedate = "2month"; // 1 month
public:
  Faculty(int memberid = 0, string membername = "", string memberaddress = "",
          int memberphonenumber = 0) {
    set_id(memberid);
    set_address(memberaddress);
    set_name(membername);
    set_memberphonenumber(memberphonenumber);
  }

  int get_issuancelimit() { return issuance_limit; }
  string get_duedate() { return duedate; }
  void display() {
    Member::display();
    cout << "Issuance Limit: " << issuance_limit << endl;
    cout << "Due Date: " << duedate << endl;
  }
};
enum BookType { Book, Magazine, Journal, StoryBook };
string BookType_toString(BookType b) {
  switch (b) {
  case Magazine:
    return "Magazine";
    break;
  case Journal:
    return "Journal";
    break;
  case StoryBook:
    return "StoryBook";
    break;
  }
}
class Books {
private:
  int id;
  string name;
  string author;
  int edition;
  string purchasedate;
  bool available;
  BookType type;

public:
  Books() {
    id = 0;
    name = "";
    author = "";
    edition = 0;
    purchasedate = "";
    available;
    type = Magazine;
  }
  Books(string bookname) { name = bookname; }
  Books(int bookid, string bookname, string bookauthor, int bookedition,
        string bookpurchasedate, bool isavailable = true,
        BookType bookType = Magazine) {
    id = bookid;
    name = bookname;
    author = bookauthor;
    edition = bookedition;
    purchasedate = bookpurchasedate;
    available = isavailable;
    type = bookType;
  }
  void set_id(int bookid) { id = bookid; }
  int get_id() { return id; }
  void set_name(string bookname) { name = bookname; }
  string get_name() { return name; }
  void set_type(BookType bookType) { type = bookType; }
  BookType get_type() { return type; }
  void set_author(string bookauthor) { author = bookauthor; }
  string get_author() { return author; }
  void set_edition(int bookedition) { edition = bookedition; }
  int get_edition() { return edition; }
  void set_purchasedate(string bookpurchasedate) {
    purchasedate = bookpurchasedate;
  }
  string get_purchasedate() { return purchasedate; }
  void set_availability(bool isavailable) { available = isavailable; }
  bool get_availability() { return available; }
  /*
  void set_issued_to(Member member)
  {
      issued_to = member;
  }
  Member get_issued_to()
  {
      return issued_to;
  }
  */
  void display() {
    cout << "Name of Book: " << name << endl;
    cout << "Type: " << BookType_toString(type) << endl;
    cout << "Author: " << author << endl;
    cout << "Edition : " << edition << endl;
    cout << "Purchasedate :" << purchasedate << endl;
  }
};
class Library {
public:
  int max_magazines = 50;
  int max_journals = 50;
  int max_storybooks = 50;
  int max_students = 50;
  int max_faculty = 50;

  Books magazines[50];
  Books journal[50];
  Books storybook[50];
  int nummagazines = 0;
  int numjournals = 0;
  int numstorybooks = 0;
  int nummembers = 0;
  // Member memberstudent[50];
  // Member memberfaculty[50];
  int num_issued_books = 0;
  int journals_issued = 0;
  int magazines_issued = 0;
  int storybooks_issued = 0;

  Library() {
    nummagazines = 0;
    numjournals = 0;
    numstorybooks = 0;
    nummembers = 0;
  }
  // public:
};

class Librarian : public Library {
private:
  string username;
  string password;

public:
  Librarian() {
    username = "";
    password = "";
  }
  Librarian(string un, string pass) {
    username = un;
    password = pass;
  }
  bool login(string un, string pass) {
    if (this->username == un && this->password == pass)
      return true;
    return false;
  }

public:
  void addbooks(int id, string name, string author, int edition,
                string purchasedate, BookType bookType = Magazine) {
    Books new_book(id, name, author, edition, purchasedate, bookType);
    for (int i = 0; i < numstorybooks; i++) {
      if (storybook[i].get_name() == name) {
        cout << "Book already exists in the library." << endl;
        return;
      }
    }
    for (int i = 0; i < numjournals; i++) {
      if (journal[i].get_name() == name) {
        cout << "Book already exists in the library." << endl;
        return;
      }
    }
    for (int i = 0; i < nummagazines; i++) {
      if (magazines[i].get_name() == name) {
        cout << "Book already exists in the library." << endl;
        return;
      }
    }
    // Add
    if (new_book.get_type() == Magazine) {
      if (nummagazines < max_magazines) {
        magazines[nummagazines] = new_book;
        nummagazines++;
        cout << "Magazine added to library." << endl;
      } else {
        cout << "Maximum number of magazines reached" << endl;
      }
    } else if (new_book.get_type() == Journal) {
      if (numjournals < max_journals) {
        journal[numjournals] = new_book;
        numjournals++;
        cout << "Journal added to library." << endl;
      } else {
        cout << "Maximum number of journals reached." << endl;
      }
    } else if (new_book.get_type() == StoryBook) {
      if (numstorybooks < max_storybooks) {
        storybook[numstorybooks] = new_book;
        numstorybooks++;
        cout << "Storybook added to library." << endl;
      } else {
        cout << " Maximum number of storybooks reached." << endl;
      }
    } else {
      cout << "Error: Invalid book type." << endl;
    }
  }
  bool searchbook(string name) {
    // Books new_book(name);
    bool search = false;

    for (int i = 0; i < nummagazines; i++) {
      if (magazines[i].get_name() == name) {
        search = true;
        cout << "Magazine found" << endl;
      }
    }
    if (!search) {
      for (int i = 0; i < numjournals; i++) {
        if (journal[i].get_name() == name) {
          search = true;
          cout << "Journal found" << endl;
        }
      }
    }
    if (!search) {
      for (int i = 0; i < numstorybooks; i++) {
        if (storybook[i].get_name() == name) {
          search = true;
          cout << "Storybook found" << endl;
        }
      }
    }
    if (!search) {
      cout << "NOT found" << endl;
    }
    return search;
  }
  void issuebook(Books book, Member member) {
    if (book.get_availability()) {
      cout << "Book is available" << endl;
    }
    if (member.get_issued_books_count() >= member.get_max_issued_books()) {
      cout << "Books reached its maximum limit" << endl;
    }
    if (book.get_type() == StoryBook) {
      cout << "storybook issued" << endl;
      storybooks_issued++;
    }
    if (book.get_type() == Journal) {
      journals_issued++;
      cout << "Journals issued" << endl;
    }
    if (book.get_type() == Magazine) {
      magazines_issued++;
      cout << "magazines issued" << endl;
    }

    book.set_availability(false);
    member.issued_books_count++;
    member.Issuedbooks(book.get_id());
    member.memberid = member.get_id();

    // cout<<"Book issued to " <<member.get_name()<<endl;
  }

  void receivebook(Books book, Member member) {
    bool found = false;
    for (int i = 0; i < member.issued_books_count; i++) {
      if (member.issued_books[i] == book.get_id() &&
          member.memberid == member.get_id()) {
        book.set_availability(true);
        member.decrement_issued_books_count();
        found = true;
        cout << "Book received!" << endl;
        member.issued_books[i] = 0;
      }
    }
    if (found == false) {
      cout << "Book not issued by member" << endl;
    }
  }

  void generatefine(string id);
  void display1() {
    cout << "Number of magazines: " << nummagazines << endl;
    cout << "Number of journals: " << numjournals << endl;
    cout << "Number of storybooks: " << numstorybooks << endl;
    cout << "Number of members: " << nummembers << endl;
  }
  void display() {
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Number of magazines: " << nummagazines << endl;
    cout << "Number of journals: " << numjournals << endl;
    cout << "Number of storybooks: " << numstorybooks << endl;
    cout << "Number of members: " << nummembers << endl;
  }
};
int main() {
  // Create a new Librarian and login
  Librarian librarian("username", "password");
  librarian.login("username", "password");
  librarian.display();

  librarian.addbooks(1, "Magazine", "thomas", 10, "7-5-23", Magazine);
  librarian.addbooks(12, "Magazine1", "thomas", 10, "7-5-23", Magazine);
  librarian.addbooks(12, "Magazine2", "thomas", 10, "7-5-23", Magazine);
  librarian.addbooks(12, "Magazine3", "thomas", 10, "7-5-23", Magazine);
  librarian.addbooks(12, "Magazine4", "thomas", 10, "7-5-23", Magazine);
  librarian.addbooks(3, "Magazine", "thomas", 10, "7-5-23", Magazine);
  /*
  librarian.addbooks("4", "Magazine", "thomas", 10, "16-6-23",true);
  librarian.addbooks("10", "Journal", "Ronald", 13, "16-6-23",true);
  librarian.addbooks("11", "Journal", "Ronald", 14, "16-6-23",true);
  librarian.addbooks("12", "Journal", "Ronald", 12, "18-6-23",true);
  librarian.addbooks("13", "Journal", "Ronald", 12, "18-6-23",true);
  librarian.addbooks("112", "Storybook", "Ronald", 12, "18-6-23",true);
  librarian.addbooks("113", "Storybook", "Ronald", 12, "18-6-23",true);
*/
  librarian.display1();
  cout << endl;
  Student student1(1, "eman", "123 street", 1232334790);
  Student student2(2, "esha", "abc colony", 2345826341);
  Student student3(3, "amna", "xyz street", 3456354732);
  Faculty faculty1(1, "ali", "pqr street", 1232344790);
  Faculty faculty2(2, "ahmed", "456 street", 123321790);

  student1.display();
  cout << endl;
  student2.display();
  cout << endl;
  student3.display();
  cout << endl;
  faculty1.display();
  cout << endl;
  faculty2.display();
  cout << endl;

  librarian.searchbook("Magazine");
  cout << "\n---\n";
  librarian.searchbook("Magazine1");
  cout << "\n---\n";
  librarian.display();
  cout << "\n---\n";
  // librarian.issuebook("Magazine ", "3");

  // Create some books
  Books b1(1234, "Magazines", "Author 1", 12, "Publisher 1", true);
  Books b2(2345, "Storybook", "Author 2", 10, "Publisher 2", true);
  Books b3(3456, "Journal", "Author 3", 11, "Publisher 3", true);
  Books b4(4567, "Book 4", "Author 4", 13, "Publisher 4", true);
  Books b5(5678, "Book 5", "Author 5", 15, "Publisher 5", true);
  Member m1(001, "John Doe", "123 Main St.", 5551234, "Student");
  Member m2(002, "kamran", "456 Main St.", 5321234, "Student");
  librarian.issuebook(b1, m1);
  librarian.issuebook(b2, m2);
  librarian.receivebook(b1, m1);
  BookType a = StoryBook;
  cout << BookType_toString(a);
}
