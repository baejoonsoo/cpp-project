#include <iostream>
#include "BookList.hpp"
// #include "../BookList/BookList.hpp"
using namespace std;



BookManagement::BookManagement(){
  headNode=nullptr;
  tailNode=nullptr;
  // cout<<"bookManagement\n";
}

BookManagement::BookManagement(string Book){
  dataInsert(Book);
}

BookManagement::BookManagement(string* Books, int len){
  for(int i=0;i<len;i++){
    dataInsert(Books[i]);
  }
}

BookManagement::~BookManagement(){
  node* temp;
  while(headNode){
    temp=headNode;
    headNode=headNode->next;

    delete headNode;
  }
  tailNode=nullptr;
}

node* BookManagement::pointerFinder(string book) const{
  for(node* t=headNode;t!=nullptr;t=t->next){
    if(t->bookName==book){
      return t;
    }
  }

  return nullptr;
}

void BookManagement::bookFinder() const{
  string book;

  this->terminalClear();
  cout<<"\n검색할 책 이름을 입력하세요!\n>> ";
  cin>>book;

  node* t=this->pointerFinder(book);

  if(t){ // t가 node주소를 가르킬 때(true)
    cout<<"\n\n<"<<book<<">책을 찾았습니다! (id : "<<t->id<<")\n";
  }
  else{  // t가 nullptr일 때(false)
    cout<<"\n\n책을 찾을 수 없습니다\n";
  }
}

void BookManagement::ShowMenu() const{
  cout<<"\n| MENU |\n";
  cout<<"================\n";
  cout<<"1 : insert\n";
  cout<<"2 : print\n";
  cout<<"3 : book finder\n";
  cout<<"0 : exit\n";
  cout<<"================\n";
}