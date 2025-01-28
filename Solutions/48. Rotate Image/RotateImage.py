def rotate(matrix):
    """
    Rotate an n x n 2D matrix 90 degrees clockwise in-place.
    - You must modify the input matrix directly without allocating extra space.
    - The rotation is achieved by first transposing the matrix, then reversing each row.

    Example:
    Input:  [[1, 2, 3],
             [4, 5, 6],
             [7, 8, 9]]
    Output: [[7, 4, 1],
             [8, 5, 2],
             [9, 6, 3]]
    """

    # Step 1: Transpose the matrix
    # Transposing swaps rows and columns. Element at (i, j) becomes (j, i).
    for i in range(len(matrix)):
        for j in range(i + 1, len(matrix)):  # Only iterate over the upper triangle to avoid redundant swaps
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Step 2: Reverse each row
    # Reversing each row achieves the 90-degree clockwise rotation.
    for i in range(len(matrix)):
        matrix[i] = matrix[i][::-1]

    # Optional: Print the result for debugging purposes
    print(matrix)


# Test Cases
# Example 1:
rotate([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
# Expected Output: [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

# Example 2:
rotate([[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]])
# Expected Output: [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]]
