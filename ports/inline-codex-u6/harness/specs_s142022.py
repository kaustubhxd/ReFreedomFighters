import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 oct=rnd(c,0xc0);it=rnd(c,0x30);e.w32(it,oct);out=rnd(c,8);p=rnd(c,12);flag=rnd(c,4)
 for i in range(3):
  lo=r.uniform(-100,100);extent=r.choice([0,0.125,1,100,-50]);e.wbytes(oct+6+4*i,struct.pack('<f',lo));e.wbytes(oct+0x12+4*i,struct.pack('<f',lo+extent));e.wbytes(p+4*i,struct.pack('<f',r.uniform(-500,500)))
  e.w32(oct+0x3c+4*i,r.choice([0,1,2,16,255,1024,0xffffffff]))
 result=bytes(r.getrandbits(8) for _ in range(8))
 hook_rec(c,0x530e80,5,this=True,ret=r.getrandbits(32),deref={1:-6},side=lambda em,k:em.wbytes(em.arg32(0),result))
 return [it,out,p,flag]
S(0x530bf0,'GUESS iterator nearest walkable world cell','thiscall',None,ret='eax',gen=gen)
