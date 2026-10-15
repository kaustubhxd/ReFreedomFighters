from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 ptrs=[rnd(c,16),rnd(c,16)];e.wbytes(ptrs[1],bytes([r.choice([0,1,65,255])]))
 hook_rec(c,0x4e5ea0,0,this=True,ret=lambda em,k:ptrs[k])
 words=[r.choice([0,1,0x100,r.getrandbits(32)]) for _ in range(5)]
 hook_rec(c,0x4e5e60,0,this=True,ret=lambda em,k:words[k])
 vals=[r.choice([0.,-0.,1.,-1.,float('nan'),r.uniform(-100,100)]) for _ in range(2)]
 if r.randrange(2):vals[1]=vals[0]
 hook_rec(c,0x4e5e80,0,this=True,st0=lambda em,k:vals[k])
 tab=obj(c,0x20,{0x58:pystub(c,1,this=True,ret=r.choice([0,1,r.getrandbits(32)])),0x114:pystub(c,4,this=True,ret=r.getrandbits(32))})
 sys=rnd(c,0x100);e.w32(0x70039c,sys);e.w32(sys+0x9b,tab)
 return [rnd(c,0x80),rnd(c,0x20)]
S(0x4afdd0,'GUESS load named action configuration','thiscall',None,ret=None,gen=gen,nan_heap=True)
