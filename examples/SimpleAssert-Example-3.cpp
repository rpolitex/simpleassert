#include "SimpleAssert.h"
#include <HardwareSerial.h>

int zeroReturnOnSuccess(int res) {
    if (res > 100) // some condition
        return 0; // return Ok
    else 
        return -1; // return some Error code
}

static int simpleAssertExample(int example) { 
    switch (example) {
        case 1: {
                CHECK0(zeroReturnOnSuccess(97)) return 1;            
            }
            break;
        case 2:{
                int p = 98;
                CHECK0(zeroReturnOnSuccess(p), " with p = %d", p)  {
                    SASERT_PRINTF("Complex reaction here\n");
                    SASERT_DEBUG("CHECK0_RES = %d", CHECK0_RES); // result of `zeroReturnOnSuccess()` call
                    return 2;
                }    
            }
            break;
        case 3: {
                CHECK0(zeroReturnOnSuccess(99), "") { // Suppress CHECK0 default message 
                    SASERT_PRINTF("CHECK0 Message suppressed\n");
                    SASERT_DEBUG("CHECK0_RES = %d", CHECK0_RES); // result of `zeroReturnOnSuccess()` call
                    return 3;
                }    
            }    
            break;
        case 4: {
                CHECK0(zeroReturnOnSuccess(100)); // just warning - no return or reaction here
                SASERT_PRINTF("Just warning - Program goes further\n");                
            }
            break;
        case 5: {
                CHECK0(zeroReturnOnSuccess(101)) { // success
                    // Never been here
                    return 5;
                }   
            }     
            break;
    }
    
    
    SASERT_DEBUG("Ok");
    return 0;
}

void simpleAssertExampleMain3() {      
    SASERT_PRINTF("=== simpleAssertExampleMain3 ===\n\n");
    CHECK0(simpleAssertExample(1)); // Check failed
    CHECK0(simpleAssertExample(2)); // Check failed
    CHECK0(simpleAssertExample(3)); // Check failed, but default check has been message suppressed
    CHECK0(simpleAssertExample(4)); // Just Warning
    CHECK0(simpleAssertExample(5)); // Ok
    
    SASERT_PRINTF("Ok example 3\n\n");
}
