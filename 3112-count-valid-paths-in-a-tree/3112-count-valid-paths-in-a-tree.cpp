struct DSU {
    vector<int> par;
    vector<int> cnt;
    
    DSU (int n) {
        par.resize(n+1, 0);
        cnt.resize(n+1, 1);
        
        for (int j = 0; j <= n; j ++) par[j] = j;
    }
    
    int Leader (int x) {
        if (x == par[x]) return x;
        return (par[x] = Leader(par[x]));
    }
    
    void Merge (int x, int y) {
        x = Leader(x);
        y = Leader(y);
        
        if (x == y) return;
        if (cnt[x] > cnt[y]) swap(x, y);
        
        cnt[y] += cnt[x];
        par[x]  = y;
    }
};

const int N = 1e5+1;
vector<vector<int>> g(N);

vector<int> sieve(N, 0);
bool sieve_built = false;

class Solution {
    
    void BuildSieve() {
        if (sieve_built) return;
        
        sieve_built = true;
        
        for (int j = 2; j < N; j ++) {
            if (!sieve[j]) sieve[j] = j;
            
            for (int k = j+j; k < N; k += j) 
                if (!sieve[k]) sieve[k] = j;
        }
    }
    
    bool IsPrime (int x) {
        return (sieve[x] == x);
    }
    
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        BuildSieve();
        for (int j = 0; j <= n; j ++) g[j].clear();
        
        DSU dsu(n);
        
        for (auto i : edges) {
            int u = i[0], v = i[1];
            g[u].push_back(v);
            g[v].push_back(u);
            
            bool u_p = IsPrime(u);
            bool v_p = IsPrime(v);
            
            if (u_p || v_p) continue;
            dsu.Merge(u, v);
        }
        
        long long result = 0;
        for (int j = 1; j <= n; j ++) {
            if (!IsPrime(j)) continue;
            
            vector<int> nodes;
            long long sum = 1;
            
            for (auto e: g[j]) {
                if (IsPrime(e)) continue;
                                
                nodes.push_back(dsu.cnt[dsu.Leader(e)]);
                sum += nodes.back();
            }
            
            for (auto i : nodes) {
                sum -= i;
                result += sum * i;
            }
        }
        return result;
    }
};