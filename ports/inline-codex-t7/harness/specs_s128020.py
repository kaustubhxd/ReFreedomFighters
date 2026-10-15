from pilot import S
from recruits_util import rnd,obj,reftab,clear_hooks,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 forms=[]
 for _ in range(r.randrange(5)):
  p=rnd(c,0x98)
  members=[rnd(c,0x28) for _ in range(r.randrange(5))];other=[rnd(c,0x28) for _ in range(r.randrange(5))]
  e.w32(p+4,reftab(c,members,count=len(members)));e.w32(p+8,reftab(c,other,count=len(other)));forms.append(p)
 me=rnd(c,0x50);table=reftab(c,forms,count=len(forms));e.w32(me+0x48,r.choice([0,table,table,table]))
 detach=r.randrange(12)==0
 def write(em,k):
  ptr,n=em.arg32(0),em.arg32(1);em.calllog.append(('block',n,em.rbytes(ptr,n)))
  if detach and k==0:em.w32(me+0x48,0)
 stream=obj(c,32,{0x10:pystub(c,2,this=True,stackmark=(0,),side=write)})
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,stream]
S(0x5b7100,'GUESS CFormationControl Save','thiscall',None,ret='al',gen=g,note='batch128020')
