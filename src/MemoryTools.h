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


// Print the hexadecimal values of the specified memory block.
// i_pMemory: The start address of the memory block.
// i_Length:  The length of the memory block.
void Memory_PrintLn (uint8_t* i_pMemory,
                     uint16_t i_Length);

// Write the specified number of bytes from the ring buffer to the given destination pointer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_GetBytesAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint16_t  i_ByteCount,
                                    uint8_t*  i_pDestination);

// Get a BOOL value from the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    bool&     o_Value);

// Get an UINT8 value from the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint8_t&  o_Value);

// Get an INT8 value from the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int8_t&  o_Value);

// Get an UINT16 value from the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint16_t& o_Value);

// Get an INT16 value from the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int16_t& o_Value);

// Get an UINT32 value from the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint32_t& o_Value);

// Get an INT32 value from the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_GetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int32_t& o_Value);

// Increment the pointer to data inside a ring buffer.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_IncrementPointer (uint8_t*  i_pRingBuffer,
                                  uint16_t  i_RingBufferLength,
                                  uint8_t*& io_pCurrent);

// Write the specified number of bytes from the given source pointer to the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_SetBytesAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint16_t  i_ByteCount,
                                    uint8_t*  i_pSource);

// Put a BOOL value into the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    bool      i_Value);

// Put an UINT8 value into the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint8_t   i_Value);

// Put an INT8 value into the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int8_t    i_Value);

// Put an UINT16 value into the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint16_t  i_Value);

// Put an INT16 value into the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int16_t   i_Value);

// Put an UINT32 value into the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    uint32_t  i_Value);

// Put an INT32 value into the ring buffer and move the pointer forward.
// If the end of the ring buffer is reached, wrap the pointer around to the buffer start.
bool RingBuffer_SetValueAndMovePtr (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint8_t*& io_pCurrent,
                                    int32_t   i_Value);

// Write the given value to the specified number of bytes in the ring buffer, starting at the given buffer position.
// i_pRingBuffer:       The start address of the ring buffer.
// i_RingBufferLength:  The length of the ring buffer.
// i_StartOffset:       The relative position in the ring buffer from which on the value is written.
// i_ByteCount:         The number of bytes that are written in the buffer.
// i_Value:             The value that is written into the buffer.
bool RingBuffer_SetValue_FromStart (uint8_t*  i_pRingBuffer,
                                    uint16_t  i_RingBufferLength,
                                    uint16_t  i_StartOffset,
                                    uint16_t  i_ByteCount,
                                    uint8_t   i_Value);

// Write the given value to the specified number of bytes in the ring buffer, ending at the given buffer position.
// i_pRingBuffer:       The start address of the ring buffer.
// i_RingBufferLength:  The length of the ring buffer.
// i_EndOffset:         The relative position in the ring buffer up to which the value is written. This position is NOT included!
// i_ByteCount:         The number of bytes that are written in the buffer.
// i_Value:             The value that is written into the buffer.
bool RingBuffer_SetValue_FromEnd (uint8_t*  i_pRingBuffer,
                                  uint16_t  i_RingBufferLength,
                                  uint16_t  i_EndOffset,
                                  uint16_t  i_ByteCount,
                                  uint8_t   i_Value);

// Write the given value to the ring buffer, starting and ending at the given buffer positions.
// i_pRingBuffer:       The start address of the ring buffer.
// i_RingBufferLength:  The length of the ring buffer.
// i_StartOffset:       The relative position in the ring buffer from which on the value is written.
// i_EndOffset:         The relative position in the ring buffer up to which the value is written. This position is NOT included!
//                      If start offset == end offset, the entire buffer will be written.
// i_Value:             The value that is written into the buffer.
bool RingBuffer_SetValue_StartToEnd (uint8_t*  i_pRingBuffer,
                                     uint16_t  i_RingBufferLength,
                                     uint16_t  i_StartOffset,
                                     uint16_t  i_EndOffset,
                                     uint8_t   i_Value);

#endif
