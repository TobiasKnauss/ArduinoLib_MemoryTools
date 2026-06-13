#ifndef MemoryTools_EEPROM_h
#define MemoryTools_EEPROM_h

#include <Arduino.h>

namespace MemoryTools
{
  class Eeprom
  {
  private:

    Eeprom () = delete;

  public:

    static uint16_t CalcChecksumCRC16 ( uint16_t i_StartAddress,
                                        uint16_t i_ByteCount);

    // Check if the given address is a valid address in the EEPROM, not exceeding the size of the EEPROM.
    static bool CheckAddress (uint16_t i_Address);

    static bool CheckAddressRange ( uint16_t  i_Address,
                                    uint16_t  i_ByteCount);

    // Read the specified number of bytes from the EEPROM to the given destination pointer and move the pointer forward.
    static bool ReadBytesAndMovePtr ( uint16_t& io_Address,
                                      uint16_t  i_ByteCount,
                                      uint8_t*  i_pDestination,
                                      bool      i_InvertByteOrder);

    // Read a BOOL value from the EEPROM and move the pointer forward.
    static bool ReadValueAndMovePtr ( uint16_t& io_Address,
                                      bool&     o_Value);

    // Read an UINT8 value from the EEPROM and move the pointer forward.
    static bool ReadValueAndMovePtr ( uint16_t& io_Address,
                                      uint8_t&  o_Value);

    // Read an INT8 value from the EEPROM and move the pointer forward.
    static bool ReadValueAndMovePtr ( uint16_t& io_Address,
                                      int8_t&   o_Value);

    // Read an UINT16 value from the EEPROM and move the pointer forward.
    static bool ReadValueAndMovePtr ( uint16_t& io_Address,
                                      uint16_t& o_Value,
                                      bool      i_InvertByteOrder);

    // Read an INT16 value from the EEPROM and move the pointer forward.
    static bool ReadValueAndMovePtr ( uint16_t& io_Address,
                                      int16_t&  o_Value,
                                      bool      i_InvertByteOrder);

    // Read an UINT32 value from the EEPROM and move the pointer forward.
    static bool ReadValueAndMovePtr ( uint16_t& io_Address,
                                      uint32_t& o_Value,
                                      bool      i_InvertByteOrder);

    // Read an INT32 value from the EEPROM and move the pointer forward.
    static bool ReadValueAndMovePtr ( uint16_t& io_Address,
                                      int32_t&  o_Value,
                                      bool      i_InvertByteOrder);

    // Write the specified number of bytes from the given source pointer to the EEPROM and move the pointer forward.
    static bool WriteBytesAndMovePtr (uint16_t& io_Address,
                                      uint16_t  i_ByteCount,
                                      uint8_t*  i_pSource,
                                      bool      i_InvertByteOrder);

    // Write a BOOL value into the EEPROM and move the pointer forward.
    static bool WriteValueAndMovePtr (uint16_t& io_Address,
                                      bool      i_Value);

    // Write an UINT8 value into the EEPROM and move the pointer forward.
    static bool WriteValueAndMovePtr (uint16_t& io_Address,
                                      uint8_t   i_Value);

    // Write an INT8 value into the EEPROM and move the pointer forward.
    static bool WriteValueAndMovePtr (uint16_t& io_Address,
                                      int8_t    i_Value);

    // Write an UINT16 value into the EEPROM and move the pointer forward.
    static bool WriteValueAndMovePtr (uint16_t& io_Address,
                                      uint16_t  i_Value,
                                      bool      i_InvertByteOrder);

    // Write an INT16 value into the EEPROM and move the pointer forward.
    static bool WriteValueAndMovePtr (uint16_t& io_Address,
                                      int16_t   i_Value,
                                      bool      i_InvertByteOrder);

    // Write an UINT32 value into the EEPROM and move the pointer forward.
    static bool WriteValueAndMovePtr (uint16_t& io_Address,
                                      uint32_t  i_Value,
                                      bool      i_InvertByteOrder);

    // Write an INT32 value into the EEPROM and move the pointer forward.
    static bool WriteValueAndMovePtr (uint16_t& io_Address,
                                      int32_t   i_Value,
                                      bool      i_InvertByteOrder);

    // Write the given value to the specified number of bytes in the EEPROM, starting at the given address.
    // i_StartAddress:      The address in the EEPROM from which on the value is written.
    // i_ByteCount:         The number of bytes that are written in the EEPROM.
    // i_Value:             The value that is written into the EEPROM.
    static bool WriteRange_FromStart (uint16_t  i_StartAddress,
                                      uint16_t  i_ByteCount,
                                      uint8_t   i_Value);

    // Write the given value to the specified number of bytes in the EEPROM, ending at the given address.
    // i_EndAddress:        The address in the EEPROM up to which the value is written. This address is NOT included!
    // i_ByteCount:         The number of bytes that are written in the EEPROM.
    // i_Value:             The value that is written into the EEPROM.
    static bool WriteRange_ToEnd (uint16_t  i_EndAddress,
                                  uint16_t  i_ByteCount,
                                  uint8_t   i_Value);

    // Write the given value to the EEPROM, starting and ending at the given address.
    // i_StartAddress:  The address in the EEPROM from which on the value is written.
    // i_EndAddress:    The address in the EEPROM up to which the value is written. This position is NOT included!
    //                  If start address == end address, nothing will be written.
    // i_Value:         The value that is written into the EEPROM.
    static bool WriteRange_StartToEnd ( uint16_t  i_StartAddress,
                                        uint16_t  i_EndAddress,
                                        uint8_t   i_Value);
  };
}

#endif
