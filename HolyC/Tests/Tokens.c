#include <Core-Backend/SDK.h>

U8 TokenTest(void *data)
{
    HC_Token t;
    HC_Lexer l = *(HC_Lexer *)data;

    U8 result = HC_LexerParse(&l);
    if (!result)
        return HC_False;
    else
    {
        I64 i;
        for (i = 0; i < l.CurrentFile->TokenCount; i++)
            printf("[%2lu][%s]\n", i, l.CurrentFile->Tokens[i].Source);
    }
    
    return HC_True;
}

U32 main()
{
    HC_Lexer l;
    HC_LexerCreateInfo lc;
    memset(&lc, 0, sizeof(HC_LexerCreateInfo));
    HC_LexerCreate(&l, &lc);
    HC_LexerLoadStream(&l, &(HC_LexerLoadStreamInfo){.Input = "Tests/NoWhitespace.HC" });

    HC_TestCreateInfo tests[] =
    {
        {.Assertion = HC_False, .Callback = TokenTest, .ExpectedResult = HC_True, .TestName = "Tokenization Test (Tests/NoWhitespace.HC)", .FailMessage = "Tokenization has failed", .ProgramData = &l },
    };


    HC_TestRuntineInfo runtime;
    U8 result = HC_TestRunTest(tests, sizeof(tests) / sizeof(HC_TestCreateInfo), &runtime);


    HC_LexerDestroy(&l);
    return result;
}
