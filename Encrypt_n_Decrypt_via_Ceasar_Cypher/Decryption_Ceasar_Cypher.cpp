#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  cout << "Type password to decrypt:  ";
  string pass;
  getline(cin, pass);

  if(pass == "myPassword925")
  {
  
    fstream file_to_decrypt;
    file_to_decrypt.open("message_to_encrypt.txt", ios::in);

    string decrypted_message = "";

    if(file_to_decrypt.is_open())
    {
      string text;
      int times_looped = 0;
      while(getline(file_to_decrypt, text))
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
        times_looped = times_looped + 1;
        if(times_looped >= 3)
        {
          decrypted_message = decrypted_message + text;
        }
      }
    }
    file_to_decrypt.close();

    file_to_decrypt.open("message_to_encrypt.txt", ios::out);

    if(file_to_decrypt.is_open())
    {

      file_to_decrypt <<  "Decrypted Message:  " << endl << endl << decrypted_message << endl;

    }
    file_to_decrypt.close();
  }
  else
  {

    cout << "Password Denied: please talk to an IT Desk and management at AndrewsIT.org";
    cout << endl << endl << endl;

  }

}
