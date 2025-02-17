import sys
input = sys.stdin.read

def main():
    data = input().split()
    n = int(data[0])
    q = int(data[1])
    
    cnt = [[[0] * n for _ in range(n)] for _ in range(3)]
    
    ans = 0
    index = 2
    results = []
    for _ in range(q):
        x = int(data[index])
        y = int(data[index + 1])
        z = int(data[index + 2])
        index += 3
        
        if cnt[0][x][y] + 1 == n:
            ans += 1
        cnt[0][x][y] += 1
        
        if cnt[1][y][z] + 1 == n:
            ans += 1
        cnt[1][y][z] += 1
        
        if cnt[2][x][z] + 1 == n:
            ans += 1
        cnt[2][x][z] += 1
        
        results.append(str(ans))
    
    print("\n".join(results))

if __name__ == "__main__":
    main()
