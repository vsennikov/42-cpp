#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

static bool readNonEmptyLine(const std::string &prompt, std::string &outValue)
{
	std::string line;

	while (line.empty())
	{
		std::cout << prompt;
		if (!std::getline(std::cin, line))
			return false;
	}
	outValue = line;
	return true;
}

static bool isAllDigits(const std::string &s)
{
	if (s.empty())
		return false;
	for (std::string::size_type i = 0; i < s.size(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}

static void printHeaderRow()
{
	std::cout << PhoneBook::formatColumn("index") << "|"
	          << PhoneBook::formatColumn("first name") << "|"
	          << PhoneBook::formatColumn("last name") << "|"
	          << PhoneBook::formatColumn("nickname") << std::endl;
}

static void printContactRow(int index, const Contact &c)
{
	std::ostringstream oss;
	oss << index;
	std::cout << PhoneBook::formatColumn(oss.str()) << "|"
	          << PhoneBook::formatColumn(c.getFirstName()) << "|"
	          << PhoneBook::formatColumn(c.getLastName()) << "|"
	          << PhoneBook::formatColumn(c.getNickname()) << std::endl;
}

static void printContactDetails(const Contact &c)
{
	std::cout << "First name: " << c.getFirstName() << std::endl;
	std::cout << "Last name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}

static void handleAdd(PhoneBook &pb)
{
	Contact c;
	std::string value;

	if (!readNonEmptyLine("First name: ", value)) return;
	c.setFirstName(value);
	if (!readNonEmptyLine("Last name: ", value)) return;
	c.setLastName(value);
	if (!readNonEmptyLine("Nickname: ", value)) return;
	c.setNickname(value);
	if (!readNonEmptyLine("Phone number: ", value)) return;
	c.setPhoneNumber(value);
	if (!readNonEmptyLine("Darkest secret: ", value)) return;
	c.setDarkestSecret(value);

	pb.addContact(c);
	std::cout << "Contact saved." << std::endl;
}

static void handleSearch(const PhoneBook &pb)
{
	if (pb.size() == 0)
	{
		std::cout << "No contacts to display." << std::endl;
		return;
	}
	printHeaderRow();
	for (int i = 0; i < pb.size(); ++i)
		printContactRow(i, pb.getContact(i));

	std::string idxStr;
	std::cout << "Index to display: ";
	if (!std::getline(std::cin, idxStr))
		return;
	if (!isAllDigits(idxStr))
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	std::istringstream iss(idxStr);
	int idx = -1;
	iss >> idx;
	if (idx < 0 || idx >= pb.size())
	{
		std::cout << "Index out of range." << std::endl;
		return;
	}
	printContactDetails(pb.getContact(idx));
}

static void interactiveLoop()
{
	PhoneBook pb;
	std::string cmd;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			break;
		if (cmd == "ADD")
			handleAdd(pb);
		else if (cmd == "SEARCH")
			handleSearch(pb);
		else if (cmd == "EXIT")
			break;
	}
}
