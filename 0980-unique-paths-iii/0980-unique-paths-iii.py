class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        # brute se nahi hoga kya
        # lets see kya optimization lagengi

        
        visited = []
        for i in grid:
            i.insert(0, -1)
            i.append(-1)
        grid.append([-1]*len(grid[0]))
        grid.insert(0, [-1]*len(grid[0]))
        
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j] == -1: visited.append(1)
                else: visited.append(0)
                if grid[i][j] == 1: start = [i, j]
                if grid[i][j] == 2: end = [i, j]
                    

        to_go = [[0,1], [1,0], [-1,0], [0,-1]]
        # print(visited, start, end)
        # print(grid, n, m)

        def backtrack(x, y, visited):
            if x >= n or y >= m: return 0

            # print(x, y)
            if [x, y] == end:
                # print("AHA!")
                if visited.count(0) == 1:
                    return 1
                else:
                    return 0

            visited[x*m+y] = 1
            ans = 0
            for dx, dy in to_go:
                if not visited[(x+dx)*m + y+dy] and grid[x+dx][y+dy] != -1:
                    ans += backtrack(x+dx, y+dy, visited)

            visited[x*m+y] = 0
            return ans

        return backtrack(start[0], start[1], visited)