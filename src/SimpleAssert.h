
/*Simple Asert settings*/
#define SIMPLE_ASSERT_SILENT 0

/* Helper macro */
#define BL_QUOT(x) #x
#define BL_QUOTE(x) BL_QUOT(x)

/* Simple assert definitions */
#if SIMPLE_ASSERT_SILENT 
    #define SASERT_PRINTF
    #define SASERT_DEBUG(__fstr__, ...)
#else        
    #define SASERT_PRINTF  Serial.printf
    #define SASERT_DEBUG(__fstr__, ...)   SASERT_PRINTF("%s() [" __FILE__ ":" BL_QUOTE(__LINE__) "]:\t" __fstr__ "\n", __FUNCTION__ , ##__VA_ARGS__)
#endif


/** Simple inline checker */
#define ASSERT(condition, ...)    if (!(condition)) SASERT_DEBUG("ASSERTION `" BL_QUOTE( (condition) ) "` FAILED. " __VA_ARGS__);  if (!(condition))