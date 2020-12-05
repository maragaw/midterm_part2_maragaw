#ifndef STRUCTFUNCS_H
#define STRUCTFUNCS_H

template<typename S>
unsigned long getPadding(S s) {
  unsigned long padding;
  //assuming only instances of CreditCard1, 2, and 3 are passed in, which have a total amount of 28 bytes of data
  padding = sizeof(s) - 28;
  return padding;
}

#endif
