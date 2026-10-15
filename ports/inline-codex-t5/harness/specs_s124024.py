from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 # x87 import boundary: consume two input floats into observable memory, return controlled float.
 rec=rnd(c,12);e.wbytes(rec+8,struct.pack('<f',r.choice([0.,.5,1.,-1.,r.uniform(-100,100)])))
 code=b'\xd9\x1d'+struct.pack('<I',rec)+b'\xd9\x1d'+struct.pack('<I',rec+4)+b'\xd9\x05'+struct.pack('<I',rec+8)+b'\xc3'
 fn=e.alloc(len(code),16);e.wbytes(fn,code);e.w32(0x676358,fn)
 info=rnd(c,16);e.w32(info,r.choice([0,16,32,64]));motion=rnd(c,0x20)
 hook_rec(c,0x478a80,0,this=True,ret=r.choice([0,motion,motion]))
 me=obj(c,0x790,{0x5a8:pystub(c,1,this=True,ret=lambda em,k:r.choice([0,info,info]) if k==0 else r.choice([0,info,info])),0x244:pystub(c,5,this=True),0x248:pystub(c,6,this=True)})
 e.wbytes(me+0x771,bytes([r.choice([0,0,1])]));e.w32(me+0x650,r.choice([8,8,0,1,9]));e.wbytes(me+0x76d,struct.pack('<f',r.choice([0.,1.,-1.,float('nan'),r.uniform(-10,10)])))
 for off in [0x755,0x769]:e.wbytes(me+off,struct.pack('<f',r.uniform(-10,10)))
 sys=rnd(c,0xb0);table=rnd(c,0x80);e.w32(0x70039c,sys);e.w32(sys+0x9b,table);e.w32(table+0x44,rnd(c,0x100))
 return [me]
S(0x47c540,'GUESS update base movement frame','thiscall',None,ret=None,gen=g,note='batch124024')
