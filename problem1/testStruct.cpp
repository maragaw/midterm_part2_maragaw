#include "MyStructs.h"
#include "structFuncs.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {

  // Sample
  CreditCard1 a;
  unsigned long sizeCreditCard1 = 40;
  ASSERT_EQUALS(sizeof(a), sizeCreditCard1);

  //You should write your own tests below.
  CreditCard2 b;
  unsigned long sizeCreditCard2 = 48;
  ASSERT_EQUALS(sizeof(b), sizeCreditCard2);

  CreditCard3 c;
  unsigned long sizeCreditCard3 = 32;
  ASSERT_EQUALS(sizeof(c), sizeCreditCard3);

  
  //getPadding tests
  unsigned long paddingSize1 = 12;
  ASSERT_EQUALS(getPadding(a),paddingSize1);
  unsigned long paddingSize2 = 20;
  ASSERT_EQUALS(getPadding(b),paddingSize2);
  unsigned long paddingSize3 = 4;
  ASSERT_EQUALS(getPadding(c),paddingSize3);


  
  return 0;
}
