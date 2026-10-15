from pilot import S
from recruits_util import rnd,clear_hooks,pystub

def axes(c):
    clear_hooks(c);e,r=c.emu,c.rng
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    # CRT _CIatan2 consumes x87 ST1/ST0 and returns one x87 result.
    stub=e.alloc(16,16);e.wbytes(stub,b'\xd9\xf3\xc3');e.w32(0x676308,stub)
    self=rnd(c,0x90);a=rnd(c,4);b=a if r.random()<0.1 else rnd(c,4)
    def v():return r.choice([0.0,-0.0,1.0,-1.0,0.2,1e-20,1e20,float('nan'),float('inf'),float('-inf'),r.uniform(-2,2)])
    e.wf32(a,v());e.wf32(b,v())
    e.wf32(self+0x69,r.choice([0.0,0.2,0.5,1.0,-1.0,float('nan'),r.uniform(-1,2)]))
    e.wf32(self+0x6d,r.choice([0.0,1.0,2.0,-1.0,float('nan'),r.uniform(-3,3)]))
    return [self,a,b]
S(0x4297a0,'GUESS_joystick_radial_deadzone','thiscall',None,ret=None,gen=axes,nan_heap=True)
