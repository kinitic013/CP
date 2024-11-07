def is_convertible(grid_a, grid_b):
  n, m = len(grid_a), len(grid_a[0])

  # Check sum of elements
  sum_a, sum_b = 0, 0
  for i in range(n):
    for j in range(m):
      sum_a += int(grid_a[i][j])
      sum_b += int(grid_b[i][j])
  if sum_a != sum_b:
    return "NO"

  # Check parity of diagonally opposite corners
  for i in range(n):
    for j in range(m):
      # Top-left and bottom-right
      parity_a1 = grid_a[i][j] % 2
      parity_b1 = grid_b[i][j] % 2
      # Top-right and bottom-left
      parity_a2 = grid_a[i][m-j-1] % 2
      parity_b2 = grid_b[i][m-j-1] % 2

      if (parity_a1 != parity_b1) or (parity_a2 != parity_b2):
        return "NO"

  return "YES"

def main():
  t = int(input())  # Read number of test cases

  for _ in range(t):
    n, m = map(int, input().split())  # Read grid dimensions (n rows, m columns)

    grid_a = []
    for _ in range(n):
      grid_a.append(input())  # Read grid a row by row

    grid_b = []
    for _ in range(n):
      grid_b.append(input())  # Read grid b row by row

    result = is_convertible(grid_a, grid_b)
    print(result)

if __name__ == "__main__":
  main()
