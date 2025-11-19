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


// Test cases for count_leading
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

//Test cases for has_mixed_case
TEST(PasswordTest, empty_case)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case(""));
}

TEST(PasswordTest, no_chars)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("1234%(#@)"));
}

TEST(PasswordTest, single_char_lowercase)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("a"));
}

TEST(PasswordTest, single_char_uppercase)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("A"));
}

TEST(PasswordTest, double_char_both_lower)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("aa"));
}

TEST(PasswordTest, double_char_both_upper)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("AA"));
}

TEST(PasswordTest, has_mixed_lowthenup)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("aA"));
}

TEST(PasswordTest, has_mixed_upthenlow)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("Aa"));
}

TEST(PasswordTest, long_mixed_lowthenup)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("aaaaaaaaaaaaaaAA"));
}

TEST(PasswordTest, lower_then_number)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("abcdef123123"));
}

TEST(PasswordTest, upper_then_number)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("ABCEDF123123"));
}

TEST(PasswordTest, num_special_char)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("123_!$AABBccdd"));
}

TEST(PasswordTest, num_special_char_thenonlylower)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("123_!$abcd"));
}

TEST(PasswordTest, num_special_char_thenonlyupper)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("123_!$ABCD"));
}

TEST(PasswordTest, mixed_with_spaces_upthenlo)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("A a"));
}

// Test cases for uniq_chars
TEST(PasswordTest, empty_string)
{
	Password my_password;
	ASSERT_EQ(0, my_password.unique_characters(""));
}

TEST(PasswordTest, only_num_and_special)
{
	Password my_password;
	ASSERT_EQ(0, my_password.unique_characters("12345!@#$%"));
}

TEST(PasswordTest, single_num)
{
	Password my_password;
	ASSERT_EQ(0, my_password.unique_characters("1"));
}

TEST(PasswordTest, single_lower_char)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("a"));
}

TEST(PasswordTest, single_upper_char)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("A"));
}

TEST(PasswordTest, single_bracket)
{
	Password my_password;
	ASSERT_EQ(0, my_password.unique_characters("["));
}

TEST(PasswordTest, five_mixed_chars)
{
	Password my_password;
	ASSERT_EQ(5, my_password.unique_characters("aBcDe"));
}

TEST(PasswordTest, same_char_upper_and_lower)
{
	Password my_password;
	ASSERT_EQ(2, my_password.unique_characters("aA"));
}

TEST(PasswordTest, same_char_five_times)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("aaaaa"));
}

TEST(PasswordTest, repeated_same)
{
	Password my_password;
	ASSERT_EQ(2, my_password.unique_characters("AaAaAaAaAaAaAa"));
}

TEST(PasswordTest, space_between_chars)
{
	Password my_password;
	ASSERT_EQ(4, my_password.unique_characters("a A a A b B b B"));
}

TEST(PasswordTest, all_test_mix)
{
	Password my_password;
	ASSERT_EQ(7, my_password.unique_characters("aA123AA$bcdDC4$"));
}