#include "BookList.hpp"
#include <iostream>
using namespace std;

int BookList::count=0;

BookList::BookList(){
  headNode=nullptr;
  tailNode=nullptr;
}

BookList::BookList(string book){
  dataInsert(book);
}

BookList::BookList(string* book, int len){
  for(int i=0;i<len;i++){
    dataInsert(book[i]);
  }
}

BookList::~BookList(){
  node* temp;
  while(headNode){
    temp=headNode;
    headNode=headNode->right;

    delete temp;
  }
  tailNode=nullptr;
}

void BookList::terminalClear() const {
  // system("cls"); // window
  system("clear"); // linux
}

void BookList::dataInsert(string book){
  node* newNode=new node;

  // node에 고유번호를 부여한다. (count++)
  // newNode->id = count++; 
  newNode->bookName=book;
  newNode->left=nullptr;
  newNode->right=nullptr;

  // 리스트가 비어 있을 경우
  if(headNode==nullptr){
    headNode=newNode;
    tailNode=newNode;
    return;
  }
  // 리스트가 비어있지 않을 때
  tailNode->right=newNode;
  newNode->left=tailNode;
  tailNode=newNode;
}

void BookList::Insert(){
  string book;
  
  this->terminalClear();

  cout<<"\n책의 이름을 입력해 주세요\n>> ";
  getline(cin,book);
  getline(cin,book);

  dataInsert(book);
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

void BookList::ShowMenu() const{
  cout<<"\n| MENU |\n";
  cout<<"============\n";
  cout<<"1 : insert\n";
  cout<<"2 : print\n";
  cout<<"0 : exit\n";
  cout<<"============\n";
}