/* add user code begin Header */
/**
  **************************************************************************
  * @file     at32f423_wk_config.c
  * @brief    work bench config program
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

#include "at32f423_wk_config.h"

/* private includes ----------------------------------------------------------*/
/* add user code begin private includes */
#include "at32f423_clock.h"
#include "at32f423_conf.h"
/* add user code end private includes */

/* private typedef -----------------------------------------------------------*/
/* add user code begin private typedef */

/* add user code end private typedef */

/* private define ------------------------------------------------------------*/
/* add user code begin private define */
#define USER_BUTTON_PIN GPIO_PINS_0
#define USER_BUTTON_PORT GPIOA
#define USER_BUTTON_CRM_CLK CRM_GPIOA_PERIPH_CLOCK
/* add user code end private define */

/* private macro -------------------------------------------------------------*/
/* add user code begin private macro */

/* add user code end private macro */

/* private variables ---------------------------------------------------------*/
/* add user code begin private variables */

/* add user code end private variables */

/* private function prototypes --------------------------------------------*/
/* add user code begin function prototypes */

/* add user code end function prototypes */

/* private user code ---------------------------------------------------------*/
/* add user code begin 0 */

/* add user code end 0 */

/**
  * @brief  system clock config program
  * @note   the system clock is configured as follow:
  *         system clock (sclk)   = (hick / 12 * pll_ns)/(pll_ms * pll_fr)
  *         system clock source   = pll (hick)
  *         - lick                = on
  *         - lext                = off
  *         - hick                = on
  *         - hext                = off
  *         - hext                = HEXT_VALUE
  *         - sclk                = 150000000
  *         - ahbdiv              = 1
  *         - ahbclk              = 150000000
  *         - apb1div             = 2
  *         - apb1clk             = 75000000
  *         - apb2div             = 1
  *         - apb2clk             = 150000000
  *         - pll_ns              = 75
  *         - pll_ms              = 1
  *         - pll_fr              = 2
  * @param  none
  * @retval none
  */
void wk_system_clock_config(void)
{
  /* reset crm */
  crm_reset();

  /* config flash psr register */
  flash_psr_set(FLASH_WAIT_CYCLE_4);

  /* enable pwc periph clock */
  crm_periph_clock_enable(CRM_PWC_PERIPH_CLOCK, TRUE);
  
  /* config ldo voltage */
  pwc_ldo_output_voltage_set(PWC_LDO_OUTPUT_1V3);

  /* enable lick */
  crm_clock_source_enable(CRM_CLOCK_SOURCE_LICK, TRUE);

  /* wait till lick is ready */
  while(crm_flag_get(CRM_LICK_STABLE_FLAG) != SET)
  {
  }

  /* enable hext */
  crm_clock_source_enable(CRM_CLOCK_SOURCE_HEXT, TRUE);

  /* wait till hext is ready */
  while(crm_hext_stable_wait() == ERROR)
  {
  }

  /* enable hick */
  crm_clock_source_enable(CRM_CLOCK_SOURCE_HICK, TRUE);

  /* wait till hick is ready */
  while(crm_flag_get(CRM_HICK_STABLE_FLAG) != SET)
  {
  }

  /* config pll clock resource
  common frequency config list: pll source selected  hick or hext(8mhz)
  _____________________________________________________________________________
  |        |         |         |         |         |         |        |        |
  | sysclk |   150   |   144   |   120   |   108   |   96    |   72   |   36   |
  |________|_________|_________|_________|_________|_________|_________________|
  |        |         |         |         |         |         |        |        |
  |pll_ns  |   75    |   72    |   120   |   108   |   96    |   72   |   72   |
  |        |         |         |         |         |         |        |        |
  |pll_ms  |   1     |   1     |   1     |   1     |   1     |   1    |   1    |
  |        |         |         |         |         |         |        |        |
  |pll_fr  |   FR_2  |   FR_2  |   FR_4  |   FR_4  |   FR_4  |   FR_4 |   FR_8 |
  |________|_________|_________|_________|_________|_________|________|________|

  if pll clock source selects hext with other frequency values, or configure pll to other
  frequency values, please use the at32 new clock  configuration tool for configuration. */
  crm_pll_config(CRM_PLL_SOURCE_HICK, 75, 1, CRM_PLL_FR_2);

  /* enable pll */
  crm_clock_source_enable(CRM_CLOCK_SOURCE_PLL, TRUE);

  /* wait till pll is ready */
  while(crm_flag_get(CRM_PLL_STABLE_FLAG) != SET)
  {
  }

  /* config ahbclk */
  crm_ahb_div_set(CRM_AHB_DIV_1);

  /* config apb2clk, the maximum frequency of APB2 clock is 150 MHz  */
  crm_apb2_div_set(CRM_APB2_DIV_1);

  /* config apb1clk, the maximum frequency of APB1 clock is 120 MHz  */
  crm_apb1_div_set(CRM_APB1_DIV_2);

  /* enable auto step mode */
  crm_auto_step_mode_enable(TRUE);

  /* select pll as system clock source */
  crm_sysclk_switch(CRM_SCLK_PLL);

  /* wait till pll is used as system clock source */
  while(crm_sysclk_switch_status_get() != CRM_SCLK_PLL)
  {
  }

  /* disable auto step mode */
  crm_auto_step_mode_enable(FALSE);

  /* update system_core_clock global variable */
  system_core_clock_update();
}

/**
  * @brief  config periph clock
  * @param  none
  * @retval none
  */
