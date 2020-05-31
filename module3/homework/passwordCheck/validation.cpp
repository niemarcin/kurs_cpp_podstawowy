#include "validation.hpp"

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
            errorMessage = "Passowrds does not match";
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
    
    if (password.length() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    bool numberFound = false;
    bool specialCharFound = false;
    bool uppercaseFound = false;
    for (auto it = password.begin(); it != password.end(); ++it) {
        if (*it >= '0' && *it <= '9') {
            numberFound = true;
        }
        if (!((*it >= '0' && *it <= '9') || (*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z'))) {
            specialCharFound = true;
        }
        if (*it >= 'A' && *it <= 'Z') {
            uppercaseFound = true;
        }
    }
    if (!numberFound) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (!specialCharFound) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (!uppercaseFound) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}