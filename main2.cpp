#include <iostream>
#include "BookList/BookList.hpp"
using namespace std;

int main() {
  // default 생성자
  // BookManagement* myList = new BookManagement;

  // 생성자 1 // string을 매개변수로 받는다
  // BookManagement* myList = new BookManagement("c++");

  // 생성자 2 // string 배열의 주소와 index의 크기를 매개변수로 받는다
  string books[5]={"c","c++","c#","java","python"};
  BookManagement* myList = new BookManagement(books,5);

  {
    system("clear"); // linux 명령어 // winodows에서 실행 X
    // system("cls"); // windows 명령어
  }

  int choose; // menu 입력 값 저장
  while (1) {
    myList->ShowMenu();
    cin >> choose;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << " 0, 1, 2 중 숫자를 입력하세요~!\n";
      continue;
    }

    switch (choose)
    {
      case 1:
        myList->Insert();
        break;
      case 2:
        myList->Print();
        break;
      case 3:
        myList->bookFinder();
        break;
      case 4:
        myList->delBook();
        break;
      case 5:
        myList->bookRental();
        break;
      case 6:
        myList->bookReturn();
        break;
      case 0:
        cout << "종료합니다!\n";
        delete myList;
        return 0;
      default:
        cout << " 0 ~ 6 중 숫자를 입력하세요~!\n";
        continue;
    }
  }
  return 0;
}