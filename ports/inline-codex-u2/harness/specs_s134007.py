from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 name=rnd(c,16);e.w32(name+4,r.choice([0,0x67c8e8,rnd(c,16)]))
 target=obj(c,0x100,{0x20:pystub(c,0,this=True,ret=name)})
 hook_rec(c,0x566360,1,this=True,ret=r.choice([0,target,target]))
 hook_rec(c,0x467260,3,this=True,ret=r.getrandbits(32))
 soundentry=rnd(c,0x100)
 stringobj=obj(c,0x40,{0:pystub(c,2,this=True,ret=r.getrandbits(32))})
 sys=sysobj(c,table_slots={0x60:pystub(c,1,this=True,ret=r.choice([0,soundentry]))},table_size=0xb00)
 table=e.r32(sys+0x9b);e.w32(table+0xae4,stringobj)
 audio=obj(c,0x40,{0x74:pystub(c,1,this=True,st0=r.uniform(0.1,100))});e.w32(sys+0x1a9f,audio)
 def alter(em,k):
  p=em.arg32(2);em.wf32(p,struct.unpack('<f',em.rbytes(p,4))[0]+0.5);em.w32(p+4,em.r32(p+4)^0x12345678)
 dest=obj(c,0x40,{0x130:pystub(c,3,this=True,deref={2:3},side=alter)})
 me=obj(c,0xb00,{0x44:pystub(c,2,this=True,deref={1:3})})
 e.w32(me+0x44,dest);identity=rnd(c,0x100);e.w32(me+0x94,identity)
 sentinel=e.rbytes(0x6a6e5c,64).split(b'\0')[0]+b'\0';e.wbytes(identity+0x48,sentinel if r.random()<0.5 else b'other\0')
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,r.getrandbits(32),r.getrandbits(32),r.choice([0,0,r.getrandbits(32)])]
S(0x5668d0,'GUESS show timed dialogue with optional sound','thiscall',None,ret='st0',gen=gen)
