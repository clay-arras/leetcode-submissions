// https://leetcode.com/problems/sum-of-prefix-scores-of-strings

class Solution {
public:
    const static int MOD1 = 1e9+7;
    const static int P1 = 31;
    const static int MOD2 = 1e9+9;
    const static int P2 = 37;
    // long long compute_hash(string s) {
    //     long long hash = 0;
    //     long long pow = 1;
    //     for (int i=0; i<(int)s.size(); i++) {
    //         hash += ((s[i] - 'a' + 1)*pow) % MOD; 
    //         pow = (pow * P) % MOD;
    //     }
    //     return hash;
    // }
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            // Hash the first element
            size_t hash1 = hash<T1>{}(p.first);
            // Hash the second element
            size_t hash2 = hash<T2>{}(p.second);
            // Combine the two hash values
            return hash1
                ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                    + (hash1 >> 2));
        }
    };


    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<pair<long long, long long>, int, hash_pair> m;
        int N = (int)words.size();
        for (int i=0; i<N; i++) {
            long long hash1 = 0;
            long long pow1 = 1;
            long long hash2 = 0;
            long long pow2 = 1;
            for (int j=0; j<(int)words[i].size(); j++) {
                hash1 += ((words[i][j] - 'a' + 1)*pow1) % MOD1; 
                pow1 = (pow1 * P1) % MOD1;
                hash2 += ((words[i][j] - 'a' + 1)*pow2) % MOD2; 
                pow2 = (pow2 * P2) % MOD1;
                m[{hash1, hash2}]++;
            }
        }
        vector<int> ans;
        for (int i=0; i<N; i++) {
            int sum = 0;
            long long hash1 = 0;
            long long pow1 = 1;
            long long hash2 = 0;
            long long pow2 = 1;
            for (int j=0; j<(int)words[i].size(); j++) {
                hash1 += ((words[i][j] - 'a' + 1)*pow1) % MOD1; 
                pow1 = (pow1 * P1) % MOD1;
                hash2 += ((words[i][j] - 'a' + 1)*pow2) % MOD2; 
                pow2 = (pow2 * P2) % MOD1;
                sum += m[{hash1, hash2}];
            }
            ans.push_back(sum);
        }


        return ans;
    }
};