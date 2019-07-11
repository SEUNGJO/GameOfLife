

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
/************************************************************
Cipher
_________________________________________________________
This program is meant to create a cipher for a given or
custom translation map and word. Some input validations
were added in to make sure the program works correctly.
_________________________________________________________
INPUT:
method: decides whether we will be encypting or decrypting
translationMap: uses a default map or a custom map to
create a cipher
word: inputs a single word to encrypt or decrypt
OUTPUT:
cout: the program will output the equation used to evaluate
      with the inputs used displayed as well. Then the result
      will display.
 ***********************************************************/
int getPosition(char ch);

int main()
{
   string alphabet12 = "abcdefghijklmnopqrstuvwxyz";
   string defaultMap = "zyxwvutsrqponmlkjihgfedcba";
   string method;
   string translationMap;
   string word;



   // Acquire the method to perform (encryption or decryption).
   cout << "What is the method (encryption or decryption)? " << "\n";
   cin >> method;

   if(method != "encryption" && method != "decryption")
   {
       cout << "Error: Invalid method choice." << endl;

       return 0;
   }


   // Acquire the translation map
   cout << "What is the translation map (type 'default' to use default): " << "\n";
   cin >> translationMap;

   if(translationMap == "default")
       translationMap = defaultMap;

   if(translationMap.size() != 26)
   {
       cout << "Error: invalid translation map size." << endl;

       return 0;
   }


   // Acquire the word to encrypt or decrypt, validate depending on method
   cout << "What is the single word to translate: " << "\n";
   cin >> word;

   for(int i = 0; i < word.size(); i++)
   {
       if(getPosition(word.at(i)) == -1)
       {
           if(method == "encryption")
               cout << "Error: encryption cannot be performed." << endl;
           else // if(method == "decryption")
               cout << "Error: decryption cannot be performed." << endl;


           return 0;
       }
   }


   // Perform encryption or decryption
   if(method == "encryption")
   {
       for(int i = 0; i < word.size(); i++)
       {
           int pos = getPosition(word.at(i));

           word[i] = translationMap[pos];
       }

       cout << "Encrypted word: " << word << endl;
   }
   else
   {
       for(int i = 0; i < word.size(); i++)
       {
           int pos = translationMap.find(word.at(i));

           word[i] = (char)(97 + pos);
       }

       cout << "Decrypted word: " << word << endl;
   }

   return 0;
}


int getPosition(char ch)
{
   if(ch >= 'a' && ch <= 'z')
       return (ch - 'a');
   else
       return -1;
}
