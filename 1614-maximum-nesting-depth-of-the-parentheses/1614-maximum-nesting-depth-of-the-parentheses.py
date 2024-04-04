class Solution:
    def maxDepth(self, s: str) -> int:
        helper_stack = []
        ans = 0
        for char in s:
            if char == '(':
                helper_stack.append(char)
            elif char == ')':
                ans = max(ans, len(helper_stack))
                helper_stack.pop()
        return ans