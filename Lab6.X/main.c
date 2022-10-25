/*
 * File:   main.c
 * Author: Byron Barrientos
 *
 * Created on October 25, 2022, 6:26 AM
 */

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT        // Oscillator Selection bits 
                                            // (INTOSC oscillator: I/O function 
                                            // on RA6/OSC2/CLKOUT pin, I/O 
                                            // function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and 
                                // can be enabled by SWDTEN bit of the WDTCON 
                                // register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR 
                                // pin function is digital input, MCLR 
                                // internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code 
                                // protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code 
                                // protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit 
                                // (Internal/External Switchover mode disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit 
                                // (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin 
                                // has digital I/O, HV on MCLR must be used for 
                                // programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out 
                                // Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits 
                                // (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 500000

//******************************************************************************
// Variables
//******************************************************************************



//******************************************************************************
// Prototipos de Funciones
//******************************************************************************

void setup(void);

//******************************************************************************
// Interrupciones
//******************************************************************************
void __interrupt() isr (void){

    

}

//******************************************************************************
// Código Principal
//******************************************************************************
void main(void) {
    
    setup();
    
    while(1){
        
        
        
    }
    return;
}

//******************************************************************************
// Funciones
//******************************************************************************
void setup (void){
    
    ANSELH = 0;
    
    TRISA = 0;              //Configuración del PORTA como output
    TRISB = 0;              //Configuración del PORTB como output
    TRISC = 0;              //Configuración del PORTC como output
    TRISD = 0;              //Configuración del PORTD como output
    TRISE = 0;              //Configuración del PORTE como output
    
    PORTA = 0;              //Limpiamos el PORTA
    PORTB = 0;              //Limpiamos el PORTB
    PORTC = 0;              //Limpiamos el PORTC
    PORTD = 0;              //Limpiamos el PORTD
    PORTE = 0;              //Limpiamos el PORTD
    
    // Configuración del Oscilador Interno a 500KHz
    
    OSCCONbits.IRCF = 0b011 ;   // Selección de los 500KHz
    OSCCONbits.SCS = 1;         // Selección del Oscilador Interno
    
}