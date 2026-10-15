from pilot import S
from recruits_util import rnd,sysobj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x20);lst=rnd(c,16);count=r.randrange(9);tab=rnd(c,max(4,count*4));so=sysobj(c)
 e.w32(lst,tab);e.w32(lst+8,count);e.w32(me+8,r.randrange(count+3));e.wbytes(me+0xc,bytes([r.randrange(2)]));e.w32(me+4,rnd(c,0x20))
 e.wbytes(so+0x48,struct.pack('<f',r.choice([0,0.001,0.016,0.1,1,-1])))
 for i in range(count):
  p=rnd(c,0xb0);e.w32(tab+4*i,p);e.w32(p+0xe,r.choice([0,1,10,100,0xffffffff]));e.wbytes(p+0xac,r.randrange(65536).to_bytes(2,'little'))
 hook_rec(c,0x5f56f0,0,this=True);hook_rec(c,0x5fd120,1,this=True)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,lst]
S(0x550f30,'GUESS budgeted list processing','thiscall',None,ret=None,gen=gen)
