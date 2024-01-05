#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	int sum = 0;
        for (int i = 0; i <= s.length() - 1; i++){
        	switch (s[i]){
        	case 'M': 	sum += 1000; break;
        	case 'D':	sum += 500; break;
        	case 'C': {
						sum += 100;
						if ((i + 1 < s.length()) && ((s[i + 1] == 'M') || (s[i + 1] == 'D'))) {
							sum += 300;
							if (s[i + 1] == 'M') sum += 500;
							i++;
							continue;
        					} 
        				break;
        				}
        	case 'L':	sum += 50; break;
        	case 'X':	{
						sum += 10;
						if ((i + 1 < s.length()) && ((s[i + 1] == 'C') || (s[i + 1] == 'L'))) {
							sum += 30;
							if (s[i + 1] == 'C') sum += 50;
							i++;
							continue;
        					} 
        				break;
        				}
        	case 'V':	sum += 5; break;
        	case 'I': 	{
						sum += 1;
						if ((i + 1 < s.length()) && ((s[i + 1] == 'X') || (s[i + 1] == 'V'))) {
							sum += 3;
							if (s[i + 1] == 'X') sum += 5;
							i++;
							continue;
        					} 
        				break;
        				}
        	}
        }
    	return (sum);
    }
    

};

int main () {
	Solution* sol = new Solution();
	cout << "III = " << sol->romanToInt("III") << endl;
	cout << "LVIII = " << sol->romanToInt("LVIII") << endl;
	cout << "MCMXCIV = " << sol->romanToInt("MCMXCIV") << endl;
	cout << "DCXXI = " << sol->romanToInt("DCXXI") << endl;

	return(0);
    }