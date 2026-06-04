#include "MemoryTools_ByteOrder.h"

int16_t ByteOrder_Invert (int16_t i_Data)
{
  return (i_Data >> 8 & 0x00FF)
       | (i_Data << 8 & 0xFF00);
}

uint16_t ByteOrder_Invert (uint16_t i_Data)
{
  return (i_Data >> 8 & 0x00FF)
       | (i_Data << 8 & 0xFF00);
}

int32_t ByteOrder_Invert (int32_t i_Data)
{
  return (i_Data >> 24 & 0x000000FF)
       | (i_Data >>  8 & 0x0000FF00)
       | (i_Data <<  8 & 0x00FF0000)
       | (i_Data << 24 & 0xFF000000);
}
uint32_t ByteOrder_Invert (uint32_t i_Data)
{
  return (i_Data >> 24 & 0x000000FF)
       | (i_Data >>  8 & 0x0000FF00)
       | (i_Data <<  8 & 0x00FF0000)
       | (i_Data << 24 & 0xFF000000);
}
