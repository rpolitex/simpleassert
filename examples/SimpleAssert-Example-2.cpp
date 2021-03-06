#include "SimpleAssert.h"
#include <HardwareSerial.h>

static int externalConditionOk() {
    static int condition = -2;
    condition++;
    return condition;
}

static int simpleAssertExample() {  
    /* Check return code from function*/
    int externalCond = externalConditionOk();
    ASSERT(externalCond > 0, "cond = %d", externalCond) return -1;
    
    SASERT_DEBUG("Ok");
    return 0;
}

void simpleAssertExampleMain2()
{
    SASERT_PRINTF("=== simpleAssertExampleMain2 ===\n\n");

    SASERT_PRINTF("%d\n", simpleAssertExample());   //assertion failed
    SASERT_PRINTF("%d\n", simpleAssertExample()); 	//assertion failed
    SASERT_PRINTF("%d\n", simpleAssertExample());	//assertion ok
    
    SASERT_PRINTF("Ok example 2\n\n");
}
