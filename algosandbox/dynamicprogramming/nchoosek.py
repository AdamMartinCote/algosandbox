def nchoosek_recursive(n: int, k: int) -> int:
    if k == n or k == 0:
        return 1
    else:
        return nchoosek_recursive(n - 1, k) + nchoosek_recursive(n - 1, k - 1)


def nchoosek_dp(n: int, k: int) -> int:
    table = []
    for row in range(n + 1):
        table.append([])
        for col in range(min(k + 1, row + 1)):
            if col == 0 or col == row:
                table[row].append(1)
            else:
                table[row].append(table[row - 1][col] + table[row - 1][col - 1])
    return table[-1][-1]
