// adapted from https://github.com/kokke/tiny-bignum-c/blob/master/tests/factorial.c
#include <stdio.h>
#include <stdlib.h>

#include "BigInt.h"

void echo(int words, BigInt_t* a){
  char buf[8192]; // TODO: infer from `words`
  // TODO: support bignum_to_string; make it safer by passing length of buffer
  BigInt_to_hex_string(words, a, buf);
  printf("num = {%s}\n", buf);
}

void factorial(int words, BigInt_t* n, BigInt_t* res)
{
  BigInt_t * tmp = (BigInt_t*) malloc(BigIntWordSize*words);
  /* Copy n -> tmp */
  BigInt_copy(words, tmp, n);

  /* Decrement n by one */
  BigInt_dec(words, n);

  /* Begin summing products: */
  while (!BigInt_is_zero(words, n))
  {
    /* res = tmp * n */
    BigInt_mul(words, tmp, words, n, words, res); // Karatsuba multiplication
    // BigInt_mul_basic(words, tmp, n, res); // old method, faster for small numbers; TODO: specify for which sizes

    /* n -= 1 */
    BigInt_dec(words, n);
    
    /* tmp = res */
    BigInt_copy(words, tmp, res);
  }

  /* res = tmp */
  BigInt_copy(words, res, tmp);
}


void test1(int n){
  int words = 10; /// PARAM
  BigInt_t* result = (BigInt_t*) malloc(BigIntWordSize*words);
  BigInt_t* num = (BigInt_t*) malloc(BigIntWordSize*words);
  BigInt_from_int(words, num, n);
  factorial(words, num, result);
  // echo(words, result);
}

int main(){
  for(int i=0;i<1000;i++) test1(100);
  // for(int i=0;i<1000;i++) test1(i); // TODO: BUG w 0
  return 0;
}

