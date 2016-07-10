/******************************************************************************
* File       : Task_PT_Demo.c
* Function   : A demo task for PT application
* description: To be done.           
* Version    : V1.00
* Author     : Ian
* Date       : 8th Jul 2016
* History    :  No.  When           Who           What
*               1    08/Jul/2016    Ian           Create
******************************************************************************/

#include "type_def.h"
#include "common_head.h"
#include "project_config.h"
#include "MOE_Core.h"
#include "MOE_Event.h"
#include "MOE_Timer.h"
#include "MOE_Msg.h"
#include "MOE_PT.h"
#include "Task_PT_Demo.h"
#include "debug.h"

static uint8 sg_u8TaskID = TASK_NO_TASK;

static void (*const TASK_PT_DEMO_LED_Off)(uint8 u8Clr)    = TASK_PT_DEMO_LED_OFF;
static void (*const TASK_PT_DEMO_LED_On)(uint8 u8Clr)     = TASK_PT_DEMO_LED_ON;
static void (*const TASK_PT_DEMO_LED_Toggle)(uint8 u8Clr) = TASK_PT_DEMO_LED_TOGGLE;

/******************************************************************************
* Name       : uint8 Task_PT_Demo_Process(uint8 u8Evt)
* Function   : A demo task for PT application
* Input      : uint8 u8Evt  1~254     Event for the task
* Output:    : None
* Return     : SW_OK   Successful operation
*            : SW_ERR  Failed operation
*              1~254   Event which is not processed.
* description: To be done
* Version    : V1.00
* Author     : Ian
* Date       : 8th Jul 2016
******************************************************************************/
uint8 Task_PT_Demo_Process(uint8 u8Evt)
{   
    PTV uint16 ptv_u16Cnt = 250;
 
    PT_INIT();

    PT_BEGIN();

    while(1)
    {
        PT_WAIT_MSG();
        TASK_PT_DEMO_LED_Toggle(1);
        PT_DELAY(ptv_u16Cnt);
        TASK_PT_DEMO_LED_Toggle(1);
        PT_DELAY(ptv_u16Cnt);
        TASK_PT_DEMO_LED_Toggle(1);
        PT_DELAY(ptv_u16Cnt);
        TASK_PT_DEMO_LED_Toggle(1);
        PT_DELAY(ptv_u16Cnt);
    }

    PT_END();

    return SW_OK;

}

/* End of file */
