class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        # sort karde agar
        # pehle wale interval se most optimal would be last ke 2 lena
        # possibility hai next wale interval me bhi aa jaye
        # nahi to next wale k last k do lele
        # hojana chahiye?


        prev1 = -1
        prev2 = -1
        ans = 0

        intervals.sort(key=lambda x:x[1])
        # print(intervals)
        for start, end in intervals:
            if prev1 >= start and prev1 <= end: # means it is good. part of interval
                pass
            else:
                prev1 = end
                ans += 1
            
            if prev2 >= start and prev2 <= end:
                pass
            else:
                prev2 = end
                ans += 1

            if prev1 > prev2:
                prev1, prev2 = prev2, prev1

            if prev1 == prev2: # kabhi same hogaye bhadwe.
                if prev2==end:
                    prev1 -=1
                else:
                    prev2 += 1
            # print(prev1, prev2, ans)

        return ans
            