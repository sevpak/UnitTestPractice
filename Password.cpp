#include "Password.h"
#include <string>
#include <cctype>
#include <vector>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 0;
  if (phrase.length() == 0) {
    return repetition;
  } else {
    repetition++;
  }
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string str)
{
  bool found = false;
  for(char c : str){
    if( !found && c >= 'A' && c <= 'Z' ){
      found = true;
    }
    else if( found && c >= 'a' && c <= 'z'){
      return true;
    }
  }
  return false;
}

unsigned int Password::unique_characters(string str)
{
  unsigned int uniq_chars = 0;
  std::vector<char> letters;
  for (int i = 0; i < str.length(); i++) {
    if (isalpha(str[i])) {
      bool already_counted = false;
      for (int j = 0; j < letters.size(); j++) {
        if (letters[j] == str[i]) {
          already_counted = true;
        }
      }
      if (already_counted == false) {
        uniq_chars++;
        letters.push_back(str[i]);
      }
    }
  }
  return uniq_chars;
}