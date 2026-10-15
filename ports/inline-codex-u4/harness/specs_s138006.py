import struct,math
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;s=rnd(c,0x80)
 def f(a):return struct.unpack('<f',e.rbytes(a,4))[0]
 ir=[(0,0,26),(0xc,-10000,0),(0x10,-10000,0),(0x14,-10000,0),(0x24,-10000,1000),(0x38,-10000,2000),(0x6c,0,255)]
 fr=[(4,f(0x678858),f(0x67cd40)),(8,0,1),(0x18,f(0x67a284),f(0x67da20)),(0x1c,f(0x67a284),f(0x680a60)),(0x20,f(0x67a284),f(0x680a60)),(0x28,0,f(0x67c198)),(0x3c,0,f(0x67a284)),(0x4c,f(0x6a2af4),f(0x67a288)),(0x50,0,1),(0x54,f(0x686080),f(0x67da1c)),(0x58,0,1),(0x5c,f(0x6a24f4),0),(0x60,f(0x67d164),f(0x6a2b00)),(0x64,f(0x67da20),f(0x67d164)),(0x68,0,f(0x680a70))]
 for off,lo,hi in ir:e.w32(s+off,r.choice([lo,hi,r.randint(lo,hi)])&0xffffffff)
 for off,lo,hi in fr:e.wbytes(s+off,struct.pack('<f',r.choice([lo,hi,r.uniform(lo,hi)])))
 if r.randrange(3):
  idx=r.randrange(len(ir)+len(fr))
  if idx<len(ir):
   off,lo,hi=ir[idx];e.w32(s+off,r.choice([lo-1,hi+1])&0xffffffff)
  else:
   off,lo,hi=fr[idx-len(ir)];e.wbytes(s+off,struct.pack('<f',r.choice([lo-max(1,abs(lo)),hi+max(1,abs(hi)),float('nan'),float('inf'),-float('inf')])))
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s]
S(0x539ca0,'GUESS validateParameters','thiscall',None,ret='al',gen=gen)
