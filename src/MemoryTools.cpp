#include <Arduino.h>
#include <Streaming.h>
#include "MemoryTools.h"

//--------------------------------------------------------------------
bool CheckMemoryAreasOverlap (uint8_t* i_pArea1,
                              uint16_t i_Area1Length,
                              uint8_t* i_pArea2,
                              uint16_t i_Area2Length)
{
  uint8_t* area1End = i_pArea1 + i_Area1Length;
  uint8_t* area2End = i_pArea2 + i_Area2Length;

  return (i_pArea1 >= i_pArea2 && i_pArea1 < area2End)
      || (i_pArea2 >= i_pArea1 && i_pArea2 < area1End);
}

//--------------------------------------------------------------------
void Memory_PrintLn (uint8_t* i_pMemory,
                     uint16_t i_Length)
{                     
  for (uint16_t index = 0; index < i_Length; index++)
    Serial.print (i_pMemory[index], HEX2);
  Serial.println ();
}

//--------------------------------------------------------------------
bool RingBuffer_SetValue (uint8_t*  i_pRingBuffer,
                          uint16_t  i_RingBufferLength,
                          uint16_t  i_StartOffset,
                          uint16_t  i_ByteCount,
                          uint8_t   i_Value)
{
  if (i_pRingBuffer == 0)
    return false;
  if (i_StartOffset >= i_RingBufferLength)
    return false;
  if (i_ByteCount == 0)
    return true;
  if (i_ByteCount > i_RingBufferLength)
    return false;

  if (i_ByteCount == i_RingBufferLength)
  {
    memset (i_pRingBuffer, i_Value, i_RingBufferLength);
    return true;
  }

  uint16_t bytesUntilEnd = i_RingBufferLength - i_StartOffset;
  if (i_ByteCount <= bytesUntilEnd)
  {
    memset (i_pRingBuffer + i_StartOffset, i_Value, i_ByteCount);
    return true;
  }

  uint16_t sizeOf2ndBlock = i_ByteCount - bytesUntilEnd;
  memset (i_pRingBuffer + i_StartOffset, i_Value, bytesUntilEnd);
  memset (i_pRingBuffer                , i_Value, sizeOf2ndBlock);
  return true;
}

//--------------------------------------------------------------------
bool RingBuffer_SetValueBackward (uint8_t*  i_pRingBuffer,
                                  uint16_t  i_RingBufferLength,
                                  uint16_t  i_EndOffset,
                                  uint16_t  i_ByteCount,
                                  uint8_t   i_Value)
{
  if (i_pRingBuffer == 0)
    return false;
  if (i_EndOffset >= i_RingBufferLength)
    return false;
  if (i_ByteCount == 0)
    return true;
  if (i_ByteCount > i_RingBufferLength)
    return false;

  if (i_ByteCount == i_RingBufferLength)
  {
    memset (i_pRingBuffer, i_Value, i_RingBufferLength);
    return true;
  }

  if (i_ByteCount <= i_EndOffset)
  {
    memset (i_pRingBuffer + i_EndOffset - i_ByteCount, i_Value, i_ByteCount);
    return true;
  }

  uint16_t sizeOf2ndBlock = i_ByteCount - i_EndOffset;
  memset (i_pRingBuffer,                                       i_Value, i_EndOffset);
  memset (i_pRingBuffer + i_RingBufferLength - sizeOf2ndBlock, i_Value, sizeOf2ndBlock);
  return true;
}

//--------------------------------------------------------------------
bool RingBuffer_GetBytesAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint16_t  i_ByteCount,
                                    uint8_t*  o_pDestination)
{
  if (i_pRingBuffer == 0)
    return false;
  uint8_t* pAfterBuffer = i_pRingBuffer + i_RingBufferLength;
  if (io_pCurrent < i_pRingBuffer
  ||  io_pCurrent >= pAfterBuffer)
    return false;

  if (i_ByteCount == 0)
    return true;

  if (i_ByteCount == 1)
  {
    *o_pDestination = *io_pCurrent++;
    if (io_pCurrent >= pAfterBuffer)
      io_pCurrent = i_pRingBuffer;
    return true;
  }

  if (i_ByteCount > i_RingBufferLength)
    return false;

  uint16_t bytesUntilEnd = pAfterBuffer - io_pCurrent;
  if (i_ByteCount <= bytesUntilEnd)
  {
    memcpy (o_pDestination, io_pCurrent, i_ByteCount);
    io_pCurrent += i_ByteCount;
    if (io_pCurrent >= pAfterBuffer)
      io_pCurrent = i_pRingBuffer;
    return true;
  }

  uint16_t sizeOf2ndBlock = i_ByteCount - bytesUntilEnd;
  memcpy (o_pDestination                , io_pCurrent  , bytesUntilEnd);
  memcpy (o_pDestination + bytesUntilEnd, i_pRingBuffer, sizeOf2ndBlock);
  io_pCurrent = i_pRingBuffer + sizeOf2ndBlock;
  return true;
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint8_t&  o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, 1, &o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int8_t&   o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, 1, (uint8_t*)&o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint16_t& o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, 2, (uint8_t*)&o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int16_t&  o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, 2, (uint8_t*)&o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint32_t& o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, 4, (uint8_t*)&o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int32_t&  o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, 4, (uint8_t*)&o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_IncrementPointer (uint8_t*  i_pRingBuffer,
                                  uint16_t  i_RingBufferLength,
                                  uint8_t*& io_pCurrent)
{
  if (i_pRingBuffer == 0)
    return false;

  io_pCurrent++;
  if (io_pCurrent < i_pRingBuffer
  ||  io_pCurrent >= i_pRingBuffer + i_RingBufferLength)
    io_pCurrent = i_pRingBuffer;
  return true;
}
