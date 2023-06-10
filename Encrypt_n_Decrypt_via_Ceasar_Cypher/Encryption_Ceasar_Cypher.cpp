#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

  fstream file_to_encrypt;
  file_to_encrypt.open("message_to_encrypt.txt", ios::in);

  string encrypted_message = "";

  if(file_to_encrypt.is_open())
  {
    string text;
    while(getline(file_to_encrypt, text))
    {
      for(int i = 0; i < (int) text.length(); i++)
      {
        if(text[i] != ' ')
        {
          int val = text[i] - 'a';
          val = (val + 13) % 26;
          text[i] = 'a' + val;
        }
      }
      encrypted_message = encrypted_message + " " + text;
    }
  }
  file_to_encrypt.close();

  file_to_encrypt.open("message_to_encrypt.txt", ios::out);

  if(file_to_encrypt.is_open())
  {

    file_to_encrypt <<  "Encrypted Message:  " << endl << endl << encrypted_message << endl;

  }
  file_to_encrypt.close();

}
