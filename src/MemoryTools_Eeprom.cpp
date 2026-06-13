#include <EEPROM.h>
#include <FastCRC.h>

#include "MemoryTools_ByteOrder.h"
#include "MemoryTools_EEPROM.h"

using namespace MemoryTools;

//--------------------------------------------------------------------
uint16_t Eeprom::CalcChecksumCRC16 (uint16_t i_StartAddress,
                                    uint16_t i_ByteCount)
{
  if (!CheckAddressRange (i_StartAddress, i_ByteCount))
    return 0;
  if (i_ByteCount <= 0)
    return 0;

  FastCRC16 crc16;
  uint8_t  byteValue = EEPROM.read (i_StartAddress);
  uint16_t checksum = crc16.modbus (&byteValue, 1);
  for (uint16_t index = 1; index < i_ByteCount; index++)
  {
    byteValue = EEPROM.read (i_StartAddress + index);
    checksum = crc16.modbus_upd (&byteValue, 1);
  }
  return checksum;
}

//--------------------------------------------------------------------
bool Eeprom::CheckAddress (uint16_t i_Address)
{
  return i_Address < EEPROM.length ();
}

//--------------------------------------------------------------------
bool Eeprom::CheckAddressRange (uint16_t  i_Address,
                                uint16_t  i_ByteCount)
{
  return i_Address + i_ByteCount <= EEPROM.length ();
}

//--------------------------------------------------------------------
bool Eeprom::ReadBytesAndMovePtr ( uint16_t& io_Address,
                                  uint16_t  i_ByteCount,
                                  uint8_t*  i_pDestination,
                                  bool      i_InvertByteOrder)
{
  if (i_pDestination == nullptr)
    return false;
  if (!CheckAddressRange (io_Address, i_ByteCount))
    return false;
  if (i_ByteCount == 0)
    return true;

  if (i_InvertByteOrder)
  {
    for (uint16_t index = 1; index <= i_ByteCount; index++)
      i_pDestination[i_ByteCount - index] = EEPROM.read (io_Address++);
    return true;
  }

  for (uint16_t index = 0; index < i_ByteCount; index++)
    i_pDestination[index] = EEPROM.read (io_Address++);
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::ReadValueAndMovePtr (uint16_t& io_Address,
                                  bool&     o_Value)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::ReadValueAndMovePtr (uint16_t& io_Address,
                                  uint8_t&  o_Value)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::ReadValueAndMovePtr (uint16_t& io_Address,
                                  int8_t&   o_Value)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::ReadValueAndMovePtr (uint16_t& io_Address,
                                  uint16_t& o_Value,
                                  bool      i_InvertByteOrder)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  if (i_InvertByteOrder)
    o_Value = ByteOrder::Invert (o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::ReadValueAndMovePtr (uint16_t& io_Address,
                                  int16_t&  o_Value,
                                  bool      i_InvertByteOrder)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  if (i_InvertByteOrder)
    o_Value = ByteOrder::Invert (o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::ReadValueAndMovePtr (uint16_t& io_Address,
                                  uint32_t& o_Value,
                                  bool      i_InvertByteOrder)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  if (i_InvertByteOrder)
    o_Value = ByteOrder::Invert (o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::ReadValueAndMovePtr (uint16_t& io_Address,
                                  int32_t&  o_Value,
                                  bool      i_InvertByteOrder)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  if (i_InvertByteOrder)
    o_Value = ByteOrder::Invert (o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::WriteBytesAndMovePtr ( uint16_t& io_Address,
                                    uint16_t  i_ByteCount,
                                    uint8_t*  i_pSource,
                                    bool      i_InvertByteOrder)
{
  if (i_pSource == nullptr)
    return false;
  if (!CheckAddressRange (io_Address, i_ByteCount))
    return false;
  if (i_ByteCount == 0)
    return true;

  if (i_InvertByteOrder)
  {
    for (uint16_t index = 1; index <= i_ByteCount; index++)
      EEPROM.update (io_Address++, i_pSource[i_ByteCount - index]);
    return true;
  }

  for (uint16_t index = 0; index < i_ByteCount; index++)
    EEPROM.update (io_Address++, i_pSource[index]);
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::WriteValueAndMovePtr ( uint16_t& io_Address,
                                    bool      i_Value)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::WriteValueAndMovePtr ( uint16_t& io_Address,
                                    uint8_t   i_Value)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::WriteValueAndMovePtr ( uint16_t& io_Address,
                                    int8_t    i_Value)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::WriteValueAndMovePtr ( uint16_t& io_Address,
                                    uint16_t  i_Value,
                                    bool      i_InvertByteOrder)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  if (i_InvertByteOrder)
    i_Value = ByteOrder::Invert (i_Value);
  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::WriteValueAndMovePtr ( uint16_t& io_Address,
                                    int16_t   i_Value,
                                    bool      i_InvertByteOrder)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  if (i_InvertByteOrder)
    i_Value = ByteOrder::Invert (i_Value);
  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::WriteValueAndMovePtr ( uint16_t& io_Address,
                                    uint32_t  i_Value,
                                    bool      i_InvertByteOrder)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  if (i_InvertByteOrder)
    i_Value = ByteOrder::Invert (i_Value);
  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::WriteValueAndMovePtr ( uint16_t& io_Address,
                                    int32_t   i_Value,
                                    bool      i_InvertByteOrder)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!CheckAddressRange (io_Address, byteCount))
    return false;

  if (i_InvertByteOrder)
    i_Value = ByteOrder::Invert (i_Value);
  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::WriteRange_FromStart ( uint16_t  i_StartAddress,
                                    uint16_t  i_ByteCount,
                                    uint8_t   i_Value)
{
  if (!CheckAddressRange (i_StartAddress, i_ByteCount))
    return false;

  for (uint16_t index = 0; index < i_ByteCount; index++)
    EEPROM.update (i_StartAddress++, i_Value);
  return true;
}

//--------------------------------------------------------------------
bool Eeprom::WriteRange_ToEnd ( uint16_t  i_EndAddress,
                                uint16_t  i_ByteCount,
                                uint8_t   i_Value)
{
  return WriteRange_FromStart ( i_EndAddress - i_ByteCount,
                                i_ByteCount,
                                i_Value);
}

//--------------------------------------------------------------------
bool Eeprom::WriteRange_StartToEnd (uint16_t  i_StartAddress,
                                  uint16_t  i_EndAddress,
                                  uint8_t   i_Value)
{
  return WriteRange_FromStart ( i_StartAddress,
                                i_EndAddress - i_StartAddress,
                                i_Value);
}
