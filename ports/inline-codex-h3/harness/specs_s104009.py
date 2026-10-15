from pilot import S
from recruits_util import rnd,clear_hooks,pystub,sysobj

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    sys=sysobj(c,slots={0x1c4:pystub(c,2,this=True,st0=r.choice([0.0,0.1,0.25,0.5,1.0]))})
    me=rnd(c,0x500)
    states=[r.randrange(2),r.randrange(2)]
    for off,state in zip((0x39f,0x3c8),states):
        vt=e.alloc(0x30,4)
        e.w32(vt+8,pystub(c,1,this=True))
        e.w32(vt+0x20,pystub(c,0,this=True,ret=state))
        e.w32(vt+4,pystub(c,3,this=True))
        e.w32(me+off,vt)
    for off in (0x22e,0x232,0x236,0x23a,0x342,0x346): e.wf32(me+off,r.uniform(-4,4))
    return [me]
S(0x51e340,'GUESS advance two emitter channels','thiscall',None,ret=None,gen=gen,note='batch104009')
