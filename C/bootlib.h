#ifndef BOOTLIB_H
#define BOOTLIB_H

#include <stdbool.h>
#include <stddef.h>

void *boot_malloc(size_t size);
void boot_free(void *ptr);

// Returns true if every block allocated with malloc() (in a file that
// includes this header) has since been passed to free().
bool boot_all_freed(void);

// Returns the total number of bytes currently allocated and not yet freed
// by files that include this header.
size_t boot_alloc_size(void);

// Route malloc/free through the tracking versions above in any file that
// includes this header, so leaks and allocation sizes can be checked in
// tests. Define BOOTLIB_NO_OVERRIDE before including this header to get
// the declarations without the redirection (used by bootlib.c itself).
#ifndef BOOTLIB_NO_OVERRIDE
#define malloc(size) boot_malloc(size)
#define free(ptr) boot_free(ptr)
#endif

#endif
