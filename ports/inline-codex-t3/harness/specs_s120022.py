from pilot import S,F
from recruits_util import rnd,clear_hooks,pystub,hook_rec,stub_memset

def enqueue(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));stub_memset(c)
 self=rnd(c,0x400);sys=rnd(c,0x50);e.w32(0x70039c,sys)
 e.w32(self+0x80,r.choice([0,1,2,3,4,5,6]))
 hook_rec(c,0x43d310,0,this=True,st0=r.choice([0.0,-0.0,1.0,float('nan'),float('inf'),r.uniform(-10,10)]))
 delay=r.choice([0.0,-0.0,1.0,-1.0,float('nan'),float('inf'),r.uniform(-10,10)])
 return [self,r.choice([0,1,2,11,12,0xffffffff,r.getrandbits(32)]),F(delay),F(r.uniform(-10,10))]
S(0x43d980,'GUESS_enqueue_timed_effect','thiscall',None,ret='al',gen=enqueue)
