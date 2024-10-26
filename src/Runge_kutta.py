import math


def runge_kutta_method(f, x0, y0, x_end, h):
    x = x0
    y = y0
    print("\nRunge-Kutta Method Results:")
    print(f"x = {x0}, y = {y0}")

    while x < x_end:
        k1 = h * f(x, y)
        k2 = h * f(x + 0.5 * h, y + 0.5 * k1)
        k3 = h * f(x + 0.5 * h, y + 0.5 * k2)
        k4 = h * f(x + h, y + k3)
        y = y + (1 / 6) * (k1 + 2 * k2 + 2 * k3 + k4)
        x = x + h
        print(f"x = {x:.4f}, y = {y:.4f}")

    print("\nFinal Result:")
    print(f"At x = {x_end}, y = {y:.4f}")

def main():
    def f(x, y):
        return eval(func, {"x": x, "y": y, "math": math})

    print("\nNote: Use 'math' functions for complex expressions (e.g., 'math.sin(x)', 'math.exp(x)', etc.)")
    func = input("Enter the function f(x, y) for dy/dx (e.g., 'x + y' or 'math.sin(x)'): ")
    x0 = float(input("Enter the initial value of x (x0): "))
    y0 = float(input("Enter the initial value of y (y0): "))
    x_end = float(input("Enter the value of x at which to find y (x_end): "))
    h = float(input("Enter the step size (h): "))

    runge_kutta_method(f, x0, y0, x_end, h)

if __name__ == "__main__":
    main()
