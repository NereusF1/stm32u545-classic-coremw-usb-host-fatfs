/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "fatfs.h"
#include "usb_host.h"
#include <stdio.h>
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

COM_InitTypeDef BspCOMInit;

HCD_HandleTypeDef hhcd_USB_DRD_FS;

/* USER CODE BEGIN PV */
extern ApplicationTypeDef Appli_state;
uint8_t USBWriteOpEnable; // set from the watch window
extern UART_HandleTypeDef huart3;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void SystemPower_Config(void);
static void MX_GPIO_Init(void);
static void MX_ICACHE_Init(void);
static void MX_USB_DRD_FS_HCD_Init(void);
/* USER CODE BEGIN PFP */
void MX_USB_HOST_Process(void);
void MyUSBUserFnc(void);
static FRESULT ETX_MSC_ProcessUsbDevice(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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

  /* Configure the System Power */
  SystemPower_Config();

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ICACHE_Init();
  MX_USB_DRD_FS_HCD_Init();
  /* USER CODE BEGIN 2 */
  MX_FATFS_Init();
  MX_USB_HOST_Init();
  /* USER CODE END 2 */

  /* Initialize led */
  BSP_LED_Init(LED_GREEN);

  /* Initialize USER push-button, will be used to trigger an interrupt each time it's pressed.*/
  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);

  /* Initialize COM1 port (115200, 8 bits (7-bit data + 1 stop bit), no parity */
  BspCOMInit.BaudRate   = 115200;
  BspCOMInit.WordLength = COM_WORDLENGTH_8B;
  BspCOMInit.StopBits   = COM_STOPBITS_1;
  BspCOMInit.Parity     = COM_PARITY_NONE;
  BspCOMInit.HwFlowCtl  = COM_HWCONTROL_NONE;
  if (BSP_COM_Init(COM1, &BspCOMInit) != BSP_ERROR_NONE)
  {
    Error_Handler();
  }

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  MX_USB_HOST_Process();
	  MyUSBUserFnc();
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

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_0;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_PCLK3;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Power Configuration
  * @retval None
  */
static void SystemPower_Config(void)
{

  /*
   * Switch to SMPS regulator instead of LDO
   */
  if (HAL_PWREx_ConfigSupply(PWR_SMPS_SUPPLY) != HAL_OK)
  {
    Error_Handler();
  }
/* USER CODE BEGIN PWR */
/* USER CODE END PWR */
}

/**
  * @brief ICACHE Initialization Function
  * @param None
  * @retval None
  */
