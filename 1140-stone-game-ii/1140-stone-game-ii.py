class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        # dp hi hai bc. ek aur factor aa jayega 'm' ka. initally its 1.
        # to wait khelna to hai hame but subtract nahi karna ab right??
        memo = {}
        n = len(piles)
        def dp(index, m, alex=True):
            if index >= n: return 0
            if (index, m, alex) in memo: return memo[(index, m, alex)][0]

            ans = -inf
            jump = 0
            curr_pile = 0
            for i in range(2*m):
                if index+i >= n:
                    break
                curr_pile += piles[index+i]
                ans2 = curr_pile - dp(index+i+1, max(i+1, m), not alex)
                if ans2 > ans:
                    jump = i+1
                    ans = ans2
            
            memo[(index, m, alex)] = (ans, jump)
            return ans

        dp(0, 1, True)
        ind = 0
        m = 1
        alex = True
        ans = 0
        # for i in memo:
        #     print(i, memo[i])

        while(ind < len(piles)):
            ans += memo[(ind, m, alex)][0]
            jumps = memo[(ind, m, alex)][1]
            ind += jumps
            m = max(m, jumps)
            alex = not alex

        return ans




        return ans