from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec,logger

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));logger(c)
 def read(em,k):em.wbytes(em.arg32(0),b'Q'*min(em.arg32(1),8))
 io=obj(c,32,{0x14:pystub(c,3,this=True,stackmark=(0,),side=read,ret=lambda em,k:em.arg32(1))})
 me=rnd(c,32);e.w32(me+0x15,io);header=rnd(c,32);mode=r.choice([0,8,8,8,1,9]);e.wbytes(header+4,mode.to_bytes(2,'little'));e.w32(header+14,r.choice([0,1,0x1ffff,0x20000,0x20001,0x40001]))
 def initialize(em,k):
  s=em.arg32(0);dest=em.r32(s+12);cap=em.r32(s+16);em.calllog.append(('init',dest,cap,em.r32(s+32),em.r32(s+36)));em.wbytes(s,bytes(56));em.w32(s+12,dest);em.w32(s+16,cap)
 hook_rec(c,0x62f9d0,4,stackmark=(0,),side=initialize,ret=r.choice([0,0,0,0xffffffff]))
 statuses=[r.choice([0,1,0xfffffffb,0xfffffffe]) for _ in range(3)];exhaust=r.randrange(2)
 def inflate(em,k):
  s=em.arg32(0);em.calllog.append(('input',em.r32(s+4),em.rbytes(em.r32(s),min(em.r32(s+4),8))))
  n=min(em.r32(s+16),8);em.wbytes(em.r32(s+12),b'Z'*n)
  if exhaust:em.w32(s+16,0)
 hook_rec(c,0x62f5d0,2,stackmark=(0,),side=inflate,ret=lambda em,k:statuses[k]);hook_rec(c,0x62f980,1,stackmark=(0,))
 return [me,header,rnd(c,64),r.getrandbits(32),r.randrange(0,33)]
S(0x4d62c0,'GUESS read_stored_or_deflated_data','thiscall',None,ret='eax',gen=gen)
