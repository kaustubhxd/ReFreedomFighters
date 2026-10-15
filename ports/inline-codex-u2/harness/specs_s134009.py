from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 driver=obj(c,0x40,{0x94:pystub(c,4,this=True),0x9c:pystub(c,4,this=True),0x98:pystub(c,4,this=True),0xa8:pystub(c,4,this=True),0xb0:pystub(c,3,this=True,deref={2:3}),0xac:pystub(c,3,this=True,deref={2:3})})
 me=rnd(c,0x80);e.w32(me+0x14,r.getrandbits(32));e.w32(me+0x1c,r.choice([0,1,2,3,0xffffffff]));e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,driver,r.getrandbits(32),r.getrandbits(32),r.getrandbits(32)]
S(0x4491c0,'GUESS apply render material parameters','thiscall',None,ret=None,gen=gen)
