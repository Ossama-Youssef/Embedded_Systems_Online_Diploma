/**
 ******************************************************************************
 * @file           : startup.s
 * @author         : Osama Youssef
 * @brief          : Startup.s is an assembly file to handle the stack pointer 
 *                    _entry point_ and vector section for arm cortex m3 mcu 
 *****************************************************************************
 **/

 .section .vectors 
 .word 0x20001000                           /*   Stack top address   */
 .word _reset                               /*     1 Reset -> main   */  
 .word _vector_handler                      /*     2 NMI             */
 .word _vector_handler                      /*     3 Hard Fault      */
 .word _vector_handler                      /*     4 MM Fault        */
 .word _vector_handler                      /*     5 Bus Fault       */ 
 .word _vector_handler                      /*     6 Usage Fault     */ 
 .word _vector_handler                      /*     7 RESEVED         */
 .word _vector_handler                      /*     8 RESEVED         */
 .word _vector_handler                      /*     9 RESEVED         */
 .word _vector_handler                      /*    10 RESEVED         */
 .word _vector_handler                      /*    11 SV Call         */ 
 .word _vector_handler                      /*    12 Debug Reseved   */ 
 .word _vector_handler                      /*    13 RESEVED         */ 
 .word _vector_handler                      /*    14 PendSV          */  
 .word _vector_handler                      /*    15 sysTick         */  
 .word _vector_handler                      /*    16 IRQ0            */ 
 .word _vector_handler                      /*    17 IRQ1            */ 
 .word _vector_handler                      /*    18 IRQ2            */ 
 .word _vector_handler                      /*    19 IRQ3            */ 
 .word _vector_handler                      /*    20 IRQ4            */ 
 .word _vector_handler                      /*    21 IRQ5            */ 
 .word _vector_handler                      /*    22 IRQ6            */ 
 .word _vector_handler                      /*    23 IRQ7            */  

                      
.section .text 
 _reset:
    bl main 
    b . 
.thumb_func 
_vector_handler:
    b _reset