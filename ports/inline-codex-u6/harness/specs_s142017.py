import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,pystub,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 me=obj(c,0x330,{0xc4:pystub(c,0,this=True)})
 e.w32(me+0x68,r.randrange(5));e.wbytes(me+0x30a,bytes([r.randrange(256)]))
 for i in range(5):e.wbytes(me+0xd9+0x82*i,struct.pack('<f',r.uniform(-1,1000)))
 e.wbytes(me+0x2f6,struct.pack('<f',r.uniform(-1,1000)))
 returns=[r.choice([0,1,2,255]) for _ in range(2)]
 raydata=[bytes(r.getrandbits(8) for _ in range(12)) for i in range(2)]
 world=obj(c,16,{0x2e0:pystub(c,6,this=True,deref={0:-0x60},ret=lambda em,k:returns[k],side=lambda em,k:em.wbytes(em.arg32(0)+0x28,raydata[k]))})
 sys=sysobj(c);table=e.r32(sys+0x9b)
 # table object needs the collision service pointer far past ordinary vtable fields.
 big=rnd(c,0xb00);e.w32(big+0xadc,world);e.w32(sys+0x9b,big)
 hook_rec(c,0x5c9910,0,this=True)
 rec=e.alloc(48,4);distances=[r.uniform(-1,1000) for _ in range(2)]
 def inputs(em,k):em.wbytes(rec+24*k,em.rbytes(em.reg('ecx'),12));em.wbytes(rec+24*k+12,em.rbytes(em.reg('edx'),12))
 hook_rec(c,0x4e0870,0,side=inputs,st0=lambda em,k:distances[k])
 return [me]
S(0x5c9ba0,'GUESS camera collision rays and closest selection','thiscall',None,ret='al',gen=gen)
