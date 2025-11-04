#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    vector<int> bitMap(1000,0);
    vector<int> bindosuMap(100,0);
    
    for(auto& i : array){
        bitMap[i] += 1;
    }
    
    int maxBindosu = 0;
    for(int i = 0 ; i< 1000 ; ++i){
        if(bitMap[i] == 0) continue;
        if(maxBindosu == bitMap[i]){
            answer = -1;
        }
        else if(maxBindosu < bitMap[i]){
            maxBindosu = bitMap[i];
            answer = i;
        }
    }
    return answer;
}