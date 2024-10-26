
# <p align="center">Hello, Visitor!</p>
This is a console application, a project which implements various numerical methods to solve mathematical problems.


## Implemented Numerical Methods
1. **Solution of Linear Equations**
    * [Jacobi iterative method](README.md#jacobi-iterative-method)
    * [Gauss-Seidel iterative method](README.md#gauss-seidel-iterative-method)
    * [Gauss elimination](README.md#gauss-elimination)
    * [Gauss-Jordan elimination](README.md#gauss-jordan-elimination)
    * [LU factorization](README.md#lu-factorization)
2. **Solution of Non-linear Equations**
    * [Bi-section method](README.md#bi-section-method)
    * [False position method](README.md#false-position-method)
    * [Secant method](README.md#secant-method)
    * [Newton-Raphson method](README.md#newton-raphson-method)
3. **Solution of Differential Equations**
    * [Runge-Kutta method](README.md#runge-kutta-method)
4. **Matrix Inversion**

## Jacobi Iterative Method

## Gauss-Seidel Iterative Method

## Gauss Elimination

## Gauss-Jordan Elimination

## LU Factorization
LU Factorization is a fundamental technique in linear algebra used to solve systems of linear equations. It expresses a given square matrix A as a product of two matrices, one lower `L` and one upper `U` i.e. `A = LU`. This simplifies many matrix operations, making it an essential tool in various engineering applications.

### How it works
1. Given a set of linear equations of the form  
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>a<sub>11</sub>x<sub>1</sub> + a<sub>12</sub>x<sub>2</sub> + a<sub>13</sub>x<sub>3</sub> + ... + a<sub>1n</sub>x<sub>n</sub> = b</code>  
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>a<sub>21</sub>x<sub>1</sub> + a<sub>22</sub>x<sub>2</sub> + a<sub>23</sub>x<sub>3</sub> + ... + a<sub>2n</sub>x<sub>n</sub> = b</code>  
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>a<sub>31</sub>x<sub>1</sub> + a<sub>32</sub>x<sub>2</sub> + a<sub>33</sub>x<sub>3</sub> + ... + a<sub>3n</sub>x<sub>n</sub> = b</code>  
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>.....................................</code>  
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>a<sub>n1</sub>x<sub>1</sub> + a<sub>n2</sub>x<sub>2</sub> + a<sub>n3</sub>x<sub>3</sub> + ... + a<sub>nn</sub>x<sub>n</sub> = b</code>  
convert them into matrix form `AX = B` where `A` is the coefficient matrix,`X` is variable matrix and `B` is the matrix of constants on the right side of the equation.
2. Create two matrices naming `L` and `U` of the same size as `A`. Calculate the values of the elements of both matrices such that `LU = A`
3. Now equation can be written as `LUX = B` or `LY = B` where `UX = Y`
4. Solve `Y` from `LY = B` and then using `Y` solve `X` from `UX = Y`
<!-- ![Equation](/res/CodeCogsEqn.svg) -->

## Bi-section Method
Bi-section method is used to find root of an equation in a given interval i.e. value of `x` for which `f(x) = 0`.  
The method is based on *The Intermediate Value Theorem* which states that if `f(x)` is a continuous function and there are two real numbers `a` and `b` such that `f(a)*f(b) < 0`, then it is guaranteed that it has at least one root between them.
### How it works
#### Assumptions
1. `f(x)` is a continuous function in interval `[a, b]`
2. `f(a) * f(b) < 0`
#### Steps
1. Find middle point `c = (a + b)/2` .
2. `If` `f(c) == 0`, then `c` is the root of the solution.
3. `Else` `f(c) != 0`
    1. `If` value `f(a)*f(c) < 0` then root lies between `a` and `c`. So we recur for `a` and `c`
    2. `Else If` `f(b)*f(c) < 0` then root lies between `b` and `c`. So we recur `b` and `c`.
    3. `Else` given function doesn’t follow one of assumptions.
4. Repeat the steps until difference between `a` and `b` is less then a value (very small value).

## False Position Method
Like Bi-section method, False Position method is also an approximation method to find the roots of a given equation by repeatedly dividing the interval.  
False position method is the same as Bi-section method with the only difference is that instead of finding the middle point we find the point that touches the x-axis.
### Steps
1. Find middle point `c = (a*func(b)-b*func(a))/(func(b)-func(a))` .
2. `If` `f(c) == 0`, then `c` is the root of the solution.
3. `Else` `f(c) != 0`
    1. `If` value `f(a)*f(c) < 0` then root lies between `a` and `c`. So we recur for `a` and `c`
    2. `Else If` `f(b)*f(c) < 0` then root lies between `b` and `c`. So we recur `b` and `c`.
    3. `Else` given function doesn’t follow one of assumptions.
4. Repeat the steps until difference between `a` and `b` is less then a value (very small value).
## Secant Method

## Newton-Raphson Method

## Runge-Kutta Method