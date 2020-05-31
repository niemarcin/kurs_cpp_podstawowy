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