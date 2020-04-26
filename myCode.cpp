/*
*/

#include "../../SPI/src/SPI.h"
#include "pinConfiguration.h"
#include "MapleFreeRTOS1000_pp.h"
#define LED PC13
void myLoop(void);
//
uint8_t ucHeap[ configTOTAL_HEAP_SIZE ];
//
class MainTask : public xTask
{
public:
            MainTask() : xTask("MainTask",10,300)
            {

            }
    void    run(void);
protected:
};


/**
 */
void MainTask::run()
{
    while(1)
    {    
        xDelay(100);
    }
}

/**
 * 
 */
void mySetup(void)
{
  afio_cfg_debug_ports( AFIO_DEBUG_SW_ONLY); // get PB3 & PB4
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
  Serial.end(); // dont let usb bother us
  interrupts();
  MainTask *mainTask=new MainTask();
  vTaskStartScheduler();        
}
void myLoop()
{
}
