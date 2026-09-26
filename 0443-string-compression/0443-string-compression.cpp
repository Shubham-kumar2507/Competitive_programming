class Solution {
public:
    int compress(vector<char>& chars) {
        int n= chars.size();
        int i=0;
        int index=0;
        while(i<n){
            char cur=chars[i];
            int cnt=0;
            while(i<n && chars[i]==cur){
                cnt+=1;
                i++;
            }
            chars[index]=cur;
            index++;
            if(cnt>1){
            string resc= to_string(cnt);
            for(char &c:resc){
                chars[index]=c;
                index++;
            }
            }
        }
        return index;
    }
};