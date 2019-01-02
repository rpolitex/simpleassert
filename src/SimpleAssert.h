#ifndef SIMPLE_ASSERT_H

/*Simple Asert settings*/
#ifndef SIMPLE_ASSERT_SILENT
#define SIMPLE_ASSERT_SILENT 0
#endif

/* Helper macro */
#define BL_QUOT(x) #x
#define BL_QUOTE(x) BL_QUOT(x)
#define BL_CAT2(x,y) x##y
#define BL_CONCAT(x,y) BL_CAT2(x,y)

/* Simple assert definitions */
#if SIMPLE_ASSERT_SILENT 
    #define SASERT_PRINTF
    #define SASERT_DEBUG(__fstr__, ...)
#else        
    #define SASERT_PRINTF  Serial.printf
    #define SASERT_DEBUG(__fstr__, ...)   SASERT_PRINTF("%s() [" __FILE__ ":" BL_QUOTE(__LINE__) "]:\t" __fstr__ "\n", __FUNCTION__ , ##__VA_ARGS__)
#endif


#define ASSERT_VAR(__name__) BL_CONCAT(__name__, __LINE__)



/** Simple inline checker */
#define ASSERT(condition, ...)    signed char ASSERT_VAR(__cond__) = (condition); if (!(ASSERT_VAR(__cond__))) SASERT_DEBUG("ASSERTION `" BL_QUOTE( (condition) ) "` FAILED. " __VA_ARGS__);  if (!(ASSERT_VAR(__cond__)))


/** Check if function returns 0*/
#define SASERT_CHECK_PRINT(function, __fstr__, ...)  SASERT_DEBUG("`" BL_QUOTE( function ) "` returns non-zero: [%d] " __fstr__, ASSERT_VAR(__zero__), ##__VA_ARGS__);
#define CHECK0(function,  ...)    signed char  ASSERT_VAR(__zero__) = (function); if (ASSERT_VAR(__zero__) != 0) SASERT_CHECK_PRINT(function, __VA_ARGS__);  if (ASSERT_VAR(__zero__) != 0)


#endif