#ifndef MemoryTools_h
#define MemoryTools_h

#include <Arduino.h>

// Check if the specified memory areas overlap.
// i_pArea1:      The start address of the first memory area.
// i_Area1Length: The length of the first memory area.
// i_pArea2:      The start address of the second memory area.
// i_Area2Length: The length of the second memory area.
bool CheckMemoryAreasOverlap (uint8_t* i_pArea1,
                              uint16_t i_Area1Length,
                              uint8_t* i_pArea2,
                              uint16_t i_Area2Length);

// Delete the object if it exists and set the pointer to NULL.
// io_pObject: The pointer to the object that will be deleted.
template <typename T>
void DeleteObject (T& io_pObject)
{
  delete (io_pObject);
  io_pObject = nullptr;
}

// Allocate the desired amount of memory for a byte-array, set the given default value on the entire memory and return the pointer to that memory.
// If the pointer is not zero at the beginning or if the allocation fails, the return value is FALSE.
bool Memory_Allocate (uint8_t*& o_pMemory,
                      uint16_t  i_Length,
                      uint8_t   i_DefaultValue);

// Print the hexadecimal values of the specified memory block.
// i_pMemory: The start address of the memory block.
// i_Length:  The length of the memory block.
void Memory_PrintLn (uint8_t* i_pMemory,
                     uint16_t i_Length);

#endif
