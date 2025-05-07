#include "PasswordGenerator.h"

PasswordGenerator::PasswordGenerator()
{
    std::srand(std::time(nullptr));

    password_ = "";
}

void PasswordGenerator::generate(int len, bool lowerC, bool upperC, bool specialChars, bool nums)
{   
    // clear the "all characters selected" vector and password string
    all.clear();
    password_.clear();

    if (lowerC) 
    {
        all.insert(std::end(all), std::begin(lowercase), std::end(lowercase));
    }

    if (upperC)
    {
        all.insert(std::end(all), std::begin(uppercase), std::end(uppercase));
    }

    if (specialChars)
    {
        all.insert(std::end(all), std::begin(special), std::end(special));
    }

    if (nums)
    {
        all.insert(std::end(all), std::begin(numbers), std::end(numbers));
    }

    if (all.size() > 0)
    {
        for (int i = 0; i < len; i++)
	    {
		    password_.push_back(all[std::rand() % all.size()]);
	    }
    }
}

std::string& PasswordGenerator::getPassword()
{
    return password_;
}
