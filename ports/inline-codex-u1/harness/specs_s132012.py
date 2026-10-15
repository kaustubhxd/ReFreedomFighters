import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub,sysobj,logger

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 hook_rec(c,0x537500,1,this=True,ret=r.choice([0,r.getrandbits(32) or 1,r.getrandbits(32) or 1]))
 rec=rnd(c,0x20);e.w32(rec,r.choice([1,2,2,3]));e.w32(rec+12,fb(r.uniform(0,30)));e.w32(rec+16,fb(r.uniform(0,1.5)));e.w8(rec+20,r.randrange(2))
 p=obj(c,0x5500,{0x74:pystub(c,1,this=True,st0=r.uniform(0,20)),0x54:pystub(c,1,this=True,ret=r.choice([rec,rec,rec,0])),0x1dc:pystub(c,1,this=True,ret=r.choice([0,1,1,1]))})
 vt=e.alloc(8,4);e.w32(vt+4,pystub(c,1,this=True));e.w32(p+0x53b2,vt)
 for i in range(9):e.w8(p+0x515d+9*i,r.choice([0,0,1]))
 e.w8(p+0x50a9,r.randrange(2));time=r.randrange(1<<25);so=sysobj(c);e.w32(so+0x1c,time);e.w32(p+0x50b6,r.choice([time,time+1]))
 logger(c,2)
 o=rnd(c,0x100);e.w32(o+4,r.choice([3,3,3,2]));e.w32(o+0x2c,r.randrange(9))
 return [p,o]
S(0x534e60,'GUESS add new sound play buffer','thiscall',None,ret='al',gen=gen)
