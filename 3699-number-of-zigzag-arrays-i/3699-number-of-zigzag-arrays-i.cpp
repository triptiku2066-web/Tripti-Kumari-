class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD=1e9+7;
        int m=r-l+1;
        vector<long long> up(m,1), down(m,1);
        for(int len=2;len<=n;++len){
            vector<long long> next_up(m,0), next_down(m,0);
            long long pref=0;
            for(int x=0;x<m;++x){
                next_up[x]=pref;
                pref=(pref+down[x])% MOD;
            }
            long long suff=0;
            for(int x=m-1;x>=0;--x){
                next_down[x]=suff;
                suff=(suff+up[x])% MOD;
            }
            up=move(next_up);
            down=move(next_down);
        }
        long long ans=0;
        for(int x=0;x<m;++x){
            ans=(ans+up[x]+down[x])% MOD;
        }
        return ans;
    }
};