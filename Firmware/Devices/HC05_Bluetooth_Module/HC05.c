#include "HC05.h"




int BL_HC05_Init(void)
{
    int i = 0;
    Serial_Init();
    Serial_Write("AT\r\n");
    if(i == 1)
    {
        //do something
    }
    
}
