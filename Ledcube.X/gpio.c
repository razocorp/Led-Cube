// =============================================================================
// Include statements
// =============================================================================
#include "gpio.h"
#include <xc.h>
// =============================================================================
// Private type definitions
// =============================================================================

// =============================================================================
// Global variables
// =============================================================================

// =============================================================================
// Private constants
// =============================================================================

// =============================================================================
// Private variables
// =============================================================================

// =============================================================================
// Private function declarations
// =============================================================================

// =============================================================================
// Public function definitions
// =============================================================================

void gpio_init(void){
    ANSEL = 0;
    ANSELH = 0;
    
    SHIFT_REG_LATCH_DIR = 0;
    SHIFT_REG_DATA_DIR = 0;
    SHIFT_REG_CLK_DIR = 0;
    
    SHIFT_REG_LATCH = 0;
    SHIFT_REG_DATA = 0;
    SHIFT_REG_CLK = 0;
}

// =============================================================================
// Private function definitions
// =============================================================================
