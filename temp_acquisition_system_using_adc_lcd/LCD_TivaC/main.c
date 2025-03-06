#include <stdint.h>
#include "LCD.h"
#include "TimerA0.h"
#include "PLL.h"
#include "ADCSWTrigger.h"
#include "SysTickInts.h"

extern int boxflag;

// step 3
    // convert ADC to Fahrenheit (make func later)
float farh(uint32_t x) {
    float c = (((x * 3.3) / 4096) * 100);   // temp in C
    float f = (c * 9 / 5 + 32) * 10;        // temp in f
    return f;
}

void main()
{
    PLL_Init(Bus80MHz);         // set system clock to 80 MHz

    LCD_Init();

    // part 1 test
        //LCD_OutString("Hello World");
        //LCD_OutUFix(0);
        //LCD_OutCmd(0xC0);
        //LCD_OutUDec(123);
        //LCD_OutUFix(12945);

        /*// A
        LCD_OutChar(0x41);
        TimerA0_Wait10ms(100);      // Wait 1s

        // B
        LCD_OutChar(0x42);
        TimerA0_Wait10ms(100);      // Wait 1s

        // C
        LCD_OutChar(0x43);
        TimerA0_Wait10ms(100);      // Wait 1s

        // Move cursor to the 2nd line
        LCD_OutCmd(0xC0);

        // 1
        LCD_OutChar(0x31);
        TimerA0_Wait10ms(100);      // Wait 1s

        // 2
        LCD_OutChar(0x32);
        TimerA0_Wait10ms(100);      // Wait 1s

        // 3
        LCD_OutChar(0x33);*/

    // step 1 testing ADC
        //ADC0_InitSWTriggerSeq3_Ch8();

        //uint32_t x;
        //x = ADC0_InSeq3();

    // step 2
        //LCD_OutUDec(x);
        //LCD_OutCmd(0xC0);
    SysTick_Init(8000000);


    //LCD_OutUFix(f);


    // step 4 create a flag for mailbox
        //uint32_t ADCvalue = SysTick_Mailbox();
        //float y = farh(ADCvalue);
        //LCD_OutUFix(y);
        //boxflag = 0;


    LCD_OutCmd(0xC0);

    while(1){                   // Main loop
        if (boxflag == 1){
            uint32_t ADCvalue = SysTick_Mailbox();
            float y = farh(ADCvalue);
            LCD_OutUFix(y);
            LCD_OutCmd(0xC0);
            boxflag = 0;
        }
    }
}
