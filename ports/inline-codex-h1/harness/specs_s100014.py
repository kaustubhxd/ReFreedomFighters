from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub
import struct

def g4a8dd0(c):
    clear_hooks(c);e=c.emu;r=c.rng
    helper_values=[0x1234,0x89ab,0x4567,0xcdef]
    hook_rec(c,0x4e5e60,0,this=True,ret=lambda em,k:helper_values[min(k,3)])
    hook_rec(c,0x4e5e80,0,this=True,st0=2.75)
    hook_rec(c,0x4a8d90,0,this=True,ret=0)
    def set_resource(em,k):em.w32(em.reg('ecx')+0xbb,em.arg32(0))
    hook_rec(c,0x4a9330,1,this=True,side=set_resource,ret=0)
    text_obj=obj(c,0x40,{0x2c:pystub(c,2,this=True,pop=0)})
    sys_obj=obj(c,0x40,{0x20:pystub(c,2,this=True,pop=8,ret=text_obj)})
    e.w32(0x700390,sys_obj)
    child=obj(c,0x40,{0x1e0:pystub(c,1,this=True,ret=lambda em,k:r.randrange(2)),
                      0xbc:pystub(c,1,this=True,ret=0)})
    me=obj(c,0x110,{0x84:pystub(c,0,this=True)})
    e.w32(me+0x44,child); e.w32(me+0x56,0 if r.randrange(2) else 1)
    src=rnd(c,0x60); extra=rnd(c,0x40)
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('ecx'))
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [me,src,extra]

S(0x4a8dd0,'GUESS initialize resource profile and reset timers','thiscall',None,ret=None,gen=g4a8dd0,note='batch100014')
