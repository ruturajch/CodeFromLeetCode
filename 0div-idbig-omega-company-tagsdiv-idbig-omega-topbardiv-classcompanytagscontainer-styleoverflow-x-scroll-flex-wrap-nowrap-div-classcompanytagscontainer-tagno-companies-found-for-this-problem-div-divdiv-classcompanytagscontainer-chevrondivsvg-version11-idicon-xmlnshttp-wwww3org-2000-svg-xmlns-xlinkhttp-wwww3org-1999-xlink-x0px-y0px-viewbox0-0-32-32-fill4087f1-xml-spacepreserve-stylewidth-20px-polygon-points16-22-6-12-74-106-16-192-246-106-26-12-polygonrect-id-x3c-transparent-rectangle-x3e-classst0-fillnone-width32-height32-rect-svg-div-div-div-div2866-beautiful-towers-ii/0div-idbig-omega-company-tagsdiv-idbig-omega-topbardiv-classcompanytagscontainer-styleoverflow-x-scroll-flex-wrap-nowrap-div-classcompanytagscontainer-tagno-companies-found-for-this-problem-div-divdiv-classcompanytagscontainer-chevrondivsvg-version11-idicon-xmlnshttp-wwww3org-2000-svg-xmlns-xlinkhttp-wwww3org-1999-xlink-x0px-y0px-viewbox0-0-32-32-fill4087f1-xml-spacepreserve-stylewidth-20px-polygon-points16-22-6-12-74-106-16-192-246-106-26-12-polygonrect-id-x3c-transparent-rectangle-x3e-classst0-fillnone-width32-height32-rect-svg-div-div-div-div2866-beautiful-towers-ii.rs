impl Solution {
    pub fn maximum_sum_of_heights(max_heights: Vec<i32>) -> i64 {
        let n = max_heights.len();
        let (mut left, mut right) = (vec![0i64; n], vec![0i64; n]);
        
        let mut sk = Vec::<(i32, usize)>::new();
        for i in 0 .. n {
            while sk.is_empty() == false && sk[sk.len() - 1].0 > max_heights[i] {
                sk.pop();
            }

            left[i] = if sk.is_empty() { max_heights[i] as i64 * (i as i64 + 1) } else 
                      { max_heights[i] as i64 * (i as i64 - sk[sk.len() - 1].1 as i64) 
                        + left[sk[sk.len() - 1].1]};
            
            sk.push((max_heights[i], i));
        }

        let mut sk = Vec::<(i32, usize)>::new();
        for i in (0 .. n).rev() {
            while sk.is_empty() == false && sk[sk.len() - 1].0 > max_heights[i] {
                sk.pop();
            }

            right[i] = if sk.is_empty() { max_heights[i] as i64 * (n as i64 - i as i64) } else 
                       { max_heights[i] as i64 * (sk[sk.len() - 1].1 as i64 - i as i64) 
                        + right[sk[sk.len() - 1].1]};
            
            sk.push((max_heights[i], i));
        }

        let mut ret = 0;
        for i in 0 .. n {
            ret = ret.max(left[i] + right[i] - max_heights[i] as i64);
        }

        ret
    }
}
