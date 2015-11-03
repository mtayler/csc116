#ifndef DECRYPTION_HEADER_INCLUDED
#define DECRYPTION_HEADER_INCLUDED

#include <string>

using namespace std;


/*
Function: reverse

Purpose:
  To reverse the order of characters in a given string.
 
Parameters:
 - 'in': String to reverse.
 
Return value:
 - A string containing the reverse of the input string.

Preconditions:
 - String 'in' has been initialized.

Postconditions:
 - The returned string contains the values of string 'in'
  in reverse order.

Example:
  out = reverse("abcde", in, 5);
  // The string 'out' should be equivalent to "edcba".
*/
string reverse(string in);

/*
Function: swap_halves

Purpose:
  Copy the first half of the input string
  into the second half of the string to be returned, 
  and the second half of the input string into the 
  first half of the string to be returned. In other words,
  swap the two halves of the input string and return the 
  resulting string.

Parameters:
 - 'in': String whose halves to swap.
 
Return value:
 - A string containing swapped halves of the input string.
 
Preconditions:
 - String 'in' has been initialized.

Postconditions:
 - The first half of the returned string has the same values
   as the second half of string 'in'.
 - The second half of the returned string has the same values
   as the first half of string 'in'.

Example:
  out = swap_halves("123456789");
  // The string 'out' should be equivalent to "567891234".
*/
string swap_halves(string in);

/*
Function: reverse_five_by_five

Purpose:
  Copy five elements at a time from the input string into
  the string to be returned in reverse order.

  If the size of the input string is not a multiple of five,
  reverse groups of five elements until possible,
  then reverse the remaining elements, whatever their number is.

  Use the function 'reverse' to copy and reverse
  each group of five (or fewer) elements.

Parameters:
 - 'in': String to process.
 
Return value:
 - An string containing the input string reversed in elements 
   of five.
 
Preconditions:
 - String 'in' has been initialized.

Postconditions:
 - Each consecutive group of five elements (or fewer) of the 
   returned string equals a group of five elements of string 
   'in' at the same position, but in reverse order.

Example:
  out = reverse_five_by_five("_1234_1234_12");
  // The string 'out' should be equivalent to "4321_4321_21_".
*/
string reverse_five_by_five(string in);

/*
Function: warp

Purpose:
  Transform each character of the input string and return 
  a string with the transformed characters (in the same order).
  Each character of the input string should be transformed
  using the following rules:
   - if the input char is less than 79,
    then the output char is equal to input char - 32 + 79.
   - it the input char is greater than or equal to 79,
    then the output char is equal to input char - 79 + 32.

	*HINT* To make your job easier, create a separate, helper 
	function, which will transform one character (passed to it
	as a parameter) according to the two rules above and return
	the transformed character. Then use the new function here, 
	inside of a loop, as you iterate over the characters in the 
	string 'in'.

Parameters:
 - 'in': String to reverse.
 
Return value:
 - A string containing the warped string.
 
Preconditions:
 - String 'in' has been initialized.

Postconditions:
 - Returned string contains the values computed from
  value of string 'in' using the rules specified above.

Example:
  out = warp("r@>AFE6CO$4:6?46");
  // The string 'out' should be equivalent to "Computer Science".
*/
string warp(string in);

/*
Function: decrypt

Purpose:
  Apply a series of string manipulations to 
  decrypt an encrypted message.

  The functions above should be applied to the
  string 'in' in the following order, each time
  passing the string returned from one function as
  the input string of the next function:
   1. swap_halves;
   2. reverse_five_by_five;
   3. warp;

Parameters:
 - 'in': String containing an encrypted message.

Return value:
 - An string containing the decrypted message.

Preconditions:
 - 'in' is a valid string.

Postconditions:
 - Returned value is a string and it contains
   the decrypted form of the message 'in'.

Example:
  out = decrypt("63O656G6:sO\\O]5=2?@:GCtOF?zO?9E=2O?pE:C@8F>O>963OED?66DO3O@EO=");
  // The string 'out' should be equivalent to "An algorithm must be seen to be
  // believed. - Donald Ervin Knuth".
*/
string decrypt(string msg);


#endif // DECRYPTION_HEADER_INCLUDED
