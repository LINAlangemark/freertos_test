/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: file.c
*
* PROJECT....: EMP
*
* DESCRIPTION: See module specification file (.h-file).
*
* Change Log:
*****************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 150322  MoH   Module created.
*
*****************************************************************************/

/***************************** Include files *******************************/
#include "file.h"
/*****************************    Defines    *******************************/


/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/
fcb pof[MAX_FILES];	            // Pool of files

/*****************************   Functions   *******************************/

BOOLEAN put_file(EMP_FILE file, INT8U ch)
{
  if (file < MAX_FILES && pof[file].put)
    return pof[file].put(ch);
  return 0;
}

BOOLEAN get_file( EMP_FILE file, INT8U *pch )
{
  BOOLEAN result = FALSE;

  if( pof[(int)file].get )
    result = pof[(int)file].get( pch );
  return( result );
}


extern INT8U init_files()
/*****************************************************************************
*   Function : See module specification (.h-file).
*****************************************************************************/
{
  INT8U i;

  for( i = 0; i < MAX_FILES; i++ )
  {
	  pof[i].put = NULL;
	  pof[i].get = NULL;
  }
  pof[COM1].put = uart0_put_q;
  pof[COM1].get = uart0_get_q;
  //pof[COM2].put = wr_ch_LCD;
  //pof[COM3].get = get_keyboard;

  return( 1 );
}

/****************************** End Of Module *******************************/












