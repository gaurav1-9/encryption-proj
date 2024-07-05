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

class PlaiFair : protected RawString{
private:
    char keyMatrix[5][5];

public:
    void generateKey(){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){}
        }
    }
};

int main(){
    string input;
    getline(cin, input);

    cout << endl
         << "INPUT STRING: " << input << endl;

    CeasarCipher cc(input);
    RailFence rf(input);

    return 0;
}