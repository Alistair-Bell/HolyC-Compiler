#include "Tokens.h"
#include "Lexer.h"

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

#define HC_LEXICAL_TOKENS_MAX_STRING_HASH           0xFFFFFFFFFFFFFFFF;



static inline U64 HC_TokenDetermineSpecialChar(HC_Token *token, HC_Token *previousToken)
{
    if (strlen(token->Source) != 1)
        return HC_False;

    switch (token->Hash)
    {
        case HC_LEXICAL_TOKENS_SEMI_COLON_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_SEMI_COLON;
            return HC_True;
        case HC_LEXICAL_TOKENS_PLUS_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_PLUS;
            return HC_True;
        case HC_LEXICAL_TOKENS_MINUS_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_MINUS;
            return HC_True;
        case HC_LEXICAL_TOKENS_MULTIPLY_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_MULTIPLY;
            return HC_True;
        case HC_LEXICAL_TOKENS_DIVIDE_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_DIVIDE;
            return HC_True;
        case HC_LEXICAL_TOKENS_EQUALS_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_DIVIDE;
            return HC_True;
        case HC_LEXICAL_TOKENS_LEFT_PARAM_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_LEFT_PARAM;
            return HC_True;
        case HC_LEXICAL_TOKENS_RIGHT_PARAM_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_RIGHT_PARAM;
            return HC_True;
        case HC_LEXICAL_TOKENS_LEFT_CURLY_BRACKET_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_LEFT_CURLY_BRACKET;
            return HC_True;
        case HC_LEXICAL_TOKENS_RIGHT_CURLY_BRACKET_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_RIGHT_CURLY_BRACKET;
            return HC_True;
        case HC_LEXICAL_TOKENS_SINGLE_QUOTE_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_SINGLE_QUOTE;
            return HC_True;
        case HC_LEXICAL_TOKENS_DOUBLE_QUOTE_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_DOUBLE_QUOTE;
            return HC_True;
    }
    return HC_False;
}
static inline U8 HC_TokenDetermineType(HC_Token *token, HC_Token *previousToken)
{
    switch (token->Hash)
    {
        case HC_LEXICAL_TOKENS_STARTING_COMMENT_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_STARTING_COMMENT;
            return HC_True;
        case HC_LEXICAL_TOKENS_ENDING_COMMENT_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_ENDING_COMMENT;
            return HC_True;
        case HC_LEXICAL_TOKENS_FOR_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_FOR;
            return HC_True;
        case HC_LEXICAL_TOKENS_WHILE_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_WHILE;
            return HC_True;
        case HC_LEXICAL_TOKENS_U0_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_U0;
            return HC_True;
        case HC_LEXICAL_TOKENS_I8_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_I8;
            return HC_True;
        case HC_LEXICAL_TOKENS_U8_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_U8;
            return HC_True;
        case HC_LEXICAL_TOKENS_I16_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_I16;
            return HC_True;
        case HC_LEXICAL_TOKENS_U16_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_U16;
            return HC_True;
        case HC_LEXICAL_TOKENS_I32_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_I32;
            return HC_True;
        case HC_LEXICAL_TOKENS_U32_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_U32;
            return HC_True;
        case HC_LEXICAL_TOKENS_I64_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_I64;
            return HC_True;
        case HC_LEXICAL_TOKENS_U64_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_U64;
            return HC_True;
        case HC_LEXICAL_TOKENS_F32_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_F32;
            return HC_True;
        case HC_LEXICAL_TOKENS_F64_STRING_HASH:
            token->Token = HC_LEXICAL_TOKENS_F64;
            return HC_True;
        default:

            if (previousToken != NULL && (previousToken->Token == HC_LEXICAL_TOKENS_SINGLE_QUOTE || previousToken->Token == HC_LEXICAL_TOKENS_DOUBLE_QUOTE))
                token->Token = HC_LEXICAL_TOKENS_VALUE; /* string value */
            else
                token->Token = HC_LEXICAL_TOKENS_NEW_SYMBOL;
            return HC_True;
    }
    return HC_True;
}

/* Needs collision testing */
U64 HC_TokenHashString(const I8 *source)
{
    U64 hash = 5381;
    I32 c;
    while ((c = *source++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}
U64 HC_TokenHashChar(const I8 character)
{
    U64 hash = 5381;
    return ((hash << 5) + hash) + (I8)character;
}
U8 HC_TokenCreate(HC_Token *token, HC_TokenHandleInfo *info)
{
    assert(token != NULL);
    assert(info != NULL);
    memset(token, 0, sizeof(HC_Token));

    HC_LexerStripToken(info->Source);
    strcpy(token->Source, info->Source);

    token->Hash = HC_TokenHashString(token->Source);
    
    if (info->SourceLength <= 1)
        HC_TokenDetermineSpecialChar(token, info->PreviousToken);
    else
        HC_TokenDetermineType(token, info->PreviousToken);        
    return HC_True;
}