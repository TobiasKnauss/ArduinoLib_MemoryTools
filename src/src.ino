#include "MemoryTools.h"
#include "MemoryTools_ByteOrder.h"
#include "MemoryTools_EEPROM.h"
#include "MemoryTools_Memory.h"

using namespace MemoryTools;

class CTest
{
public:
  int m_Value = 1;
};

uint8_t   m_DefaultValue = 0xFF;
uint8_t*  m_pMemory1 = nullptr;
uint8_t*  m_pMemory2 = nullptr;
uint16_t  m_Length1  = 0;
uint16_t  m_Length2  = 0;

bool      m_ValueBOOL = false;
uint8_t   m_ValueUI8  = 0;
int8_t    m_ValueI8   = 0;
uint16_t  m_ValueUI16 = 0;
int16_t   m_ValueI16  = 0;
uint32_t  m_ValueUI32 = 0;
int32_t   m_ValueI32  = 0;

void setup ()
{
  Memory::Allocate (m_pMemory1, m_Length1, m_DefaultValue);

  Memory::CheckAreasOverlap (m_pMemory1, m_Length1, m_pMemory2, m_Length2);

  CTest* pTest = new CTest ();
  DeleteObject (pTest);

  Memory::PrintLn (m_pMemory1, m_Length1);

  //--------------------------------------------------------------------

  ByteOrder::Invert (m_ValueI16);

  ByteOrder::Invert (m_ValueUI16);

  ByteOrder::Invert (m_ValueI32);

  ByteOrder::Invert (m_ValueUI32);
}

void loop ()
{
}
