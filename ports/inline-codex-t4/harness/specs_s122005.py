from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,ret=r.getrandbits(32),pop=0)
 value=r.choice([0.,-0.,1.,-123.5,r.uniform(-1.e6,1.e6)])
 s=obj(c,0x5400,{0x1e0:pystub(c,1,this=True,st0=value),0x1e8:pystub(c,1,this=True,ret=r.getrandbits(32))})
 base=rnd(c,0x100);off=4*r.randrange(16);tag=r.choice([1,2,0,3,0xffffffff])
 e.w32(base+off,tag);e.w32(base+off+8,0x80)
 e.w32(s+0x5302,base if r.randrange(4) else 0)
 log=obj(c,0x20,{0x2c:pystub(c,3,pop=0)})
 sys=obj(c,0x20,{0x20:pystub(c,2,this=True,ret=log)})
 e.w32(0x700390,sys)
 return [s,off]
S(0x5377d0,'GUESS read typed float value','thiscall',None,ret='st0',gen=gen)
