import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 me=rnd(c,0x600)
 e.w32(me+0x34a,r.choice([0,0,0,1]));e.w32(me+0x469,r.choice([0,1,2]))
 for off in (0x232,0x236,0x23a,0x597):e.wf32(me+off,r.choice(EDGE_F+[r.uniform(-100,100)]))
 sink=obj(c,16,{0x184:pystub(c,8,pop=0)})
 sysobj(c,slots={0x190:pystub(c,0,this=True,ret=sink)})
 return [me]
S(0x51e470,'update helicopter tilt','thiscall',None,ret=None,gen=gen,nan_heap=True)
