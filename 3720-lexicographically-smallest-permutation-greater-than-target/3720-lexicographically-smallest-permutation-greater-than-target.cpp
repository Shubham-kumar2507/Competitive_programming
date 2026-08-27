class Solution {
public:
    bool check_smaller(string f, string s){
        if(s == ""){
            return true;
        }
        for(int i=0 ; i<f.size() ; i++){
            if(s[i] < f[i]){
                return false;
            }else if(s[i] > f[i]){
                return true;
            }
        }

        return false;
    }

    void find(string curr, string target, string &ans, bool found, vector<int>&freq, int pos){
        if(found == true){
            for(int i=0 ; i<26 ; i++){
                while(freq[i]){
                    curr += (i + 'a');
                    freq[i]--;
                }
            }

            if(check_smaller(curr, ans)){
                ans = curr;
            }

            return;
        }
        for(int i=0 ; i<26 ; i++){
            if(freq[i]){
                if((i+'a') > target[pos]){
                    curr += (i+'a');
                    freq[i]--;
                    find(curr, target, ans, true, freq, pos+1);
                    curr.pop_back();
                    freq[i]++;
                }else if((i+'a') == target[pos]){
                    curr += (i+'a');
                    freq[i]--;
                    find(curr, target, ans, false, freq, pos+1);
                    curr.pop_back();
                    freq[i]++;
                }
            }
        }
        
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int>freq(26, 0);
        for(int i=0 ; i<s.size() ; i++){
            freq[s[i] - 'a']++;
        }

        string ans = "";


        find("",target, ans, false, freq, 0);

        return ans;
    }
};