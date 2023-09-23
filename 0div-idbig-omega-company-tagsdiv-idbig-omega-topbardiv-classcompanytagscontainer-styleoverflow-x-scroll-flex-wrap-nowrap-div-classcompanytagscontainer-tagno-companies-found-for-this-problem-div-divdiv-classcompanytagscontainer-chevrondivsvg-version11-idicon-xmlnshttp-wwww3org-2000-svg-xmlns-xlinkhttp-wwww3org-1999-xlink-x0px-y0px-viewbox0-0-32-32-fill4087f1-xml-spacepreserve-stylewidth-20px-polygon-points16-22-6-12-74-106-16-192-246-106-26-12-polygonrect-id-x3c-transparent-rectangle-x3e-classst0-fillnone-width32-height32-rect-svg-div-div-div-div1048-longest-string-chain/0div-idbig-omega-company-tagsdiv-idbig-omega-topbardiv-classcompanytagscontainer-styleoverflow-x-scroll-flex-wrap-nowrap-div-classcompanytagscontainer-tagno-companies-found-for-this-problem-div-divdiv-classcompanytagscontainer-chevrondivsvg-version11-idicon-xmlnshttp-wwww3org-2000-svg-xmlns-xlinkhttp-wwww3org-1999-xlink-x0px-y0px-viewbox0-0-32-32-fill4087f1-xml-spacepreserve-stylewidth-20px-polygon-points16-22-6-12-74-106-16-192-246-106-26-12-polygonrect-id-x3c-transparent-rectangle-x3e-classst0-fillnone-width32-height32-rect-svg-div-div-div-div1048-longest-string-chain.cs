public class Solution {
    public int LongestStrChain(string[] words) {
        Dictionary<int,List<string>> d = new Dictionary<int,List<string>>();
        for(int i = 1; i <=16; i++)
        {
            d[i] = new List<string>();
        }
        foreach(string s in words)
        {
            int length = s.Length;
            d[length].Add(s);
            //Console.WriteLine(s.Length + " " + s + " " + d[length].Count);
        }
        List<(string,int)> lastSet = new List<(string,int)>();
        int maxChain = 0;
        for(int i = 1; i <=16; i++)
        {
            //Console.WriteLine(i);
            List<(string,int)> newSet = new List<(string,int)>();
            
            if(lastSet.Count == 0)
            {
                //Console.WriteLine("i count: " + i + " " + d[i].Count);
                foreach(string s in d[i])
                {
                    //Console.WriteLine("adding first: " + s + " " + 1);
                    newSet.Add((s,1));
                }
                maxChain = Math.Max(maxChain,1);
            }
            else
            {
                foreach(string t in d[i])
                {
                    bool added = false;
                    int maxTStreak = 1;
                    foreach((string,int) pair in lastSet)
                    {
                        string s = pair.Item1;
                        int streak = pair.Item2;
                        if(valid(s,t))
                        {
                            added=true;
                            //Console.WriteLine("adding: " + t + " " + (streak+1));
                            maxTStreak = Math.Max(maxTStreak,streak+1);
                            
                            maxChain = Math.Max(maxChain,streak+1);
                            //break;
                        }
                    }
                    newSet.Add((t,maxTStreak));
                }
            }
                
            lastSet = newSet;
        }
        return maxChain;
    }
    private bool valid(string smaller, string bigger)
    {
        //Console.WriteLine("Compare: " + smaller + " " + bigger);
        bool addedOne = false;
        int l = 0;
        int r = 0;
        while(l<smaller.Length && r<bigger.Length)
        {
            if(smaller[l]==bigger[r])
            {
                l++;
                r++;
            }
            else
            {
                if(addedOne)
                {
                    return false;
                }
                r++;
                addedOne=true;
            }
        }
        return true;
    }
}