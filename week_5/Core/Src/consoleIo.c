// Console IO is a wrapper between the actual in and output and the console code
// In an embedded system, this might interface to a UART driver.

#include "consoleIo.h"
#include <stdio.h>
#include "usart.h"
#include <string.h>

eConsoleError ConsoleIoInit(void)
{
	return CONSOLE_SUCCESS;
}
eConsoleError ConsoleIoReceive(uint8_t *buffer, const uint32_t bufferLength, uint32_t *readLength)
{
	uint32_t i = 0;
	unsigned char ch;

	HAL_UART_Receive(&huart3, &ch, 1, 1000000);
//	while ( ( '\r' != ch ) && ( i < bufferLength ) )
//	{
//		buffer[i] = (uint8_t) ch;
//		i++;
//		HAL_UART_Receive(&huart1, &ch, 1, 1000000);
//	}
	buffer[i] = ch;
	i++;
	*readLength = i;
	return CONSOLE_SUCCESS;
}

eConsoleError ConsoleIoSendString(const char *buffer)
{
	HAL_UART_Transmit(&huart3, (unsigned char *) buffer, strlen(buffer), 1000000);
	return CONSOLE_SUCCESS;
}

