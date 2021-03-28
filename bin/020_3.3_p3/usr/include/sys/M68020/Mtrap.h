#ifndef SYS_M68020_MTRAP_H
#define SYS_M68020_MTRAP_H

/*	START NEW ARIX SCCS HEADER			*/
/*							*/
/*	@(#) Mtrap.h: version 24.1 created on 10/28/91 at 18:30:26	*/
/*							*/
/*	Copyright (c) 1990 by Arix Corporation		*/
/*	All Rights Reserved				*/
/*							*/
#ident	"@(#)Mtrap.h	24.1	10/28/91 Copyright (c) 1990 by Arix Corporation"
/*							*/
/*	END NEW ARIX SCCS HEADER			*/
/*							*/

/*		Copyright (c) 1985 AT&T		*/
/*		All Rights Reserved		*/

/*
 * Trap type values
 */

/*
*****************************************************
	The following traps apply to the Motorola 68K
	family of processors.  These defines are used
	by os/trap.c in the UNIX kernel.
*****************************************************
*/

#define BUSERR	2	/* Bus Error/Segment Violation (SIGBUS) */
#define ADDRERR	3	/* Address Error (SIGSEGV) */
#define INSTERR	4	/* Illegal Instruction Trap (SIGILL) */
#define ZDVDERR	5	/* Zero Divide Trap (SIGFPE) */
#define CHKTRAP	6	/* CHK Trap (SIGSEGV) */
#define TRAPVFT	7	/* TRAPV instruction fault (SIGILL) */
#define PRIVFLT	8	/* privileged instruction fault (SIGILL) */
#define TRCTRAP	9	/* Trace Trap (SIGTRAP) */
#define L1010FT	10	/* Line 1010 Emulator Trap (SIGILL) */
#define L1111FT	11	/* Line 1111 Emulator Trap (SIGILL) */
#define COPROTV 13	/* Coprocessor Protocol Violation (SIGILL) */
#define FMTERR	14	/* Format error--Illegal Exception Format (SIGILL) */
#define UNINTR	15	/* Uninitialized Interrupt Vector Error */
#define STRAYFT	24	/* Spurious Interrupt */
#define AUTO1	25	/* ARETE AUTO 1 */
#define AUTO2	26	/* ARETE AUTO 2 */
#define AUTO3	27	/* ARETE AUTO 3 */
#define AUTO4	28	/* ARETE AUTO 4 */
#define AUTO5	29	/* ARETE AUTO 5 */
#define AUTO6	30	/* ARETE AUTO 6 */
#define AUTO7	31	/* ARETE AUTO 7 */

/*
***************************************************************
	The following are generated by the 68K TRAP instruction
***************************************************************
*/

#define SYSCALL	32	/* TRAP 0 - System Call Trap */
#if not_arete
#define BPTFLT	33	/* TRAP 1 - Breakpoint Trap (SIGTRAP) */
#define IOTTRAP	34	/* TRAP 2 - Simulate DEC IOT Trap (SIGIOT) */
#define EMTTRAP	35	/* TRAP 3 - Simulate DEC EMT Trap (SIGEMT) */
#define FPETRAP	36	/* TRAP 4 - Floating Point Exception Trap (SIGFPE) */
#else
#define	TRAP1	33	/* ARETE TRAP 1 */
#define	TRAP2	34	/* ARETE TRAP 2 */
#define	TRAP3	35	/* ARETE TRAP 3 */
#define	TRAP4	36	/* ARETE TRAP 4 */
#define	TRAP5	37	/* ARETE TRAP 5 */
#define	TRAP6	38	/* ARETE TRAP 6 */
#define	TRAP7	39	/* ARETE TRAP 7 */
#define	TRAP8	40	/* ARETE TRAP 8 */
#define	TRAP9	41	/* ARETE TRAP 9 */
#define	TRAP10	42	/* ARETE TRAP 10 */
#define	TRAP11	43	/* ARETE TRAP 11 */
#define	TRAP12	44	/* ARETE TRAP 12 */
#define	TRAP13	45	/* ARETE TRAP 13 */
#define	TRAP14	46	/* ARETE TRAP 14 */
#define	TRAP15	47	/* ARETE TRAP 15 */
#endif


/* The following are 881-specific floating point exceptions. */
#define	FPTBSUN	48	/* FPU exc. - Branch or Set on UNordered cond.*/
			    /* at addr 192 or $C0 */
#define	FPTINEX	49	/* FPU exc. - INEXact result */
			    /* at addr 196 or $C4 */
#define	FPTDZ  	50	/* FPU exc. - Divide by Zero */
			    /* at addr 200 or $C8 */
#define	FPTUNFL	51	/* FPU exc. - UNderFLow */
			    /* at addr 204 or $CC */
#define	FPTOPER	52	/* FPU exc. - OPerand ERror */
			    /* at addr 208 or $D0 */
#define	FPTOVFL	53	/* FPU exc. - OVerFLow */
			    /* at addr 212 or $D4 */
#define	FPTSNAN	54	/* FPU exc. - Signalling NAN */
			    /* at addr 216 or $D8 */

#endif /* SYS_M68020_MTRAP_H */