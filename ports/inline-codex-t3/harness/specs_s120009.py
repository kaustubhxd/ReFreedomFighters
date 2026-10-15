from pilot import S
from recruits_util import rnd,clear_hooks,pystub
import struct

def adjust(c):
    clear_hooks(c);e,r=c.emu,c.rng
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    n=r.randint(0,60);hole=r.randint(0,max(0,n+1))
    first=rnd(c,53*(n+8),1)
    for i in range(n+8):e.wf32(first+53*i,r.choice([0.0,-0.0,1.0,-1.0,float('nan'),float('inf'),float('-inf'),r.uniform(-500,500)]))
    value=struct.pack('<f',r.choice([0.0,1.0,-1.0,float('nan'),r.uniform(-500,500)]))+bytes(r.getrandbits(8) for _ in range(52))
    return [first,hole,n,*struct.unpack('<14I',value)]
S(0x4adc70,'GUESS_adjust_heap_53byte_float_records','fastcall',None,ret=None,gen=adjust)
