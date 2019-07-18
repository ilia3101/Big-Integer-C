# Small and fast Big Integer library in C

Made this for one of my own projects. No dynamic memory allocation is used. Everything is done on the stack, so you may want to be careful if your numbers are bigger than a megabyte :stuck_out_tongue_winking_eye:

Based on the amazing [kokke/tiny-bignum-c](https://github.com/kokke/tiny-bignum-c), but with the following changes:
- [Karatsuba](https://en.wikipedia.org/wiki/Karatsuba_algorithm) multiplication algorithm: **shocking** speed improvement for bigger numbers
- Added function to convert denary strings to integers
- No use of `sscanf` and `sprintf` for converting to and from hex
- Size of big ints is not set at compile time, but rather passed as an argument to all functions
- Optional use of 64 bit words: nice speed up if your CPU has 64→128 multiplications (it probably does)
- The add, subtract and multiply functions can take differently sized inputs

If what you want is the fastest library for big numbers, look at [GNU GMP](https://gmplib.org/), but if you want to be in control of your memory, you have come to the right place.

Usage example:

```
// integers in this demo will be 100 words in size
int words = 100;

// allocate 3 numbers, all 100 words in length
BigInt_t * number1 = malloc(BigIntWordSize*words);
BigInt_t * number2 = malloc(BigIntWordSize*words);
BigInt_t * number3 = malloc(BigIntWordSize*words);

// set number1 and number2 values to some random digits
BigInt_from_string(words, number1, "1234567890123456789012345678902187617826");
BigInt_from_string(words, number1, "12134");

// multiply number1 by number2, outputting to 3
BigInt_mul(words, number1, words, number2, words, number3);
```

... also I have not tested everything yet :confused:
