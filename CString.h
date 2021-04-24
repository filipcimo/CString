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


static void cstringDestructor(struct CString** const str)
{
  if (str != NULL && str[0] != NULL)
  {
    if (str[0]->text != NULL)
    {
      free(str[0]->text);
    }

    free(str[0]);
    str[0] = NULL;
  }
}


static void cstringUninit(struct CString* const str)
{
  if (str != NULL && str->text != NULL)
  {
    free(str->text);

    str->text = NULL;
    str->textSize = 0;
  }
}


static void cstringInit(struct CString* const str)
{
  str->text = NULL;
  str->textSize = 0;
}


static void cstringInitCC(struct CString* const str, const struct CString* const str2)
{
  if (str != NULL && str2 != NULL && str2->text != NULL)
  {
    if (str->text != NULL)
    {
      free(str->text);
    }

    str->textSize = str2->textSize;
    str->text = (char*) malloc(str->textSize);

    strncpy(str->text, str2->text, str->textSize);
  }
}


static void cstringInitStr(struct CString* const str, const char* const str2)
{
  if (str != NULL && str2 != NULL)
  {
    if (str->text != NULL)
    {
      free(str->text);
    }

    str->textSize = strlen(str2);
    str->text = (char*) malloc(str->textSize);

    strncpy(str->text, str2, str->textSize);
  }
}


static void cstringUnit(struct CString* const str, const struct CString* const str2)
{
  if (str != NULL && str2 != NULL && str2->text != NULL)
  {
    char* newText = (char*) malloc(str->textSize + str2->textSize);

    if (str->text != NULL)
    {
      strncpy(newText, str->text, str->textSize);
      free(str->text);
      str->text = NULL;
    }

    strncpy((newText + str->textSize), str2->text, str2->textSize);
    str->text = newText;

    str->textSize = str->textSize + str2->textSize;
  }
}


static char* cstringData(const struct CString* const str)
{
  return str->text;
}


static uint64_t cstringSize(const struct CString* const str)
{
  return str->textSize;
}


static char cstringAt(const struct CString* const str, const uint64_t pos)
{
  if (pos >= str->textSize)
  {
    fprintf(stderr, "Error: Index out of range ");
    fprintf(stderr, "(Index: %li)\n", pos);

    free(str->text);

    exit(EXIT_FAILURE);
  }

  return str->text[pos];
}


static char* cstringAtPtr(const struct CString* const str, const uint64_t pos)
{
  if (pos >= str->textSize)
  {
    fprintf(stderr, "Error: Index out of range ");
    fprintf(stderr, "(Index: %li)\n", pos);

    free(str->text);

    exit(EXIT_FAILURE);
  }

  return (char*) &str->text[pos];
}


static void cstringPrint(const struct CString* const str, const char terminator)
{
  if (str != NULL && str->text != NULL)
  {
    for (uint64_t i = 0; i < str->textSize; i = i + 1)
    {
      printf("%c", str->text[i]);
    }

    printf("%c", terminator);
  }
}



#endif  //CSTRING_H
