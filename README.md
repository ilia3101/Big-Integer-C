# Small and fast Big Integer library in C

Made this for one of my own projects. This library uses no dynamic memory allocation. So everything is done on the stack. You may want to be careful with multiplying if your numbers are bigger than a megabyte :stuck_out_tongue_winking_eye:

Originally based on the amazing [kokke/tiny-bignum-c](https://github.com/kokke/tiny-bignum-c), but with the following changes:
- [Karatsuba](https://en.wikipedia.org/wiki/Karatsuba_algorithm) multiplication algorithm: a **shocking** speed improvement for bigger numbers, O(n^1.585) instead of O(n^2)
- Not dependant on on `sscanf` and `sprintf` for hex string conversions
- Size of big ints is not set at compile time, but rather passed as an argument to all functions
- Optional use of 64 bit words, big speed improvement if your CPU can do 64→128 multiplications (probably can)
- The add, subtract and multiply functions can take different sized inputs

Usage example:

```
// integers in this demo will be 100 words in size
int words = 100;

// allocate 3 numbers, all 100 words in length
BigInt_t * number1 = malloc(BigIntWordSize*words);
BigInt_t * number2 = malloc(BigIntWordSize*words);
BigInt_t * number3 = malloc(BigIntWordSize*words);

BigInt_from_string(words, number1, "1234567890123456789012345678902187617826");
BigInt_from_string(words, number1, "12134");

// multiply number1 by number2, outputting to 3
BigInt_mul(words, number1, words, number2, words, number3);
```
