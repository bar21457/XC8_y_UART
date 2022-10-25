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

#define _XTAL_FREQ 8000000

//******************************************************************************
// Variables
//******************************************************************************

//char A;

int c = 12;
int i;

char letra;
char cadena[] = {'H', 'o', 'l', 'a', ' ', 'M', 'u', 'n', 'd', 'o'};

//******************************************************************************
// Prototipos de Funciones
//******************************************************************************

void setup(void);
void initUART(void);
void Hola_Mundo(void);

//******************************************************************************
// Interrupciones
//******************************************************************************
//void __interrupt() isr (void){}

//******************************************************************************
// Código Principal
//******************************************************************************
void main(void) {
    
    setup();
    initUART();
    
    //A = 'A';
    //PORTB = A;
            
    while(1){
        
        //PreLab
        
//        if(TXSTAbits.TRMT == 1){
//        TXREG = PORTB;
//
//        }
//        if(PIR1bits.RCIF == 1){
//        PORTD = RCREG;
//        PIR1bits.RCIF = 0;
//        }
//        __delay_ms(500);
        
        //Lab
        
        Hola_Mundo();
        
        if(TXSTAbits.TRMT == 1)
        {
            TXREG = PORTB;
        }
        
        if(PIR1bits.RCIF == 1)
        {
            PORTD = RCREG;
            PIR1bits.RCIF = 0;
        }
    
        __delay_ms(100);
            
    }
    return;
}

//******************************************************************************
// Funciones
//******************************************************************************
void setup (void){
    
    ANSELH = 0;
    
    TRISB = 0;              //Configuración del PORTB como output
    TRISD = 0;              //Configuración del PORTD como output
    
    PORTB = 0;              //Limpiamos el PORTB
    PORTD = 0;              //Limpiamos el PORTD
    
    // Configuración del Oscilador Interno a 8MHz
    
    OSCCONbits.IRCF = 0b111 ;   // Selección de los 8MHz
    OSCCONbits.SCS = 1;         // Selección del Oscilador Interno

    INTCONbits.GIE = 1;         // Habilitamos las interrupciones globales
    PIE1bits.RCIE = 1; 
    
}
    
void initUART(void){
    
    // Paso 1: Configuramos la velocidad del Baud Rate
    
    SPBRG = 12;
    
    // Paso 2: Habilitamos el puerto serial asíncrono
    
    TXSTAbits.SYNC = 0;         // Trabajaremos de forma asincrona
    RCSTAbits.SPEN = 1;         // Habilitamos el UART
    
    // Paso 3: Se salta porque no usamos 9 bits
    
    // Paso 4: Habilitamos la transmisión
    
    TXSTAbits.TXEN = 1;         // Habilitamos la transmision y la interrupción
    
    PIR1bits.TXIF = 0;          
    
    RCSTAbits.CREN = 1;         // Habilitamos la recepción
    
    PIR1bits.RCIF = 0;
}

void Hola_Mundo(void){

    if (c == 12)
        {
            c = 0;
        }
        
        else
        {
            c++;
        }
        
        for (int i = 0; i < 10; i++)
        {
            if (c <= 10)
            {       
                PORTB = cadena[c];
            }
            
            if (c == 11)
            {
                PORTB = 10;
            }
            
            if (c == 12)
            {
                PORTB = 13;
            }
            
            else{}
        }
}