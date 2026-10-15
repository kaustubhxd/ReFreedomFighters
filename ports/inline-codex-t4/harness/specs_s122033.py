from pilot import S,F
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 bounds=[struct.unpack('<f',e.rbytes(a,4))[0] for a in [0x693d3c,0x693d48,0x693d4c,0x693d58,0x693d38,0x693d30]]
 bounds=sorted(set([0.]+bounds));values=bounds+[(a+b)*0.5 for a,b in zip(bounds,bounds[1:])]+[-1.,10000.,float('nan'),r.uniform(-1,10)]
 return [rnd(c,0x20),F(r.choice(values))]
S(0x4bca90,'GUESS piecewise signed curve','thiscall',None,ret='st0',gen=gen)
