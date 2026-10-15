import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=rnd(c,0x800);out=rnd(c,0x30);indices=rnd(c,32)
 count=r.randrange(0,10);e.w32(p+0x5b8,count)
 # The original forms a 15-byte string by replacing the first word of a global template.
 tail=e.rbytes(0x6b11f8,11);prefix=r.choice([b'ABCD',b'WXYZ',b'\0\0\0\0',b'AB\0D'])
 for i in range(max(count,1)):
  s=rnd(c,64);value=prefix+tail if r.random()<0.45 else r.choice([b'ABCD_bad\0',b'other\0',b'xyz\0'])
  e.wbytes(s,value+b'\0');e.w32(p+8+4*i,s)
 # Selected index is valid even for the empty count path.
 e.w32(p+8,e.r32(p+8))
 n=r.randrange(9)
 for i in range(8):e.w32(p+0x598+4*i,r.randrange(max(count,1)) if i<n else 0xffffffff)
 hook_rec(c,0x5b1000,1,this=True,ret=r.choice([0,1,1]))
 return [p,out,indices]
S(0x5b0cc0,'GUESS resolve selected string indices','thiscall',None,ret=None,gen=gen)
