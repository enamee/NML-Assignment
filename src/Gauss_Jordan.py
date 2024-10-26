import numpy as np


def gauss_jordan_solver(coeff, rhs):
    aug = np.column_stack((coeff, rhs))
    n = len(rhs)

    # Gauss-Jordan Elimination - Converting to Reduced Row Echelon Form
    for r in range(n):
        if aug[r][r] == 0:
            raise ValueError("Cannot proceed: Zero pivot.")
        aug[r] = aug[r] / aug[r][r]
        for tr in range(n):
            if tr != r:
                scale = aug[tr][r]
                aug[tr] -= scale * aug[r]

    return aug[:, -1]

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
        sol = gauss_jordan_solver(coeff, rhs)
        print("\nCalculated Solutions using Gauss-Jordan Elimination:")
        for i, res in enumerate(sol):
            print(f"Variable x{i + 1} = {res}")
    except ValueError as err:
        print(f"An error occurred: {err}")

if __name__ == "__main__":
    main()
