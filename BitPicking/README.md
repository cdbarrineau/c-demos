# Notes on Bit Picking


> **_IMPORTANT_**

* Shifting by a negative number or a number greater than bit width is undefined!
* All vacant bits are filled in by 0 no matter if shifting left or right.
* Left shifting by 0 always results in 1:

```
1 << 0 = 1 because x^1 == 1
```

### Left Shift

Left shift effectively multliplies by 2.

a << n is the same as mathematically: a * (2^n)

Where:
 * a: The number whose bits to shift.
 * n: The number of places to shift (e.g. 1 is shift 1 place, 2 is shift two places).

This example can see that multiplying by 2 not only gives 10 but also shifts the bits by one to the left:

```
5 in binary: (0101) : 5 << 1 = 10 (1010)  or 5 * (2^1)
```

Another example, shift bits in 5 three places:

```
5 in binary: (0101) : 5 << 3 = 40 (101000) or 5 * (2^3)
```

##### Usages

Bit Masking and Manipulation
* Used to create a Bit Mask.  Bit Masks are used to isolate, set, or clear specific bits in a binary number.

```
int mask = 1 << 3;          // Creates a mask with the fourth bit set (1000)
int value = 4;              // 5 in binary is 0101
int result = value & mask;  // Masks the larger value, isolating the fourth bit.
```

Packing data into a single integer
* Can pack individual items by shifting a bit number into the appropriate position



### Right Shift

Right shift effectively divides by 2.

a >> n is the same mathematically as a / (2^n)

(Same operands as left shift)

Example:

```
20 in binary: (10100) 20 >> 2 = 5 (1010) or 20 / (2^2)
```


 *
 * result = value << positions:
 *      r = 1 << 3 Shifts the bits in 1 by 3 positions.
 *      1 << 3 = 1000  Creates a mask with the 4th bit set.
