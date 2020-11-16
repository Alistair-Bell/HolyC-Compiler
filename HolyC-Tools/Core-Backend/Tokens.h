#ifndef TOKENS_HEADER
#define TOKENS_HEADER

#include "Common.h"

#define HC_TOKEN_SOURCE_MAX_BUFFER_COUNT 32

#define HC_LEXICAL_TOKENS_SEMI_COLON_STRING_HASH    177632 /* ; */
#define HC_LEXICAL_TOKENS_PLUS_STRING_HASH          177616 /* + */
#define HC_LEXICAL_TOKENS_MINUS_STRING_HASH         177618 /* - */
#define HC_LEXICAL_TOKENS_MULTIPLY_STRING_HASH      177615 /* * */
#define HC_LEXICAL_TOKENS_DIVIDE_STRING_HASH        177620 /* / */
#define HC_LEXICAL_TOKENS_EQUALS_STRING_HASH        177634 /* = */  
#define HC_LEXICAL_TOKENS_LEFT_PARAM_STRING_HASH    177613 /* ( */
#define HC_LEXICAL_TOKENS_RIGHT_PARAM_STRING_HASH   177614 /* ) */
#define HC_LEXICAL_TOKENS_LEFT_CURLY_BRACKET_STRING_HASH        177696  /* { */
#define HC_LEXICAL_TOKENS_RIGHT_CURLY_BRACKET_STRING_HASH       177698  /* } */
#define HC_LEXICAL_TOKENS_SINGLE_QUOTE_STRING_HASH  177612 /* ' */
#define HC_LEXICAL_TOKENS_DOUBLE_QUOTE_STRING_HASH  177607 /* " */

/* Predefined keywords */

#define HC_LEXICAL_TOKENS_FOR_STRING_HASH           193491852 /* for */
#define HC_LEXICAL_TOKENS_WHILE_STRING_HASH         210732529790 /* while */
#define HC_LEXICAL_TOKENS_U0_STRING_HASH            5862762   /* U0 */
#define HC_LEXICAL_TOKENS_I8_STRING_HASH            5862374   /* I8 */
#define HC_LEXICAL_TOKENS_U8_STRING_HASH            5862770   /* U8 */
#define HC_LEXICAL_TOKENS_I16_STRING_HASH           193458165 /* I16 */
#define HC_LEXICAL_TOKENS_U16_STRING_HASH           193471233 /* U16 */
#define HC_LEXICAL_TOKENS_I32_STRING_HASH           193458227 /* I32 */
#define HC_LEXICAL_TOKENS_U32_STRING_HASH           193471295 /* U32 */
#define HC_LEXICAL_TOKENS_I64_STRING_HASH           193458328 /* I64 */
#define HC_LEXICAL_TOKENS_U64_STRING_HASH           193471396 /* U64 */
#define HC_LEXICAL_TOKENS_F32_STRING_HASH           193454960 /* F32 */
#define HC_LEXICAL_TOKENS_F64_STRING_HASH           193455061 /* F64 */

/* Other keywords */
#define HC_LEXICAL_TOKENS_STARTING_COMMENT_STRING_HASH 5861502
#define HC_LEXICAL_TOKENS_ENDING_COMMENT_STRING_HASH   5861342

typedef struct HC_Lexer HC_Lexer;

typedef enum HC_LexicalTokens
{
    HC_LEXICAL_TOKENS_SEMI_COLON,

    /*
        Operators
    */  
    HC_LEXICAL_TOKENS_PLUS,
    HC_LEXICAL_TOKENS_MINUS,
    HC_LEXICAL_TOKENS_MULTIPLY,
    HC_LEXICAL_TOKENS_DIVIDE,
    HC_LEXICAL_TOKENS_EQUALS,  

    HC_LEXICAL_TOKENS_LEFT_PARAM,
    HC_LEXICAL_TOKENS_RIGHT_PARAM,

    HC_LEXICAL_TOKENS_LEFT_CURLY_BRACKET,
    HC_LEXICAL_TOKENS_RIGHT_CURLY_BRACKET,

    HC_LEXICAL_TOKENS_STARTING_COMMENT,
    HC_LEXICAL_TOKENS_ENDING_COMMENT,
    
    HC_LEXICAL_TOKENS_SINGLE_QUOTE,
    HC_LEXICAL_TOKENS_DOUBLE_QUOTE,

    HC_LEXICAL_TOKENS_VALUE,

    HC_LEXICAL_TOKENS_NEW_SYMBOL,

    /*
        Keywords
    */
    HC_LEXICAL_TOKENS_FOR,
    HC_LEXICAL_TOKENS_WHILE,

    /* 
        Predefined types
    */
    HC_LEXICAL_TOKENS_I8,
    HC_LEXICAL_TOKENS_U0,
    HC_LEXICAL_TOKENS_U8,
    HC_LEXICAL_TOKENS_I16,
    HC_LEXICAL_TOKENS_U16,
    HC_LEXICAL_TOKENS_I32,
    HC_LEXICAL_TOKENS_U32,
    HC_LEXICAL_TOKENS_I64,
    HC_LEXICAL_TOKENS_U64,
    HC_LEXICAL_TOKENS_F32,
    HC_LEXICAL_TOKENS_F64,
} HC_LexicalTokens;

typedef struct HC_Token
{
    U64                 Hash;
    U32                 Line;
    U32                 LineOffset;
    I8                  Source[HC_TOKEN_SOURCE_MAX_BUFFER_COUNT];
    HC_LexicalTokens    Token;
} HC_Token;
typedef struct HC_TokenHandleInfo
{
    HC_Lexer            *Lexer;
    HC_Token            *PreviousToken;
    U64                 SourceLength;
    U32                 Line;
    U32                 LineOffset;
    I8                  Source[HC_TOKEN_SOURCE_MAX_BUFFER_COUNT];
} HC_TokenHandleInfo;

extern U64 HC_TokenHashString(const I8 *source);
extern U64 HC_TokenHashChar(const I8 character);
extern U8 HC_TokenCreate(HC_Token *token, HC_TokenHandleInfo *info);

#endif