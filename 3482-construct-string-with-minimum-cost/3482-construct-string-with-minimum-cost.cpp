const int mxN = 1e6 + 5;
int to[mxN][26], sl[mxN], term[mxN], d[mxN][26], de[mxN], id[mxN];
int cur = 0;
 
void add_string(const string &s, int i){
	int u = 0;
	for(char c: s){
		if(!to[u][c - 'a'])
			to[u][c - 'a'] = ++cur;
		u = to[u][c - 'a'];
	}	
	term[u] = u;
    id[u] = i;
}
 
void push_sl(){
	queue<int> q;
	q.push(0);
	while(q.size()){
		int u = q.front(); q.pop();
		for(int i = 0; i < 26; ++i){
			int v = to[u][i];
			if(v){
				sl[v] = d[sl[u]][i];
				if(!term[v])
					term[v] = term[sl[v]];
				de[v] = de[u] + 1;	
				d[u][i] = v;
				q.push(v);
			}else
				d[u][i] = d[sl[u]][i];	
 
		}
	}	
}

const int inf = 1e9;

class Solution {
public:
    int minimumCost(string t, vector<string>& w, vector<int>& c) {
        int n = w.size();
        map<string, int> mp;
        for(int i = 0; i < n; ++i){
            if(mp.find(w[i]) != mp.end())
                mp[w[i]] = min(mp[w[i]], c[i]);
            else
                mp[w[i]] = c[i];
        }
        int total = 0;
        for(const string& s: w){
            total += s.size();
        }

        cur = 0;
        for(int i = 0; i <= total + 5; ++i){
            sl[i] = term[i] = de[i] = 0; 
            for(int j = 0; j < 26; ++j){
                to[i][j] = d[i][j] = 0;
            }
        }

        for(int i = 0; i < n; ++i){
            if(mp[w[i]] == c[i])
                add_string(w[i], i);
        }
        push_sl();
        vector<int> dp(t.size() + 1, inf);
        dp[0] = 0;
        int u = 0;
        for(int i = 1; i <= t.size(); ++i){
            u = d[u][t[i - 1] - 'a'];
            int v = term[u];
            while(v){
                dp[i] = min(dp[i], c[id[v]] + dp[i - de[v]]);
                v = term[sl[v]];
            }
        }
        return dp.back() == inf ? -1 : dp.back();
    }
};