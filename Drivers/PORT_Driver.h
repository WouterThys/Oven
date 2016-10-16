#ifndef PORT_DRIVER_H
#define	PORT_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

    // Ports for GLCD
#define GLCD_DATA       PORTD
#define GLCD_DATA_Dir   TRISD    
    
#define GLCD_CS1        PORTEbits.RE0
#define GLCD_CS2        PORTEbits.RE1
#define GLCD_CS3        PORTEbits.RE2
#define GLCD_RS         PORTBbits.RB4
#define GLCD_RW         PORTBbits.RB3
#define GLCD_RST        PORTBbits.RB5    
#define GLCD_EN         PORTBbits.RB2
    
#define GLCD_CS1_Dir    TRISEbits.TRISE0
#define GLCD_CS2_Dir    TRISEbits.TRISE1
#define GLCD_CS3_Dir    TRISEbits.TRISE2
#define GLCD_RS_Dir     TRISBbits.TRISB4
#define GLCD_RW_Dir     TRISBbits.TRISB3
#define GLCD_RST_Dir    TRISBbits.TRISB5    
#define GLCD_EN_Dir     TRISBbits.TRISB2
    
    // Ports for UART
#define UART_TX         PORTCbits.RC7
#define UART_RX         PORTCbits.RC6
    
#define UART_TX_Dir     TRISCbits.TRISC7
#define UART_RX_Dir     TRISCbits.TRISC6
    
    // Ports for SPI
#define SPI_SCK         PORTBbits.RB1
#define SPI_SDI         PORTBbits.RB0
#define SPI_SDO         PORTCbits.RC7
    
#define SPI_SCK_Dir     TRISBbits.TRISB1
#define SPI_SDI_Dir     TRISBbits.TRISB0
#define SPI_SDO_Dir     TRISCbits.TRISC7
    
#define PWM1_PIN        PORTCbits.RC2
#define PWM1_PIN_Dir    TRISCbits.TRISC2
    // Other
 /**
 * Initializes all the parameters to the default setting, as well as writing the
 * tri-state registers. Sets all ports to zero, and all tri-states to output.
 */
void D_PORT_Init();

#ifdef	__cplusplus
}
#endif

#endif	/* PORT_DRIVER */