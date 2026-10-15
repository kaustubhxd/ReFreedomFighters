from pilot import S,EDGE_F
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 me=rnd(c,0xa0);src=rnd(c,12)
 for p in (src,):
  for i in range(3):e.wf32(p+4*i,r.choice(EDGE_F+[r.uniform(-100,100)]))
 for off in (0x11,0x2d,0x35):e.wf32(me+off,r.choice(EDGE_F+[r.uniform(-10,10)]))
 for a in (0x5243f0,0x5243d0):
  hook_rec(c,a,1,this=True,side=lambda em,k:em.w32(em.reg('ecx')+8,em.arg32(0)))
 hook_rec(c,0x516130,2,this=True,st0=r.choice(EDGE_F+[r.uniform(-10,10)]))
 hook_rec(c,0x5243a0,0,this=True,st0=r.choice(EDGE_F+[r.uniform(-10,10)]))
 hook_rec(c,0x524980,2,this=True);hook_rec(c,0x5247e0,0,this=True)
 e.w32(0x7003b0,pystub(c,0))
 return [me,src]
S(0x516360,'initialize damper at ground','thiscall',None,ret=None,gen=gen,nan_heap=True)
