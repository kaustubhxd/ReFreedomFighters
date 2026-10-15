from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 target=rnd(c,0x100);me=rnd(c,0x80);e.w32(me+8,target);e.w8(me+0x18,r.randrange(32))
 e.wbytes(me+0x1c,struct.pack('<7f',*[r.choice([0.,-0.,0.001,1.,70.,-10.,1000.,r.uniform(-100,100)]) for _ in range(7)]))
 def scale(em,k):
  p=em.reg('ecx');factor=struct.unpack('<f',em.arg32(0).to_bytes(4,'little'))[0]
  for i in range(3):em.wf32(p+4*i,struct.unpack('<f',em.rbytes(p+4*i,4))[0]*factor)
 hook_rec(c,0x4e0d00,1,this='mark',side=scale)
 hook_rec(c,0x4dc5d0,3,this=True)
 hook_rec(c,0x4dc600,1,this=True,deref={0:3})
 hook_rec(c,0x4dd060,1,this=True,deref={0:3})
 hook_rec(c,0x4dce50,1,this=True)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x43e330,'GUESS recalculate bounds and sphere','thiscall',None,ret=None,gen=gen)
