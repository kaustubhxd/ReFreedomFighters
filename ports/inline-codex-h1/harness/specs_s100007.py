from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import random

def g57f420(c):
    clear_hooks(c);e=c.emu;r=c.rng
    returned_b=obj(c,0x30,{})
    middle=obj(c,0x400,{
        0x36c:pystub(c,1,this=True,ret=r.getrandbits(32)),
        0x2e8:pystub(c,1,this=True,ret=r.getrandbits(32))})
    returned_a_v=obj(c,0x40,{0x25c:pystub(c,2,this=True,ret=middle)})
    returned_b_v=obj(c,0x40,{0x25c:pystub(c,2,this=True,ret=returned_b)})
    def root_ret(em,k): return returned_a_v if em.arg32(0)==0x67a00c else returned_b_v
    root=obj(c,0x40,{0x25c:pystub(c,2,this=True,ret=root_ret)})
    engine_result=obj(c,0x40,{0xa8:pystub(c,1,this=True,st0=0.625)})
    result_by_table=obj(c,0x40,{})
    so=sysobj(c,slots={0xbc:pystub(c,0,this=True,ret=engine_result)},
               table_slots={0x4c:pystub(c,1,this=True,ret=result_by_table)})
    hook_rec(c,0x563510,1,this=True,ret=0)
    hook_rec(c,0x57f6b0,0,this=True,ret=0)
    me=rnd(c,0x1a0);e.w32(me+0x54,root);e.w32(me+0x44,r.getrandbits(32))
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('eax'))
    return [me]

S(0x57f420,'GUESS initialize and connect engine resource handles','thiscall',None,ret=None,gen=g57f420,note='batch100007')
