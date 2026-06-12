#ifndef MemoryTools_h
#define MemoryTools_h

namespace MemoryTools
{
  // Delete the object if it exists and set the pointer to NULL.
  // io_pObject: The pointer to the object that will be deleted.
  template <typename T>
  void DeleteObject (T& io_pObject)
  {
    delete (io_pObject);
    io_pObject = nullptr;
  }
}

#endif
