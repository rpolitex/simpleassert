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
                CHECK0(zeroReturnOnSuccess(99)) return 1;
            }
            break;
        case 2:{
                int p = 99;
                CHECK0(zeroReturnOnSuccess(p), "params: %d", p) return 2;
            }
            break;
        case 3: {
                CHECK0(zeroReturnOnSuccess(99), "params: %d", 99) {
                    SASERT_PRINTF("Complex reaction here\n");
                    return 3;
                }    
            }    
            break;
        case 4: {
                CHECK0(zeroReturnOnSuccess(99)); // just warning - no reaction here
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
    
    
    SASERT_PRINTF("Ok\n");
    return 0;
}

void simpleAssertExampleMain3() {        
    CHECK0(simpleAssertExample(1)); // Check failed
    CHECK0(simpleAssertExample(2)); // Check failed
    CHECK0(simpleAssertExample(3)); // Check failed
    CHECK0(simpleAssertExample(4)); // Just Warning
    CHECK0(simpleAssertExample(5)); // Ok
    
    SASERT_PRINTF("Ok example 3\n");
}