/********************************************************************************
 * @file           : linker_script.ld 
 * @author         : Osama Youssef
 * @brief          : liker script file to organise the linking process 
 *******************************************************************************/
/* Memory Types and lengthes */
MEMORY
{
    
  FLASH(RX): ORIGIN = 0X08000000 , LENGTH = 128K
  SRAM(RWX): ORIGIN = 0X20000000 , LENGTH = 20K

}


SECTIONS
{
    .text : 
    {
       *(.vectors*)
       *(.text*)
       *(.rodata)
    }> FLASH
    .data : 
    { 

       *(.data)

    }> SRAM
    .bss :
    {
       
       *(.bss)

    }> SRAM
   .comment :
   {

     *(.comment) *(COMMON)

   }> FLASH



}