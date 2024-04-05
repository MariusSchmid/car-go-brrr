/*
 * File:   main.c
 * Author: Marius
 *
 * Created on 1. April 2024, 17:12
 */
// CONFIG
#pragma config FOSC = INTRCIO // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF     // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF    // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF    // GP3/MCLR pin function select (GP3/MCLR pin function is MCLR)
#pragma config BOREN = OFF    // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF       // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF      // Data Code Protection bit (Data memory code protection is disabled)

#define _XTAL_FREQ 4000000
#include <xc.h>

#define WAIT_UNTIL_TRIGGER_S 40
#define ACTIVE_RELAIS_TIME_S 1

void main(void)
{
    TRISIO = 0x00; // make all GPIOs as output
    GP5 = 0; //set GPIO LOW

    for (uint8_t i = 0; i < WAIT_UNTIL_TRIGGER_S; i++)
    {
        __delay_ms(1000);
    }
    GP5 = 1; //set GPIO HIGH
    for (uint8_t i = 0; i < ACTIVE_RELAIS_TIME_S; i++)
    {
        __delay_ms(1000);
    }
    GP5 = 0; //set GPIO LOW
    //Endless loop
    while (1)
    {
        __delay_ms(500);
    }
}
