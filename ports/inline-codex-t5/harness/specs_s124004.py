from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 target=obj(c,0x30,{0x2c:pystub(c,0,this=True),0xbc:pystub(c,1,this=True),0x258:pystub(c,2,this=True,deref={0:2}),0x26c:pystub(c,3,this=True)})
 second=obj(c,0x20,{0x25c:pystub(c,2,this=True,ret=r.choice([0,target,target]))})
 first=obj(c,0x20,{0x25c:pystub(c,2,this=True,ret=r.choice([0,second,second]))})
 me=obj(c,0x110,{0x84:pystub(c,0,this=True,ret=first)})
 sys=rnd(c,0xb0);e.w32(0x70039c,sys)
 for off in [0x6f,0x73]:e.w32(sys+off,r.choice([0,1,640,480,1921,1081,0xffffffff,0x80000000,r.getrandbits(32)]))
 return [me,r.choice([0,0x6a6850,rnd(c,16)])]
S(0x563510,'GUESS background picture dimensions','thiscall',None,ret=None,gen=g,note='batch124004')
