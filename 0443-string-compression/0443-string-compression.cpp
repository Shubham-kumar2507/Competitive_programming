// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         char cc='a';
//         int cnt=1;
//         int indx=0;
//        for(int i=0;i<chars.size();i++){
//          if(chars[i]!=cc||i==chars.size()-1){
//             chars[indx]=cc;
//             indx++;
//             if(cnt>9){
//                 int tens = cnt / 10;
//                 int ones = cnt % 10;
//                 chars[indx]=tens+'0';
//                 indx++;
//                 chars[indx]=ones+'0';
//             }else
//                 chars[indx]=cnt + '0';
//             indx++;
//             cc=chars[i];
//             cnt=0;
//          }
//          cnt++;
//        }
//        return indx;
//     }
// };
class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0; 
        int indx = 0; 
        
        while (i < chars.size()) {
            int groupLength = 1;
            while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i]) {
                groupLength++;
            }
            
            chars[indx++] = chars[i];
            if (groupLength > 1) {
                // Convert the number to a string to easily handle multi-digit numbers (like 12 or 2000)
                string countStr = to_string(groupLength);
                for (char c : countStr) {
                    chars[indx++] = c;
                }
            }
            i += groupLength;
        }
        
        return indx;
    }
};