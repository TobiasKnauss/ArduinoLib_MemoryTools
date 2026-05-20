#include "MemoryTools.h"

//--------------------------------------------------------------------
bool CheckMemoryAreasOverlap (uint8_t* i_pArea1,
                              uint16_t i_Area1Length,
                              uint8_t* i_pArea2,
                              uint16_t i_Area2Length)
{
  if (i_pArea1 == nullptr
  ||  i_pArea2 == nullptr)
    return false;

  uint8_t* area1End = i_pArea1 + i_Area1Length;
  uint8_t* area2End = i_pArea2 + i_Area2Length;

  return (i_pArea1 >= i_pArea2 && i_pArea1 < area2End)
      || (i_pArea2 >= i_pArea1 && i_pArea2 < area1End);
}

//--------------------------------------------------------------------
bool Memory_Allocate (uint8_t*& o_pMemory,
                      uint16_t  i_Length,
                      uint8_t   i_DefaultValue)
{
  if (o_pMemory != nullptr)  // memory is allocated already
    return false;

  o_pMemory = new uint8_t[i_Length];
  if (o_pMemory == nullptr)
    return false;

  memset (o_pMemory, i_DefaultValue, i_Length);
  return true;
}

//--------------------------------------------------------------------
void Memory_PrintLn (uint8_t* i_pMemory,
                     uint16_t i_Length)
{
  if (i_pMemory == nullptr)
    return;

  for (uint16_t index = 0; index < i_Length; index++)
    Serial.print (i_pMemory[index], HEX2);
  Serial.println ();
}

