#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RawString{
protected:
    string rawString,noSpaceStr;
    int stringLength;

public:
    RawString(string rawString)
    {
        this->rawString = rawString;
        this->stringLength = rawString.length();
    }
    void spaceRemover(){
        for(char c:rawString){
            if(c!=' ') noSpaceStr+=c;
        }
    }
};

class CeasarCipher : protected RawString{
public:
    CeasarCipher(string rawString) : RawString(rawString) {
        cout << "\nCEASAR CIPHER ENCRYPTION VALUE" << endl;
        ceasarCipherAlgo();
        cout<<endl;
    }

    void ceasarCipherAlgo()
    {
        for (int i = 0; i < stringLength; i++)
        {
            if (rawString[i] == ' ')
                cout << " ";

            //Lower case
            else if (rawString[i] >= 97 && rawString[i] <= 122)
                cout << (char)((((int)rawString[i] - 97 + 3) % 26) + 97);

            //Upper case
            else if (rawString[i] >= 65 && rawString[i] <= 90)
                cout << (char)((((int)rawString[i] - 65 + 3) % 26) + 65);
            else cout<<"_";
        }
    }
    ~CeasarCipher(){}
};

class RailFence : protected RawString{
private:
    int depth = 3,col,count=0;
    vector<vector<char>> railfenceMatrix;
public:

    RailFence(string rawString) : RawString(rawString) {
        cout << "\nRAILFENCE CIPHER ENCRYPTION VALUE" << endl;
        spaceRemover();
        setColValue();
        railfenceMatrix.resize(depth,vector<char>(col,'\0'));
        setMatrix();
        railfenceEncryptionValue();
    }

    
    void setColValue(){
        col = noSpaceStr.length();
    }
    void setMatrix(){
        int a=0;
        bool inc = true;
        for(int i=0;i<col;i++){
            for(int j=0;j<depth;j++){
                if(noSpaceStr.length()>count && a==j){
                    railfenceMatrix[j][i] = noSpaceStr[count];
                    count++;
                }
            }
            if(inc){
                if(a==2){ 
                    inc = false;
                    a--;
                }
                else a++;
            }
            else{
                if(a==0){
                    inc = true;
                    a++;
                }
                else a--;
            }
        }
    }
    void railfenceEncryptionValue(){
        for(int i=0;i<depth;i++){
            for(int j=0;j<col;j++){
                cout<<railfenceMatrix[i][j];
            }
        }
    }
    ~RailFence(){}
};

class PlayFair : protected RawString{
private:
    char keyMatrix[5][5];
    string keyString = "monarchy",remainingKeyString = "bdefgiklpqstuvwxz",playfairStr;
    int subStrings;

public:
    PlayFair(string rawString):RawString(rawString){
        spaceRemover();
        generateKey();
        subStringCalculations();
        playfairEncryption();
    }
    void subStringCalculations(){
        int count, changed = 0;
        playfairStr = noSpaceStr;
        for(int i=1;i<noSpaceStr.length();i++){
            count =i;
            if(noSpaceStr[i]==noSpaceStr[i-1]) {
                if(changed) count=count+changed;
                changed ++;
                playfairStr.insert(count,"x");
            }
        }
        if(playfairStr.length()%2!=0) playfairStr.push_back('x');
        subStrings = playfairStr.length()/2;
        cout<<playfairStr<<endl<<subStrings<<'\t'<<playfairStr.length()<<endl;
    }

    void generateKey(){
        int count =0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(count<keyString.length()){
                    keyMatrix[i][j] = keyString[count];
                }
                else {
                    keyMatrix[i][j] = remainingKeyString[count-keyString.length()];
                }
                count++;
            }
        }
    }
    void playfairEncryption(){
        char fChar,sChar;
        int fCharIdx[2],sCharIdx[2];
        string playfairCipherText;
        for(int i=1;i<=subStrings;i++){
            fChar = playfairStr[(2*i)-2];
            sChar = playfairStr[(2*i)-1];

            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(keyMatrix[i][j]==fChar) {
                        fCharIdx[0] = i;
                        fCharIdx[1] = j;
                    }
                    if(keyMatrix[i][j]==sChar) {
                        sCharIdx[0] = i;
                        sCharIdx[1] = j;
                    }
                }
            }
            cout<<fChar<<"("<<fCharIdx[0]<<fCharIdx[1]<<"), "<<sChar<<"("<<sCharIdx[0]<<sCharIdx[1]<<")\t";
            if(fCharIdx[1]==sCharIdx[1]){
                fCharIdx[0] = (fCharIdx[0]+1)%5;
                sCharIdx[0] = (sCharIdx[0]+1)%5;
            }
            else if(fCharIdx[0]==sCharIdx[0]){
                fCharIdx[1] = (fCharIdx[1]+1)%5;
                sCharIdx[1] = (sCharIdx[1]+1)%5;
            }
            

            fChar = keyMatrix[fCharIdx[0]][fCharIdx[1]];
            sChar = keyMatrix[sCharIdx[0]][sCharIdx[1]];
            playfairCipherText.push_back(fChar);
            playfairCipherText.push_back(sChar);

            cout<<fChar<<"("<<fCharIdx[0]<<fCharIdx[1]<<"), "<<sChar<<"("<<sCharIdx[0]<<sCharIdx[1]<<")"<<endl;
        }
        cout<<endl<<playfairCipherText;
    }
};

int main(){
    string input;
    getline(cin, input);

    cout << endl
         << "INPUT STRING: " << input << endl;

    // CeasarCipher cc(input);
    // RailFence rf(input);
    PlayFair pf(input);

    return 0;
}