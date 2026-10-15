from pilot import S,F
from recruits_util import rnd,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 for slot,nm in [(0x67630c,'stub_ci_pow'),(0x67635c,'stub_floor'),(0x676334,'stub_ftol')]:e.w32(slot,e.symbols[nm])
 e.wbytes(e.symbols['stub_pow_bias'],struct.pack('<d',r.choice([0,0,0,0.125,-0.125])))
 n=r.choice([0,1,2,16,31,64,128]);source=rnd(c,108);output=rnd(c,max(4,n*4))
 e.wbytes(source,struct.pack('<27f',*[r.uniform(-100,100) for _ in range(27)]))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [source,output,n,F(r.choice([1000,10000,1e5,1e6,1e7]))]
S(0x4039c0,'GUESS nonlinear curve resampling','cdecl',None,ret=None,gen=gen,max_insns=100000)
