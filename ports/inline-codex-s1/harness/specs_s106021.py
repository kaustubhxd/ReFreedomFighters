import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 me=rnd(c,0x150);word=r.getrandbits(16);e.wbytes(me+0x115,struct.pack('<H',word))
 zero=bytes(r.getrandbits(8) for _ in range(12));copy=bytes(r.getrandbits(8) for _ in range(12))
 def fill(em,k,out):
  em.calllog.append(('before',em.rbytes(em.arg32(0),12).hex()));em.wbytes(em.arg32(0),out)
 actor=obj(c,16,{0x74:pystub(c,2,this=True,deref={0:3,1:3}),0x84:pystub(c,1,this=True,nullflag=(0,),side=lambda em,k:fill(em,k,zero)),0x88:pystub(c,1,this=True,nullflag=(0,),side=lambda em,k:fill(em,k,copy))})
 e.w32(me+0x44,actor);sys=sysobj(c);e.w32(sys+0x40,r.getrandbits(32));e.wf32(me+0xea,r.uniform(-10,10))
 hook_rec(c,0x4e73b0,5,this=True,deref={0:3,1:3,2:3})
 hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('eax'))
 e.w32(0x7003b0,pystub(c,0))
 return [me,word if r.random()<.7 else r.getrandbits(32),r.choice([0,1])]
S(0x4a64c0,'restore saved transform','thiscall',None,ret='eax',gen=gen)
