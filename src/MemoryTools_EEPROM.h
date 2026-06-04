#ifndef MemoryTools_EEPROM_h
#define MemoryTools_EEPROM_h

#include <Arduino.h>

uint16_t EEPROM_CalcChecksumCRC16 (uint16_t i_StartAddress,
                                   uint16_t i_ByteCount);

// Check if the given address is a valid address in the EEPROM, not exceeding the size of the EEPROM.
bool EEPROM_CheckAddress (uint16_t i_Address);

bool EEPROM_CheckAddressRange ( uint16_t  i_Address,
                                uint16_t  i_ByteCount);

// Write the specified number of bytes from the EEPROM to the given destination pointer and move the pointer forward.
bool EEPROM_GetBytesAndMovePtr (uint16_t& io_Address,
                                uint16_t  i_ByteCount,
                                uint8_t*  i_pDestination);

// Get a BOOL value from the EEPROM and move the pointer forward.
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                bool&     o_Value);

// Get an UINT8 value from the EEPROM and move the pointer forward.
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                uint8_t&  o_Value);

// Get an INT8 value from the EEPROM and move the pointer forward.
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                int8_t&  o_Value);

// Get an UINT16 value from the EEPROM and move the pointer forward.
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                uint16_t& o_Value);

// Get an INT16 value from the EEPROM and move the pointer forward.
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                int16_t& o_Value);

// Get an UINT32 value from the EEPROM and move the pointer forward.
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                uint32_t& o_Value);

// Get an INT32 value from the EEPROM and move the pointer forward.
bool EEPROM_GetValueAndMovePtr (uint16_t& io_Address,
                                int32_t& o_Value);

// Write the specified number of bytes from the given source pointer to the EEPROM and move the pointer forward.
bool EEPROM_SetBytesAndMovePtr (uint16_t& io_Address,
                                uint16_t  i_ByteCount,
                                uint8_t*  i_pSource);

// Put a BOOL value into the EEPROM and move the pointer forward.
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                bool      i_Value);

// Put an UINT8 value into the EEPROM and move the pointer forward.
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                uint8_t   i_Value);

// Put an INT8 value into the EEPROM and move the pointer forward.
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                int8_t    i_Value);

// Put an UINT16 value into the EEPROM and move the pointer forward.
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                uint16_t  i_Value);

// Put an INT16 value into the EEPROM and move the pointer forward.
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                int16_t   i_Value);

// Put an UINT32 value into the EEPROM and move the pointer forward.
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                uint32_t  i_Value);

// Put an INT32 value into the EEPROM and move the pointer forward.
bool EEPROM_SetValueAndMovePtr (uint16_t& io_Address,
                                int32_t   i_Value);

// Write the given value to the specified number of bytes in the EEPROM, starting at the given address.
// i_StartAddress:      The address in the EEPROM from which on the value is written.
// i_ByteCount:         The number of bytes that are written in the EEPROM.
// i_Value:             The value that is written into the EEPROM.
bool EEPROM_SetValue_FromStart (uint16_t  i_StartAddress,
                                uint16_t  i_ByteCount,
                                uint8_t   i_Value);

// Write the given value to the specified number of bytes in the EEPROM, ending at the given address.
// i_EndAddress:        The address in the EEPROM up to which the value is written. This address is NOT included!
// i_ByteCount:         The number of bytes that are written in the EEPROM.
// i_Value:             The value that is written into the EEPROM.
bool EEPROM_SetValue_FromEnd (uint16_t  i_EndAddress,
                              uint16_t  i_ByteCount,
                              uint8_t   i_Value);

// Write the given value to the EEPROM, starting and ending at the given address.
// i_StartOffset:       The address in the EEPROM from which on the value is written.
// i_EndOffset:         The address in the EEPROM up to which the value is written. This position is NOT included!
//                      If start offset == end offset, nothing will be written.
// i_Value:             The value that is written into the EEPROM.
bool EEPROM_SetValue_StartToEnd ( uint16_t  i_StartAddress,
                                  uint16_t  i_EndAddress,
                                  uint8_t   i_Value);

#endif
