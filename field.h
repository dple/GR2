#include<stdint.h>

typedef uint8_t u8;     // unsigned integer 8-bit
typedef uint64_t limb;  // 64-bits word 
typedef uint128_t widelimb; // 128-bits word

typedef limb felem[4];        // A 256-bits field element represented as five 64-bits words
typedef widelimb widefelem[7]; // an extension field element represented as eight 128-bits words
typedef u8 felem_bytearray[33]; // Field element represented as a byte arrary. 33*8 = 264 bits 
                                
/*
 *                              FIELD OPERATIONS
 */
/* Sum two field elements: out += in */
void felem_sum(felem out, const felem in);

/* Get negative value: out = -in */
void felem_neg(felem out, const felem in);

/* Subtract field elements: out -= in */
void felem_diff(felem out, const felem in);

/* Subtract in unreduced 128-bit mode: out -= in */
void widefelem_diff(widefelem out, const widefelem in);

/* Square a field element: out = in^2 */
void felem_square(widefelem out, const felem in);

/* Multiply two field elements: out = in1 * in2 */
void felem_mul(widefelem out, const felem in1, const felem in2);

/* Reduce seven 128-bit coefficients to four 64-bit coefficients */
void felem_reduce(felem out, const widefelem in);

void felem_square_reduce(felem out, const felem in);

void felem_mul_reduce(felem out, const felem in1, const felem in2);

/* Invert a field element */
void felem_inv(felem out, const felem in);
