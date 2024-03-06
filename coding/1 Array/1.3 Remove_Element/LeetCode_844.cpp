// 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
// 注意：如果对空文本输入退格字符，文本继续为空。           退格字符#：backspace删除键

#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    int dealString(string& s){
        int slowIndex=0;
        int size_s =s.size();

        for(int fastIndex=0;fastIndex<size_s;fastIndex++){
            if(s[fastIndex]!='#'){
                s[slowIndex]=s[fastIndex];
                slowIndex++;
            }
            else{
                slowIndex=slowIndex>0?slowIndex-1:0;
            }
        }
        return slowIndex;
    }
    bool backspaceCompare(string s,string t)
    {
        int len_s=dealString(s);
        int len_t=dealString(t);
        if(len_s!=len_t)    return false;
        for(int i=0;i<len_s;i++)
        {
            if(s[i]!=t[i]) return false;
        }
    return true;
    }
};

int main(){
    string s("#c");
    string t("#nn");
    Solution solution;
    if(solution.backspaceCompare(s,t)){
        cout<<"s"<<"="<<"t";
    }
    else{
        cout<<"s"<<"!="<<"t";
    }
    return 0;
}