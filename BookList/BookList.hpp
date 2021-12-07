#include <iostream>
#include <string>
using namespace std;

struct node{
  int id;
  string bookName;

  bool rental;
  string rentalUser;

  node* next;
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
    void ShowMenu() const;
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
};