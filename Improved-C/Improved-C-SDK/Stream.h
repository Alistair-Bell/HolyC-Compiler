#ifndef STREAM_H
#define STREAM_H

#include "Common.h"

typedef struct
{
    U8              Reallocatable;
    U64             *StreamSize;
    U8              *Data;
    const I8        *Path;
} IC_Stream;

extern void IC_StreamCreate(IC_Stream *stream);


#endif