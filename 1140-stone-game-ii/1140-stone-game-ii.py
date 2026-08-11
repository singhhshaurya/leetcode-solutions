class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        # dp hi hai bc. ek aur factor aa jayega 'm' ka. initally its 1.
        # to wait khelna to hai hame but subtract nahi karna ab right??
        n = len(piles)
        memo = [[[-1, -1] for i in range(n+1)] for i in range(n)]

        suffix_sums = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix_sums[i] = suffix_sums[i + 1] + piles[i]

        def dp(index, m, alex=True):
            if index + 2 * m >= n:
                return suffix_sums[index]
            if index >= n: return 0
            if memo[index][m] != [-1, -1]: return memo[index][m][0]

            ans = -inf
            jump = 0
            curr_pile = 0
            for i in range(min(2*m, n-index)):
                curr_pile += piles[index+i]
                ans2 = curr_pile - dp(index+i+1, max(i+1, m), not alex)
                if ans2 > ans:
                    jump = i+1
                    ans = ans2
            
            memo[index][m] = (ans, jump)
            return ans

        dp(0, 1, True)
        ind = 0
        m = 1
        ans = 0


        while(ind < len(piles)):
            if ind + 2 * m >= n:
                ans += suffix_sums[ind]
                break
            ans += memo[ind][m][0]
            jumps = memo[ind][m][1]
            ind += jumps
            m = max(m, jumps)


        return ans

