from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def step(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 self=rnd(c,0xb0);sys=rnd(c,0x50);e.w32(0x70039c,sys)
 e.wf32(sys+0x48,r.choice([0.0,0.1,-0.1,1.0,float('nan'),float('inf'),r.uniform(-10,10)]))
 for off in (0x88,0x90):
  a=r.getrandbits(32);b=r.choice([a,r.getrandbits(32),0x80000000,0,1])
  e.w32(self+off,a);e.w32(self+off+4,b)
 for off,val in zip((0x68,0x60,0x5c,0x74,0x78,0x7c),(11,12,13,21,22,23)):e.w32(self+off,val)
 changes=[r.getrandbits(32) for _ in range(6)];mutate=r.random()<0.6
 def side(em,k):
  if mutate:em.w32(self+(0x8c if em.arg32(0)<20 else 0x94),changes[k])
 hook_rec(c,0x5d9f00,3,this=True,side=side)
 return [self]
S(0x5d98b0,'GUESS_step_two_integer_transitions','thiscall',None,ret=None,gen=step)
