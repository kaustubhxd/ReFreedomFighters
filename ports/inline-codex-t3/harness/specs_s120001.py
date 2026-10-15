from pilot import S
from recruits_util import rnd,clear_hooks,pystub
import struct,math

def partition(c):
    clear_hooks(c);e,r=c.emu,c.rng
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    n=r.randint(2,70);a=rnd(c,53*(n+2),1); first=a+53;last=first+53*n
    pivot=r.choice([-100.0,0.0,1.0,r.uniform(-100,100),float('nan')])
    for i in range(-1,n+1):
        v=r.choice([pivot,r.uniform(-1000,1000),float('inf'),float('-inf'),float('nan')])
        e.wf32(first+53*i,v)
    # Sentinels bound unguarded scans, including pivot outside the inner keys.
    e.wf32(first-53,float('-inf'));e.wf32(last,float('inf'))
    # At least one <= and >= pivot inside each endpoint for finite pivot.
    e.wf32(first,float('-inf'));e.wf32(last-53,float('inf'))
    b=struct.pack('<f',pivot)+bytes(r.getrandbits(8) for _ in range(52))
    return [first,last,*struct.unpack('<14I',b)]
S(0x4ae320,'GUESS_partition_53byte_float_records','fastcall',None,ret='eax',gen=partition)
