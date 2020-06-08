#pragma once
#include <string>

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

constexpr size_t minPasswordLength = 9;

std::string getErrorMessage(ErrorCode error);
bool doesPasswordsMatch(const std::string& passwordA, const std::string& passwordB);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& passwordA, const std::string& passwordB);
