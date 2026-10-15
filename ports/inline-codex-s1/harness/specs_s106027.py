from pilot import S,EDGE_F
from recruits_util import rnd,logger,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 me=rnd(c,0x900)
 for off in (0,4,8,0x64):e.wf32(me+off,r.choice(EDGE_F+[r.uniform(-10,10)]))
 e.w32(me+0x8c,r.choice([0,1,2,3,0xffffffff]));e.w32(me+0x90,r.choice([0,1,2,3]))
 values=[r.choice(EDGE_F+[r.uniform(-10,10)]) for _ in range(8)]
 hook_rec(c,0x5162d0,0,this=True,st0=lambda em,k:values[k%8])
 hook_rec(c,0x525640,2,this=True,deref={0:3})
 logger(c,slot=0x30);e.w32(0x7003b0,pystub(c,0))
 return [me]
S(0x526df0,'average child heights and reposition','thiscall',None,ret=None,gen=gen,nan_heap=True)
