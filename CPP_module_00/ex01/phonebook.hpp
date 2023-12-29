#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    // Setters
    void setFirstName(const std::string& name) { first_name = name; }
    void setLastName(const std::string& name) { last_name = name; }
    void setNickname(const std::string& name) { nickname = name; }
    void setPhoneNumber(const std::string& number) { phone_number = number; }
    void setDarkestSecret(const std::string& secret) { darkest_secret = secret; }

    // Getters
    std::string getFirstName() const { return first_name; }
    std::string getLastName() const { return last_name; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phone_number; }
    std::string getDarkestSecret() const { return darkest_secret; }
};


class PhoneBook
{
private:
    Contact contacts[8];

public:
    Contact& getContact(int index) { return contacts[index]; }
};

std::string truncate(const std::string& str);
int checkforalpha(const std::string& str);

