class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        helperMap = defaultdict(int)
        for num in nums:
            helperMap[num] += 1
        sorted_items = sorted(helperMap.items(), key=lambda x: x[1], reverse=True)
        return [item[0] for item in sorted_items[:k]]
