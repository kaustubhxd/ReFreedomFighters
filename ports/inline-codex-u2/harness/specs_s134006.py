from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,logger
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 prop=obj(c,0x40,{0x14:pystub(c,4,pop=16,deref={3:1},side=lambda em,k:em.w32(em.arg32(3),r.getrandbits(32)))})
 def query(em,k):em.w32(em.arg32(2),prop)
 buffer=obj(c,0x40,{0:pystub(c,3,pop=12,nullflag=(2,),side=query,ret=r.choice([0,1,0x80004005,0xffffffff]))})
 def create(em,k):
  desc=em.arg32(1);wave=em.r32(desc+16)
  em.calllog.append(('wave',em.rbytes(wave,18)))
  em.w32(em.arg32(2),buffer)
 def recorddesc(em,k):
  p=em.arg32(1);desc=[em.r32(p+4*j) for j in range(9)];desc[4]=1 if desc[4] else 0
  em.calllog.append(('desc',tuple(desc)));create(em,k)
 device=obj(c,0x40,{0xc:pystub(c,4,pop=16,nullflag=(1,2),side=recorddesc,ret=r.choice([0,0,1,0xffffffff]))})
 me=obj(c,0x100,{0x10:pystub(c,0,this=True)})
 logger(c,2);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,device,r.choice([0,buffer]),r.choice([0,1,2,256,257])]
S(0x54edb0,'GUESS initialize sound buffer interfaces','thiscall',None,ret='eax',gen=gen)
