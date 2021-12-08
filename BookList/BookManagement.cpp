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
    headNode=headNode->right;

    delete temp;
  }
  tailNode=nullptr;
}

node* BookManagement::pointerFinder(string book) const{
  for(node* t=headNode;t!=nullptr;t=t->right){
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
    cout<<"\n\n<"<<book<<">책을 찾았습니다!\n";
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
  cout<<"4 : book delete\n";
  cout<<"0 : exit\n";
  cout<<"================\n";
}

void BookManagement::delBook(){
  string book;

  cout<<"삭제하고 싶은 책의 제목을 입력하세요.\n>> ";
  cin>>book;

  node* del = this->pointerFinder(book);
  node* temp=del;

  if(del){
    if(del->left==nullptr){
      cout<<"head\n";
      headNode=headNode->right;

      if(headNode){
        headNode->left=nullptr;
      }
    }
    else if(del->right==nullptr){
      cout<<"tail\n";
      tailNode=tailNode->left;
      tailNode->right=nullptr;
    }
    else if(del->left!=nullptr&&del->right!=nullptr){
      cout<<"m\n";
      del->left->right=del->right;
      del->right->left=del->left;
    }
    delete temp;
  }
  else{
    cout<<"책이 없습니다\n\n";
  }
}

void BookManagement::bookRental() const{
  string bookName,userName;
  
  cout<<"당신의 이름을 입력하세요.\n>> ";
  cin>>userName;

  cout<<"대여할 책 이름을 입력하세요.\n>> ";
  cin>>bookName;

  node* t = this->pointerFinder(bookName);

  if(t){
    if(t->rental){
      cout<<"빌릴 수 없는 책입니다. (대여인 : "<<t->rentalUser<<")\n";
    }
    else{
      t->rental=true;
      t->rentalUser=userName;
      cout<<"책을 대여합니다!\n책 제목 : "<<t->bookName<<"사용자명 : "<<t->rentalUser<<"\n\n";
    }
  }
  else{
    cout<<"찾을 수 없는 책입니다.\n";
  }
}

void BookManagement::bookRental() const{
  
}

void BookList::Print() const{

  this->terminalClear();

  int number=1;
  if(this->headNode){
    cout<<"\n| Book List |\n";
    cout<<"-------------------------------------------------------\n";
    for(node* temp=this->headNode; temp!=nullptr;temp=temp->right, number++){
      cout<<number<<". "<<temp->bookName<<"\n";
      cout<<"-------------------------------------------------------\n";
    }
  }
  else{
    cout<<"\n책이 존재하지 않습니다!\n";
  }
}
