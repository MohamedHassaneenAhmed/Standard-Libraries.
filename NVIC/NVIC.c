/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  NVIC.h
 *        \brief  --- Enable peripheral interrupt
 *                --- Disable peripheral interrupt
 *                --- Set Priority of Peripheral interrupt
 *
 *      \details
 *
 *
 *********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 15/8/2022
**********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NVIC.h"



/******************************************************************************
* \Syntax          : uint8_t  NVIC_Enable_IRQ( uint8_t U8Peripheral_Name);
* \Description     : Enable peripheral interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : U8Peripheral_Name  name of peripheral that i want to enable
* \Parameters (out): None
* \Return value:   : Std_ReturnType         E_OK
*                                           E_NOT_OK
*******************************************************************************/
Std_ReturnType NVIC_Enable_IRQ (uint8_t U8Peripheral_Name)
{
     if (U8Peripheral_Name > 138)
         {
	       return NOT_OK;
         }
     else
        {
    	 if (U8Peripheral_Name < 32 )
            {
    		 Set_Pin(NVIC_EN0,U8Peripheral_Name);
            }
        else if ((U8Peripheral_Name > 31 ) | (U8Peripheral_Name < 64))
            {
	          U8Peripheral_Name =U8Peripheral_Name % 32;
	          Set_Pin(NVIC_EN1,U8Peripheral_Name);
            }
        else if ((U8Peripheral_Name > 63 ) | (U8Peripheral_Name < 96))
            {
	          U8Peripheral_Name =U8Peripheral_Name % 32;
	          Set_Pin(NVIC_EN2,U8Peripheral_Name);
            }
        else if((U8Peripheral_Name > 95 ) | (U8Peripheral_Name < 128))
            {
	          U8Peripheral_Name =U8Peripheral_Name % 32;
	          Set_Pin(NVIC_EN0,U8Peripheral_Name);
            }
        else if ((U8Peripheral_Name > 127 ) | (U8Peripheral_Name < 139))
            {
        	  U8Peripheral_Name =U8Peripheral_Name % 32;
        	  Set_Pin(NVIC_EN4,U8Peripheral_Name);
            }
        }
}

/******************************************************************************
* \Syntax          : uint8_t  NVIC_Disable_IRQ( uint8_t U8Peripheral_Name);
* \Description     : Disable peripheral interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : U8Peripheral_Name  name of peripheral that i want to disnable
* \Parameters (out): None
* \Return value:   : uint8_t         E_OK
*                                    E_NOT_OK
*******************************************************************************/
Std_ReturnType  NVIC_Disable_IRQ( uint8_t U8Peripheral_Name)
{
	 if  (U8Peripheral_Name > 138)
	    {
		  return NOT_OK;
	    }
	 else
	   {
          if (U8Peripheral_Name < 32 )
            {
	          Set_Pin(NVIC_DIS0,U8Peripheral_Name);
            }
          else if ((U8Peripheral_Name > 31 ) | (U8Peripheral_Name < 64))
            {
	          U8Peripheral_Name =U8Peripheral_Name % 32;
	          Set_Pin(NVIC_DIS1,U8Peripheral_Name);
            }
           else if ((U8Peripheral_Name > 63 ) | (U8Peripheral_Name < 96))
            {
	          U8Peripheral_Name =U8Peripheral_Name % 32;
	          Set_Pin(NVIC_DIS2,U8Peripheral_Name);
            }
           else if ((U8Peripheral_Name > 95 ) | (U8Peripheral_Name < 128))
            {
	          U8Peripheral_Name =U8Peripheral_Name % 32;
	          Set_Pin(NVIC_DIS3,U8Peripheral_Name);
            }
           else if ((U8Peripheral_Name > 127 ) | (U8Peripheral_Name < 139))
            {
        	  U8Peripheral_Name =U8Peripheral_Name % 32;
        	  Set_Pin(NVIC_DIS4,U8Peripheral_Name);
            }
	   }
}

/******************************************************************************
* \Syntax          : uint8_t  NVIC_Priority_IRQ( uint32_t *U8Ptr_NVIC_PRI_Reg,
							                     uint8_t  U8Peripheral_Name,
							                      uint8_t  U8Level_Priority
							                   );
* \Description     : set priority of peripheral interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : uint8_t *U8Ptr_NVIC_PRI_Reg,  --> Array contains all PRI registers
					 uint8_t  U8Peripheral_Name,   --> name of peripheral that i want to set priority
					 uint8_t  U8Level_Priority     --> level of priority
* \Parameters (out): None
* \Return value:   : uint8_t         E_OK
*                                    E_NOT_OK
*******************************************************************************/
Std_ReturnType  NVIC_Priority_IRQ( uint32_t *NVIC_PRI_Reg_Addresses[],
								   uint8_t  U8Peripheral_Name,
							       uint8_t  U8Level_Priority
						         )
{
	uint8_t pri_num   = U8Peripheral_Name / 4;  /* for selecting PRI Reg */
	uint8_t bit_field = U8Peripheral_Name % 4;  /* for selecting zone of PRI Reg */
   if (
	    (U8Peripheral_Name > 138) |
	    (U8Level_Priority > 7)
	  )
          {
	        return NOT_OK;
          }
   else
          {
	          switch (bit_field)
	          {
	          case 0 :
	        	  *(NVIC_PRI_Reg_Addresses[pri_num]) |= (U8Level_Priority << 5 );
	        	  break;
	          case 1 :
	          	   *(NVIC_PRI_Reg_Addresses[pri_num]) |= (U8Level_Priority << 13 );
	          	   break;
	          case 2 :
	          	   *(NVIC_PRI_Reg_Addresses[pri_num]) |= (U8Level_Priority << 21 );
	          	   break;
	          case 3 :
	          	   *(NVIC_PRI_Reg_Addresses[pri_num]) |= (U8Level_Priority << 29);
	          	   break;
	          }
          }
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
