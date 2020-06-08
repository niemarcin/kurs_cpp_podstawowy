#include "validation.hpp"
#include <algorithm>

std::string getErrorMessage(ErrorCode error) {
    std::string errorMessage;
    
    switch (error) {
        case ErrorCode::Ok :
            errorMessage = "OK";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters :
            errorMessage = "Password needs at least nine characters";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber :
            errorMessage = "Password needs at least one number";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter :
            errorMessage = "Password needs at least one special character";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter :
            errorMessage = "Password needs at least one uppercase letter";
            break;
        case ErrorCode::PasswordsDoesNotMatch :
            errorMessage = "Passwords does not match";
            break;
        default:
            errorMessage = "Unknown error code";
            break; 
    }
	
    return errorMessage;
}

bool doesPasswordsMatch(const std::string& passwordA, const std::string& passwordB) {
    return passwordA == passwordB;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < minPasswordLength) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if (std::none_of(password.begin(), password.end(), ::isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    if (std::all_of(password.begin(), password.end(), ::isalnum)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if (std::none_of(password.begin(), password.end(), ::isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& passwordA, const std::string& passwordB) {
    if (!(doesPasswordsMatch(passwordA, passwordB))) {
        return ErrorCode::PasswordsDoesNotMatch;
    }

    return checkPasswordRules(passwordA);
}
