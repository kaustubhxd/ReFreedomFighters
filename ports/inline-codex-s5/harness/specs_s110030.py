from pilot import S
from recruits_util import clear_hooks,rnd,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 t=rnd(c,0x1600)
 for off in [0x8c,0x90]:e.w32(t+off,r.choice([-1,0,1,2,3,4,6])&0xffffffff)
 for off in [0x68,0x6c,0x74,0x7c,0x94,0x98]:e.wf32(t+off,r.choice([0.,-0.,.0001220703125,r.uniform(-100,100),r.uniform(-1,1)]))
 if r.random()<.3:
  for off,v in [(0x68,10.),(0x6c,100.),(0x7c,1.),(0x94,1.)]:e.wf32(t+off,v)
  e.w32(t+0x90,2)
 return [t]
S(0x526ac0,'GUESS car weight transfer','thiscall',None,ret=None,gen=gen)
