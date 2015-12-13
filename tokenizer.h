#ifndef _H_TOKENIZE
#define _H_TOKENIZE

#include <string>
#include <cstring>
#include <iostream>
#include <cctype>

using namespace std;

#define CHARSTRING 1	// used to tokenize C style character strings
#define STRINGOBJ 2		// used to tokenize C++ string objects.

namespace charstring {
	size_t i;
	int (*delimiter_check) (char);		// function to identify delimiters
}

namespace stringobj {
	size_t i;
	int (*delimiter_check) (char);		// function to identify delimiters
}

// this function should be called before you start calling next_token to initialize the strings
void settok(unsigned short type, int (*del_chk)(char)) {
	switch(type) {
		case CHARSTRING:	charstring::i = 0;
							charstring::delimiter_check = del_chk;
							break;
		case STRINGOBJ:		stringobj::i = 0;
							stringobj::delimiter_check = del_chk;
							break;
	}
}

// repeatedly call next_token function to get further tokens
// tokens consist of non space characters

// call when you have to extract tokens from C style strings
int next_token(const char * str, size_t l, char * buf) {
	size_t j = 0;
	using charstring::i;
	using charstring::delimiter_check;
	if(i == l) {
		buf[0] = '\0';
		return 0;
	}
	while(delimiter_check(str[i]) && (i < l))
		i++;
	while(!delimiter_check(str[i]) && (i < l))
		buf[j++] = str[i++];
	buf[j] = '\0';
	return j;
}

// call when you have to extract tokens from string objects
int next_token(const string & str, size_t l, string & buf) {
	using stringobj::i;
	using stringobj::delimiter_check;
	buf = string("");
	if(i == l) {
		return 0;
	}
	while(delimiter_check(str[i]) && (i < l))
		i++;
	while(!delimiter_check(str[i]) && (i < l))
		buf += str[i++];
	return buf.size();
}

#endif
