#include "MemoryTools_RingBuffer.h"

//--------------------------------------------------------------------
bool RingBuffer_GetBytesAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint16_t  i_ByteCount,
                                    uint8_t*  i_pDestination)
{
  if (i_pRingBuffer  == nullptr
  ||  io_pCurrent    == nullptr
  ||  i_pDestination == nullptr)
    return false;
  uint8_t* pAfterBuffer = i_pRingBuffer + i_RingBufferLength;
  if (io_pCurrent < i_pRingBuffer
  ||  io_pCurrent >= pAfterBuffer)
    return false;
  if (i_ByteCount == 0)
    return true;

  if (i_ByteCount == 1)
  {
    *i_pDestination = *io_pCurrent++;
    if (io_pCurrent >= pAfterBuffer)
      io_pCurrent = i_pRingBuffer;
    return true;
  }

  if (i_ByteCount > i_RingBufferLength)
    return false;

  uint16_t bytesUntilEnd = pAfterBuffer - io_pCurrent;
  if (i_ByteCount <= bytesUntilEnd)
  {
    memcpy (i_pDestination, io_pCurrent, i_ByteCount);
    io_pCurrent += i_ByteCount;
    if (io_pCurrent >= pAfterBuffer)
      io_pCurrent = i_pRingBuffer;
    return true;
  }

  uint16_t sizeOf2ndBlock = i_ByteCount - bytesUntilEnd;
  memcpy (i_pDestination                , io_pCurrent  , bytesUntilEnd);
  memcpy (i_pDestination + bytesUntilEnd, i_pRingBuffer, sizeOf2ndBlock);
  io_pCurrent = i_pRingBuffer + sizeOf2ndBlock;
  return true;
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    bool&     o_Value)
{
  uint8_t value = 0;
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, 1, &value);
  o_Value = value != 0;
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint8_t&  o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (uint8_t), &o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int8_t&   o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (int8_t), (uint8_t*)&o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint16_t& o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (uint16_t), (uint8_t*)&o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int16_t&  o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (int16_t), (uint8_t*)&o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint32_t& o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (uint32_t), (uint8_t*)&o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int32_t&  o_Value)
{
  return RingBuffer_GetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (int32_t), (uint8_t*)&o_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_IncrementPointer (uint8_t*  i_pRingBuffer,
                                  uint16_t  i_RingBufferLength,
                                  uint8_t*& io_pCurrent)
{
  if (i_pRingBuffer == nullptr
  ||  io_pCurrent   == nullptr)
    return false;

  io_pCurrent++;
  if (io_pCurrent < i_pRingBuffer
  ||  io_pCurrent >= i_pRingBuffer + i_RingBufferLength)
    io_pCurrent = i_pRingBuffer;
  return true;
}

//--------------------------------------------------------------------
bool RingBuffer_SetBytesAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint16_t  i_ByteCount,
                                    uint8_t*  i_pSource)
{
  if (i_pRingBuffer == nullptr
  ||  io_pCurrent   == nullptr
  ||  i_pSource     == nullptr)
    return false;
  uint8_t* pAfterBuffer = i_pRingBuffer + i_RingBufferLength;
  if (io_pCurrent < i_pRingBuffer
  ||  io_pCurrent >= pAfterBuffer)
    return false;

  if (i_ByteCount == 0)
    return true;

  if (i_ByteCount == 1)
  {
    *io_pCurrent++ = *i_pSource;
    if (io_pCurrent >= pAfterBuffer)
      io_pCurrent = i_pRingBuffer;
    return true;
  }

  if (i_ByteCount > i_RingBufferLength)
    return false;

  uint16_t bytesUntilEnd = pAfterBuffer - io_pCurrent;
  if (i_ByteCount <= bytesUntilEnd)
  {
    memcpy (io_pCurrent, i_pSource, i_ByteCount);
    io_pCurrent += i_ByteCount;
    if (io_pCurrent >= pAfterBuffer)
      io_pCurrent = i_pRingBuffer;
    return true;
  }

  uint16_t sizeOf2ndBlock = i_ByteCount - bytesUntilEnd;
  memcpy (io_pCurrent  , i_pSource                , bytesUntilEnd);
  memcpy (i_pRingBuffer, i_pSource + bytesUntilEnd, sizeOf2ndBlock);
  io_pCurrent = i_pRingBuffer + sizeOf2ndBlock;
  return true;
}

//--------------------------------------------------------------------
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    bool      i_Value)
{
  uint8_t value = i_Value ? 1 : 0;
  return RingBuffer_SetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, 1, &value);
}

