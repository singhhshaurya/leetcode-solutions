class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        # okay so how do we approach?
        # include exclude? every indice we have 2 options either remoe or not in final answer
        # each removal have to check sab lexicographical hue ya nahi
        # 100*100 = 10**4. dp would take 100 so 10**6? seems good? 
        # dp[i] = min removal req to make all [i:] lexicographical
        # so dp[i] = dp[i+1] if ith and ith+1 are in order, else dp[i+1]+1. seems so
        # any mismatch me +1 hi karde ig ho jana chahiye
        
        dp = [1]*len(strs[0])

        for i in range(len(strs[0])):
            longest = 1
            for k in range(i-1, -1, -1):
                for j in range(len(strs)): # check on all the words.
                    if strs[j][k] > strs[j][i]:
                        break
                else:
                    longest = max(longest, dp[k]+1)
            dp[i] = longest


        # print(dp)
        return len(strs[0]) - max(dp)