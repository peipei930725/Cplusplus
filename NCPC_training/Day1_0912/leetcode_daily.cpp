class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words[i].size();++j){
                for(int k=0;k<allowed.size();++k){
                    if(allowed[k]==words[i][j]){
                        count++;
                        break;
                    }
                    ++i;
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        
        // 確保 allowed 和 words 被正確初始化
        if (allowed.empty() || words.empty()) return count;
        
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());  // 使用集合來加速查找
        
        for (int i = 0; i < words.size(); ++i) {
            bool consistent = true;
            for (int j = 0; j < words[i].size(); ++j) {
                if (allowedSet.find(words[i][j]) == allowedSet.end()) {  // 如果有字元不在 allowed 中
                    consistent = false;
                    break;
                }
            }
            if (consistent) {
                ++count;
            }
        }
        return count;
    }
};
