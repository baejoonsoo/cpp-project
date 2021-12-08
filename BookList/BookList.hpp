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
    void dataInsert(string book);
    void terminalClear() const;
    void delBackempty();
  public:
    BookList();
    BookList(string book);
    BookList(string* book, int len);
    virtual ~BookList();

    void Insert();
    virtual void ShowMenu() const;
    void Print() const;
};


class BookManagement:public BookList{
  private:
    node* pointerFinder(string book) const;
  public:
    BookManagement();
    BookManagement(string book);
    BookManagement(string* books, int len);
    virtual ~BookManagement();
    void bookFinder() const;
    virtual void ShowMenu() const;
    void delBook();
    virtual void print() const;
    void bookRental() const;
    void bookReturn() const;

};