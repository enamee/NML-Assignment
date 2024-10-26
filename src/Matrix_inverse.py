import numpy as np


def display_inverse_matrix(matrix):
    try:
        inv_matrix = np.linalg.inv(matrix)
        print("\nInverse of the Provided Matrix:")
        print(inv_matrix)
    except np.linalg.LinAlgError:
        print("The matrix is singular and cannot be inverted.")

def main():
    size = int(input("Enter the size of the matrix (e.g., 3 for a 3x3 matrix): "))
    matrix_data = []

    print("\nProvide the matrix to invert:")
    for i in range(size):
        row = input(f"Row {i + 1} elements (space-separated): ").split()
        matrix_data.append([float(x) for x in row])

    matrix = np.array(matrix_data, dtype=float)
    display_inverse_matrix(matrix)

if __name__ == "__main__":
    main()
