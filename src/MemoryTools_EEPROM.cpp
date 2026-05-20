#include <EEPROM.h>
#include <FastCRC.h>

#include "MemoryTools_EEPROM.h"

//--------------------------------------------------------------------
uint16_t EEPROM_CalcChecksumCRC16 (uint16_t i_StartAddress,
                                   uint16_t i_ByteCount)
{
  if (!EEPROM_CheckAddressRange (i_StartAddress, i_ByteCount))
    return 0;

  FastCRC16 crc16;
  uint8_t  byteValue = 0;
  uint16_t checksum = crc16.modbus (&byteValue, 0);
  for (uint16_t index = 0; index < i_ByteCount; index++)
  {
    byteValue = EEPROM.read (i_StartAddress + index);
    checksum = crc16.modbus_upd (&byteValue, 1);
  }
  return checksum;
}

//--------------------------------------------------------------------
bool EEPROM_CheckAddress (uint16_t i_Address)
{
  return i_Address < EEPROM.length ();
}

//--------------------------------------------------------------------
bool EEPROM_CheckAddressRange ( uint16_t  i_Address,
                                uint16_t  i_ByteCount)
{
  return i_Address + i_ByteCount <= EEPROM.length ();
}

//--------------------------------------------------------------------
bool EEPROM_GetBytesAndMovePtr (uint16_t& io_Address,
                                uint16_t  i_ByteCount,
                                uint8_t*  i_pDestination)
{
  if (i_pDestination == nullptr)
    return false;
  if (!EEPROM_CheckAddressRange (io_Address, i_ByteCount))
    return false;
  if (i_ByteCount == 0)
    return true;

  for (uint16_t index = 0; index < i_ByteCount; index++)
    i_pDestination[index] = EEPROM.read (io_Address++);
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                bool&     o_Value)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                uint8_t&  o_Value)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                int8_t&   o_Value)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                uint16_t& o_Value)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                int16_t&  o_Value)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                uint32_t& o_Value)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                int32_t&  o_Value)
{
  uint8_t byteCount = sizeof (o_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.get (io_Address, o_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_SetBytesAndMovePtr (uint16_t& io_Address,
                                uint16_t  i_ByteCount,
                                uint8_t*  i_pSource)
{
  if (i_pSource == nullptr)
    return false;
  if (!EEPROM_CheckAddressRange (io_Address, i_ByteCount))
    return false;
  if (i_ByteCount == 0)
    return true;

  for (uint16_t index = 0; index < i_ByteCount; index++)
    EEPROM.update (io_Address++, i_pSource[index]);
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                bool      i_Value)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                uint8_t   i_Value)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                int8_t    i_Value)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                uint16_t  i_Value)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                int16_t   i_Value)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                uint32_t  i_Value)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                int32_t   i_Value)
{
  uint8_t byteCount = sizeof (i_Value);
  if (!EEPROM_CheckAddressRange (io_Address, byteCount))
    return false;

  EEPROM.put (io_Address, i_Value);
  io_Address += byteCount;
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_SetValue_FromStart (uint16_t  i_StartAddress,
                                uint16_t  i_ByteCount,
                                uint8_t   i_Value)
{
  if (!EEPROM_CheckAddressRange (i_StartAddress, i_ByteCount))
    return false;

  for (uint16_t index = 0; index < i_ByteCount; index++)
    EEPROM.update (i_StartAddress++, i_Value);
  return true;
}

//--------------------------------------------------------------------
bool EEPROM_SetValue_FromEnd (uint16_t  i_EndAddress,
                              uint16_t  i_ByteCount,
                              uint8_t   i_Value)
{
  return EEPROM_SetValue_FromStart (i_EndAddress - i_ByteCount,
                                    i_ByteCount,
                                    i_Value);
}

//--------------------------------------------------------------------
bool EEPROM_SetValue_StartToEnd ( uint16_t  i_StartAddress,
                                  uint16_t  i_EndAddress,
                                  uint8_t   i_Value)
{
  return EEPROM_SetValue_FromStart (i_StartAddress,
                                    i_EndAddress - i_StartAddress,
                                    i_Value);
}
