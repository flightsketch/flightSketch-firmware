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
    uint32_t i;
    
    for (i=0; i<msek; i++){
        __delay_ms(1);
    }
}

int8_t  BMP280_SPI_bus_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t cnt)
{
    __delay_ms(1);
	int32_t iError=BMP280_OK;
	int8_t array[SPI_BUFFER_LEN]={BUFFER_LENGTH};
	uint8_t stringpos;
	array[0] = reg_addr|SPI_READ;

    uint8_t i;
    CS_BARO_SetLow();
    for (i=0; i<cnt+1; i++){
        array[i] = spi1_exchangeByte(array[i]);
    }
    //while (SPI1STATbits.SRMPT == false);
    __delay_ms(10);
    CS_BARO_SetHigh();
    
	for (stringpos = 0; stringpos < cnt; stringpos++) {
		*(reg_data + stringpos) = array[stringpos+BMP280_DATA_INDEX];
	}
	return (int8_t)iError;
}

int8_t  BMP280_SPI_bus_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t cnt)
{
	int32_t iError=BMP280_OK;

    uint8_t i;

    CS_BARO_SetLow();
    spi1_exchangeByte(reg_addr);
    for (i=0; i<cnt; i++){
        spi1_exchangeByte(*(reg_data + i));
    }
    //while (SPI1STATbits.SRMPT == false);
    __delay_ms(10);
    CS_BARO_SetHigh();
	return (int8_t)iError;
}

void tmr_fire(void){
//    int a;
//    RC5 = !RC5;
//    a = ADC_GetConversion(5);
//    EUSART1_Write(a>>8);
//    EUSART1_Write(a);
//    spi1_exchangeByte(0x42);
    
    int8_t rslt;
    uint32_t alt;
    float altf;
    
    struct bmp280_uncomp_data ucomp_data;
    uint8_t meas_dur = bmp280_compute_meas_time(&bmp);


    rslt = bmp280_get_uncomp_data(&ucomp_data, &bmp);
    int32_t  temp32 = bmp280_comp_temp_32bit(ucomp_data.uncomp_temp, &bmp);
    uint32_t pres32 = bmp280_comp_pres_32bit(ucomp_data.uncomp_press, &bmp);
    
    EUSART1_Write(0x42);
    __delay_ms(10);
    EUSART1_Write(0x43);
    __delay_ms(10);
    
    EUSART1_Write((temp32 >> (0 * 8)) & 0xFF);
    __delay_ms(10);
    EUSART1_Write((temp32 >> (1 * 8)) & 0xFF);
    __delay_ms(10);
    EUSART1_Write((temp32 >> (2 * 8)) & 0xFF);
    __delay_ms(10);
    EUSART1_Write((temp32 >> (3 * 8)) & 0xFF);
    
    EUSART1_Write((pres32 >> (0 * 8)) & 0xFF);
    __delay_ms(10);
    EUSART1_Write((pres32 >> (1 * 8)) & 0xFF);
    __delay_ms(10);
    EUSART1_Write((pres32 >> (2 * 8)) & 0xFF);
    __delay_ms(10);
    EUSART1_Write((pres32 >> (3 * 8)) & 0xFF);
    
    
}

void main(void) {
    
    SYSTEM_Initialize();
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1; // Enable peripheral interrupts
    TMR0_SetInterruptHandler(tmr_fire);
    TMR0_StartTimer();
    spi1_master_open(CUSTOM0);
    
    CS_BARO_SetHigh();
    __delay_ms(10);
    char tx[] = {0x60, 0xB6};
    BMP280_SPI_bus_write(0x00, 0x00, &tx, 2);

    int8_t rslt;
    bmp.dev_id  =  0;
    bmp.intf = BMP280_SPI_INTF;
    bmp.read = BMP280_SPI_bus_read;
    bmp.write = BMP280_SPI_bus_write;
    bmp.delay_ms = BMP280_delay_msek;

    rslt = bmp280_init(&bmp);
    
    struct bmp280_config conf;

    rslt = bmp280_get_config(&conf, &bmp);

    conf.filter = BMP280_FILTER_COEFF_2;
    conf.os_pres = BMP280_OS_16X;
    conf.os_temp = BMP280_OS_1X;
    conf.odr = BMP280_ODR_0_5_MS;

    rslt = bmp280_set_config(&conf, &bmp);
    /* Check if rslt == BMP280_OK, if not, then handle accordingly */
    rslt = bmp280_get_config(&conf, &bmp);
    /* Always set the power mode after setting the configuration */
    rslt = bmp280_set_power_mode(BMP280_NORMAL_MODE, &bmp);
    /* Check if rslt == BMP280_OK, if not, then handle accordingly */
    rslt = bmp280_get_config(&conf, &bmp);
    
    while(1){
        
    }
    
    
    return;
}
