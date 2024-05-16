/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RB0 aliases
#define SPI_MOSI_TRIS                 TRISBbits.TRISB0
#define SPI_MOSI_LAT                  LATBbits.LATB0
#define SPI_MOSI_PORT                 PORTBbits.RB0
#define SPI_MOSI_WPU                  WPUBbits.WPUB0
#define SPI_MOSI_OD                   ODCONBbits.ODCB0
#define SPI_MOSI_ANS                  ANSELBbits.ANSB0
#define SPI_MOSI_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define SPI_MOSI_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define SPI_MOSI_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SPI_MOSI_GetValue()           PORTBbits.RB0
#define SPI_MOSI_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define SPI_MOSI_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define SPI_MOSI_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define SPI_MOSI_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define SPI_MOSI_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define SPI_MOSI_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define SPI_MOSI_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define SPI_MOSI_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)
// get/set IO_RB1 aliases
#define PWM_OUTPUT_TRIS                 TRISBbits.TRISB1
#define PWM_OUTPUT_LAT                  LATBbits.LATB1
#define PWM_OUTPUT_PORT                 PORTBbits.RB1
#define PWM_OUTPUT_WPU                  WPUBbits.WPUB1
#define PWM_OUTPUT_OD                   ODCONBbits.ODCB1
#define PWM_OUTPUT_ANS                  ANSELBbits.ANSB1
#define PWM_OUTPUT_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define PWM_OUTPUT_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define PWM_OUTPUT_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define PWM_OUTPUT_GetValue()           PORTBbits.RB1
#define PWM_OUTPUT_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define PWM_OUTPUT_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define PWM_OUTPUT_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define PWM_OUTPUT_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define PWM_OUTPUT_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define PWM_OUTPUT_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define PWM_OUTPUT_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define PWM_OUTPUT_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)
// get/set IO_RB2 aliases
#define IO_RB2_TRIS                 TRISBbits.TRISB2
#define IO_RB2_LAT                  LATBbits.LATB2
#define IO_RB2_PORT                 PORTBbits.RB2
#define IO_RB2_WPU                  WPUBbits.WPUB2
#define IO_RB2_OD                   ODCONBbits.ODCB2
#define IO_RB2_ANS                  ANSELBbits.ANSB2
#define IO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_RB2_GetValue()           PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_RB2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_RB2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IO_RB2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IO_RB2_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)
#define RB2_SetInterruptHandler  IO_RB2_SetInterruptHandler
// get/set IO_RB3 aliases
#define IO_RB3_TRIS                 TRISBbits.TRISB3
#define IO_RB3_LAT                  LATBbits.LATB3
#define IO_RB3_PORT                 PORTBbits.RB3
#define IO_RB3_WPU                  WPUBbits.WPUB3
#define IO_RB3_OD                   ODCONBbits.ODCB3
#define IO_RB3_ANS                  ANSELBbits.ANSB3
#define IO_RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_RB3_GetValue()           PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IO_RB3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define IO_RB3_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define IO_RB3_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define IO_RB3_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the IO_RB2 pin functionality
 * @param none
 * @return none
 */
void IO_RB2_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_RB2 pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for IO_RB2 at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_RB2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for IO_RB2 pin.
 *        This is a dynamic interrupt handler to be used together with the IO_RB2_SetInterruptHandler() method.
 *        This handler is called every time the IO_RB2 ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*IO_RB2_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_RB2 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_RB2_SetInterruptHandler() method.
 *        This handler is called every time the IO_RB2 ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void IO_RB2_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/