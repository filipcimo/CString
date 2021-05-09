#ifndef CSTRING_H
#define CSTRING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


struct CString
{
  char* text;
  uint64_t textSize;
};



void cstringDestructor(struct CString** const str);

void cstringUninit(struct CString* const str);

void cstringInit(struct CString* const str);

void cstringInitCC(struct CString* const str, const struct CString* const str2);

void cstringInitStr(struct CString* const str, const char* const str2);

void cstringUnit(struct CString* const str, const struct CString* const str2);

char* cstringData(const struct CString* const str);

uint64_t cstringSize(const struct CString* const str);

char cstringAt(const struct CString* const str, const uint64_t pos);

char* cstringAtPtr(const struct CString* const str, const uint64_t pos);

void cstringPrint(const struct CString* const str, const char terminator);



#endif  //CSTRING_H
