# Fast Fourier Transform (FFT) for Polynomial Multiplication

## Description
This program implements **Fast Fourier Transform (FFT)** to efficiently multiply two polynomials. It leverages the **Divide and Conquer** strategy along with **complex number arithmetic** to achieve a time complexity of **O(n log n)**.

## How the Algorithm Works

1. **FFT (Fast Fourier Transform):**
   - Recursively splits the polynomial into even and odd indexed coefficients.
   - Applies the FFT using complex roots of unity (`ω = e^(2πi/n)`) for evaluation at n-th roots of unity.
   - Uses an iterative **butterfly operation** to combine results.
   - If `invert = true`, it computes the **Inverse FFT (IFFT)** by reversing the transformation and normalizing the values.

2. **Polynomial Multiplication:**
   - Converts the polynomial coefficient vectors into complex vectors.
   - Extends them to a power of 2 size to prevent circular convolution issues.
   - Performs FFT on both polynomials.
   - Multiplies the transformed values element-wise.
   - Applies the **Inverse FFT** to retrieve the coefficient representation of the result.
   - Rounds the coefficients to the nearest integer.

3. **Handling Input and Output:**
   - Reads two polynomials as coefficient lists.
   - Reverses input order for proper multiplication.
   - Outputs the resulting polynomial degree and coefficients.

## Input Format
- Two lines describing the polynomials:
  - First integer: Degree of the first polynomial.
  - Next `degree + 1` integers: Coefficients of the first polynomial.
  - Next integer: Degree of the second polynomial.
  - Next `degree + 1` integers: Coefficients of the second polynomial.

## Output Format
- First integer: Degree of the resulting polynomial.
- Next `degree + 1` integers: Coefficients of the resultant polynomial (from highest to lowest degree).

## Complexity Analysis
- **FFT Complexity:** O(n log n)
- **Overall Complexity:** O(n log n) (significantly faster than naive O(n²) multiplication)

## Example Usage

### **Input**
2 1 0 2 \
1 2 3

## **Output**
3 2 3 4 6 
