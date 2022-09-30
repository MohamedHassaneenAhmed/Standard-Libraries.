/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Std_Types.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Standard Types
 *
 *********************************************************************************************************************/



#ifndef COMMON_STD_TYPES_H_
#define COMMON_STD_TYPES_H_

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define HIGH     1u            /* Physical state 5V or 3.3V */
#define LOW      0u            /* Physical state 0V */

#define ACTIVE   1u            /* Logical state active */
#define IDLE     0u            /* Logical state idle */

#define ON       1u
#define OFF      0u

#define OK        0u
#define NOT_OK    -1

#ifndef TRUE
   #define TRUE   1u
#endif

#ifndef FALSE
   #define FALSE  0u
#endif

#define ENABLE    1u
#define DISABLE   0u



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

    typedef signed char           int8_t ;
    typedef  unsigned char       uint8_t ;
    typedef  short int           int16_t ;
    typedef  unsigned short int  uint16_t;
    typedef  long                int32_t ;
    typedef  unsigned long       uint32_t;
	typedef  float               float32_t;
    typedef  double              float64_t;
	typedef  long long           int64_t ;
    typedef  unsigned long long  uint64_t;


    typedef int8_t Std_ReturnType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



#endif /* COMMON_STD_TYPES_H_ */
