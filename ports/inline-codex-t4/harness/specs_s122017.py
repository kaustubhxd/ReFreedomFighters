from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub,reftab
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0x70);sys=obj(c,0x100,{0x1c0:pystub(c,2,this=True,st0=r.uniform(-5,5))})
 e.w32(0x70039c,sys)
 entries=[]
 for _ in range(r.randrange(6)):
  node=rnd(c,0x50);p=rnd(c,0x20);e.w32(p+8,node);e.w32(node+0x3c,r.choice([0,0x1000,0x1001]));entries.append(p)
 ids=[r.getrandbits(32) for _ in entries]
 def resolve(em,k):return entries[k]
 tab=obj(c,0x20,{0x58:pystub(c,1,this=True,ret=resolve)})
 e.w32(sys+0x9b,tab)
 li=reftab(c,ids);e.w32(s+0x48,li if r.randrange(4) else 0)
 for a in [sys+0x48,s+0x4c,s+0x54,s+0x5c]:e.wbytes(a,struct.pack('<f',r.choice([0.,1.,-1.,r.uniform(-10,10)])))
 e.wbytes(s+0x50,struct.pack('<f',r.choice([0.5,1.,2.,10.])))
 hook_rec(c,0x4c3740,1,this=True)
 return [s]
S(0x4c3510,'GUESS interpolate wind and apply to list','thiscall',None,ret=None,gen=gen)
