/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Z"));
}

TEST(PasswordTest, two_leading_letters)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("ZZ"));
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	ASSERT_EQ(0, my_password.count_leading_characters(""));
}

TEST(PasswordTest, five_leading)
{
	Password my_password;
	ASSERT_EQ(5, my_password.count_leading_characters("000001"));
}

TEST(PasswordTest, repeated_characters_at_end)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("afffffgaaaaaaeeeggsaaa"));
}

TEST(PasswordTest, special_leading_characters)
{
	Password my_password;
	ASSERT_EQ(3, my_password.count_leading_characters("{{{(())}}}"));
}

TEST(PasswordTest, difference_in_capitals)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("hhHHHHhhhHHH"));
}