#include "tests/threads/tests.h"
#include "threads/palloc.h"
#include <stdio.h>

void test_nextfit (void) 
{
  palloc_set_mode (PAL_NEXT_FIT);
  void* page1 = palloc_get_page(0);
  void* page2 = palloc_get_page(0);
  palloc_free_page(page1);
  void *page3 = palloc_get_page(0);

  if (page3 != page1)
	pass();
  palloc_free_page(page2);
  palloc_free_page(page3);
}

