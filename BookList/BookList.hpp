#include <iostream>
#include <string>
using namespace std;

struct node{
  string bookName;

  bool rental;
  string rentalUser;

  node* left;
  node* right;
};

class BookList{
  protected:
    static int count;
    node* headNode;
    node* tailNode;
    node* pointerFinder(string book) const;
    void dataInsert(string book);
    void terminalClear() const;
    void delBackempty(string& str);
  public:
    BookList();
    BookList(string book);
    BookList(string* book, int len);
    virtual ~BookList();

    void Insert();
    virtual void ShowMenu() const;
    virtual void Print() const;
};


class BookManagement:public BookList{
  private:
    void printBookData() const;
  public:
    BookManagement();
    BookManagement(string book);
    BookManagement(string* books, int len);

    virtual ~BookManagement();
    virtual void ShowMenu() const;
    virtual void Print() const;
    void delBook();
    void bookFinder();
    void bookRental();
    void bookReturn();
};