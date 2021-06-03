#include<iostream>
#include<gtest/gtest.h>
#include "../src/Rational.h"

class HelloGTest : public ::testing::Test {
	protected:
		HelloGTest(){
			std::cout<<"HelloGTest()"<<std::endl;
		}

void SetUp() override
{
	std::cout<<"SetUp()"<<std::endl;
}

void TearDown() override{
	std::cout<< "TearDown()" <<std::endl;
}

~HelloGTest(){
	std::cout<<"~HelloGTest()"<<std::endl;
}
};

TEST_F(HelloGTest,n1){
	
	Rational r(1,2);
Rational t(1,2);
Rational w(1,1);
	ASSERT_EQ(w, r+t);
}

