 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
� [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"


#include "ws2812/Inc/ws2812_uart.h"
#include "string.h"


#if SPI
#include "ws2812/Inc/ws2812_spi.h"
#endif

#if PWM
#include "ws2812/Inc/ws2812_pwm.h"
#endif


/*
    Main application
*/

ws2812_configuration ws2812_spi;
ws2812_configuration ws2812_pwm;

char c;
uint8_t index = 0;
bool fade_flag = 0;
uint16_t fade_time = 0;
uint8_t rxBuff[RX_BUFF_SIZE];



static void Handle_UART_Data(void) {

    
    while(!EUSART_IsRxReady());
    c = EUSART_Read();
    rxBuff[index++] = c;
    if (index > RX_BUFF_SIZE) {
        index = 0;
    }

    if (c == '\n') {
        ws2812_uart_commands(rxBuff, index);
        memset(rxBuff, 0, RX_BUFF_SIZE);
        index = 0;
    }
    
}


int main(void)
{
    SYSTEM_Initialize();
 
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

#if SPI

    SPI1_Open((uint8_t)ws2812_spi.handle);

#endif
    
    
    
#if PWM
    //ws2812_pwm.handle = 0;
    //ws2812_pwm.led_num = 25;
    //ws2812_pwm.brightness = 50;
    //ws2812_pwm.dma = 0;
    
    //ws2812_pwm_init(&ws2812_pwm);
    
    //for (uint8_t i = 0; i < ws2812_pwm.led_num; i++) {
    //    ws2812_set_led(&ws2812_pwm, i, 0, 0, 255);
    //}
    

#endif
    

    while(1)
    {
        
#if SPI
    
    
    
    Handle_UART_Data(); 
    


#endif
        
        
#if PWM
    
    //ws2812_pwm_send(&ws2812_pwm, ws2812_pwm.brightness);
    
    
    Handle_UART_Data(); 


#endif
        
    }    
}