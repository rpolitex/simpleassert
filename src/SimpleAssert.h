#ifndef SIMPLE_ASSERT_H

/*Simple Asert settings*/
#ifndef SIMPLE_ASSERT_SILENT
#define SIMPLE_ASSERT_SILENT 0
#endif

#ifndef SIMPLE_ASSERT_PRINTF
#define SIMPLE_ASSERT_PRINTF printf /*Use `Serial.printf` for Arduino-based platforms (Arduino, ESP32 etc.)*/
#endif

/* Helper macro */
#define BL_QUOT(x) #x
#define BL_QUOTE(x) BL_QUOT(x)

#define SASERT_CHECK_EMPTY_STRING(__str__) ( sizeof(BL_QUOTE(__str__)) == 3 && BL_QUOTE(__str__)[0] == '\"' && BL_QUOTE(__str__)[1] == '\"'&& BL_QUOTE(__str__)[2] == '\0')

/* Simple assert definitions */
#if SIMPLE_ASSERT_SILENT 
    #define SASERT_PRINTF [](){return 0;}()
    #define SASERT_DEBUG(__fstr__, ...) [](){return 0;}()
#else        
    #define SASERT_PRINTF  SIMPLE_ASSERT_PRINTF /*Use `Serial.printf` for Arduino-based platforms (Arduino, ESP32 etc.)*/
    #define SASERT_DEBUG(__fstr__, ...)   SASERT_PRINTF("%s() [" __FILE__ ":" BL_QUOTE(__LINE__) "]:\t" __fstr__ "\n", __FUNCTION__ , ##__VA_ARGS__)
#endif

/** Prints only when `checkmsg` is non-empty */
#define SASERT_DEBUG_NE(checkmsg, __fstr__, ...) ( ( SASERT_CHECK_EMPTY_STRING(checkmsg) ) ? (0) : (SASERT_DEBUG(__fstr__, ##__VA_ARGS__)) )

/** Simple inline checker */
#define SASERT_ASSERT_PRINT(condition, __fstr__, ...)   SASERT_DEBUG_NE(__fstr__, "Assertion `" BL_QUOTE( (condition) ) "` failed; " __fstr__, ##__VA_ARGS__)
#define SASERT_ASSERT(condition, ...) if ( (condition) ? false : (SASERT_ASSERT_PRINT(condition, __VA_ARGS__) || 1) ) 
/* Aliases */
/* If one of the macro names is already in use in your project, you may choose another one: ASSERT, VERIFY */
#ifndef ASSERT
    #define ASSERT SASERT_ASSERT
#endif
#ifndef VERIFY
    #define VERIFY SASERT_ASSERT
#endif

/** Check  zero */
#define SASERT_CHECK0_PRINT(function, errcode, __fstr__, ...) SASERT_DEBUG_NE(__fstr__, "`" BL_QUOTE( function ) "` returns non-zero errcode: [%d]; " __fstr__, errcode, ##__VA_ARGS__)
/** When use CHECK0 you may obtain the non-zero `function` return code by this macro*/
#define CHECK0_RES __sasert_res__
/** Check either function returns 0 or error code*/
#define CHECK0(function,  ...)  if (int CHECK0_RES = (function)) if ( SASERT_CHECK0_PRINT(function, __sasert_res__, __VA_ARGS__) || 1 )

/** Check  true */
#define SASERT_CHECK_PRINT(function, __fstr__, ...) SASERT_DEBUG_NE(__fstr__, "`" BL_QUOTE( function ) "` returns false; " __fstr__, ##__VA_ARGS__)
/** Check if function returns true (consider false is zero, and true is any non-zero value)*/               
#define CHECKOK(function,  ...) if ( ( (function) != 0) ? false : (SASERT_CHECK_PRINT(function, __VA_ARGS__) || 1) ) 
#define CHECK1 CHECKOK


//void simpleAssertExampleMain1();
//void simpleAssertExampleMain2();
//void simpleAssertExampleMain3();
#endif
