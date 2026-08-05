class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        # n = 50 CHHI! chi chi question (jaldi boldiya kya) 2500 elements hai to bc.
        # path with MINIMUM MAX VALUE. question understood 50% solved.
        # simple bfs bruteforce?
        # simple dp tabulation? 4 directional kaisa hoga

        # exploring every path to pakka tle dega bc
        # 1 to n2 hi numbers hai. we use that somehow.
        # so the WORST path would be including nsquare - 1. 
        # best path: (n-2)*2+1 elements honge usme max = (n-2)*2 
        
        n = len(grid)
        # print(grid)
        queue = [(grid[0][0], 0, 0)]
        visited = [[0]*n for i in range(n)]

        while queue:
            m, x, y = heappop(queue)
            if (x, y) == (n-1,n-1):
                return m
            if visited[x][y]: continue

            if x != n-1:
                heappush(queue, (max(m, grid[x+1][y]), x+1, y ))
                
            if x != 0:
                heappush(queue, (max(m, grid[x-1][y]), x-1, y))
            if y != n-1:
                heappush(queue, (max(m, grid[x][y+1]), x, y+1))
            if y != 0:
                heappush(queue, (max(m, grid[x][y-1]), x, y-1))

            visited[x][y] = 1
        