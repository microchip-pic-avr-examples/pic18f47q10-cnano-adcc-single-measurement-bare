/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/*disable Watchdog*/
#pragma config WDTE = OFF
/* Low voltage programming enabled, RE3 pin is MCLR */
#pragma config LVP = ON 

#include <xc.h>
#include <stdint.h>

static void CLK_Init(void);
static void PORT_Init(void);
static void ADCC_Init(void);
static void ADCC_DischargeSampleCap(void);
static uint16_t ADCC_ReadValue(uint8_t channel);

uint16_t volatile adcVal;

static void CLK_Init(void)
{
    /* set HFINTOSC Oscillator */
    OSCCON1bits.NOSC = 6;
    /* set HFFRQ to 1 MHz */
    OSCFRQbits.HFFRQ = 0;
}

static void PORT_Init(void)
{
    /*set pin RA0 as analog*/
    ANSELAbits.ANSELA0 = 1;
    /*set pin RA0 as input*/
    TRISAbits.TRISA0 = 1;  
}

static void ADCC_Init(void)
{
    /* Enable the ADCC module */
    ADCON0bits.ADON = 1; 
    /* Select FRC clock */
    ADCON0bits.ADCS = 1;
    /* result right justified */
    ADCON0bits.ADFM = 1;
}

static void ADCC_DischargeSampleCap(void)
{
    /*channel number that connects to VSS*/
    ADPCH = 0x3C;
}

static uint16_t ADCC_ReadValue(uint8_t channel)
{   
    ADPCH = channel;
    /*start conversion*/
    ADCON0bits.ADGO = 1;
    while (ADCON0bits.ADGO)
    {
        ;
    }
        
    return ((uint16_t)((ADRESH << 8) + ADRESL));
}
 
void main(void)
{    
    CLK_Init();   
    PORT_Init();
    ADCC_Init();
    ADCC_DischargeSampleCap();
    
    /*channel number that connects to RA0*/
    adcVal = ADCC_ReadValue(0x00); 
    while(1)
    {
          ;
    }
}

