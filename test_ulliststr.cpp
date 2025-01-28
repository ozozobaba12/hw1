#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr testList;

  testList.push_back("ozozobaba");
  testList.push_back("banana");
  testList.push_front("treyway");

  for (size_t i=0; i<testList.size(); i++ ){
    cout<<i<<": " <<testList.get(i)<<endl;
  }

  cout<<"front: "<<testList.front()<<endl;
   cout<<"last: "<<testList.back()<<endl;

   testList.pop_front();
   for (size_t i=0; i<testList.size(); i++ ){
    cout<<i<<": " <<testList.get(i)<<endl;
  }

  testList.pop_back();
  for (size_t i=0; i<testList.size(); i++ ){
    cout<<i<<": " <<testList.get(i)<<endl;
  }




}
