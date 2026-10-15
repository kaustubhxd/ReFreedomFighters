import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 vals=[r.choice([0.,1.,-1.,r.uniform(-100,100)]) for _ in range(3)]
 if r.random()<.15:vals[r.randrange(3)]=r.choice(EDGE_F)
 def sub(em,k):
  em.calllog.append(('sub',em.reg('edx')));em.wbytes(em.reg('ecx'),struct.pack('<fff',*vals))
 hook_rec(c,0x43e920,1,this='mark',side=sub)
 basis=bytes(r.getrandbits(8) for _ in range(36))
 def make_basis(em,k):
  em.calllog.append(('basis-input',em.rbytes(em.reg('edx'),12).hex()))
  em.wbytes(em.reg('ecx'),basis)
 hook_rec(c,0x4de040,1,this='mark',side=make_basis)
 sums=bytes(r.getrandbits(8) for _ in range(12))
 def add(em,k):
  em.calllog.append(('add-edx',em.reg('edx')));em.wbytes(em.reg('ecx'),sums)
 hook_rec(c,0x43e8e0,1,this='mark',side=add)
 def scale(em,k):
  em.calllog.append(('scale-input',em.rbytes(em.reg('ecx'),12).hex()))
  # Use deterministic output so the final slot observes any pointer/order error.
  em.wbytes(em.reg('ecx'),sums[::-1])
 hook_rec(c,0x4e0d00,1,this='mark',side=scale)
 hook_rec(c,0x4690b0,0,this=True)
 hook_rec(c,0x633654,0)
 me=obj(c,0x80,{0x74:pystub(c,2,this=True,deref={0:9,1:3})})
 e.wbytes(me+0x18,bytes([r.choice([0,4,0xff,0x10])]))
 e.w32(me+8,rnd(c,16))
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,k:em.ret(eax=0)))
 return [me,rnd(c,12),rnd(c,12),r.getrandbits(32)]
S(0x43e740,'update direction and basis','thiscall',None,ret=None,gen=gen,nan_heap=True)
