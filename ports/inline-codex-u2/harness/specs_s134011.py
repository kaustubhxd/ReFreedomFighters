from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,logger
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 targets=[]
 for i in range(4):
  p=rnd(c,0x100);targets.append(r.choice([0,p,p]));e.w32(p+4,r.choice([0,3,7,11]));e.w32(p+0x2c,r.choice([0,1,2]));e.w8(p+0x40,r.choice([0,8,255,16]));e.w32(p+0x6c,r.getrandbits(32));e.wbytes(p+0x70,struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)]))
 sys=sysobj(c,table_slots={0x60:pystub(c,1,this=True,ret=lambda em,k:targets[em.arg32(0)%4])});e.w32(sys+0x1c,r.getrandbits(32))
 events=rnd(c,0x200);p=events
 for i in range(r.randrange(9)):
  size=r.choice([12,16,20]);e.w32(p,r.choice([0x1001,0x1002,0x1100,0x900,0xffffffff]));e.w32(p+4,size);e.w32(p+8,r.randrange(4));p+=size
 e.w32(p,0x10000);alternate=rnd(c,16)
 first=r.choice([0,events,events]);last=r.choice([0,events,alternate])
 me=obj(c,0x40,{0x1a8:pystub(c,0,this=True,ret=r.choice([0,1,255,256,257])),0x190:pystub(c,0,this=True,ret=lambda em,k:first if k==0 else last),0x198:pystub(c,1,this=True,ret=r.choice([0,1,256,257])),0x1a4:pystub(c,0,this=True)})
 logger(c,4);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));e.w8(0x711b70,r.getrandbits(8))
 return [me]
S(0x538340,'GUESS process queued timeline events','thiscall',None,ret=None,gen=gen)
