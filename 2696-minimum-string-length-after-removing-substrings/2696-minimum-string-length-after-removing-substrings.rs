impl Solution {
    pub fn min_length(s: String) -> i32 {
        let mut stack = Vec::new();
        
        for ch in s.chars() {
            if !stack.is_empty() && ((ch == 'B' && *stack.last().unwrap() == 'A') || (ch == 'D' && *stack.last().unwrap() == 'C')) {
                stack.pop();
            } else {
                stack.push(ch);
            }
        }
        
        stack.len() as i32
    }
}