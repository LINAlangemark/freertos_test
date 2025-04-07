#include "controller_params.h"

xQueueHandle xUartRxQueue = NULL;
xQueueHandle xUartTxQueue = NULL;

unsigned char ref;

Controller_t Controller = { .CtrlState = CTRL_IDLE };

void vControllerTask(void *pvParameters)
{
    Controller_t *ctrl = (Controller_t *)pvParameters;

  for(;;){

      gprintf("=== CONTROLLER TASK ===\n");
     // gprintf("CtrlInput address: %p\n", ctrl->CtrlInput);

      gprintf("ref: %u ", ref);

      unsigned char fb = fb+ctrl->Feedback;
      gprintf("feedback: %u ", fb);

      unsigned char out = ref+fb;
      gprintf("output: %u ", out);

      //YIELD CONTROL
     vTaskDelay(pdMS_TO_TICKS(300));
  }

}

