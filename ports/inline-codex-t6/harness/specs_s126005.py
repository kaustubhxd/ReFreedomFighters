from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;inp=rnd(c,0x90);so=sysobj(c);link=rnd(c,0x30)
 e.w32(so+0x1aa3,link);e.w32(inp+0x44,r.randrange(0,7));e.wbytes(inp+0x40,struct.pack('<f',r.choice([0,1,-1,0.5,r.uniform(-2,2)])))
 n=r.randrange(0,30)
 def side(em,k):
  count=em.arg32(3);em.calllog.append(('color-data',em.rbytes(em.arg32(2),4*count)))
 table=obj(c,0x20,{0xf4:pystub(c,1,this=True,ret=n),0x70:pystub(c,4,this=True,nullflag=(2,),side=side)})
 e.w32(link+0x18,table);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [inp]
S(0x65f210,'GUESS alpha color array update','stdcall',None,ret=None,gen=gen)
