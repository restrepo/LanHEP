#include <setjmp.h>
#include "lanhep.h"

extern jmp_buf alg1_jmp_buf;


Term namely_w_t(Term t)
	{
	Term tt,sub;
	List l1,l2,l3;
	l3=NewList();
	tt=ConsumeCompoundArg(t,1);
	sub=ConsumeCompoundArg(t,2);
	FreeAtomic(t);
	l1=OperToList(sub,OPR_SECO);
	l2=l1;
	while(!is_empty_list(l2))
		{
		List la,lai,ll;
		lai=NewList();
		la=CommaToList(ListFirst(l2));
		ll=la;
		while(!is_empty_list(ll))
			{
			lai=AppendLast(lai,
				InterfSetAlias(MakeCompound1(OPR_ALIAS,ListFirst(ll)),0));
			ll=ListTail(ll);
			}
		l3=AppendFirst(l3,ProcessAlias(CopyTerm(tt)));
		RemoveAlias(lai);
		RemoveList(la);
		l2=ListTail(l2);
		}
	RemoveList(l1);
	l1=l2plus(l3);
	RemoveList(l3);
	return l1;
	}	



Term WheredTerm(Term t)
	{
	if(is_compound(t) && CompoundName(t)==OPR_WHERE && CompoundArity(t)==2)
		return WheredTerm(namely_w_t(t));
	if(is_atomic(t))
		return t;
	if(is_compound(t))
		{
		Term t1;
		int ac,i;
		ac=CompoundArity(t);
		t1=NewCompound(CompoundFunctor(t));
		for(i=1;i<=ac;i++)
			SetCompoundArg(t1,i,WheredTerm(ConsumeCompoundArg(t,i)));
		FreeAtomic(t);
		return t1;
		}
	if(is_list(t))
		{
		List l,tl;
		tl=t;
		l=NewList();
		while(!is_empty_list(tl))
			{
			l=AppendLast(l,WheredTerm(ListFirst(tl)));
			tl=ListTail(tl);
			}
		RemoveList(t);
		return l;	
		}
	return t;
	}
	

static List check_list(List l)
{
	List l2, nl;
	int ll=0, i;
	
	
	for(l2=ListFirst(l);l2;l2=ListTail(l2))
	{
	Term t=ListFirst(l2);
	if(!is_compound(t) || CompoundArity(t)!=2)
		{
		ErrorInfo(0);printf("where: bad substitution ");WriteTerm(t);puts("");
		return l;
		}
	if(is_list(CompoundArg2(t)))
	{
		if(ll==0)
			ll=ListLength(CompoundArg2(t));
		else if(ll!=ListLength(CompoundArg2(t)))
		{
		ErrorInfo(0);puts("where: list length is different.");
		return l;
		}
	}
	}
	
	if(ll==0)
		return l;
	
	nl=NewList();
	for(i=1;i<=ll;i++)
	{
		List nl1=NewList();
		for(l2=ListFirst(l);l2;l2=ListTail(l2))
		{
		Term t,t2;
		t=ListFirst(l2);
		t2=MakeCompound2(OPR_EQSIGN,CompoundArg1(t),is_list(CompoundArg2(t))?
			ListNth(CompoundArg2(t),i):CompoundArg2(t));
		nl1=AppendLast(nl1,t2);
		}
		nl=AppendLast(nl,nl1);
	}
	FreeAtomic(l);
	return nl;
}


Term ProcWhere(Term t, Term ind)
{
	Term tt,sub;
	List l1,l2;
	if(!is_compound(t) ||CompoundArity(t)!=2)
	{
		ErrorInfo(0);
		puts("where: wrong syntax");
		return 0;
	}
	tt=ConsumeCompoundArg(t,1);
	sub=ConsumeCompoundArg(t,2);
	FreeAtomic(t);
	l1=OperToList(sub,OPR_SECO);
	
	for(l2=l1;l2;l2=ListTail(l2))
		ChangeList(l2,CommaToList(ListFirst(l2)));
/*	DumpList(l1);*/
	if(ListLength(l1)==1)
		l1=check_list(l1);
/*	DumpList(l1);*/
	l2=l1;
	while(!is_empty_list(l2))
		{
		List la,lai,ll;
		lai=NewList();
		la= /*CommaToList*/ (ListFirst(l2));
		ll=la;
		while(!is_empty_list(ll))
			{
			lai=AppendLast(lai,
				InterfSetAlias(MakeCompound1(OPR_ALIAS,ListFirst(ll)),0));
			ll=ListTail(ll);
			}
		ProcessTerm(ProcessAlias(CopyTerm(tt)));
		RemoveAlias(lai);
		RemoveList(la);
		l2=ListTail(l2);
		}
	RemoveList(l1);
	return 0;
}	
	
	
	

