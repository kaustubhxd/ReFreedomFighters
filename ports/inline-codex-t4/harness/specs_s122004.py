from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub
import struct

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,ret=r.getrandbits(32),pop=0)
 s=rnd(c,0x50);sys=rnd(c,0x100)
 tab=obj(c,0xb00,{0x30:pystub(c,1,this=True,deref={0:16})})
 e.w32(0x70039c,sys);e.w32(sys+0x9b,tab)
 e.wbytes(tab+0xae0,struct.pack('<f',r.choice([0.,1.,-1.,0.99999,r.uniform(-10,10),float('nan'),float('inf')])))
 return [s]
S(0x469870,'GUESS event base constructor','thiscall',None,ret='eax',gen=gen,nan_heap=True)
