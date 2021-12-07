#include <iostream>
#include "BookList/BookList.hpp"
using namespace std;

int main() {
  // default 생성자
  // BookList* myList = new BookList;

  // 생성자 1 // string을 매개변수로 받는다
  // BookList* myList = new BookList("C++");

  //생성자 2 // string 배열의 주소와 index의 크기를 매개변수로 받는다
  string books[3]={"c","c++","python"};
  BookList* myList = new BookList(books,3);

  system("clear"); // linux 명령어 // winodows에서 실행 X
  //system("cls"); // windows 명령어

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
      case 0:
        cout << "종료합니다!\n";
        delete myList;
        return 0;
      default:
        cout << " 0, 1, 2 중 숫자를 입력하세요~!\n";
        continue;
    }
  }
  return 0;
}