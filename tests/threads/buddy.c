#include "tests/threads/tests.h"
#include "threads/palloc.h"
#include <stdio.h>
void test_buddy (void) 
{
  palloc_set_mode (PAL_BUDDY);
  void* page1 = palloc_get_page(0);
  msg("Allocated A at index 0");
  void* page2 = palloc_get_multiple(0, 4);
  msg("Allocated B at index 4"); 
  void* page3 = palloc_get_multiple(0, 16);
  if (palloc_get_page_index(page3) % 16 != 0)
	fail("page3 Failed");
  if (palloc_get_page_index(page2) % 4 == 0)
	pass();
  palloc_free_page(page1);
  palloc_free_multiple(page2, 4);
}
