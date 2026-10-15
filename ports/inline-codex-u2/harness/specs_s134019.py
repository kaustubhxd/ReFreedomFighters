from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;driver=obj(c,0x40,{0x70:pystub(c,1,this=True,deref={0:3})});me=rnd(c,0x80);e.w32(me+0x44,driver)
 e.wf32(me+0x48,r.choice([0,1,-1,0.5,10]));e.wf32(me+0x58,r.choice([0,1,2,10,-10,1e10]));e.w16(me+0x5c,r.randrange(5))
 inp=rnd(c,28);e.wbytes(inp,struct.pack('<7f',*[r.choice([0.,-0.,0.1,1.,-1.,10.,r.uniform(-10,10)]) for _ in range(7)]))
 force=r.choice([None,None,0,1,0xffffffff])
 def side(em,k):
  em.calllog.append(('computed-count',em.r32(me+0x50)))
  if force is not None:em.w32(me+0x50,force)
 hook_rec(c,0x5d5fc0,0,this=True,side=side)
 sys=sysobj(c);e.w32(sys+0x6f,r.choice([0,1,3,640,1920,-1,-3,0x7fffffff,0x80000000]));e.w32(sys+0x73,r.choice([0,1,3,480,1080,-1,-3,0x7fffffff,0x80000000]))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,r.choice([r.getrandbits(32),e.r32(me+0x5c)&0xffff,0x10000|(e.r32(me+0x5c)&0xffff)]),inp]
S(0x5d5d40,'GUESS update scaled UI event placement','thiscall',None,ret='eax',gen=gen)
