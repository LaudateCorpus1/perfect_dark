#include "libultra_internal.h"
#include "data.h"

void __osSpSetStatus(u32 data)
{
	IO_WRITE(SP_STATUS_REG, data);
}
