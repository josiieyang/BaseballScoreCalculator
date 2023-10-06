#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

void getScores(string inningInfo, int &awayScore, int &homeScore);

int main(){

    string inningInfo;
    int awayScore;
    int homeScore;  
    
    cout << "Enter the inning information: ";
    cin >> inningInfo;
    getScores(inningInfo, awayScore, homeScore);
    cout << "The end scores is Away: " << awayScore << ", Home: " << homeScore << "." << endl;

    return 0;

}


void getScores(string inningInfo, int &awayScore, int &homeScore) {
    int base1 = 0;
    int base2 = 0;
    int base3 = 0;
    int base4 = 0; 
    int homeRun = 0;
    int length = inningInfo.length();
    bool isAway = true;
        for (int a = 0; a < length; a++){
            if (inningInfo[a] == 's') {
                if (base3 == 1){
                    ++homeRun;
                    base3 = 0;
                } 
                if (base2 == 1) {
                    base3 = 1;
                    base2 = 0;
                }
                if (base1 == 1) {
                    base2 = 1;
                    base1 = 0;
                } 
                base1 = 1;
            } else if (inningInfo[a] == 'd') {
                if (base3 == 1) {
                    ++homeRun;
                    base3 = 0;
                }
                if (base2 == 1) {
                    ++homeRun;
                    base2 = 0;
                }
                if (base1 == 1) {
                    base3 = 1;
                    base1 = 0;
                }
                base2 = 1;
            } else if (inningInfo[a] == 't') {
                if (base3 == 1) {
                    ++homeRun;
                    base3 = 0;
                } 
                if (base2 == 1) {
                    ++homeRun;
                    base2 = 0;
                }
                if (base1 == 1) {
                    ++homeRun;
                    base1 = 0;
                }
                base3 = 1;
            } else if (inningInfo[a] == 'h') {
                if (base3 == 1) {
                    ++homeRun;
                    base3 = 0;
                }
                if (base2 == 1) {
                    ++homeRun;
                    base2 = 0;
                }
                if (base1 == 1) {
                    ++homeRun;
                    base1 = 0;
                }
                ++homeRun;
            } else {
                isAway = !isAway;
                base1 = 0;
                base2 = 0;
                base3 = 0;
            }
                    
            if (isAway){
                awayScore = awayScore + homeRun;                
            } else {
                homeScore = homeScore + homeRun;
            }  
            homeRun = 0;
        }
}

    