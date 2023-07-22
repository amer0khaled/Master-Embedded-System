
/*
startup_cortex_m3.s
Eng: Amer Khaled
*/



.section .vectors

.word 0x20001000        /*put stack top address at the entry point of cortex-m3*/

/*interrupt vector table*/

.word    _reset               /*1 Reset */
.word    _vector_handler      /*2 NMI */
.word    _vector_handler      /*3 HardfFault */
.word    _vector_handler      /*4 MemManage */
.word    _vector_handler      /*5 BusFault */
.word    _vector_handler      /*6 UsageFault */
.word    _vector_handler      /*7 Reserved */
.word    _vector_handler      /*8 SVCCall */
.word    _vector_handler      /*9 DebugMonitor */
.word    _vector_handler      /*10 Reserved */
.word    _vector_handler      /*11 PendSV */
.word    _vector_handler      /*12 SysTick */
.word    _vector_handler      /*13 WWDG */
.word    _vector_handler      /*14 PVD */
.word    _vector_handler      /*15 TAMPER */
.word    _vector_handler      /*16 RTC */
.word    _vector_handler      /*17 FLASH */
.word    _vector_handler      /*18 RCC */
.word    _vector_handler      /*19 EXTI0 */
.word    _vector_handler      /*20 EXTI1 */
.word    _vector_handler      /*21 EXTI2 */ 



.section .text

_reset:
	bl main
	b .
		
.thumb_func		/*TO ENABLE 16 BIT INSTRUCTIONS*/
	
_vector_handler:
	b _reset
	