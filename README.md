Simple Assert Library
==========================

## Summary

One-header, zero-dependency simple assertion lib for restricted environments.

## Usage

Use `ASSERT()` macro to check the specified condition. If condition falls, the assertion message appears on stdout and you may do a specific reaction (return, close rosource or smth. else).


```c++
int resize(unsigned int newSize) {  
    /* Simple checking of variable */

    // check with reaction (return from routine)
    ASSERT(0 < newSize && newSize < 100) return -1; 

    // check with reaction and message
    ASSERT(newSize != 10, "size should not be equal to 10, but received: %d", newSize) {
    	/* Free some resources, close files etc. */
    	return -2;
    }

    
    /* Do something useful */

    return 0; // all is Ok
}
```

See more examples in `examples` folder.

Also there is an alias for `ASSERT()` macro named `VERIFY()` (it's handy in situations when `ASSERT()` is already in use). 

## Printing messages

By default `ASSERT(condition, msg)` prints message (through `SASERT_PRINTF`) "Assertion  `condition`  failed" and any additional message `msg` that specified as a second  parameter. 

To **suppress message** - use the empty string as a second parameter `ASSERT(i > 15, "")`. This useful while assert condition happens frequently or is a part of normal program flow to prevent flooding the output with a lot of assertion messages.

If you don't need **any output at all** - set `SIMPLE_ASSERT_SILENT 1` in `src/SimpleAssert.h`.

If your **platform** doesn't support `printf` you may define your own `SIMPLE_ASSERT_PRINTF` macro to make formatted output. For example, for Arduino-based platforms (Arduino, ESP8266, ESP32 etc.) use `#define SIMPLE_ASSERT_PRINTF  Serial.printf` 

## Special case: check zero return

Many functions from std and other lib returns 0 on success and some error code otherwise. Simple Assert Lib includes special macro `CHECK0(function, msg)` for this case.

In a nutshell `CHECK0()` is a special kind of `ASSERT()` that checks return value of the function and prints it if return is non-zero. For example `CHECK0(foo()) return -3;` prints value, returned by `foo()` and return `-3`, if `foo()` value is non-zero. You may add a custom or suppress message to `CHECK0()` in the same ways as to the  `ASSERT()`.

If you need to retrieve the error code, returned by function inside `CHECK0()`, you may use a special macro `CHECK0_RES`:
```C++
CHECK0(readInput()) {
   if (CHECK0_RES == ENOMEM)
       printf("Out of memory\n");
   else if (CHECK0_RES == EACCES)
       printf("Permission denied\n");
   else
       printf("Unknown error\n");
}
```
Also there is an alias for `CHECK0()` macro named `IFNOT0()`.

## Special case: check True

Many functions in Arduino-based environments return true (non-zero) on success and false (zero) otherwise. Simple Assert Lib includes special macro `CHECKOK(function, msg)` for this case. The usage is the same as `ASSERT()` and `CHECK0()`.

Also there is an alias for `CHECKOK()` macro named `IFFALSE()` - this may improve a code readability:
```
IFFALSE (connectServer(address), "Failed connect to: %s", address) return;
```


## Authors
1. dRKr, Sinai RnD (<info@sinai.io>)
