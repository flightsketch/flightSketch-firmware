/*
 * File:   main.c
 * Author: russ
 *
 * Created on June 26, 2018, 10:32 PM
 */
#include "bmp280.h"
#include "main.h"

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#define FCY _XTAL_FREQ/2



#define SPI_BUFFER_LEN 30
#define BUFFER_LENGTH	0xFF
#define	SPI_READ	0x80
#define SPI_WRITE	0x7F
#define BMP280_DATA_INDEX	1
#define BMP280_ADDRESS_INDEX	2




void BMP280_delay_msek(uint32_t msek);

struct bmp280_dev bmp;

void  BMP280_delay_msek(uint32_t msek)
{
//	__delay_ms(msek);
}

int8_t  BMP280_SPI_bus_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t cnt)
{
    __delay_ms(1);
	int32_t iError=BMP280_OK;
	int8_t array[SPI_BUFFER_LEN]={BUFFER_LENGTH};
	uint8_t stringpos;
	array[0] = reg_addr|SPI_READ;

    uint8_t i;
//    BMP280_CS_SetLow();
    for (i=0; i<cnt+1; i++){
//        array[i] = SPI1_Exchange8bit(array[i]);
    }
    //while (SPI1STATbits.SRMPT == false);
//    BMP280_CS_SetHigh();
	for (stringpos = 0; stringpos < cnt; stringpos++) {
		*(reg_data + stringpos) = array[stringpos+BMP280_DATA_INDEX];
	}
	return (int8_t)iError;
}

int8_t  BMP280_SPI_bus_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t cnt)
{
	int32_t iError=BMP280_OK;

//    uint8_t i;
//
//    BMP280_CS_SetLow();
//    SPI1_Exchange8bit(reg_addr);
//    for (i=0; i<cnt; i++){
//        SPI1_Exchange8bit(*(reg_data + i));
//    }
//    //while (SPI1STATbits.SRMPT == false);
//    BMP280_CS_SetHigh();
	return (int8_t)iError;
}

void tmr_fire(void){
    RC5 = !RC5;
}

void main(void) {
    
    SYSTEM_Initialize();
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1; // Enable peripheral interrupts
//    TMR0_SetInterruptHandler(tmr_fire);
    TMR0_StartTimer();
    int8_t rslt;
    bmp.dev_id  =  0;
    bmp.intf = BMP280_SPI_INTF;
    bmp.read = BMP280_SPI_bus_read;
    bmp.write = BMP280_SPI_bus_write;
    bmp.delay_ms = BMP280_delay_msek;

    rslt = bmp280_init(&bmp);
    
    while(1){
        
    }
    
    
    return;
}