//--------------------------------------------------------------------
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint8_t   i_Value)
{
  return RingBuffer_SetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (uint8_t), &i_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int8_t    i_Value)
{
  return RingBuffer_SetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (int8_t), (uint8_t*)&i_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint16_t  i_Value)
{
  return RingBuffer_SetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (uint16_t), (uint8_t*)&i_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int16_t   i_Value)
{
  return RingBuffer_SetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (int16_t), (uint8_t*)&i_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint32_t  i_Value)
{
  return RingBuffer_SetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (uint32_t), (uint8_t*)&i_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int32_t   i_Value)
{
  return RingBuffer_SetBytesAndMovePtr (i_pRingBuffer, i_RingBufferLength, io_pCurrent, sizeof (int32_t), (uint8_t*)&i_Value);
}

//--------------------------------------------------------------------
bool RingBuffer_SetValue_FromStart (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint16_t  i_StartOffset,
                                    uint16_t  i_ByteCount,
                                    uint8_t   i_Value)
{
  if (i_pRingBuffer == nullptr)
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
bool RingBuffer_SetValue_FromEnd (uint8_t*  i_pRingBuffer,
                                  uint16_t  i_RingBufferLength,   // ex.1: 8    ex.2: 8
                                  uint16_t  i_EndOffset,          // ex.1: 6    ex.2: 3
                                  uint16_t  i_ByteCount,          // ex.1: 3    ex.2: 6
                                  uint8_t   i_Value)
{
  if (i_pRingBuffer == nullptr)
    return false;
  if (i_EndOffset >= i_RingBufferLength)  // ex.1,2: i_RingBufferLength == 8  --> i_EndOffset may be 0 to 7.
    return false;
  if (i_ByteCount == 0)  // nothing to do.
    return true;
  if (i_ByteCount > i_RingBufferLength)  // cannot write more values than the buffer actually has.
    return false;

  if (i_ByteCount == i_RingBufferLength)  // write the entire buffer
  {
    memset (i_pRingBuffer, i_Value, i_RingBufferLength);
    return true;
  }

  if (i_ByteCount <= i_EndOffset)  // the start is before the end, write in one pass (like in ex.1)
  {
    memset (i_pRingBuffer + i_EndOffset - i_ByteCount, i_Value, i_ByteCount);  // ex.1:  start offset = 6 - 3 = 3  --> writing the bytes 3,4,5.
    return true;
  }

  // the start is after the end, write in two passes (like in ex.2)
  uint16_t sizeOf2ndBlock = i_ByteCount - i_EndOffset;  // ex.2: 6 - 3 = 3
  memset (i_pRingBuffer,                                       i_Value, i_EndOffset);     // ex.2: writing the bytes 0,1,2
  memset (i_pRingBuffer + i_RingBufferLength - sizeOf2ndBlock, i_Value, sizeOf2ndBlock);  // ex.2: start offset = 8 - 3 = 5  --> writing the bytes 5,6,7.
  return true;
}

//--------------------------------------------------------------------
bool RingBuffer_SetValue_StartToEnd (uint8_t*  i_pRingBuffer,
                                     uint16_t  i_RingBufferLength,   // ex.1: 8    ex.2: 8
                                     uint16_t  i_StartOffset,        // ex.1: 3    ex.2: 6
                                     uint16_t  i_EndOffset,          // ex.1: 6    ex.2: 3
                                     uint8_t   i_Value)
{
  if (i_pRingBuffer == nullptr)
    return false;
  if (i_StartOffset >= i_RingBufferLength)  // ex.1,2: i_RingBufferLength == 8  --> i_StartOffset may be 0 to 7.
    return false;
  if (i_EndOffset >= i_RingBufferLength)  // ex.1,2: i_RingBufferLength == 8  --> i_EndOffset may be 0 to 7.
    return false;

  if (i_StartOffset == i_EndOffset)  // write the entire buffer
  {
    memset (i_pRingBuffer, i_Value, i_RingBufferLength);
    return true;
  }

  if (i_EndOffset > i_StartOffset)  // the start is before the end, write in one pass (like in ex.1)
  {
    memset (i_pRingBuffer + i_StartOffset, i_Value, i_EndOffset - i_StartOffset);  // ex.1: start offset = 3, length = 6 - 3 = 3 -->  writing the bytes 3,4,5
    return true;
  }

  // the start is after the end, write in two passes (like in ex.2)
  uint16_t bytesUntilEnd = i_RingBufferLength - i_StartOffset;    // ex.2: 8 - 6 = 2
  memset (i_pRingBuffer + i_StartOffset, i_Value, bytesUntilEnd); // ex.2: writing the bytes 6,7.
  memset (i_pRingBuffer                , i_Value, i_EndOffset);   // ex.2: writing the bytes 0,1,2.
  return true;
}
