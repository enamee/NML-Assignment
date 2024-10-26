import numpy as np


def gauss_solver(coeff, rhs):
    aug = np.column_stack((coeff, rhs))
    n = len(rhs)
    
    # Step 1: Forward Elimination - Convert to upper triangular form
    for r in range(n):
        if aug[r][r] == 0:
            raise ValueError("Cannot proceed: Zero pivot.")
        for tr in range(r + 1, n):
            scale = aug[tr][r] / aug[r][r]
            aug[tr] -= scale * aug[r]
    
    # Step 2: Back Substitution - Solving the upper triangular system
    sol = np.zeros(n)
    for r in range(n - 1, -1, -1):
        if r + 1 < n:
            sum_prod = np.dot(aug[r][r + 1:n], sol[r + 1:n])
        else:
            sum_prod = 0
        sol[r] = (aug[r][-1] - sum_prod) / aug[r][r]

    return sol

def main():
    var_count = int(input("Enter the number of variables (equations): "))
    coeff_data = []
    rhs_data = []

    print("\nProvide the coefficients for each equation:")
    for i in range(var_count):
        coeff_line = input(f"Equation {i + 1} coefficients (space-separated): ").split()
        coeff_data.append([float(x) for x in coeff_line])

    print("\nProviding the constants (RHS values):")
    rhs_data = [float(input(f"Constant for equation {i + 1}: ")) for i in range(var_count)]

    coeff = np.array(coeff_data, dtype=float)
    rhs = np.array(rhs_data, dtype=float)

    try:
        sol = gauss_solver(coeff, rhs)
        print("\nCalculated Solutions using Gauss Elimination:")
        for i, res in enumerate(sol):
            print(f"Variable x{i + 1} = {res}")
    except ValueError as err:
        print(f"An error occurred: {err}")

if __name__ == "__main__":
    main()
