#ifdef CONFIG_X86_32
# include "processor_32.h"
#else
# include "processor_64.h"
extern void early_trap_init(void);

#endif
