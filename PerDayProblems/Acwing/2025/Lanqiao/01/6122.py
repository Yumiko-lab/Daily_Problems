def main():
    n, q = map(int, input().split())
    
    cnt = [[[0] * n for _ in range(n)] for _ in range(3)]
    
    res = []
    ans = 0
    for _ in range(q):
        x, y, z = map(int, input().split())
        
        if cnt[0][x][y] + 1 == n:
            ans += 1
        cnt[0][x][y] += 1
        
        if cnt[1][y][z] + 1 == n:
            ans += 1
        cnt[1][y][z] += 1
        
        if cnt[2][x][z] + 1 == n:
            ans += 1
        cnt[2][x][z] += 1
        
        res.append(str(ans))
    
    print("\n".join(res))

if __name__ == "__main__":
    main()