Simple Assert Library
==========================

## Summary

One-header, zero-dependency simple assertion lib for restricted environments.

## Usage

Use `ASSERT()` macro to check the specified condition. If condition falls, the assertion message appears on stdout and you may do a specific reaction (return, close rosource or smth. else).

If you don't need the assertion message - set `SIMPLE_ASSERT_SILENT 1`.



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

    
    /* Doing something useful */

    return 0; // all is Ok
}
```

See more examples in `examples` folder.


## Authors
1. dRKr, Sinai RnD (<info@sinai.io>)
