// =============================================================================
// Include statements
// =============================================================================
#include "gpio.h"
#include "timer.h"
#include "leds.h"
#include <stdint.h>
#include <stdbool.h>
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
static void setLights(uint8_t gate, uint16_t lights);
static void moveSnake(int dir);
// =============================================================================
// Public function definitions
// =============================================================================

int main(void){
    gpio_init();
    timer_init();
    leds_init();
    while(1){
        if(animation_flag){
            animation_flag = 0;
            update_animation();
        }

    };
}

// =============================================================================
// Private function definitions
// =============================================================================

/*static void moveSnake(int dir){
    
}

static void setLights(uint8_t gate, uint16_t lights){
    TRANS_GATE_1 = (0 == gate);
    TRANS_GATE_2 = (1 == gate);
    TRANS_GATE_3 = (2 == gate);
    TRANS_GATE_4 = (3 == gate);
    uint16_t a = 1;
    for(uint8_t j = 0; j != 16; ++j){
        SHIFT_REG_CLK = 0;
        SHIFT_REG_DATA = (0u != (lights & (1u << j)));
        //SHIFT_REG_DATA = ((uint16_t)0 != (uint16_t)0xffff & (uint16_t)0x0001);
        //SHIFT_REG_DATA = 1;
        SHIFT_REG_CLK = 1;
    }
    SHIFT_REG_LATCH = 1;
    SHIFT_REG_CLK = 0;
    SHIFT_REG_LATCH = 0;
}*/
