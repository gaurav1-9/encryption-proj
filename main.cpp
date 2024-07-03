#include<iostream>
#include<string>
using namespace std;

class RawString{
private:
    bool isConverted = false;
protected:
    string rawString;
    int stringLength;
public:
    RawString(string rawString){
        this->rawString = rawString;
        this->stringLength = rawString.length();
        toLower();
    }
    void toLower(){
        for(int i=0;i<stringLength;i++){
            if(rawString[i] == ' ') continue;
            else{
                if(rawString[i]>=65 && rawString[i]<=90){
                    rawString[i] = rawString[i]+32;
                    isConverted = true;
                }
            }
        }
        if(isConverted) cout<<endl<<"Input string converted to lower case"<<endl;
    }
};
class CeasarCipher : protected RawString{
public:
    CeasarCipher(string rawString):RawString(rawString){}

    void ceasarCipherAlgo(){
        for(int i=0;i<stringLength;i++){
            if(rawString[i] == ' ') continue;
            else cout<<(int)rawString[i]<<endl;
        }
    }
};

int main(){
    string input;
    getline(cin,input);

    CeasarCipher cc(input);
    cc.ceasarCipherAlgo();
    
    return 0;
}