import struct
from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 me=obj(c,0x2400,{0x1fc:pystub(c,5,this=True,deref={0:2})})
 e.wbytes(me+0x1e90,bytes([r.choice([0,1,2])]))
 counter=r.getrandbits(64);low=r.getrandbits(32);high=r.getrandbits(32)
 def hi(em,k):em.mu.reg_write(em._reg_edx,high)
 # Explicit EDX write for the engine's 64-bit return.
 from unicorn.x86_const import UC_X86_REG_EDX
 def highword(em,k):em.mu.reg_write(UC_X86_REG_EDX,high)
 sys=obj(c,16,{0x1c8:pystub(c,2,this=True,ret=low,side=highword)})
 e.w32(0x70039c,sys)
 e.w32(0x6760e0,pystub(c,1,stackmark=(0,),ret=r.getrandbits(32),side=lambda em,k:em.wbytes(em.arg32(0),struct.pack('<Q',counter))))
 e.w32(0x676434,pystub(c,0,ret=r.choice([0,1,0x7fffffff,0x80000000,0xffffffff,r.getrandbits(32)])))
 return [me]
S(0x4234f0,'GUESS serialize engine and process clock samples','thiscall',None,ret=None,gen=gen)
