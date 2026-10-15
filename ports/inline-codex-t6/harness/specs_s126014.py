from pilot import S
from recruits_util import obj,sysobj,logger,clear_hooks,pystub
from unicorn.x86_const import UC_X86_REG_EDX
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def side(em,k):
  if k==0:em.wbytes(em.arg32(0),b'\x01')
  else:em.w32(em.arg32(0),0x3f800000)
 me=obj(c,0x1ea0,{0x1fc:pystub(c,5,this=True,side=side)})
 e.wbytes(me+0x58,e.rbytes(0x6785d0,4) if r.random()<0.75 else struct.pack('<f',r.uniform(-10,10)))
 start=r.getrandbits(64);end=(start+r.randrange(0,10000000))&((1<<64)-1);ticks=[start,end]
 def edx(em,k):em.mu.reg_write(UC_X86_REG_EDX,ticks[min(k,1)]>>32)
 timer=pystub(c,2,this=True,ret=lambda em,k:ticks[min(k,1)]&0xffffffff,side=edx)
 sysobj(c,slots={0x1c8:timer});logger(c,nargs=4)
 def sleep(em,res):em.calllog.append(('sleep',em.arg32(0)));em.ret(argbytes=4)
 e.stub_import('Sleep',sleep);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x420070,'GUESS clock calibration fields','thiscall',None,ret=None,gen=gen)
