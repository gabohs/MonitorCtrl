#pragma once

#include <vector>
#include <string>
#include <iostream>

class PasswordGenerator
{
private:
    std::string password_;

    char lowercase[26] = {
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
        'r','s','t','u','v','w','x','y','z'
    };

    char uppercase[26] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q',
        'R','S','T','U','V','W','X','Y','Z'
    };

    char special[23] = {
        '~', '!', '@', '#', '$', '%', '&', '*', '(', ')', '[', ']', '{', '}',
        '-', '_', '|', '/', '\\', ';', '"', '?'
    };

    char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    std::vector<char> all = {};

public:
    PasswordGenerator();
    void generate(int len, static bool lowerC, static bool upperC, static bool specialChars, static bool nums);
    std::string& getPassword(); 
};