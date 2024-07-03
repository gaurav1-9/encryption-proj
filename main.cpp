#include <iostream>
#include <string>
using namespace std;

class RawString{
private:
    bool isConverted = false;

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
    CeasarCipher(string rawString) : RawString(rawString) {}

    void ceasarCipherAlgo()
    {
        cout << "\nCEASAR CIPHER ENCRYPTION VALUE" << endl;
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

int main(){
    string input;
    getline(cin, input);

    cout << endl
         << "INPUT STRING: " << input << endl;

    CeasarCipher cc(input);
    cc.ceasarCipherAlgo();

    return 0;
}