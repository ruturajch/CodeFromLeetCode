impl Solution {
    pub fn min_reorder(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let edges = {
            let mut ans = vec![Vec::new(); edges.len() + 1];
            for edge in edges {
                ans[edge[0] as usize].push((edge[1] as usize, true));
                ans[edge[1] as usize].push((edge[0] as usize, false));
            }
            ans
        };

        Self::dfs(0, n as usize, &edges)
    }

    fn dfs(node: usize, parent: usize, edges: &Vec<Vec<(usize, bool)>>) -> i32 {
        let mut ans = 0;

        for &(neighbor, dir) in edges[node].iter() {
            if neighbor != parent {
                if dir {
                    ans += 1
                }
                ans += Self::dfs(neighbor, node, edges);
            }
        }

        ans
    }
}