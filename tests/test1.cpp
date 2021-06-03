#include<gtest/gtest.h>
#include "../src/Rational.h"
#include <iostream>
//+                   ===================================
TEST(TEST1,tc1)
{
    std::cout<<"Test 1"<<std::endl;
	Rational r1(1,2), r2(1,3),res2(5,6);
	ASSERT_EQ(res2,r1+r2);
}

TEST(TEST1,tc2)
{
    std::cout<<"Test 2"<<std::endl;
    Rational r1(1,0), r2(1,0),res2(2,1);
    ASSERT_EQ(res2,r1+r2);
}

TEST(TEST1,tc3) {
    std::cout << "Test 3" << std::endl;
    Rational r1(2, 9), r2(3, -9), res2(-1, 9);
    ASSERT_EQ(res2, r1 + r2);
}
/*
TEST(TEST1,tc4) {
    std::cout << "Test 4" << std::endl;
    Rational r1(2, 9), r2(3, -2), res2(-23, 18);
    ASSERT_EQ(res2, r1 + r2);
}
// /                   ===================================
TEST(TEST1,tc5)
{
    std::cout<<"Test 3"<<std::endl;
    Rational r1(3,0), r2(3,0),res2(1,1);
    ASSERT_EQ(res2,r1/r2);
}

// -                   ===================================

TEST(TEST1,tc6)
{
    std::cout<<"Test 4"<<std::endl;
    Rational r1(1,3), r2(1,3),res2(0,0);
    ASSERT_EQ(res2,r1 - r2);
}

TEST(TEST1, tc7)
{
    std::cout<<"Test 4"<<std::endl;
    Rational r1(3,2), r2(5,3),res2(-1,6);
    ASSERT_EQ(res2,r1 - r2);

}

TEST(TEST1,tc8)
{
    std::cout<<"Test 5"<<std::endl;
    Rational r1(3,2), r2(5,3),res2(1,-6);
    ASSERT_EQ(res2,r1/r2);
}
// *                   ===================================


TEST(TEST1,tc9)
{
    std::cout<<"Test 6"<<std::endl;
    Rational r1(3,0), r2(3,0),res2(1,1);
    ASSERT_EQ(res2,r1/r2);
}

TEST(TEST1,tc10)
{
    std::cout<<"Test 6"<<std::endl;
    Rational r1(2,3), r2(3,0),res2(1,1);
    ASSERT_EQ(res2,r1/r2);
}
 */