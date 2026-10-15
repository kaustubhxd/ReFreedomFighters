from pilot import S,EDGE_F
from recruits_util import rnd,clear_hooks,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 out=rnd(c,40);src=rnd(c,16)
 if r.random()<.3:arena=rnd(c,80);out=arena;src=arena+r.choice([0,4,16,32])
 for i in range(4):e.wf32(src+4*i,r.choice(EDGE_F+[r.uniform(-20,20)]))
 e.w32(0x7003b0,pystub(c,0))
 return [out,src]
S(0x4df1e0,'quaternion matrix conversion','fastcall',None,ret=None,gen=gen,nan_heap=True)
