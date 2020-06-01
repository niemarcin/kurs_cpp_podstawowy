#include "gtest/gtest.h"
#include "validation.hpp"

std::string EMPTY_PASSWORD = "";
std::string PROPER_PASSWORD = "abcABC123!@#";
std::string TOO_SHORT_PASSWORD = "12345678";
std::string NO_UPPERCASE_PASSWORD = "abcabc123!@#";
std::string NO_SPECIAL_CHARACTER_PASSWORD = "abcABC123123";
std::string NO_NUMBER_PASSWORD = "abcABCabc!@#";
auto MIN_ALLOWED_ERROR_CODE = ErrorCode::Ok;
auto MAX_ALLOWED_ERROR_CODE = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
auto PASSWORD_OK_ERROR_CODE = ErrorCode::Ok;
auto PASSWORD_LENGTH_ERROR_CODE = ErrorCode::PasswordNeedsAtLeastNineCharacters;
auto PASSWORD_NUMBER_ERROR_CODE = ErrorCode::PasswordNeedsAtLeastOneNumber;
auto PASSWORD_SPECIAL_CHAR_ERROR_CODE = ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
auto PASSWORD_UPPERCASE_ERROR_CODE = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

TEST(DoesPasswordsMatchTests, returnsTrueForIdenticalPasswords) {
    EXPECT_TRUE(doesPasswordsMatch(EMPTY_PASSWORD, EMPTY_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(PROPER_PASSWORD, PROPER_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(TOO_SHORT_PASSWORD, TOO_SHORT_PASSWORD));
}

TEST(DoesPasswordsMatchTests, returnsFalseForDifferentPasswords) {
    EXPECT_FALSE(doesPasswordsMatch(EMPTY_PASSWORD, PROPER_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_PASSWORD, EMPTY_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_PASSWORD, TOO_SHORT_PASSWORD));
}

TEST(checkPasswordRulesTests, returnsValuesBetweenOkAndPasswordNeedsAtLeastOneUppercaseLetter) {
    EXPECT_GE(checkPasswordRules(EMPTY_PASSWORD), MIN_ALLOWED_ERROR_CODE);  // greater or equal >=
    EXPECT_LE(checkPasswordRules(EMPTY_PASSWORD), MAX_ALLOWED_ERROR_CODE);  // less or equal <=
    EXPECT_GE(checkPasswordRules(TOO_SHORT_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(TOO_SHORT_PASSWORD), MAX_ALLOWED_ERROR_CODE);
    EXPECT_GE(checkPasswordRules(PROPER_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(PROPER_PASSWORD), MAX_ALLOWED_ERROR_CODE);
    EXPECT_GE(checkPasswordRules(NO_UPPERCASE_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(NO_UPPERCASE_PASSWORD), MAX_ALLOWED_ERROR_CODE);
    EXPECT_GE(checkPasswordRules(NO_SPECIAL_CHARACTER_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(NO_SPECIAL_CHARACTER_PASSWORD), MAX_ALLOWED_ERROR_CODE);
    EXPECT_GE(checkPasswordRules(NO_NUMBER_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(NO_NUMBER_PASSWORD), MAX_ALLOWED_ERROR_CODE);
}

TEST(checkPasswordRulesTests, returnsPasswordNeedsAtLeastNineCharactersError) {
    EXPECT_EQ(checkPasswordRules(TOO_SHORT_PASSWORD), PASSWORD_LENGTH_ERROR_CODE);
}

TEST(checkPasswordRulesTests, returnsPasswordNeedsAtLeastOneUppercaseLetterError) {
    EXPECT_EQ(checkPasswordRules(NO_UPPERCASE_PASSWORD), PASSWORD_UPPERCASE_ERROR_CODE);
}

TEST(checkPasswordRulesTests, returnsPasswordNeedsAtLeastOneSpecialCharacterError) {
    EXPECT_EQ(checkPasswordRules(NO_SPECIAL_CHARACTER_PASSWORD), PASSWORD_SPECIAL_CHAR_ERROR_CODE);
}

TEST(checkPasswordRulesTests, returnsPasswordNeedsAtLeastOneNumberError) {
    EXPECT_EQ(checkPasswordRules(NO_NUMBER_PASSWORD), PASSWORD_NUMBER_ERROR_CODE);
}

TEST(checkPasswordTests, returnsValuesBetweenOkAndPasswordNeedsAtLeastOneUppercaseLetter) {
    EXPECT_GE(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), MAX_ALLOWED_ERROR_CODE);
}

TEST(checkPasswordTests, returnsPasswordsDoesNotMatchForDifferentPasswords) {
    EXPECT_EQ(checkPassword(PROPER_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch); // equal ==
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch); 
}

TEST(getErrorMessageTests, returnsErrorCodeAsString) {
    EXPECT_EQ(getErrorMessage(ErrorCode::Ok), "OK");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastNineCharacters), "Password needs at least nine characters");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneNumber), "Password needs at least one number");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter), "Password needs at least one special character");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter), "Password needs at least one uppercase letter");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordsDoesNotMatch), "Passwords does not match");
    EXPECT_EQ(getErrorMessage(static_cast<ErrorCode>(static_cast<int>(ErrorCode::PasswordsDoesNotMatch) + 1)), "Unknown error code");
    
    // Add other tests for getErrorMessage if you wish
}
