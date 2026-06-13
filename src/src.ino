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
  CTest* pTest = new CTest ();
  DeleteObject (pTest);

  //--------------------------------------------------------------------

  ByteOrder::Invert (m_ValueI16);

  ByteOrder::Invert (m_ValueUI16);

  ByteOrder::Invert (m_ValueI32);

  ByteOrder::Invert (m_ValueUI32);

  //--------------------------------------------------------------------

  uint16_t checksum = 0;
  uint16_t address = 0;
  uint8_t buffer[20];
  memset (buffer, 0, sizeof(buffer));

  Eeprom::CalcChecksumCRC16_From   (0, 1, checksum);
  Eeprom::CalcChecksumCRC16_To     (0, 1, checksum);
  Eeprom::CalcChecksumCRC16_FromTo (0, 1, checksum);

  Eeprom::CheckAddress (1);
  Eeprom::CheckAddressRange (1, 2);

  bool      valueB    = false;
  uint8_t   valueUI8  = 0;
  int8_t    valueI8   = 0;
  uint16_t  valueUI16 = 0;
  int16_t   valueI16  = 0;
  uint32_t  valueUI32 = 0;
  int32_t   valueI32  = 0;

  Eeprom::ReadBytesAndMovePtr (address, 2, buffer, false);
  Eeprom::ReadValueAndMovePtr (address, valueB);
  Eeprom::ReadValueAndMovePtr (address, valueUI8);
  Eeprom::ReadValueAndMovePtr (address, valueI8);
  Eeprom::ReadValueAndMovePtr (address, valueUI16, false);
  Eeprom::ReadValueAndMovePtr (address, valueI16,  false);
  Eeprom::ReadValueAndMovePtr (address, valueUI32, false);
  Eeprom::ReadValueAndMovePtr (address, valueI32,  false);

  Eeprom::WriteBytesAndMovePtr (address, 2, buffer, false);
  Eeprom::WriteValueAndMovePtr (address, valueB);
  Eeprom::WriteValueAndMovePtr (address, valueUI8);
  Eeprom::WriteValueAndMovePtr (address, valueI8);
  Eeprom::WriteValueAndMovePtr (address, valueUI16, false);
  Eeprom::WriteValueAndMovePtr (address, valueI16,  false);
  Eeprom::WriteValueAndMovePtr (address, valueUI32, false);
  Eeprom::WriteValueAndMovePtr (address, valueI32,  false);

  Eeprom::WriteRange_From   (1, 2, 3);
  Eeprom::WriteRange_To     (1, 2, 3);
  Eeprom::WriteRange_FromTo (1, 2, 3);

  //--------------------------------------------------------------------

  Memory::Allocate (m_pMemory1, m_Length1, m_DefaultValue);

  Memory::CheckAreasOverlap (m_pMemory1, m_Length1, m_pMemory2, m_Length2);

  Memory::Print   (         m_pMemory1, m_Length1);
  Memory::Print   (&Serial, m_pMemory1, m_Length1);
  Memory::PrintLn (         m_pMemory1, m_Length1);
  Memory::PrintLn (&Serial, m_pMemory1, m_Length1);
}

void loop ()
{
}
