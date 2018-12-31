#include "SimpleAssert.h"
#include <HardwareSerial.h>

bool externalConditionOk(int condition) {
    static int cond = -2;
    cond++;
    return condition > 0;
}

int simpleAssertExample() {  
    /* Check return code from function*/
    ASSERT(externalConditionOk(cond), "cond = %d", cond) return -1;
    
    SASERT_PRINTF("Ok");
    return 0;
}

void simpleAssertExampleMain()
{
    SASERT_PRINTF("%d", simpleAssertExample()); 
    SASERT_PRINTF("%d", simpleAssertExample());
    SASERT_PRINTF("%d", simpleAssertExample());
}