#include<iostream>
#include<string>
using namespace std;

class RawString{
private:
    string rawString;
    int stringLength;
public:
    RawString(string rawString){
        this->rawString = rawString;
        this->stringLength = rawString.length();
    }
    void getInfo(){
        cout<<stringLength;
    }
};

int main(){
    string input;
    getline(cin,input);

    RawString rs(input);
    rs.getInfo();
    
    return 0;
}