static void MX_ICACHE_Init(void)
{

  /* USER CODE BEGIN ICACHE_Init 0 */

  /* USER CODE END ICACHE_Init 0 */

  /* USER CODE BEGIN ICACHE_Init 1 */

  /* USER CODE END ICACHE_Init 1 */

  /** Enable instruction cache in 1-way (direct mapped cache)
  */
  if (HAL_ICACHE_ConfigAssociativityMode(ICACHE_1WAY) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_ICACHE_Enable() != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ICACHE_Init 2 */

  /* USER CODE END ICACHE_Init 2 */

}

/**
  * @brief USB_DRD_FS Initialization Function
  * @param None
  * @retval None
  */
static void MX_USB_DRD_FS_HCD_Init(void)
{

  /* USER CODE BEGIN USB_DRD_FS_Init 0 */

  /* USER CODE END USB_DRD_FS_Init 0 */

  /* USER CODE BEGIN USB_DRD_FS_Init 1 */

  /* USER CODE END USB_DRD_FS_Init 1 */
  hhcd_USB_DRD_FS.Instance = USB_DRD_FS;
  hhcd_USB_DRD_FS.Init.dev_endpoints = 8;
  hhcd_USB_DRD_FS.Init.Host_channels = 8;
  hhcd_USB_DRD_FS.Init.speed = HCD_SPEED_FULL;
  hhcd_USB_DRD_FS.Init.phy_itface = HCD_PHY_EMBEDDED;
  hhcd_USB_DRD_FS.Init.Sof_enable = DISABLE;
  hhcd_USB_DRD_FS.Init.low_power_enable = DISABLE;
  hhcd_USB_DRD_FS.Init.vbus_sensing_enable = DISABLE;
  hhcd_USB_DRD_FS.Init.bulk_doublebuffer_enable = DISABLE;
  hhcd_USB_DRD_FS.Init.iso_singlebuffer_enable = DISABLE;
  if (HAL_HCD_Init(&hhcd_USB_DRD_FS) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USB_DRD_FS_Init 2 */

  /* USER CODE END USB_DRD_FS_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/**
  * @brief Print the characters to UART (printf).
  * @retval int
  */
//#ifdef __GNUC__
//  /* With GCC, small printf (option LD Linker->Libraries->Small printf
//     set to 'Yes') calls __io_putchar() */
//int __io_putchar(int ch)
//#else
//int fputc(int ch, FILE *f)
//#endif /* __GNUC__ */
//{
//  /* Place your implementation of fputc here */
//  /* e.g. write a character to the UART3 and Loop until the end of transmission */
//  HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
//  return ch;
//}


static FRESULT ETX_MSC_ProcessUsbDevice(void)
{
  FATFS     UsbDiskFatFs;                                 /* File system object for USB disk logical drive */
  char      UsbDiskPath[4] = {0};                         /* USB Host logical drive path */
  FIL       file;                                         /* File object */
  FRESULT   res;                                          /* FatFs function common result code */
  uint32_t  total_space, free_space;                      /* Total Space and Free Space */
  DWORD     fre_clust;                                    /* Freee Cluster */
  uint32_t  byteswritten, bytesread;                      /* File write/read counts */
  uint8_t   wr_data[] = "Welcome to EmbeTronicX!!!";      /* Data buffer */
  uint8_t   rd_data[100];                                 /* Read buffer */
  char      file_name[] = "temp.txt";                     /* File name */

  do
  {
    /* Register the file system object to the FatFs module */
    res = f_mount( &UsbDiskFatFs, (TCHAR const*)UsbDiskPath, 0 );
    if( res != FR_OK )
    {
      /* FatFs Init Error */
      break;
    }

    /* Check the Free Space */
    FATFS *fatFs = &UsbDiskFatFs;
    f_getfree("", &fre_clust, &fatFs);
    total_space = (uint32_t)((UsbDiskFatFs.n_fatent - 2) * UsbDiskFatFs.csize * 0.5);
    free_space = (uint32_t)(fre_clust * UsbDiskFatFs.csize * 0.5);
    printf("USB Device Total Space = %lu MB\n", total_space/1024);
    printf("USB Device Free Space  = %lu MB\n", free_space/1024);

    /* Create a new text file with write access */
    res = f_open( &file, file_name, ( FA_CREATE_ALWAYS | FA_WRITE ) );
    if( res != FR_OK )
    {
      /* File Open Error */
      break;
    }

    /* Write the data to the text file */
    res = f_write( &file, wr_data, sizeof(wr_data), (void *)&byteswritten );

    /* Close the opened file */
    f_close( &file );

    if( res != FR_OK )
    {
      /* File write Error */
      break;
    }

    printf("Data written to the USD Device\n");

    /* Open the text file object with read access */
    res = f_open( &file, file_name, FA_READ );
    if( res != FR_OK )
    {
      /* File Open Error */
      break;
    }

    /* Read data from the file */
    res = f_read( &file, rd_data, sizeof(wr_data), (void *)&bytesread);

    /* Close the file */
    f_close(&file);

    if(res != FR_OK)
    {
      /* File Read Error */
      break;
    }

    /* Print the data */
    printf("Read Data : %s\n", rd_data);

  } while ( 0 );

  /* Unmount the device */
  f_mount(NULL, UsbDiskPath, 0);

  /* Unlink the USB disk driver */
  FATFS_UnLinkDriver(UsbDiskPath);

  return res;
}

void MyUSBUserFnc(void)
{
	  if(Appli_state == APPLICATION_READY)
	  {
		  if(USBWriteOpEnable==1)
		  {
			  if( ETX_MSC_ProcessUsbDevice() != FR_OK )
			  {
				printf("USB Device Process Error\n");
				USBWriteOpEnable=2;
			  }
			  else
			  {
				USBWriteOpEnable=0;
			  }
		  }
	  }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
