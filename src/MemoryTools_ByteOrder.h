#ifndef MemoryTools_ByteOrder_h
#define MemoryTools_ByteOrder_h

#include <Arduino.h>

namespace MemoryTools
{
  class ByteOrder
  {
  private:

    ByteOrder () = delete;

  public:

    // Invert the order of the bytes of the given value.
    static int16_t Invert (int16_t i_Data);

    // Invert the order of the bytes of the given value.
    static uint16_t Invert (uint16_t i_Data);

    // Invert the order of the bytes of the given value.
    static int32_t Invert (int32_t i_Data);

    // Invert the order of the bytes of the given value.
    static uint32_t Invert (uint32_t i_Data);
  };
}

#endif
