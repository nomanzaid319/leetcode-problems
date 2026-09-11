#include<iostream>
#include<vector>
using namespace std;

int totalNumbers(vector<int>& digits) {
    vector<int> freq(10, 0);
    for (int d : digits) freq[d]++;

    int count = 0;

    for (int units = 0; units <= 8; units += 2) {
        if (freq[units] == 0) continue;

        freq[units]--;                       
        for (int hundreds = 1; hundreds <= 9; hundreds++) {
            if (freq[hundreds] == 0) continue;

            freq[hundreds]--;                

            for (int tens = 0; tens <= 9; tens++) {
                if (freq[tens] > 0) {
                    count++;                 
                }
            }

            freq[hundreds]++;                
        }

        freq[units]++;                       
    }

    return count;
}

int main(){
    vector<int> digits = {1, 2, 3};
    cout << totalNumbers(digits) << endl;
    return 0;
}