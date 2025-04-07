#include "FreeRTOS.h"
#include "task.h"
#include "debugger.h"
#include <stdio.h>

extern TaskHandle_t vLedTaskHandle;
extern TaskHandle_t vSwitchTaskHandle;
extern TaskHandle_t vUartRxTaskHandle;
extern TaskHandle_t vUartTxTaskHandle;

const char* getTaskStateString(eTaskState state) {
    switch (state) {
        case eRunning:   return "Running";
        case eReady:     return "Ready";
        case eBlocked:   return "Blocked";
        case eSuspended: return "Suspended";
        case eDeleted:   return "Deleted";
        default:         return "Unknown";
    }
}

void vDebugTask(void *pvParameters) {
    for (;;) {

        TaskStatus_t taskStats[10];
        UBaseType_t total = uxTaskGetSystemState(taskStats, 10, NULL);

        gprintf("=== Debug: System State ===\n");
        gprintf("Number of tasks:  %u\n", total);

        for (int i = 0; i < total; i++) {
                gprintf("Task: %s | Num: %u | Prio: %u | State: %s | Stack: %u\n",
                taskStats[i].pcTaskName,
                taskStats[i].xTaskNumber,
                taskStats[i].uxCurrentPriority,
                getTaskStateString(taskStats[i].eCurrentState),
                taskStats[i].usStackHighWaterMark);
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
