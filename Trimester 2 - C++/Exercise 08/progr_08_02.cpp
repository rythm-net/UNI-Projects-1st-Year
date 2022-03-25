#include <iostream>
#include <cstring> // за работа с типа char*
#include <string> // за работа с типа string
using namespace std;

int main() {

  // char*
  const int maxStrLen = 100;
  char sCh[1+maxStrLen];
  memset(sCh,'&',5);
  memset(sCh+5,';',4);
  sCh[9]=0;
  cout<<'\"'<<sCh<<"\"\n------------\n";

  // string
  string str;
  str.assign(sCh);
  cout<<'\"'<<str<<"\"\n";
  str.resize(11);
  memset(&str[0],'%',5);
  memset(&str[5],'=',2);
  cout<< "str[10] == \'" << str[10] <<"\'\n";
  cout<< "(int)(str[10]) == " << (int)(str[10]) <<endl;
  cout<<'\"'<<str<<"\"\n------------\n";
  cout<<endl;
  double r;

  // char*
  cout<<"Въведете число: ";
  cin>>r;
  cin.getline(sCh, 1+maxStrLen);
  // горното четене е за изчистване на буфера на клавиатурата
  cout<<"Прочетено число: "<<r<<endl;
  cout<<"Въведете низ с интервали (до "<<maxStrLen<<" знака): ";
  cin.getline(sCh, 1+maxStrLen); // това е действителното четене
  cout<<"Прочетен низ: \""<<sCh<<"\"\n------------\n";

  // string
  cout<<"Въведете число: ";
  cin>>r;
  getline(cin, str);
  // горното четене е за изчистване на буфера на клавиатурата
  cout<<"Прочетено число: "<<r<<endl;
  cout<<"Въведете низ с интервали: ";
  getline(cin, str); // това е действителното четене
  cout<<"Прочетен низ: \""<<str<<"\"\n------------\n";
  cout<<endl;

  // char*
  cout<<"Въведете низ (до "
      <<maxStrLen<<" знака) с раделител \'%\': ";
  cin.getline(sCh, 1+maxStrLen, '%'); // знакът '%' е разделител
  cout<<"Прочетен низ: \""<<sCh<<"\"\n";
  cin.getline(sCh, 1+maxStrLen); // разделителят е '\n'
  cout<<"Остатък в буфера: \""<<sCh<<"\"\n------------\n";

  // string
  cout<<"Въведете низ с раделител \'%\': ";
  getline(cin, str, '%'); // знакът '%' е разделител
  cout<<"Прочетен низ: \""<<str<<"\"\n";
  getline(cin, str); // разделителят е '\n'
  cout<<"Остатък в буфера: \""<<str<<"\"\n------------\n";
}