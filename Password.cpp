#include "Password.h"
#include <string>
#include <algorithm>

using std::string;

Password::Password(){
  pass_history.push_back("ChicoCA-95929");
}

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  if(phrase.length() == 0){
    return 0;
  }

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

  /*
  returns whether the phrase has both at least one upper-case letter and
  at least one lower-case letter
  */
// bool Password::has_mixed_case(string pass){
//   bool upper = false;
//   bool lower = false;
//   for (int i = 0; i < pass.size(); i++){
//     if(pass[i] > 64 && pass[i] < 91){
//       upper = true;
//     } else if (pass[i] > 96 && pass[i] < 123){
//       lower = true;
//     }
//   }
//   return (upper && lower);
// }
bool Password::has_mixed_case(string pass){
  bool lower = false;
  bool upper = false;
  for(int i = 0; i < pass.size(); i++){
    if( pass[i] >= 'A' && pass[i] <= 'Z' ){
      upper = true;
    }
    else if( pass[i] < 'z'){
      lower = true;
    }
  }
  return upper && lower;
}
// bool Password::has_mixed_case(string phrase)
// {
//   bool upper = false;
//   bool lower = false;

//   //for(int i = 0; i < phrase.length()-1; i++)
//   for(char c : phrase)
//   {
//     if(isupper(c))
//     {
//       upper = true;
//     }
//     if(islower(c)){
//       lower = true;
//     }
//   }

//   if(upper && lower){
//     return true;
//   }

//   return false;
// }

  /*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
void Password::set(string newPass){
  if(newPass.length() >= 8 && count_leading_characters(newPass) <= 3 && has_mixed_case(newPass)){
    //if password is not in pass_history vector
    if(std::find(Password::pass_history.begin(), Password::pass_history.end(), newPass) == Password::pass_history.end()){
      Password::pass_history.push_back(newPass);
    }
  }
}

bool Password::authenticate(string pass){
  if(Password::pass_history.size() == 0 || pass != Password::pass_history[pass_history.size()-1])
    return false;
  return true;
}
