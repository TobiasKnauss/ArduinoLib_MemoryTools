#include <Arduino.h>
#include <MemoryTools.h>

byte m_BufferLength = 200;
byte m_MessageLength = 80;
byte m_Buffer[200];
byte m_Message[80];

void setup ()
{
  Serial.begin (9600);
  Serial.println ((uint16_t)m_Buffer);
  Serial.println ((uint16_t)m_Message);
  bool result = CheckMemoryAreasOverlap (m_Buffer, m_BufferLength, m_Message, m_MessageLength);
  Serial.println (result);

  for (uint8_t index = 0; index < m_BufferLength; index++)
    m_Buffer[index] = index;

  uint8_t* pBuffer = &m_Buffer[7];
  uint8_t valueUI8 = 0;
  result = RingBuffer_GetValueAndMovePtr (m_Buffer, m_BufferLength, pBuffer, valueUI8);
  Serial.println (result);
  Serial.println (valueUI8, HEX2);
  uint32_t valueUI32 = 0;
  RingBuffer_GetValueAndMovePtr (m_Buffer, m_BufferLength, pBuffer, valueUI32);
  Serial.println (result);
  Serial.println (valueUI32, HEX8);
}

void loop ()
{
  // put your main code here, to run repeatedly:

}
