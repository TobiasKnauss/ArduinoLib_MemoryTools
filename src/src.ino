#include "MemoryTools.h"

class CTest
{
public:
  int m_Value = 1;
};

void setup ()
{
  CTest* pTest = new CTest ();
  DeleteObject (pTest);
}

void loop ()
{
}
