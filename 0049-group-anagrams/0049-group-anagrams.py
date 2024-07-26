class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        helperMap = defaultdict(list)
        for str in strs:
            sorted_str = tuple(sorted(str))
            helperMap[sorted_str].append(str)
        return list(helperMap.values())
        