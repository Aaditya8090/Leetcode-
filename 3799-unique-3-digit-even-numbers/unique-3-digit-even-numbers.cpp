// class Solution {
// public:
//     int totalNumbers(vector<int>& digits) {
//         int n = digits.size();

//         vector<int>fact(11, 0);
//         fact[0] = 1;
//         for(int i=1;i <=10; i++)
//             fact[i] = fact[i-1]*i;
        
//         unordered_map<int, int>mp;
//         int z=0, e=0;
//         for(int dig: digits){
//             mp[dig]++;
//             if(dig==0)
//                 z++;
//             if(dig%2==0)
//                 e++;
//         }

//         int zf=1, tf=1, zzf = mp[0]==0?1:fact[mp[0]-1];
//         for(auto &[a,b]: mp){
//             if(a == 0)
//                 zf = fact[b];
//             if(b > 1)
//                 tf *= fact[b];
//         }

//         if(z==n || e==0)
//             return 0;

//         return (n-1)*(n-2)*e/(zf*tf) - z*(e-z)*(n-2)/(zzf*tf);
//     }
// };

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Count frequencies of each digit in the input array
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;

        // Check every valid 3-digit even number from 100 to 998
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;        // Hundreds digit
            int d2 = (num / 10) % 10;  // Tens digit
            int d3 = num % 10;         // Units digit

            // Track digit counts needed for current number
            vector<int> req(10, 0);
            req[d1]++;
            req[d2]++;
            req[d3]++;

            // Verify if available digit frequencies satisfy requirements
            bool canForm = true;
            for (int i = 0; i < 10; ++i) {
                if (req[i] > freq[i]) {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                count++;
            }
        }

        return count;
    }
};