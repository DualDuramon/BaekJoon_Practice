#include <string>
#include <vector>

using namespace std;

void itoa(string& str, int n){
    while(n > 0){
        str.push_back((char)('0' + n%10));
        n = n/10;
    }
}


vector<int> solution(int l, int r) {
    vector<int> answer;
    bool conTrigger = false;
    
    for(int i = l ; i <=r ; ++i)
    {
        string str = "";
        itoa(str, i);
        conTrigger = false;
        
        for(auto& ch : str){
            if(ch != '0' && ch != '5'){
                conTrigger = true;
                break;
            }
        }
        
        if(!conTrigger){
            answer.emplace_back(i);
        }
    }
    
    if(answer.size() == 0){
        answer.emplace_back(-1);
    }
    
    return answer;
}