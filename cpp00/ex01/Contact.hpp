#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  Contact();
  ~Contact();

  void setFirstName(std::string &value);
  void setLastName(std::string &value);
  void setNickname(std::string &value);
  void setPhoneNumber(std::string &value);
  void setDarkestSecret(std::string &value);

  std::string &getFirstName();
  std::string &getLastName();
  std::string &getNickname();
  std::string &getPhoneNumber();
  std::string &getDarkestSecret();

  bool isEmpty();

private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
};

#endif
