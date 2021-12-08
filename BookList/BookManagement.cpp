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

void BookManagement::bookFinder(){
  string book;

  this->terminalClear();
  cout<<"\n검색할 책 이름을 입력하세요!\n>> ";
  getline(cin,book);
  getline(cin,book);

  delBackempty(book);

  if(book=="return"){
    return;
  }


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
  cout<<"5 : book rental\n";
  cout<<"6 : book return\n";
  cout<<"0 : exit\n";
  cout<<"================\n";
}

void BookManagement::delBook(){
  string book;

    this->terminalClear();

  cout<<"삭제하고 싶은 책의 제목을 입력하세요.\n>> ";
  // cin>>book;
  getline(cin,book);
  getline(cin,book);

  this->delBackempty(book);

  cout<<"\'"<<book<<"\'\n";

  if(book=="return"){
    return;
  }

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

void BookManagement::bookRental(){
  string bookName,userName;

  this->terminalClear();

  cout<<"당신의 이름을 입력하세요.\n>> ";
  getline(cin,userName);
  getline(cin,userName);

  this->delBackempty(userName);

  if(userName=="return"){
    return;
  }

  cout<<"대여할 책 이름을 입력하세요.\n>> ";
  getline(cin,bookName);

  this->delBackempty(bookName);

  if(bookName=="return"){
    return;
  }


  node* t = this->pointerFinder(bookName);

  if(t){
    if(t->rental){
      cout<<"이미 대여된 책입니다. (대여인 : "<<t->rentalUser<<")\n";
    }
    else{
      t->rental=true;
      t->rentalUser=userName;
      cout<<"책을 대여합니다!\n책 제목 : "<<t->bookName<<"\n사용자명 : "<<t->rentalUser<<"\n\n";
    }
  }
  else{
    cout<<"<"<<bookName<<">책은 찾을 수 없는 책입니다.\n";
  }
}

void BookManagement::bookReturn(){
  string bookName;

  this->terminalClear();

  cout<<"반납할 책의 이름을 입력하세요.\n>> ";
  getline(cin,bookName);
  getline(cin,bookName);

  this->delBackempty(bookName);

  if(bookName=="return"){
    return;
  }

  node* t = this->pointerFinder(bookName);

  if(t){
    if(t->rental){
      t->rental=false;
      cout<<"책을 반납합니다!\n책 제목 : "<<t->bookName<<"\n반납자명 : "<<t->rentalUser<<"\n\n";
    }
    else{
      cout<<"이미 반납된 책입니다.\n";
    }
  }
  else{
    cout<<"<"<<bookName<<">책은 찾을 수 없는 책입니다.\n";
  }


}

void BookManagement::Print() const{
  this->terminalClear();  

  int number=1;
  if(this->headNode){
    cout<<"\n| Book List |\n";
    cout<<"-------------------------------------------------------\n";
    for(node* temp=this->headNode; temp!=nullptr;temp=temp->right, number++){
      cout<<number<<". "<<temp->bookName<<"\n";
      if(temp->rental){
        cout<<"대여 상태 입니다!\n(대여한 유저 : "<<temp->rentalUser<<")\n";
      }
      cout<<"-------------------------------------------------------\n";
    }
  }
  else{
    cout<<"\n책이 존재하지 않습니다!\n";
  }
}
