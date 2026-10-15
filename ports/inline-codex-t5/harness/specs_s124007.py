from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x633654,0,pop=0)
 # Real fixed-size matrix copy initializes all nine local dwords.
 backing=rnd(c,0x60);child=rnd(c,0x20);e.w32(backing+0x50,r.choice([0,child,child]))
 matrix=rnd(c,36);vec=rnd(c,12)
 def writeout(em,k):
  for i in range(3):em.w32(em.arg32(0)+4*i,outputs[(k*3+i)%9])
 outputs=[r.getrandbits(32) for _ in range(9)]
 hook_rec(c,0x4db1f0,1,this=True,deref={0:3},side=writeout)
 hook_rec(c,0x4db270,1,this=True,stackmark=[0],side=writeout)
 def transform(em,k):
  em.calllog.append(('transform',tuple(em.r32(em.reg('ecx')+4*i) for i in range(3)),tuple(em.r32(em.reg('edx')+4*i) for i in range(3))))
  em.w32(em.reg('ecx'),(em.r32(em.reg('ecx'))^outputs[k%9]))
 hook_rec(c,0x43e960,0,this='mark',side=transform)
 hook_rec(c,0x441a60,0,this='mark',side=transform)
 hook_rec(c,0x4dcac0,2,this=True,deref={0:9,1:3})
 me=rnd(c,0x60);e.w32(me+0x50,r.choice([0,backing,backing,backing]))
 return [me,matrix,vec]
S(0x4dcf80,'GUESS apply linked matrix and position','thiscall',None,ret=None,gen=g,note='batch124007')
