/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}
TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, caseSenseTest)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zZ");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, emptyLeadingTest)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, noLettersLeadingTest)
{
	Password my_password;
	int actual = my_password.count_leading_characters("??.3!!?");
	ASSERT_EQ(2, actual);
}
TEST(PasswordTest, emptyCaseTest)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, caseTestPass)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zZ");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, allLowerTest)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zz");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, allUpperTest)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ZZ");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, noLettersCaseTest)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("123!!?");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, constructorTest)
{
	Password my_password;
	bool actual = my_password.authenticate("ChicoCA-95929");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, setTestHappy)
{
	Password my_password;
	my_password.set("ppAssword");
	bool actual = my_password.authenticate("ppAssword");
	ASSERT_EQ(true, actual);
}