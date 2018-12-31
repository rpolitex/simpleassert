#include "SimpleAssert.h"
#include <HardwareSerial.h>

bool externalConditionOk() {
    static int condition = -2;
    condition++;
    return condition > 0;
}

int simpleAssertExample() {  
    /* Check return code from function*/
    bool externalCond = externalConditionOk();
    ASSERT(externalCond, "cond = %d", externalCond) return -1;
    
    SASERT_DEBUG("Ok\n");
    return 0;
}

void simpleAssertExampleMain()
{
    SASERT_PRINTF("%d\n", simpleAssertExample());  //assertion failed
    SASERT_PRINTF("%d\n", simpleAssertExample()); 	//assertion failed
    SASERT_PRINTF("%d\n", simpleAssertExample());	//assertion ok
}