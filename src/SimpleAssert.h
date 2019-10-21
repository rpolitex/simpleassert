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
#define BL_CAT2(x,y) x##y
#define BL_CONCAT(x,y) BL_CAT2(x,y)

#define ASSERT_VAR(__name__) BL_CONCAT(__name__, __LINE__)
#define SASERT_CHECK_EMPTY_STRING(__str__) ( sizeof(BL_QUOTE(__str__)) == 3 && BL_QUOTE(__str__)[0] == '\"' && BL_QUOTE(__str__)[1] == '\"'&& BL_QUOTE(__str__)[2] == '\0')


/* Simple assert definitions */
#if SIMPLE_ASSERT_SILENT 
    #define SASERT_PRINTF [](){return 0;}()
    #define SASERT_DEBUG(__fstr__, ...) [](){return 0;}()
#else        
    #define SASERT_PRINTF  SIMPLE_ASSERT_PRINTF /*Use `Serial.printf` for Arduino-based platforms (Arduino, ESP32 etc.)*/
    #define SASERT_DEBUG(__fstr__, ...)   SASERT_PRINTF("%s() [" __FILE__ ":" BL_QUOTE(__LINE__) "]:\t" __fstr__ "\n", __FUNCTION__ , ##__VA_ARGS__)
#endif



/** Simple inline checker */
#define SASERT_ASSERT_PRINT(condition, __fstr__, ...)  ( ( SASERT_CHECK_EMPTY_STRING(__fstr__) ) ? (0) : SASERT_DEBUG("Assertion `" BL_QUOTE( (condition) ) "` failed. " __fstr__, ##__VA_ARGS__) )
#define ASSERT(condition, ...) signed char ASSERT_VAR(__cond__) = (condition); if (!(ASSERT_VAR(__cond__))) SASERT_ASSERT_PRINT(condition, __VA_ARGS__);  if (!(ASSERT_VAR(__cond__)))


/** Check either function returns 0 or error code*/             
#define SASERT_CHECK0_PRINT(function, __fstr__, ...) ( ( SASERT_CHECK_EMPTY_STRING(__fstr__) ) ? (0) :  SASERT_DEBUG("`" BL_QUOTE( function ) "` returns non-zero errcode: [%d] " __fstr__, ASSERT_VAR(__zero__), ##__VA_ARGS__) )
#define CHECK0(function,  ...) signed char  ASSERT_VAR(__zero__) = (function); if (ASSERT_VAR(__zero__) != 0) SASERT_CHECK0_PRINT(function, __VA_ARGS__);  if (ASSERT_VAR(__zero__) != 0)


/** Check if function returns true (consider false is zero, and true is any non-zero value)*/               
#define SASERT_CHECK_PRINT(function, __fstr__, ...) ( ( SASERT_CHECK_EMPTY_STRING(__fstr__) ) ? (0) :  SASERT_DEBUG("`" BL_QUOTE( function ) "` returns false. " __fstr__, ##__VA_ARGS__) )
#define CHECK1(function,  ...) signed char  ASSERT_VAR(__true__) = (function); if (ASSERT_VAR(__true__) == 0) SASERT_CHECK_PRINT(function, __VA_ARGS__);  if (ASSERT_VAR(__true__) == 0)

//void simpleAssertExampleMain1();
//void simpleAssertExampleMain2();
//void simpleAssertExampleMain3();
#endif
