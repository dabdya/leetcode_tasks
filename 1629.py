class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        n = len(releaseTimes)
        
        slowest_index = 0
        for i in range(1,n):
            release_time = releaseTimes[i] - releaseTimes[i-1]
            slow_time = releaseTimes[slowest_index]
            if slowest_index > 0:
                slow_time -= releaseTimes[slowest_index-1]
            if release_time > slow_time:
                slowest_index = i
            elif release_time == slow_time:
                if keysPressed[i] > keysPressed[slowest_index]:
                    slowest_index = i
        return keysPressed[slowest_index]