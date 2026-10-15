from pilot import S
from recruits_util import rnd,clear_hooks,pystub

def heapselect(c):
    clear_hooks(c);e,r=c.emu,c.rng
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    n=r.randint(0,30);extra=r.randint(0,25)
    a=rnd(c,53*(n+extra+2),1)
    for i in range(n+extra+2):
        e.wf32(a+53*i,r.choice([0.0,-0.0,1.0,-1.0,r.uniform(-500,500),float('inf'),float('-inf'),float('nan')]))
    return [a,a+53*n,a+53*(n+extra),r.getrandbits(32)]
S(0x4ae0b0,'GUESS_heap_select_sort_53byte_records','fastcall',None,ret=None,gen=heapselect)
