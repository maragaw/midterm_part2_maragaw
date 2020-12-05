#ifndef MYSTRUCTS_H
#define MYSTRUCTS_H

struct CreditCard1 {
  unsigned long long int cardNumber;
  char firstNameInitial;
  unsigned int expirationDate;
  char lastNameInitial;
  unsigned long long int linkedCheckingAccountNumber;
  char bankNameInitial;
  bool isActive;
  int cvv;
};

struct CreditCard2 {
  unsigned long long int cardNumber;
  char firstNameInitial;
  unsigned int expirationDate;
  char lastNameInitial;
  unsigned long long int linkedCheckingAccountNumber;
  char bankNameInitial;
  int cvv;
  bool isActive;
};

struct CreditCard3 {
  unsigned long long int cardNumber;
  unsigned long long int linkedCheckingAccountNumber;
  char firstNameInitial;
  char lastNameInitial;
  unsigned int expirationDate;
  char bankNameInitial;
  bool isActive;
  int cvv;
};

#endif
