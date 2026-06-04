#include "MemoryTools.h"
#include "MemoryTools_ByteOrder.h"
#include "MemoryTools_EEPROM.h"
#include "MemoryTools_RingBuffer.h"

class CTest
{
public:
  int m_Value = 1;
};

uint8_t   m_DefaultValue = 0xFF;
uint8_t*  m_pMemory  = nullptr;
uint8_t*  m_pMemory2 = nullptr;
uint16_t  m_Length   = 0;
uint16_t  m_Length2  = 0;

uint8_t*  m_pRingBuffer       = nullptr;
uint16_t  m_RingBufferLength  = 0;
uint8_t*  m_pDestination      = nullptr;
uint8_t*  m_pCurrent          = nullptr;
uint8_t*  m_pSource           = new uint8_t[0];
uint16_t  m_ByteCount         = 0;
uint16_t  m_StartOffset       = 0;
uint16_t  m_EndOffset         = 0;

bool      m_ValueBOOL = false;
uint8_t   m_ValueUI8  = 0;
int8_t    m_ValueI8   = 0;
uint16_t  m_ValueUI16 = 0;
int16_t   m_ValueI16  = 0;
uint32_t  m_ValueUI32 = 0;
int32_t   m_ValueI32  = 0;

void setup ()
{
  CheckMemoryAreasOverlap (m_pMemory, m_Length, m_pMemory2, m_Length2);

  CTest* pTest = new CTest ();
  DeleteObject (pTest);

  Memory_Allocate (m_pMemory, m_Length, m_DefaultValue);

  Memory_PrintLn (m_pMemory, m_Length);

  //--------------------------------------------------------------------

  ByteOrderInvert (m_ValueI16);

  ByteOrderInvert (m_ValueUI16);

  ByteOrderInvert (m_ValueI32);

  ByteOrderInvert (m_ValueUI32);

  //--------------------------------------------------------------------

  RingBuffer_GetBytesAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ByteCount, m_pDestination);

  RingBuffer_GetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueBOOL);

  RingBuffer_GetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueUI8);

  RingBuffer_GetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueI8);

  RingBuffer_GetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueUI16);

  RingBuffer_GetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueI16);

  RingBuffer_GetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueUI32);

  RingBuffer_GetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueI32);

  RingBuffer_IncrementPointer (m_pRingBuffer, m_RingBufferLength, m_pCurrent);

  RingBuffer_SetBytesAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ByteCount, m_pSource);

  RingBuffer_SetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueBOOL);

  RingBuffer_SetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueUI8);

  RingBuffer_SetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueI8);

  RingBuffer_SetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueUI16);

  RingBuffer_SetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueI16);

  RingBuffer_SetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueUI32);

  RingBuffer_SetValueAndMovePtr (m_pRingBuffer, m_RingBufferLength, m_pCurrent, m_ValueI32);

  RingBuffer_SetValue_FromStart  (m_pRingBuffer, m_RingBufferLength, m_StartOffset, m_ByteCount, m_ValueUI8);

  RingBuffer_SetValue_FromEnd    (m_pRingBuffer, m_RingBufferLength, m_EndOffset, m_ByteCount, m_ValueUI8);

  RingBuffer_SetValue_StartToEnd (m_pRingBuffer, m_RingBufferLength, m_StartOffset, m_EndOffset, m_ValueUI8);
}

void loop ()
{
}
