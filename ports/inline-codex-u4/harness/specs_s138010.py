import struct
from pilot import S
from recruits_util import rnd,obj,pystub,sysobj,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 s=obj(c,0x680,{0x2dc:pystub(c,4,this=True)})
 device=obj(c,0x40,{0x2c:pystub(c,2,this=True,ret=lambda em,k:em.arg32(0)&1)})
 sys=sysobj(c);e.w32(sys+0x1907,device)
 def f(a):return struct.unpack('<f',e.rbytes(a,4))[0]
 dt=r.choice([0.,0.01,0.1,1.,-0.01]);e.wbytes(sys+0x34,struct.pack('<f',dt))
 threshold=f(0x67c1a4)
 for i in range(262):
  e.w32(s+0x1df+4*i,0)
  if i<256:e.w8(sys+0xa0b+5*i,r.randrange(128))
 for i in r.sample(range(256),10):
  e.w8(sys+0xa0b+5*i,r.choice([0,0x80,0xff]))
  e.wbytes(s+0x1df+4*i,struct.pack('<f',r.choice([0.,-0.,threshold,threshold+0.1,-1.,1.,float('nan')])))
 for i in range(256,262):
  e.w32(s+0x603+8*(i-256),r.getrandbits(32))
  e.wbytes(s+0x1df+4*i,struct.pack('<f',r.choice([0.,threshold,threshold+0.1,-1.,1.])))
 e.w8(s+0x5fd,r.randrange(2))
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s]
S(0x4f2300,'GUESS updateInputTimers','thiscall',None,ret=None,gen=gen)
