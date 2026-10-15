from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x40);info=rnd(c,0x80)
 actor=obj(c,0x20,{0x2d0:pystub(c,2,this=True)});ref=obj(c,0x20,{0x10:pystub(c,0,this=True,ret=r.choice([0,actor,actor,actor]))})
 owner=obj(c,0x20,{0x474:pystub(c,1,this=True,ret=r.getrandbits(32)),0x244:pystub(c,5,this=True),0x458:pystub(c,1,this=True)})
 e.w32(me+0xc,ref);e.w32(me+8,owner);e.w32(me+0x28,r.choice([0,info,info,info]))
 so=sysobj(c);tick=r.choice([0,1,1024,100000,0x7fffffff,0xffffffff]);e.w32(so+0x40,tick)
 signed=tick if tick<0x80000000 else tick-0x100000000
 multiplier=struct.unpack('<f',e.rbytes(0x6785e4,4))[0];now=struct.unpack('<f',struct.pack('<f',signed))[0]*multiplier;now=struct.unpack('<f',struct.pack('<f',now))[0]
 e.wbytes(me+0x2c,struct.pack('<f',now+r.choice([0,-0.01,-0.5,-2,-100,1])))
 start=r.getrandbits(32);e.w32(info+0x60,start);e.w32(info+0x64,(start+r.choice([0,1,100,1024,10000,0xffffffff]))&0xffffffff)
 e.w32(info+0x5c,r.getrandbits(32));e.w32(info+0x6c,r.choice([1,2,100,0xffffffff,0x7fffffff]))
 hook_rec(c,0x4863c0,1,this=True);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x487110,'GUESS chamber action update','thiscall',None,ret='al',gen=gen)
