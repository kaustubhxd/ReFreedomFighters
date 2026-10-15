import struct
from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks,logger

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 me=rnd(c,0x40)
 for po,co,stride in [(0xf,0x28,0x34),(0x13,0x2c,12),(0x17,0x30,12)]:
  n=r.choice([-1,0,1,2]);p=rnd(c,stride*max(n,1));e.w32(me+po,p);e.w32(me+co,n&0xffffffff)
  if stride==12:
   for i in range(max(n,1)):e.wbytes(p+i*stride+8,struct.pack('<f',r.uniform(-100,100)))
 # Full call arguments fit recorder's eight rows for vectors; scalar stream has custom extended record.
 record=e.alloc(4*32,4)
 def scalar(em,k):em.w32(record+4*k,em.arg32(0))
 stream=obj(c,16,{0x44:pystub(c,1,this=True,side=scalar),0x4c:pystub(c,1,this=True),0x68:pystub(c,1,this=True,deref={0:3})})
 logger(c,7)
 return [me,stream]
S(0x547520,'GUESS constrained particle system save','thiscall',None,ret='al',gen=gen)
