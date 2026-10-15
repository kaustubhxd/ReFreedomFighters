import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 capacity=r.choice([1,2,4,8,16,32,64]);entries=rnd(c,capacity*8);bits=rnd(c,max(4,(capacity+31)//32*4));key=rnd(c,16)
 first=r.getrandbits(32);second=r.getrandbits(32)
 def hash(em,k):em.w32(em.arg32(1),first);em.w32(em.arg32(2),second)
 matches=[r.choice([0,0,1,1,255]) for _ in range(capacity)]
 def equal(em,k):return matches[(em.arg32(0)-entries)//8]
 me=obj(c,0x30,{0x10:pystub(c,3,this=True,nullflag=[1,2],side=hash),0x14:pystub(c,2,this=True,deref={0:2,1:4},ret=equal)})
 e.w32(me+4,bits);e.w32(me+8,capacity);e.w32(me+0x14,r.randrange(0,capacity+2));e.w32(me+0x18,entries)
 e.wbytes(me+0x1c,struct.pack('<f',r.choice([0.,1.,-1.,100.,r.uniform(-100,100)])))
 return [me,key]
S(0x48f880,'GUESS find open-addressed hash entry','thiscall',None,ret='eax',gen=gen)
