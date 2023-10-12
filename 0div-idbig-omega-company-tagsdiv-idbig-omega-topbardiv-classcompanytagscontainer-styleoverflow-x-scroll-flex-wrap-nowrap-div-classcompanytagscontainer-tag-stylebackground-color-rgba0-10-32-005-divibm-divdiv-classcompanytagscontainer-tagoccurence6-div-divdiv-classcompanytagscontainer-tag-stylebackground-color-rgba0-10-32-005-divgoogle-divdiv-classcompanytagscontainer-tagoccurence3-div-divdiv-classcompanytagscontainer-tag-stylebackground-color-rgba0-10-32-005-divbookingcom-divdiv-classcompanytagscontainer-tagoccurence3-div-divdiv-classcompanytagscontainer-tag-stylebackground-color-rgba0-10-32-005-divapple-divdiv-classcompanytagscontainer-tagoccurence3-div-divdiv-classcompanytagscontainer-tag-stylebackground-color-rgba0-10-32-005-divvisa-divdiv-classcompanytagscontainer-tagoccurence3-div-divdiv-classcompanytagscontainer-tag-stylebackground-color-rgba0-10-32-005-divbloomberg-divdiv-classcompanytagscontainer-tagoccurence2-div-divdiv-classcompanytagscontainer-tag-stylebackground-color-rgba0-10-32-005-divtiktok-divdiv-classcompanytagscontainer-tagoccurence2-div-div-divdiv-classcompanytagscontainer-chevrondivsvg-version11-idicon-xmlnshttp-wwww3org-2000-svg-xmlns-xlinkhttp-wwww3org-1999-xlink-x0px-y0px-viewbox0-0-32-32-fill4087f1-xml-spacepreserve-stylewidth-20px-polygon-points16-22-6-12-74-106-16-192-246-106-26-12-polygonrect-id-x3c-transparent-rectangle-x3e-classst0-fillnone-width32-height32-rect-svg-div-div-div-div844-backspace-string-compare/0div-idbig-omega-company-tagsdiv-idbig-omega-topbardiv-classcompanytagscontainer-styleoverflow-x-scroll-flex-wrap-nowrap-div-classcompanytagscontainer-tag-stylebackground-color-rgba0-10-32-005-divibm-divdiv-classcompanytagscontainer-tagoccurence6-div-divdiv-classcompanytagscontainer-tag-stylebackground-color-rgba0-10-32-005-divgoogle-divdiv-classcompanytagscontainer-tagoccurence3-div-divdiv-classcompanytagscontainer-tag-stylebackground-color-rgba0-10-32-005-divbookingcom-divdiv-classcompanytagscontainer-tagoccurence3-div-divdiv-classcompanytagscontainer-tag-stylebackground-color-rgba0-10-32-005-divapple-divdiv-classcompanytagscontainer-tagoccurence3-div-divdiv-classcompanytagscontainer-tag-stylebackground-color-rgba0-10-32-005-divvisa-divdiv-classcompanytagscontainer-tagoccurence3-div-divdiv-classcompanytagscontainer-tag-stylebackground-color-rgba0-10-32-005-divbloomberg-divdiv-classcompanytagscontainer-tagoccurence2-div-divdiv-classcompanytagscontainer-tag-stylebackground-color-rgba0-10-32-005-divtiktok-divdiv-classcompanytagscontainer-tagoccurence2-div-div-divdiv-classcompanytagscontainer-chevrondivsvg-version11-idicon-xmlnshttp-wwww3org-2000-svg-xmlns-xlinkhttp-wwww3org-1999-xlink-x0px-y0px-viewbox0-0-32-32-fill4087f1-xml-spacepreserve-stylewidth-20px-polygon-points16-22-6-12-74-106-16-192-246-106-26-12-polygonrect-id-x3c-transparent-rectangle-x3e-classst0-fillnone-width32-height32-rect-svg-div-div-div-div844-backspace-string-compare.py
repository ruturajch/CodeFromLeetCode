class Solution(object):
    def backspaceCompare(self, s, t):
        s_str=""
        t_str=""
        for letters in s:

            if letters=="#":
                s_str=s_str[:-1]
            else:
                s_str+=letters
        # print(s_str)
        for letters in t:

            if letters=="#":
                t_str=t_str[:-1]
            else:
                t_str+=letters
        # print(t_str)
        if s_str==t_str:
            # print("True")
            return True
        else:
            # print("False")
            return False