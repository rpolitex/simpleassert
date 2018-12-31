#include "SimpleAssert.h"
#include <HardwareSerial.h>

int simpleAssertExample(int i) {  
    /* Simple checking of variable */
    ASSERT(i >= -10) return 1;          // simple check with reaction (return from routine)

    ASSERT(-5 <= i && i < 20) return 2;  // check of complex condition with reaction 
    
    ASSERT(i >= 5, "error occurs") return 3;   // check with message
    
    ASSERT(i > 10, "i = %d", i) {      // check with complex message and multi-line reaction
        /*Any complex reaction here*/
        return 4;
    }

    ASSERT(i == 15);                  // check without reaction - executiuon CONTINUED (just assertion message appears as warning)  
    
    SASERT_PRINTF("Ok");
    return 0;
}

void simpleAssertExampleMain()
{
    SASERT_PRINTF("%d", simpleAssertExample(-15));
    SASERT_PRINTF("%d", simpleAssertExample(-6));
    SASERT_PRINTF("%d", simpleAssertExample(4));
    SASERT_PRINTF("%d", simpleAssertExample(10));
    SASERT_PRINTF("%d", simpleAssertExample(11));

    SASERT_PRINTF("%d", simpleAssertExample(15));

}