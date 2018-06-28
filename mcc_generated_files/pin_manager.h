/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F15325
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set AN4 aliases
#define AN4_TRIS                 TRISAbits.TRISA4
#define AN4_LAT                  LATAbits.LATA4
#define AN4_PORT                 PORTAbits.RA4
#define AN4_WPU                  WPUAbits.WPUA4
#define AN4_OD                   ODCONAbits.ODCA4
#define AN4_ANS                  ANSELAbits.ANSA4
#define AN4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define AN4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define AN4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define AN4_GetValue()           PORTAbits.RA4
#define AN4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define AN4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define AN4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define AN4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define AN4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define AN4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define AN4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define AN4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set AN5 aliases
#define AN5_TRIS                 TRISAbits.TRISA5
#define AN5_LAT                  LATAbits.LATA5
#define AN5_PORT                 PORTAbits.RA5
#define AN5_WPU                  WPUAbits.WPUA5
#define AN5_OD                   ODCONAbits.ODCA5
#define AN5_ANS                  ANSELAbits.ANSA5
#define AN5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define AN5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define AN5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define AN5_GetValue()           PORTAbits.RA5
#define AN5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define AN5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define AN5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define AN5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define AN5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define AN5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define AN5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define AN5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set SCK1 aliases
#define SCK1_TRIS                 TRISCbits.TRISC0
#define SCK1_LAT                  LATCbits.LATC0
#define SCK1_PORT                 PORTCbits.RC0
#define SCK1_WPU                  WPUCbits.WPUC0
#define SCK1_OD                   ODCONCbits.ODCC0
#define SCK1_ANS                  ANSELCbits.ANSC0
#define SCK1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SCK1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SCK1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SCK1_GetValue()           PORTCbits.RC0
#define SCK1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SCK1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SCK1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SCK1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SCK1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SCK1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SCK1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SCK1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SDI1 aliases
#define SDI1_TRIS                 TRISCbits.TRISC1
#define SDI1_LAT                  LATCbits.LATC1
#define SDI1_PORT                 PORTCbits.RC1
#define SDI1_WPU                  WPUCbits.WPUC1
#define SDI1_OD                   ODCONCbits.ODCC1
#define SDI1_ANS                  ANSELCbits.ANSC1
#define SDI1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SDI1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SDI1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SDI1_GetValue()           PORTCbits.RC1
#define SDI1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SDI1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SDI1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SDI1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SDI1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SDI1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SDI1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SDI1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SDO1 aliases
#define SDO1_TRIS                 TRISCbits.TRISC2
#define SDO1_LAT                  LATCbits.LATC2
#define SDO1_PORT                 PORTCbits.RC2
#define SDO1_WPU                  WPUCbits.WPUC2
#define SDO1_OD                   ODCONCbits.ODCC2
#define SDO1_ANS                  ANSELCbits.ANSC2
#define SDO1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SDO1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SDO1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SDO1_GetValue()           PORTCbits.RC2
#define SDO1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SDO1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SDO1_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SDO1_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SDO1_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SDO1_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SDO1_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SDO1_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()               do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()                do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()                do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()       do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()      do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()               do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()                do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()                do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()       do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()      do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 aliases
#define RC5_TRIS                 TRISCbits.TRISC5
#define RC5_LAT                  LATCbits.LATC5
#define RC5_PORT                 PORTCbits.RC5
#define RC5_WPU                  WPUCbits.WPUC5
#define RC5_OD                   ODCONCbits.ODCC5
#define RC5_ANS                  ANSELCbits.ANSC5
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()           PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define RC5_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/