void wk_periph_clock_config(void)
{
  /* enable gpioa periph clock */
  crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);

  /* enable gpiob periph clock */
  crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);

  /* enable gpiod periph clock */
  crm_periph_clock_enable(CRM_GPIOD_PERIPH_CLOCK, TRUE);

  /* enable gpiof periph clock */
  crm_periph_clock_enable(CRM_GPIOF_PERIPH_CLOCK, TRUE);

  /* enable tmr1 periph clock */
  crm_periph_clock_enable(CRM_TMR1_PERIPH_CLOCK, TRUE);

  /* enable usart1 periph clock */
  crm_periph_clock_enable(CRM_USART1_PERIPH_CLOCK, TRUE);

  /* enable scfg periph clock */
  crm_periph_clock_enable(CRM_SCFG_PERIPH_CLOCK, TRUE);
}

/**
  * @brief  nvic config
  * @param  none
  * @retval none
  */
void wk_nvic_config(void)
{
  nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);

  nvic_irq_enable(EXINT0_IRQn, 0, 0);
}

/**
  * @brief  init gpio_input/gpio_output/gpio_analog/eventout function.
  * @param  none
  * @retval none
  */
void wk_gpio_config(void)
{
  gpio_init_type gpio_init_struct;
  gpio_default_para_init(&gpio_init_struct);

  /* gpio output config */
  gpio_bits_set(GPIOD, LED2_PIN | LED3_PIN | LED4_PIN);

  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
  gpio_init_struct.gpio_pins = LED2_PIN | LED3_PIN | LED4_PIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOD, &gpio_init_struct);
}

/**
  * @brief  init exint function.
  * @param  none
  * @retval none
  */
void wk_exint_config(void)
{
  gpio_init_type gpio_init_struct;
  exint_init_type exint_init_struct; // @suppress("Type cannot be resolved")

  /* configure the EXINT0 */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = USER_BUTTON_PIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOA, &gpio_init_struct);

  scfg_exint_line_config(SCFG_PORT_SOURCE_GPIOA, SCFG_PINS_SOURCE0); // @suppress("Symbol is not resolved")

  exint_default_para_init(&exint_init_struct);
  exint_init_struct.line_enable = TRUE;
  exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
  exint_init_struct.line_select = EXINT_LINE_0;
  exint_init_struct.line_polarity = EXINT_TRIGGER_RISING_EDGE;
  exint_init(&exint_init_struct);

  /**
   * Users need to configure EXINT0 interrupt functions according to the actual application.
   * 1. Call the below function to enable the corresponding EXINT0 interrupt.
   *     --exint_interrupt_enable(EXINT_LINE_0, TRUE);
   * 2. Add the user's interrupt handler code into the below function in the at32f423_int.c file.
   *     --void EXINT0_IRQHandler(void)
   */
}

/**
  * @brief  init usart1 function
  * @param  none
  * @retval none
  */
void wk_usart1_init(void)
{
  /* add user code begin usart1_init 0 */

  /* add user code end usart1_init 0 */

  gpio_init_type gpio_init_struct;
  gpio_default_para_init(&gpio_init_struct);

  /* add user code begin usart1_init 1 */

  /* add user code end usart1_init 1 */

  /* configure the TX pin */
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_pins = GPIO_PINS_9;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOA, &gpio_init_struct);

  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE9, GPIO_MUX_7);

  /* configure the RX pin */
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_pins = GPIO_PINS_10;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOA, &gpio_init_struct);

  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE10, GPIO_MUX_7);

  /* configure the CK pin */
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_pins = GPIO_PINS_8;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOA, &gpio_init_struct);

  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE8, GPIO_MUX_7);

  /* configure param */
  usart_init(USART1, 115200, USART_DATA_8BITS, USART_STOP_1_BIT);
  usart_transmitter_enable(USART1, TRUE);
  usart_receiver_enable(USART1, TRUE);
  usart_parity_selection_config(USART1, USART_PARITY_NONE);
  usart_clock_config(USART1, USART_CLOCK_POLARITY_LOW, USART_CLOCK_PHASE_1EDGE, USART_CLOCK_LAST_BIT_NONE);
  usart_clock_enable(USART1, TRUE);

  usart_enable(USART1, TRUE);

  /* add user code begin usart1_init 2 */

  /* add user code end usart1_init 2 */
}

/**
  * @brief  init tmr1 function.
  * @param  none
  * @retval none
  */
void wk_tmr1_init(void)
{
  /* add user code begin tmr1_init 0 */

  /* add user code end tmr1_init 0 */


  /* add user code begin tmr1_init 1 */

  /* add user code end tmr1_init 1 */

  /* configure counter settings */
  tmr_base_init(TMR1, 65535, 0);
  tmr_cnt_dir_set(TMR1, TMR_COUNT_UP);
  tmr_clock_source_div_set(TMR1, TMR_CLOCK_DIV1);
  tmr_repetition_counter_set(TMR1, 0);
  tmr_period_buffer_enable(TMR1, FALSE);

  /* configure primary mode settings */
  tmr_sub_sync_mode_set(TMR1, FALSE);
  tmr_primary_mode_select(TMR1, TMR_PRIMARY_SEL_RESET);

  tmr_counter_enable(TMR1, TRUE);

  /* add user code begin tmr1_init 2 */

  /* add user code end tmr1_init 2 */
}

/* add user code begin 1 */

/* add user code end 1 */
