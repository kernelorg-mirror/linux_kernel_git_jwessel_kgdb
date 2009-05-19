/*
 * Created by: Jason Wessel <jason.wessel@windriver.com>
 *
 * Copyright (c) 2009 Wind River Systems, Inc.  All Rights Reserved.
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2. This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#ifndef _DEBUG_CORE_H_
#define _DEBUG_CORE_H_
/*
 * These are the private implementation headers between the kernel
 * debugger core and the debugger front end code.
 */

/* kernel debug core data structures */
struct kgdb_state {
	int			ex_vector;
	int			signo;
	int			err_code;
	int			cpu;
	int			pass_exception;
	unsigned long		thr_query;
	unsigned long		threadid;
	long			kgdb_usethreadid;
	struct pt_regs		*linux_regs;
};

struct debuggerinfo_struct {
	void			*debuggerinfo;
	struct task_struct	*task;
};

extern struct debuggerinfo_struct kgdb_info[];

/* kernel debug core break point routines */
extern int dbg_remove_all_break(void);
extern int dbg_set_sw_break(unsigned long addr);
extern int dbg_remove_sw_break(unsigned long addr);
extern int dbg_activate_sw_breakpoints(void);

/* gdbstub interface functions */
extern int gdb_serial_stub(struct kgdb_state *ks);
extern void gdbstub_msg_write(const char *s, int len);

#endif /* _DEBUG_CORE_H_ */
