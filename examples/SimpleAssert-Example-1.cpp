#include "SimpleAssert.h"
#include <HardwareSerial.h>

static int simpleAssertExample(int i) {  
    /* Simple checking of variable */
    ASSERT(i >= -10) return 1;                  // simple check with message and return

    ASSERT(-5 <= i && i <= 20) return 2;         // check of complex condition with return 
    
    ASSERT(i >= 5, "error occurs") return 3;    // check with custom message
    
    ASSERT(i > 10, "i = %d", i) {               // check with complex message and multi-line reaction
        /*Any complex reaction here*/
        SASERT_PRINTF("Complex reaction\n");
        return 4;
    }

    ASSERT(i > 15, "") { // suppress assert default message  
        SASERT_PRINTF("Default assert message has been suppressed\n");
        return 5;      
    }
    
    ASSERT(i == 20);                  // check without reaction - executiuon CONTINUED (just assertion message appears as warning)  
    
    SASERT_DEBUG("Ok");
    return 0;
}

void simpleAssertExampleMain1()
{
    SASERT_PRINTF("=== simpleAssertExampleMain1 ===\n\n");
    
    SASERT_PRINTF("%d\n", simpleAssertExample(-15));    // 1. Failed
    SASERT_PRINTF("%d\n", simpleAssertExample(-6));     // 2. Failed 
    SASERT_PRINTF("%d\n", simpleAssertExample(4));      // 3. Failed
    SASERT_PRINTF("%d\n", simpleAssertExample(10));     // 4. Failed
    SASERT_PRINTF("%d\n", simpleAssertExample(11));     // 5. Failed, without assert message
    SASERT_PRINTF("%d\n", simpleAssertExample(16));     // 6. Just Warning - executed to Ok

    SASERT_PRINTF("%d\n", simpleAssertExample(20));     // Ok
    
    SASERT_PRINTF("Ok example 1\n\n");
}