/*
 * File:   main.c
 * Author: Ahmet
 *
 * Created on 12 Aral?k 2023 Sal?, 22:25
 */

// PIC16F877 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF        // FLASH Program Memory Write Enable (Unprotected program memory may not be written to by EECON control)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>

// Tan?mlamalar
#define BUTTON1 RB0 // Birinci buton
#define BUTTON2 RB1 // ikinci buton
#define MOTOR_PIN1 RC0 // Motorun birinci kontrol pini
#define MOTOR_PIN2 RC1 // Motorun ikinci kontrol pini
#define _XTAL_FREQ 8000000


void main() {
    // Giri? ve ç?k?? pinlerini ayarlar
    TRISB0 = 1; // RB0 ve RB1 giri? pinleri
    TRISB1 = 1;
    TRISC0 = 0; // RC0 ve RC1 ç?k?? pinleri
    TRISC1 = 0;

    MOTOR_PIN1 = 0; // Ba?lang?çta motor durdurulmu? olarak ayarlan?r
    MOTOR_PIN2 = 0;

    while(1) {
        if(BUTTON1 == 1) { // Birinci butona bas?ld???nda
            MOTOR_PIN1 = 1; // Motor bir yönde döner
            MOTOR_PIN2 = 0;
            __delay_ms(100);
        } else if(BUTTON2 == 1) { // ?kinci butona bas?ld???nda
            MOTOR_PIN1 = 0; // Motor di?er yönde döner
            MOTOR_PIN2 = 1;
            __delay_ms(100); 
        } else if (BUTTON1 == 1 && BUTTON2 == 1){
            MOTOR_PIN1 = 0;
            MOTOR_PIN2 = 0;
        } else {
            MOTOR_PIN1 = 0;
            MOTOR_PIN2 = 0;
        }
    }
}
