from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 n=r.randrange(1,32);order=list(range(n));r.shuffle(order)
 L={i:None for i in order};R=L.copy();P=L.copy();C={i:0 for i in order};root=None
 def rotate(x,left):
  nonlocal root
  A,B=(R,L) if left else (L,R);y=A[x];A[x]=B[y]
  if B[y] is not None:P[B[y]]=x
  P[y]=P[x]
  if P[x] is None:root=y
  elif x==L[P[x]]:L[P[x]]=y
  else:R[P[x]]=y
  B[y]=x;P[x]=y
 for z in order:
  p=None;x=root
  while x is not None:p=x;x=L[x] if z<x else R[x]
  P[z]=p
  if p is None:root=z
  elif z<p:L[p]=z
  else:R[p]=z
  x=z
  while P[x] is not None and C[P[x]]==0:
   p=P[x];grand=P[p]
   if p==L[grand]:
    uncle=R[grand]
    if uncle is not None and C[uncle]==0:C[p]=C[uncle]=1;C[grand]=0;x=grand
    else:
     if x==R[p]:x=p;rotate(x,True)
     C[P[x]]=1;C[P[P[x]]]=0;rotate(P[P[x]],False)
   else:
    uncle=L[grand]
    if uncle is not None and C[uncle]==0:C[p]=C[uncle]=1;C[grand]=0;x=grand
    else:
     if x==L[p]:x=p;rotate(x,False)
     C[P[x]]=1;C[P[P[x]]]=0;rotate(P[P[x]],True)
  C[root]=1
 nodes={i:rnd(c,20) for i in order};header=rnd(c,20)
 for i,p in nodes.items():
  e.wbytes(p,bytes([C[i]]));e.w32(p+1,nodes[P[i]] if P[i] is not None else header);e.w32(p+5,nodes[L[i]] if L[i] is not None else 0);e.w32(p+9,nodes[R[i]] if R[i] is not None else 0)
 refs=rnd(c,12);e.w32(refs,nodes[root]);e.w32(refs+4,nodes[0]);e.w32(refs+8,nodes[n-1])
 def rot(em,k,left):
  x,ref=em.reg('ecx'),em.reg('edx');a,b=(9,5) if left else (5,9);y=em.r32(x+a);par=em.r32(x+1);child=em.r32(y+b)
  em.calllog.append(('rotate',left,x,ref));em.w32(x+a,child)
  if child:em.w32(child+1,x)
  em.w32(y+1,par)
  if em.r32(ref)==x:em.w32(ref,y)
  elif em.r32(par+5)==x:em.w32(par+5,y)
  else:em.w32(par+9,y)
  em.w32(y+b,x);em.w32(x+1,y)
 hook_rec(c,0x430910,0,this=True,side=lambda em,k:rot(em,k,True));hook_rec(c,0x430960,0,this=True,side=lambda em,k:rot(em,k,False))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [nodes[r.randrange(n)],refs,refs+4,refs+8]
S(0x430620,'GUESS red black erase rebalance','fastcall',None,ret='eax',gen=g,note='batch128012')
