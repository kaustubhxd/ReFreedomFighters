from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def g(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x633654,0,pop=0)
 lookup=obj(c,0x20,{0x114:pystub(c,4,this=True,ret=lambda em,k:r.getrandbits(32))})
 sys=rnd(c,0xb0);e.w32(0x70039c,sys);e.w32(sys+0x9b,lookup)
 for off in [0x6f,0x73]:e.w32(sys+off,r.choice([0,1,640,480,1920,1080,0xffffffff,0x7fffffff,r.getrandbits(32)]))
 target=obj(c,0x20,{0x258:pystub(c,2,this=True,deref={0:2}),0x70:pystub(c,1,this=True,deref={0:3}),0x250:pystub(c,1,this=True),0xbc:pystub(c,1,this=True)})
 me=rnd(c,0x70);e.w32(me+0x44,target)
 for off in [0x48,0x4c]:e.wbytes(me+off,struct.pack('<f',r.choice([0.,1.,-1.,r.uniform(-10,10),float('nan'),float('inf')])))
 return [me]
S(0x5d6f90,'GUESS initialize screen scaled object','thiscall',None,ret=None,gen=g,nan_heap=True,note='batch124001')
