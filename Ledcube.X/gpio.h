#ifndef GPIO_H
#define	GPIO_H


// =============================================================================
// Include statements
// =============================================================================
#include <xc.h>
// =============================================================================
// Public type definitions
// =============================================================================

// =============================================================================
// Global variable declarations
// =============================================================================
    
// =============================================================================
// Global constatants
// =============================================================================
#define SHIFT_REG_LATCH_DIR             TRISCbits.TRISC5
#define SHIFT_REG_DATA_DIR              TRISCbits.TRISC7
#define SHIFT_REG_CLK_DIR               TRISBbits.TRISB6

#define SHIFT_REG_LATCH                 PORTCbits.RC5
#define SHIFT_REG_DATA                  PORTCbits.RC7
#define SHIFT_REG_CLK                   PORTBbits.RB6 

#define TRANS_GATE_1_DIR                TRISCbits.TRISC0
#define TRANS_GATE_2_DIR                TRISCbits.TRISC1
#define TRANS_GATE_3_DIR                TRISCbits.TRISC2
#define TRANS_GATE_4_DIR                TRISBbits.TRISB4

#define TRANS_GATE_1                    PORTCbits.RC0
#define TRANS_GATE_2                    PORTCbits.RC1
#define TRANS_GATE_3                    PORTCbits.RC2
#define TRANS_GATE_4                    PORTBbits.RB4
    
// =============================================================================
// Public function declarations
// =============================================================================

void gpio_init(void);
    
#endif /* HEADER_TEMPLATE_H */