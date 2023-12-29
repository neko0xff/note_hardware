/* add user code begin Header */
/**
  **************************************************************************
  * @file     main.c
  * @brief    main program
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */
/* add user code end Header */

/* Includes ------------------------------------------------------------------*/
#include "at32f423_wk_config.h"

/* private includes ----------------------------------------------------------*/
/* add user code begin private includes */
#include "stdio.h"
#include "at32f423_conf.h"
#include "at32f423_board.h"
#include "at32f423_clock.h"
/* add user code end private includes */

/* private typedef -----------------------------------------------------------*/
/* add user code begin private typedef */

/* add user code end private typedef */

/* private define ------------------------------------------------------------*/
/* add user code begin private define */
#define DELAY                            100
#define FAST                             1
#define SLOW                             4

/* add user code end private define */

/* private macro -------------------------------------------------------------*/
/* add user code begin private macro */

/* add user code end private macro */

/* private variables ---------------------------------------------------------*/
/* add user code begin private variables */
uint8_t g_speed = 1;
/* add user code end private variables */

/* private function prototypes --------------------------------------------*/
/* add user code begin function prototypes */

/* add user code end function prototypes */

/* private user code ---------------------------------------------------------*/
/* add user code begin 0 */

void UART_init(void){
	 uart_print_init(115200); //鮑率: 115200bps
	 printf("UART(Serial Port): Is Start \r\n");
}
void LED_runtime1(void){
	printf("Task: LED_runtime1() \r\n");
	printf("LED: LED4(Green) ON \r\n");
	gpio_bits_toggle(LED2_GPIO_PORT,LED2_PIN);
	delay_ms(2000);
	printf("LED: LED3(Orange) ON \r\n");
	gpio_bits_toggle(LED3_GPIO_PORT,LED3_PIN);
	delay_ms(2000);
	printf("LED: LED2(RED) ON \r\n");
	gpio_bits_toggle(LED4_GPIO_PORT,LED4_PIN);
	delay_ms(2000);
}
void LED_runtime2(void){
	printf("Task: LED_runtime2() \r\n");
	printf("LED: LED2(RED) ON \r\n");
	gpio_bits_toggle(LED4_GPIO_PORT,LED4_PIN);
	delay_ms(2000);
	printf("LED: LED3(Orange) ON \r\n");
	gpio_bits_toggle(LED3_GPIO_PORT,LED3_PIN);
	delay_ms(2000);
	printf("LED: LED4(Green) ON \r\n");
	gpio_bits_toggle(LED2_GPIO_PORT,LED2_PIN);
	delay_ms(2000);
}
void LED_OFFALL(void){
	printf("Task: Clear ALL GPIO \r\n");
	gpio_bits_reset(LED2_GPIO_PORT,LED2_PIN);
	gpio_bits_reset(LED3_GPIO_PORT,LED3_PIN);
	gpio_bits_reset(LED4_GPIO_PORT,LED4_PIN);
}

/* add user code end 0 */


/**
  * @brief  take some delay for waiting power stable, delay is about 60ms with frequency 8MHz.
  * @param  none
  * @retval none
  */
static void wk_wait_for_power_stable(void)
{
  volatile uint32_t delay = 0;
  for(delay = 0; delay < 50000; delay++);
}

/**
  * @brief main function.
  * @param  none
  * @retval none
  */
int main(void)
{
  /* add user code begin 1 */

  /* 初始化需要的服務 */
  delay_init();
  UART_init();

  /* add user code end 1 */

  /* add a necessary delay to ensure that Vdd is higher than the operating
     voltage of battery powered domain (2.57V) when the battery powered 
     domain is powered on for the first time and being operated. */
  wk_wait_for_power_stable();
  
  /* system clock config. */
  wk_system_clock_config();

  /* config periph clock. */
  wk_periph_clock_config();

  /* nvic config. */
  wk_nvic_config();

  /* init usart1 function. */
  wk_usart1_init();

  /* init exint function. */
  wk_exint_config();

  /* init gpio function. */
  wk_gpio_config();

  /* init tmr1 function. */
  wk_tmr1_init();

  /* add user code begin 2 */

  /* add user code end 2 */

  while(1)
  {
    /* add user code begin 3 */
	  LED_runtime1();
	  //LED_OFFALL();
	  LED_runtime2();
    /* add user code end 3 */
  }
}
