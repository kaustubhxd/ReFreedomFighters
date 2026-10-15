from pilot import S,F
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0x270);parent=rnd(c,0x20);node=rnd(c,0x80);sys=rnd(c,0x100);cfg=rnd(c,0xac0)
 e.w32(s+0x18,parent);e.w32(parent+8,node);e.w32(0x70039c,sys);e.w32(0x7003b8,cfg);e.wbytes(cfg+0xab8,bytes([r.randrange(2)]))
 for p in [s+0x14,s+0x29,s+0x2d,sys+0x48]:e.wbytes(p,struct.pack('<f',r.choice([0.1,1.,2.,-1.,r.uniform(-3,3)])))
 e.wbytes(s+0x28,bytes([r.randrange(2)]))
 for j in range(9):e.wbytes(node+4*j,struct.pack('<f',r.uniform(-3,3)))
 mat=struct.pack('<9f',*[r.uniform(-3,3) for _ in range(9)]);rec=e.alloc(12,4)
 def rotation(em,k):em.wbytes(rec,em.rbytes(em.reg('edx'),12));em.wbytes(em.reg('ecx'),mat)
 hook_rec(c,0x4ddcb0,1,this='mark',side=rotation)
 hook_rec(c,0x4dcb90,1,this=True,deref={0:9})
 hook_rec(c,0x5168b0,0,this=True)
 return [s,F(r.uniform(-10,10)),F(r.choice([-3.,0.,1.,3.,r.uniform(-5,5)]))]
S(0x529e30,'GUESS revolve wheel and update effects','thiscall',None,ret=None,gen=gen)
