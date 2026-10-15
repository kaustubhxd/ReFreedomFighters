from pilot import S,F
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 # _ftol consumes st0, returns truncating signed64 in edx:eax.
 code=bytes.fromhex('83ec08dd0c24585ac3');stub=e.alloc(32,16);e.wbytes(stub,code);e.mu.ctl_flush_tb();e.w32(0x676334,stub)
 table=rnd(c,44)
 for i in range(11):
  shape=rnd(c,64);e.w32(table+4*i,shape)
  for j in range(16):e.wbytes(shape+4*j,struct.pack('<f',r.uniform(-20,20)))
  e.wbytes(shape,struct.pack('<f',r.randrange(4)));e.wbytes(shape+4,struct.pack('<f',r.randrange(4,13)))
 out=rnd(c,128*4)
 for i in range(128):e.wbytes(out+4*i,struct.pack('<f',r.uniform(-30,30)))
 return [out,table,F(r.uniform(-30,30)),r.randrange(9),r.randrange(20,100),r.randrange(1,8),F(r.uniform(-20,20))]
S(0x4043a0,'GUESS raster maximum envelope','cdecl',None,ret=None,gen=gen)
