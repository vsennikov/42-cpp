#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  Contact();
  ~Contact();

  void setFirstName(const std::string &value);
  void setLastName(const std::string &value);
  void setNickname(const std::string &value);
  void setPhoneNumber(const std::string &value);
  void setDarkestSecret(const std::string &value);

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
