/*	START NEW ARIX SCCS HEADER			*/
/*							*/
/*	@(#) libgen.h: version 25.1 created on 12/2/91 at 19:33:02	*/
/*							*/
/*	Copyright (c) 1990 by Arix Corporation		*/
/*	All Rights Reserved				*/
/*							*/
#ident	"@(#)libgen.h	25.1	12/2/91 Copyright (c) 1990 by Arix Corporation"
/*							*/
/*	END NEW ARIX SCCS HEADER			*/
/*							*/
/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*	ATT:#ident	"libgen:libgen.h	2.4"	*/
	
#ident	"@(#)libgen:libgen.h	25.1"


/*	declarations of functions found in libgen
*/


extern char * basename();

extern unsigned char * bgets();

extern unsigned bufsplit();

extern char * copylist();

extern char * day();

extern char * dirname();

extern int eaccess();

extern int incount();

extern int julian();

extern int leap();

extern int mkdirp();

extern int num();

extern int numd();

extern p2open();

extern int p2close();

extern char * pathfind();

extern char * regerror();

extern int rmdirp();

extern int sesystem();

extern short sgets();

extern char * smemcpy();

extern void sputs();

extern char * stradd();

extern char * strccpy();

extern char * strecpy();

extern int strnlen();

extern char * sweekday();

extern long tconv();

extern long tconvs();

extern void to_date();

extern long to_day();

extern char * triml();

extern char * trimt();

extern int waitpid();

extern int weekday();