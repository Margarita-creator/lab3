// Copyright by Margarita-creator

#include <gtest/gtest.h>
#include "ptr.hpp"

TEST(Test, Zerro) {
  SharedPtr<int> chislo;
  EXPECT_EQ((chislo),0);
}
TEST(Test, UseCount) {
  char letter = 'a';
  SharedPtr<char> sp1 (&letter);
  SharedPtr<char> sp2(sp1);
  SharedPtr<char> sp3(sp2);
  SharedPtr<char> sp4(sp3);
  EXPECT_EQ(sp1.use_count(),4);
}
TEST(Test, Clas_Strelka) {
  class Values{
   public:
    int val;
  };
  Values val1;
  val1.val=20;
  SharedPtr<Values> sp5(&val1);
  EXPECT_EQ(sp5->val,20);
}
TEST(Test, Zvezda) {
  int val = 5, val2 = 30;
  SharedPtr<int> sp1 (&val);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> sp3(sp2);
  SharedPtr<int> spz(&val2);
  std::stringstream str;
  str<<*sp1<<" "<<*sp2<<" "<<*sp3<<" "<<*spz;
  std::string line = "5 5 5 30";
  EXPECT_EQ(str.str(), line);
}
TEST(Test, Get) {
  int val = 5, val2 = 30;
  SharedPtr<int> sp1 (&val);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> sp3(sp2);
  SharedPtr<int> spz(&val2);
  std::stringstream str, str2;
  str<<*sp1.get()<<" "<<*sp2.get()<<" "<<*sp3.get()<<" "<<*spz.get();
  std::string line = "5 5 5 30";
  EXPECT_EQ(str.str(), line);
}
TEST(Test, Reset) {
  int val = 5, val2 =30;
  SharedPtr<int> sp1 (&val);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> sp3(sp2);
  sp1.reset();
  sp2.reset(&val2);
  std::stringstream str;
  str<<(sp1)<<" "<<*sp2;
  std::string line = "0 30";
  EXPECT_EQ(str.str(), line);
}
TEST(Test, Swap) {
  int val = 5, val2 = 30;
  SharedPtr<int> sp1 (&val);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> sp3(sp2);
  SharedPtr<int> spz(&val2);
  std::stringstream str;
  str<<*sp3<<" "<<*spz;
  sp3.swapPtr(spz);
  str<<" "<<*sp3<<" "<<*spz;
  std::string line = "5 30 30 5";
  EXPECT_EQ(str.str(), line);
}