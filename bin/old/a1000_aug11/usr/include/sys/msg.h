#ifndef SYS_MSG_H
#define SYS_MSG_H

/*	START NEW ARIX SCCS HEADER			*/
/*							*/
/*	@(#) msg.h: version 2.1 created on 5/22/89 at 19:08:52	*/
/*							*/
/*	Copyright (c) 1988 by Arix Corporation		*/
/*	All Rights Reserved				*/
/*							*/
#ident	"@(#)msg.h	2.1	5/22/89 Copyright (c) 1988 by Arix Corporation"
/*							*/
/*	END NEW ARIX SCCS HEADER			*/
/*							*/
/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*	ATT: #ident	"kern-port:sys/msg.h	10.4"		*/

#ident	"@(#)uts/head/sys:msg.h	2.1"

/*
**	IPC Message Facility.
*/

/*
**	Implementation Constants.
*/

#define	PMSG	(PZERO + 2)	/* message facility sleep priority */

/*
**	Permission Definitions.
*/

#define	MSG_R	0400	/* read permission */
#define	MSG_W	0200	/* write permission */

/*
**	ipc_perm Mode Definitions.
*/

#define	MSG_RWAIT	01000	/* a reader is waiting for a message */
#define	MSG_WWAIT	02000	/* a writer is waiting to send */

/*
**	Message Operation Flags.
*/

#define	MSG_NOERROR	010000	/* no error if big message */

/*
**	Structure Definitions.
*/

/*
**	There is one msg queue id data structure for each q in the system.
*/

struct msqid_ds {
	struct ipc_perm	msg_perm;	/* operation permission struct */
	struct msg	*msg_first;	/* ptr to first message on q */
	struct msg	*msg_last;	/* ptr to last message on q */
	ushort		msg_cbytes;	/* current # bytes on q */
	ushort		msg_qnum;	/* # of messages on q */
	ushort		msg_qbytes;	/* max # of bytes on q */
	ushort		msg_lspid;	/* pid of last msgsnd */
	ushort		msg_lrpid;	/* pid of last msgrcv */
	time_t		msg_stime;	/* last msgsnd time */
	time_t		msg_rtime;	/* last msgrcv time */
	time_t		msg_ctime;	/* last change time */
};

/*
**	There is one msg structure for each message that may be in the system.
*/

struct msg {
	struct msg	*msg_next;	/* ptr to next message on q */
	long		msg_type;	/* message type */
	short		msg_ts;		/* message text size */
	short		msg_spot;	/* message text map address */
};

/*
**	User message buffer template for msgsnd and msgrecv system calls.
*/

struct msgbuf {
	long	mtype;		/* message type */
	char	mtext[1];	/* message text */
};

/*
**	Message information structure.
*/

struct msginfo {
	int	msgmap,	/* # of entries in msg map */
		msgmax,	/* max message size */
		msgmnb,	/* max # bytes on queue */
		msgmni,	/* # of message queue identifiers */
		msgssz,	/* msg segment size (should be word size multiple) */
		msgtql;	/* # of system message headers */
	ushort	msgseg;	/* # of msg segments (MUST BE < 32768) */
};

/*	We have to be able to lock a message queue since we can
**	sleep during message processing due to a page fault in
**	copyin/copyout or iomove.  We cannot add anything to the
**	msqid_ds structure since this is used in user programs
**	and any change would break object file compatibility.
**	Therefore, we allocate a parallel array, msglock, which
**	is used to lock a message queue.  The array is defined
**	in the msg master file.  The following macro takes a
**	pointer to a message queue and returns a pointer to the
**	lock entry.  The argument must be a pointer to a msgqid
**	structure.
**/

#define	MSGLOCK(X)	&msglock[X - msgque]

#endif /* SYS_MSG_H */