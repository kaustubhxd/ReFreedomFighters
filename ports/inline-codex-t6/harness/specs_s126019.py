from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=obj(c,0xb9b0,{0xb0:pystub(c,1,this=True)});inp=rnd(c,0x50);slot=rnd(c,0x30);table=rnd(c,4096*4)
 e.w32(me+0x68,table);e.w32(me+0x170,r.choice([0,1,5,15,16]));e.wbytes(inp+0x40,r.choice([0,0,0,1,4095,4096,r.randrange(65536)]).to_bytes(2,'little'))
 for off in [0x18,0x1c]:e.wbytes(inp+off,struct.pack('<f',r.choice([0,0,1,-1,r.uniform(-10,10)])))
 alloc=obj(c,0x20,{8:pystub(c,0,this=True,ret=r.choice([0,slot,slot,slot]))});e.w32(me+0x22c,alloc)
 hook_rec(c,0x4ce7b0,0,this=True,ret=r.choice([0,1,4094,4095,4096,r.getrandbits(32)]))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,inp,r.getrandbits(32)]
S(0x63f3e0,'GUESS cached draw slot allocation','thiscall',None,ret='eax',gen=gen)
