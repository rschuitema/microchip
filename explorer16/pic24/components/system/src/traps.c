/*******************************************************************************
    Description      : implementation of the oscillator interface 
*******************************************************************************/
/*******************************************************************************
*                          Include files
*******************************************************************************/
#include <stdint.h>
#include "processor.h"
#include "oscillator.h"

/*******************************************************************************
*                          Macro definitions
*******************************************************************************/
#define TRAP __attribute__((interrupt,no_auto_psv,noreturn))
#define FAILSAFE_STACK_GUARDSIZE (8)

/*******************************************************************************
*                          Type definitions
*******************************************************************************/

/**
 * Error codes
 */
typedef enum 
{
    TRAP_OSC_FAIL = 0,   /** Oscillator Fail Trap Vector */
    TRAP_STACK_ERR,      /** Stack Error Trap Vector */
    TRAP_ADDRESS_ERR,    /** Address Error Trap Vector */
    TRAP_MATH_ERR,       /** Math Error Trap Vector */
} TrapCode_t;

/*******************************************************************************
*                          Static function prototypes
*******************************************************************************/
static void __attribute__((naked, noreturn)) trap_halt_on_error(uint16_t code);
inline static void use_failsafe_stack(void);

/*******************************************************************************
*                          Static data definitions
*******************************************************************************/
static uint16_t trap_code = -1;

/*******************************************************************************
*                          Extern function definitions
*******************************************************************************/
void TRAP _MathError(void)
{
    INTCON1bits.MATHERR = 0;  //Clear the trap flag
    trap_halt_on_error(TRAP_MATH_ERR);
}

void TRAP _AddressError(void)
{
    INTCON1bits.ADDRERR = 0;  //Clear the trap flag
    trap_halt_on_error(TRAP_ADDRESS_ERR);
}

void TRAP _StackError(void)
{
    while(1);
}

void TRAP _OscillatorFail(void)
{
    INTCON1bits.OSCFAIL = 0;  //Clear the trap flag
    trap_halt_on_error(TRAP_OSC_FAIL);
}

/*******************************************************************************
*                          Static function definitions
*******************************************************************************/
/**
 * Sets the stack pointer to a backup area of memory, in case we run into
 * a stack error (in which case we can't really trust the stack pointer)
 */
inline static void use_failsafe_stack(void)
{
    static uint8_t failsafe_stack[32];
    asm volatile (
        "   mov    %[pstack], W15\n"
        :
        : [pstack]"r"(failsafe_stack)
    );
    
    /* Controls where the stack pointer limit is, relative to the end of the
     * failsafe stack
     */    
    SPLIM = (uint16_t)(((uint8_t *)failsafe_stack) 
            + sizeof(failsafe_stack) 
            - FAILSAFE_STACK_GUARDSIZE);
}


void __attribute__((naked, noreturn)) trap_halt_on_error(TrapCode_t code)
{
    trap_code = code;
#ifdef __DEBUG    
    __builtin_software_breakpoint();
    /* If we are in debug mode, cause a software breakpoint in the debugger */
#endif
    while(1);
}

/*******************************************************************************
*                          End of File
*******************************************************************************/
