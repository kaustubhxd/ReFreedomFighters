import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 me=rnd(c,0x600);length=r.randrange(0,25)
 e.wbytes(me+0x1c9,bytes(r.randrange(33,127) for _ in range(length))+b'\0')
 data=rnd(c,0x40);e.wbytes(data+0x24,struct.pack('<fff',*[r.uniform(-100,100) for _ in range(3)]))
 charwidth=r.choice([1,2,3,10]);base=r.choice([0,0,1,-1]);limit=r.choice([-1,0,1,length*charwidth,r.randrange(1,50)])
 child=obj(c,0x20,{0x290:pystub(c,1,this=True,ret=lambda em,k:(em.arg32(0)*charwidth+base)&0xffffffff),0x284:pystub(c,1,this=True,deref={0:7})})
 e.w32(child+8,data)
 def change_limit(em,k):
  if k==0 and limit>0 and rflag:e.w32(me+0x184,newlimit)
 rflag=r.choice([False,True]);newlimit=r.randrange(1,50)
 cursor=obj(c,0x20,{0x248:pystub(c,1,this=True,side=change_limit),0x70:pystub(c,1,this=True,deref={0:3})})
 e.w32(me+0x5ca,0 if r.randrange(8)==0 else cursor);e.w32(me+0x5ce,child);e.w32(me+0x184,limit&0xffffffff)
 return [me]
S(0x56fb10,'GUESS clamp edit text to width','thiscall',None,ret='al',gen=gen)
