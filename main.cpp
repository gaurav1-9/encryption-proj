#include <iostream>
#include <string>
using namespace std;

class RawString{
protected:
    string rawString;
    int stringLength;

public:
    RawString(string rawString)
    {
        this->rawString = rawString;
        this->stringLength = rawString.length();
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
};

class RailFence : protected RawString{
private:
    string noSpaceStr;
    int depth = 3,col;
public:
    RailFence(string rawString) : RawString(rawString) {
        cout << "\nRAILFENCE CIPHER ENCRYPTION VALUE" << endl;
        spaceRemover();
    }

    void spaceRemover(){
        for(int i=0;i<rawString.length();i++){
            if(rawString[i]!=' ')
            noSpaceStr+=rawString[i];
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