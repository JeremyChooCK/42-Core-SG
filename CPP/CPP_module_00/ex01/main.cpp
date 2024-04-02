#include "phonebook.hpp"

std::string truncate(const std::string& str) {
    return (str.length() > 10) ? str.substr(0, 9) + "." : str;
}

int checkforalpha(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (std::isalpha(str[i]))
            return 1;
    }
    return 0;
}

int main() {
    std::string index;
    int count = 0;
    int current = 0;
    std::string cmd;
    PhoneBook phonebook;

    while (true) {
        std::cout << "Please enter 1 of these 3 commands\nADD\nSEARCH\nEXIT\n";
        std::cin >> cmd;
        if (cmd == "ADD") {
            Contact& currentContact = phonebook.getContact(current);

            std::cout << "Please enter the following information" << std::endl;

            std::cout << "First Name: ";
            std::cin >> cmd;
            currentContact.setFirstName(cmd);

            std::cout << "Last Name: ";
            std::cin >> cmd;
            currentContact.setLastName(cmd);

            std::cout << "Nickname: ";
            std::cin >> cmd;
            currentContact.setNickname(cmd);

            std::cout << "Phone Number: ";
            std::cin >> cmd;
            currentContact.setPhoneNumber(cmd);

            std::cout << "Darkest Secret: ";
            std::cin >> cmd;
            currentContact.setDarkestSecret(cmd);

            if (count < 8) {
                count++;
            }
            current = (current + 1) % 8;
        } else if (cmd == "SEARCH") {
            for (int i = 0; i < count; i++) {
                const Contact& contact = phonebook.getContact(i);
                std::cout << std::setw(10) << i << "|";
                std::cout << std::setw(10) << truncate(contact.getFirstName()) << "|";
                std::cout << std::setw(10) << truncate(contact.getLastName()) << "|";
                std::cout << std::setw(10) << truncate(contact.getNickname()) << std::endl;
            }
            std::cout << "Please enter the index of the contact you want to see\n";
            std::cin >> index;
            int idx = atoi(index.c_str());
            if (idx < 0 || idx >= count || checkforalpha(index)) {
                std::cout << "Invalid index\n";
            } else {
                const Contact& contact = phonebook.getContact(idx);
                std::cout << "First Name: " << contact.getFirstName() << std::endl;
                std::cout << "Last Name: " << contact.getLastName() << std::endl;
                std::cout << "Nickname: " << contact.getNickname() << std::endl;
                std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
                std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
            }
        } else if (cmd == "EXIT") {
            break;
        }
    }
    return 0;
}
