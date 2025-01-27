 auto check = [&](vector<bool>& vis, int src, auto& r_check) -> void {
            vis[src] = true;

            for (auto it: adj[src]) {
                if (!vis[it]) {
                    r_check(vis, it, r_check);
                }
            }
        };
