#include <AUnit.h>

#include <MemoryTools_Memory.h>

using namespace MemoryTools;

//--------------------------------------------------------------------
test (Memory_Allocate_Test1)
{
  //---------- Arrange ----------
  uint8_t value = 0;
  uint8_t* pMemory = &value;

  //---------- Act ----------
  bool result = Memory::Allocate (pMemory, 0, 0x00);

  //---------- Assert ----------
  assertFalse (result);
  assertEqual (pMemory, &value);
}

//--------------------------------------------------------------------
test (Memory_Allocate_Test2)
{
  //---------- Arrange ----------
  uint8_t* pMemory = nullptr;

  //---------- Act ----------
  bool result = Memory::Allocate (pMemory, 0x7FFF, 0x00);

  //---------- Assert ----------
  assertFalse (result);
  assertEqual (pMemory, nullptr);

  //---------- Cleanup ----------
  delete (pMemory);
}

//--------------------------------------------------------------------
test (Memory_Allocate_Test3)
{
  //---------- Arrange ----------
  uint8_t* pMemory = 0;
  uint8_t  length  = 10;
  uint8_t  defaultValue = 0x9D;

  //---------- Act ----------
  bool result = Memory::Allocate (pMemory, length, defaultValue);

  //---------- Assert ----------
  assertTrue (result);
  assertNotEqual (pMemory, nullptr);
  for (int index = 0; index < length; index++)
    assertEqual (*(pMemory + index), defaultValue);

  //---------- Cleanup ----------
  delete (pMemory);
}

//--------------------------------------------------------------------
test (Memory_CheckAreasOverlap_Test1)
{
  //---------- Arrange ----------
  uint8_t length1 = 20;
  uint8_t length2 = 10;
  uint8_t* pMemory1 = new uint8_t[length1];
  uint8_t* pMemory2 = new uint8_t[length2];

  //---------- Act ----------
  bool result = Memory::CheckAreasOverlap (pMemory1, length1, pMemory2, length2);

  //---------- Assert ----------
  assertFalse (result);
  assertNotEqual (pMemory1, pMemory2);

  //---------- Cleanup ----------
  delete (pMemory1);
  delete (pMemory2);
}

//--------------------------------------------------------------------
test (Memory_CheckAreasOverlap_Test2)
{
  //---------- Arrange ----------
  uint8_t* pMemory1 = new uint8_t[20];

  //---------- Act & Assert ----------
  assertFalse (Memory::CheckAreasOverlap (pMemory1,  0, pMemory1,  0));
  assertTrue  (Memory::CheckAreasOverlap (pMemory1,  0, pMemory1, 10));
  assertTrue  (Memory::CheckAreasOverlap (pMemory1, 10, pMemory1,  0));

  assertTrue (Memory::CheckAreasOverlap (pMemory1, 10, pMemory1, 10));
  assertTrue (Memory::CheckAreasOverlap (pMemory1, 20, pMemory1, 10));
  assertTrue (Memory::CheckAreasOverlap (pMemory1, 10, pMemory1, 20));

  assertTrue (Memory::CheckAreasOverlap (pMemory1    , 10, pMemory1 + 5, 10));
  assertTrue (Memory::CheckAreasOverlap (pMemory1    , 20, pMemory1 + 5, 10));
  assertTrue (Memory::CheckAreasOverlap (pMemory1    , 10, pMemory1 + 5, 20));
  assertTrue (Memory::CheckAreasOverlap (pMemory1 + 5, 10, pMemory1    , 10));
  assertTrue (Memory::CheckAreasOverlap (pMemory1 + 5, 20, pMemory1    , 10));
  assertTrue (Memory::CheckAreasOverlap (pMemory1 + 5, 10, pMemory1    , 20));
  assertTrue (Memory::CheckAreasOverlap (pMemory1 + 5, 10, pMemory1 + 5, 10));
  assertTrue (Memory::CheckAreasOverlap (pMemory1 + 5, 20, pMemory1 + 5, 10));
  assertTrue (Memory::CheckAreasOverlap (pMemory1 + 5, 10, pMemory1 + 5, 20));

  assertFalse (Memory::CheckAreasOverlap (pMemory1     , 10, pMemory1 + 10, 10));
  assertTrue  (Memory::CheckAreasOverlap (pMemory1     , 20, pMemory1 + 10, 10));
  assertFalse (Memory::CheckAreasOverlap (pMemory1     , 10, pMemory1 + 10, 20));
  assertFalse (Memory::CheckAreasOverlap (pMemory1 + 10, 10, pMemory1     , 10));
  assertFalse (Memory::CheckAreasOverlap (pMemory1 + 10, 20, pMemory1     , 10));
  assertTrue  (Memory::CheckAreasOverlap (pMemory1 + 10, 10, pMemory1     , 20));
  assertTrue  (Memory::CheckAreasOverlap (pMemory1 + 10, 10, pMemory1 + 10, 10));
  assertTrue  (Memory::CheckAreasOverlap (pMemory1 + 10, 20, pMemory1 + 10, 10));
  assertTrue  (Memory::CheckAreasOverlap (pMemory1 + 10, 10, pMemory1 + 10, 20));

  assertFalse (Memory::CheckAreasOverlap (pMemory1     , 10, pMemory1 + 25, 10));
  assertFalse (Memory::CheckAreasOverlap (pMemory1     , 20, pMemory1 + 25, 10));
  assertFalse (Memory::CheckAreasOverlap (pMemory1     , 10, pMemory1 + 25, 20));
  assertFalse (Memory::CheckAreasOverlap (pMemory1 + 25, 10, pMemory1     , 10));
  assertFalse (Memory::CheckAreasOverlap (pMemory1 + 25, 20, pMemory1     , 10));
  assertFalse (Memory::CheckAreasOverlap (pMemory1 + 25, 10, pMemory1     , 20));
  assertTrue  (Memory::CheckAreasOverlap (pMemory1 + 25, 10, pMemory1 + 25, 10));
  assertTrue  (Memory::CheckAreasOverlap (pMemory1 + 25, 20, pMemory1 + 25, 10));
  assertTrue (Memory::CheckAreasOverlap (pMemory1 + 25, 10, pMemory1 + 25, 20));

  //---------- Cleanup ----------
  delete (pMemory1);
}

//--------------------------------------------------------------------
void setup ()
{
  Serial.begin (115200);
  delay (2000);
}

void loop ()
{
  aunit::TestRunner::run ();
}
