from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,sysobj,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    read_id=r.getrandbits(32); idptr=rnd(c,0x680); resolved=obj(c,0x690,{})
    mapped=r.getrandbits(32); e.w32(resolved+0x676,mapped)
    lookup_value=r.getrandbits(32)
    lookup=obj(c,0x20,{0x100:pystub(c,1,this=True,ret=lookup_value)})
    block=rnd(c,0xc)
    for j in range(3): e.w32(block+4*j,r.getrandbits(32))
    def put_id(em,k): em.w32(em.arg32(1),read_id)
    def put_float(v):
        def side(em,k): em.wf32(em.arg32(1),v)
        return side
    reader=obj(c,0x100,{0x88:pystub(c,2,this=True,stackmark=(1,),side=put_id),0x84:pystub(c,2,this=True,stackmark=(1,),side=put_float(r.uniform(-5,5))),0x9c:pystub(c,2,this=True,ret=block)})
    table_values=[resolved,lookup]
    def table_ret(em,k): return table_values[min(k,1)]
    sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=reader),0x58:pystub(c,1,this=True,ret=table_ret)})
    me=rnd(c,0x140); e.w32(me+0x114,0); e.w32(me+0x130,r.getrandbits(32))
    return [me]
S(0x5de260,'GUESS read environment and resolve resource ids','thiscall',None,ret=None,gen=gen,note='batch104011')
