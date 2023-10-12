class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        
        n = s.replace("()", "(1)").replace(")(", ")+(") 
        while n.count("(("):
            n = n.replace("((","2*(1*(").replace("1*(2", "2*(2")
        return eval(n)