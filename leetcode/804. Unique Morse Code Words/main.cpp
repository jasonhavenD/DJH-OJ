#include <bits/stdc++.h>

using namespace std;

string values[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> rst;
        vector<string>::iterator iter=words.begin();
        while(iter!=words.end()){
            string word=*iter++;
            string temp;
            for(int i=0;i<word.size();i++){
                //cout<<values[word[i]-'a'];
                temp+=values[word[i]-'a'];
            }
            rst.insert(temp);
            //cout<<endl;
        }
        return rst.size();
    }
};

int main()
{
    Solution s;
    vector<string> vs;
    //vs.push_back("abc");
    vs.push_back("gin");
    vs.push_back("zen");
    vs.push_back("gig");
    vs.push_back("msg");
    cout<<s.uniqueMorseRepresentations(vs);
    return 0;
}
