#ifndef MemoryTools_ByteOrder_h
#define MemoryTools_ByteOrder_h

#include <Arduino.h>

// Invert the order of the bytes of the given value.
int16_t ByteOrder_Invert (int16_t i_Data);

// Invert the order of the bytes of the given value.
uint16_t ByteOrder_Invert (uint16_t i_Data);

// Invert the order of the bytes of the given value.
int32_t ByteOrder_Invert (int32_t i_Data);

// Invert the order of the bytes of the given value.
uint32_t ByteOrder_Invert (uint32_t i_Data);

#endif
