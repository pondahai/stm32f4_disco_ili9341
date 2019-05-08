/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_host.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "arm_math.h"
#include "ili9341.h"
//#include "ili9341_touch.h"
#include "fonts.h"
#include "testimg.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

I2S_HandleTypeDef hi2s3;

SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2S3_Init(void);
static void MX_SPI1_Init(void);
void MX_USB_HOST_Process(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void lcd_init() {
    ILI9341_Unselect();
    ILI9341_Init();
}
void lcd_loop() {
    if(HAL_SPI_DeInit(&hspi1) != HAL_OK) {
//        UART_Printf("HAL_SPI_DeInit failed!\r\n");
        return;
    }

//    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;

    if(HAL_SPI_Init(&hspi1) != HAL_OK) {
//        UART_Printf("HAL_SPI_Init failed!\r\n");
        return;
    }

    // Check border
    ILI9341_FillScreen(ILI9341_BLACK);

//    for(int x = 0; x < ILI9341_WIDTH; x++) {
//        ILI9341_DrawPixel(x, 0, ILI9341_RED);
//        ILI9341_DrawPixel(x, ILI9341_HEIGHT-1, ILI9341_RED);
//    }
//
//    for(int y = 0; y < ILI9341_HEIGHT; y++) {
//        ILI9341_DrawPixel(0, y, ILI9341_RED);
//        ILI9341_DrawPixel(ILI9341_WIDTH-1, y, ILI9341_RED);
//    }

//    HAL_Delay(3000);

    // Check fonts
//    ILI9341_FillScreen(ILI9341_BLACK);
//    ILI9341_WriteString(0, 0, "Font_7x10, red on black, lorem ipsum dolor sit amet", Font_7x10, ILI9341_RED, ILI9341_BLACK);
//    ILI9341_WriteString(0, 3*10, "Font_11x18, green, lorem ipsum dolor sit amet", Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
//    ILI9341_WriteString(0, 3*10+3*18, "Font_16x26, blue, lorem ipsum dolor sit amet", Font_16x26, ILI9341_BLUE, ILI9341_BLACK);

//    HAL_Delay(1000);
//    ILI9341_InvertColors(true);
//    HAL_Delay(1000);
//    ILI9341_InvertColors(false);

//    HAL_Delay(5000);

    // Check colors
//    ILI9341_FillScreen(ILI9341_WHITE);
//    ILI9341_WriteString(0, 0, "WHITE", Font_11x18, ILI9341_BLACK, ILI9341_WHITE);
//    HAL_Delay(500);
//
//    ILI9341_FillScreen(ILI9341_BLUE);
//    ILI9341_WriteString(0, 0, "BLUE", Font_11x18, ILI9341_BLACK, ILI9341_BLUE);
//    HAL_Delay(500);
//
//    ILI9341_FillScreen(ILI9341_RED);
//    ILI9341_WriteString(0, 0, "RED", Font_11x18, ILI9341_BLACK, ILI9341_RED);
//    HAL_Delay(500);
//
//    ILI9341_FillScreen(ILI9341_GREEN);
//    ILI9341_WriteString(0, 0, "GREEN", Font_11x18, ILI9341_BLACK, ILI9341_GREEN);
//    HAL_Delay(500);
//
//    ILI9341_FillScreen(ILI9341_CYAN);
//    ILI9341_WriteString(0, 0, "CYAN", Font_11x18, ILI9341_BLACK, ILI9341_CYAN);
//    HAL_Delay(500);
//
//    ILI9341_FillScreen(ILI9341_MAGENTA);
//    ILI9341_WriteString(0, 0, "MAGENTA", Font_11x18, ILI9341_BLACK, ILI9341_MAGENTA);
//    HAL_Delay(500);
//
//    ILI9341_FillScreen(ILI9341_YELLOW);
//    ILI9341_WriteString(0, 0, "YELLOW", Font_11x18, ILI9341_BLACK, ILI9341_YELLOW);
//    HAL_Delay(500);
//
//    ILI9341_FillScreen(ILI9341_BLACK);
//    ILI9341_WriteString(0, 0, "BLACK", Font_11x18, ILI9341_WHITE, ILI9341_BLACK);
//    HAL_Delay(500);

//    ILI9341_DrawImage((ILI9341_WIDTH - 240) / 2, (ILI9341_HEIGHT - 240) / 2, 240, 240, (const uint16_t*)test_img_240x240);
//
//    HAL_Delay(3000);

//    char str[8];
//    for(long i=0;i<2000;i++)
//    {
    /*
    	ILI9341_FillRectangle( \
    			rand()%ILI9341_WIDTH, \
				rand()%ILI9341_HEIGHT, \
				rand()%ILI9341_WIDTH, \
				rand()%ILI9341_HEIGHT, \
				ILI9341_COLOR565(rand()%255,rand()%255,rand()%255));
				*/
//    	sprintf(str,"%ld ",i);
//    	ILI9341_WriteString(0, 0, str, Font_7x10, ILI9341_RED, ILI9341_BLACK);
//    }
//    for(long i=0;i<100;i++)
//    {
    /*
    	ILI9341_DrawLine( \
    			rand()%ILI9341_WIDTH, \
				rand()%ILI9341_HEIGHT, \
				rand()%ILI9341_WIDTH, \
				rand()%ILI9341_HEIGHT, \
				ILI9341_COLOR565(rand()%255,rand()%255,rand()%255));
				*/
//    	sprintf(str,"%ld ",i);
//    	ILI9341_WriteString(0, 0, str, Font_7x10, ILI9341_RED, ILI9341_BLACK);
//    }


//    float waveform[320];
//  for(int timescale=2;timescale<16;timescale+=2)
//  {
//    for(int i=0;i<320;i++)
//    {
//    	waveform[i] = 120*sin(timescale*3.14/320*i)+120;
//    }
//    for(int x=0;x<320;x++)
//    {
//    	ILI9341_DrawPixel(x,waveform[x],ILI9341_COLOR565(255,0,0));
//    }
//  }

    int FFT_SIZE = 256;
    float Inputbuf[1024];
    arm_cfft_radix4_instance_f32 Base4fft;
    float32_t maxValue;                /* Max FFT value is stored here */
    uint32_t maxIndex;                /* Index in Output array where max value is */
    //float Inputdata[1024];
    float Outputdata[1024];
    float Fs=256.0;
  for(int c=1;c<20;c++){
	  int k = (c<10)?c:(20-c);
//	  ILI9341_FillScreen(ILI9341_BLACK);
    for(int i=0;i<FFT_SIZE;i++)
    {
       Inputbuf[2*i]=120+
      .1*120*arm_sin_f32(2*PI*k*i/Fs)+
      .3*120*arm_sin_f32(2*PI*k*4*i/Fs)+
      .5*120*arm_sin_f32(2*PI*k*8*i/Fs);
      Inputbuf[2*i+1]=0;
    }
    float old_y;
    for(int x=0;x<FFT_SIZE;x++)
    {
    	float y = 240-Inputbuf[x*2];
    	if(x == 0){
  	  ILI9341_DrawPixel(x,y,ILI9341_COLOR565(255,0,0));
    	}else{
    		ILI9341_DrawLine(x,y,x-1,old_y,ILI9341_COLOR565(0,255,0));
    	}
    	old_y = y;
    }
    for(int x=0;x<FFT_SIZE;x++)
    {
    	float y = 240-Inputbuf[x*2];
    	if(x == 0){
  	  ILI9341_DrawPixel(x,y,ILI9341_COLOR565(255,0,0));
    	}else{
    		ILI9341_DrawLine(x,y,x-1,old_y,ILI9341_COLOR565(0,0,0));
    	}
    	old_y = y;
    }
      arm_cfft_radix4_init_f32(&Base4fft,FFT_SIZE,0,1);
      arm_cfft_radix4_f32(&Base4fft,Inputbuf);
      arm_cmplx_mag_f32(Inputbuf,Outputdata,FFT_SIZE);
      arm_max_f32(Outputdata, FFT_SIZE, &maxValue, &maxIndex);

      for(int x=0;x<FFT_SIZE;x++)
      {
    	  float y = 240-Outputdata[x]*(240/maxValue);
    	if(x==0){
    	  ILI9341_DrawPixel(x,y,ILI9341_COLOR565(0,255,0));
    	}else{
    		ILI9341_DrawLine(x,y,x-1,old_y,ILI9341_COLOR565(255,0,0));
    	}
    	  old_y = y;
      }

      for(int x=0;x<FFT_SIZE;x++)
      {
    	  float y = 240-Outputdata[x]*(240/maxValue);
    	if(x==0){
    	  ILI9341_DrawPixel(x,y,ILI9341_COLOR565(0,255,0));
    	}else{
    		ILI9341_DrawLine(x,y,x-1,old_y,ILI9341_COLOR565(0,0,0));
    	}
    	  old_y = y;
      }
      HAL_Delay(100);
 }
//    HAL_Delay(6000);
//    ILI9341_FillScreen(ILI9341_BLACK);
//    ILI9341_WriteString(0, 0, "Touchpad test.  Draw something!", Font_11x18, ILI9341_WHITE, ILI9341_BLACK);
//    HAL_Delay(1000);
//    ILI9341_FillScreen(ILI9341_BLACK);

    if(HAL_SPI_DeInit(&hspi1) != HAL_OK) {
//        UART_Printf("HAL_SPI_DeInit failed!\r\n");
        return;
    }

//    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;

    if(HAL_SPI_Init(&hspi1) != HAL_OK) {
//        UART_Printf("HAL_SPI_Init failed!\r\n");
        return;
    }

}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_I2S3_Init();
  MX_SPI1_Init();
  MX_USB_HOST_Init();
  /* USER CODE BEGIN 2 */
  /*
   * ILI9341 pin assignments
   * rst : pe10
   * cs  : pe11
   * dc  : pe12
   * mosi: pa7
   * miso: pa6
   * sck : pa5
   */
  lcd_init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin , GPIO_PIN_SET);
	  HAL_Delay(300);
	  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin , GPIO_PIN_RESET);
	  HAL_Delay(300);
	  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin , GPIO_PIN_SET);
	  HAL_Delay(300);
	  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin , GPIO_PIN_RESET);
	  HAL_Delay(300);
	  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin , GPIO_PIN_SET);
	  HAL_Delay(300);
	  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin , GPIO_PIN_RESET);
	  HAL_Delay(300);

    /* USER CODE END WHILE */
    MX_USB_HOST_Process();

    /* USER CODE BEGIN 3 */
    lcd_loop();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2S;
  PeriphClkInitStruct.PLLI2S.PLLI2SN = 192;
  PeriphClkInitStruct.PLLI2S.PLLI2SR = 2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2S3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2S3_Init(void)
{

  /* USER CODE BEGIN I2S3_Init 0 */

  /* USER CODE END I2S3_Init 0 */

  /* USER CODE BEGIN I2S3_Init 1 */

  /* USER CODE END I2S3_Init 1 */
  hi2s3.Instance = SPI3;
  hi2s3.Init.Mode = I2S_MODE_MASTER_TX;
  hi2s3.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s3.Init.DataFormat = I2S_DATAFORMAT_16B;
  hi2s3.Init.MCLKOutput = I2S_MCLKOUTPUT_ENABLE;
  hi2s3.Init.AudioFreq = I2S_AUDIOFREQ_96K;
  hi2s3.Init.CPOL = I2S_CPOL_LOW;
  hi2s3.Init.ClockSource = I2S_CLOCK_PLL;
  hi2s3.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_DISABLE;
  if (HAL_I2S_Init(&hi2s3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2S3_Init 2 */

  /* USER CODE END I2S3_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, CS_I2C_SPI_Pin|ILI9341_RST_Pin|ILI9341_CS_Pin|ILI9341_DC_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OTG_FS_PowerSwitchOn_GPIO_Port, OTG_FS_PowerSwitchOn_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin 
                          |Audio_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : CS_I2C_SPI_Pin */
  GPIO_InitStruct.Pin = CS_I2C_SPI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CS_I2C_SPI_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = OTG_FS_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OTG_FS_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PDM_OUT_Pin */
  GPIO_InitStruct.Pin = PDM_OUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(PDM_OUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : BOOT1_Pin */
  GPIO_InitStruct.Pin = BOOT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BOOT1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : ILI9341_RST_Pin ILI9341_CS_Pin ILI9341_DC_Pin */
  GPIO_InitStruct.Pin = ILI9341_RST_Pin|ILI9341_CS_Pin|ILI9341_DC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : CLK_IN_Pin */
  GPIO_InitStruct.Pin = CLK_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CLK_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD4_Pin LD3_Pin LD5_Pin LD6_Pin 
                           Audio_RST_Pin */
  GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin 
                          |Audio_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_OverCurrent_Pin */
  GPIO_InitStruct.Pin = OTG_FS_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OTG_FS_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : MEMS_INT2_Pin */
  GPIO_InitStruct.Pin = MEMS_INT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MEMS_INT2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
