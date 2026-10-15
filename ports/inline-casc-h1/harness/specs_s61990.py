from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    e=c.emu
    r=c.rng
    rr=lambda:r.getrandbits(32)
    sysobj(c,table_slots={0x4c:pystub(c,1,ret=rr(),this=True)})
    target=obj(c,0x30,{0x2d0:pystub(c,2,ret=rr(),this=True)})
    worker=obj(c,0x40,{8:pystub(c,2,ret=rr(),this=True)})
    me=rnd(c,0x30)
    e.w32(me+8,target)
    e.w32(me+0xc,rr())
    e.w32(me+0x10,worker)
    hook_rec(c,0x467410,6,ret=rr(),pop=24,this=True)
    return [me]
S(0x486020,'GUESS initialize worker and invoke two target modes','thiscall',None,ret='al',gen=gen,note='batch61990')
