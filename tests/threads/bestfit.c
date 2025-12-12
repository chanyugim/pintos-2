#include "tests/threads/tests.h"
#include "threads/palloc.h"
#include <stdio.h>

void test_bestfit (void) 
{
  palloc_set_mode (PAL_BEST_FIT);
  void* page1 = palloc_get_multiple(0, 4);
  void* page2 = palloc_get_multiple(0, 5);
  void* page3 = palloc_get_multiple(0, 3);
  void* page4 = palloc_get_multiple(0, 5);
  void* page5 = palloc_get_multiple(0, 6);
  void* page6 = palloc_get_page(0);

  palloc_free_multiple(page1, 4);
  palloc_free_multiple(page3, 3);
  palloc_free_multiple(page5, 6);
  void* test_best_page = palloc_get_multiple(0, 3);

  if(test_best_page == page3)
	pass();
  palloc_free_multiple(page2, 5);
  palloc_free_multiple(page4, 5);
  palloc_free_page(page6);
  palloc_free_multiple(test_best_page, 3);
}
