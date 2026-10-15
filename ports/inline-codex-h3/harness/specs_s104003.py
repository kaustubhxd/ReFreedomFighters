from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    vals=[r.getrandbits(32) for _ in range(16)]
    hook_rec(c,0x6352f0,1,this=True,side=lambda em,k:em.w32(em.arg32(0),vals[k%len(vals)]),stackmark=(0,))
    hook_rec(c,0x4e5e80,0,this=True,st0=lambda em,k:[-1.25,0.0,0.375,4.5][k%4])
    hook_rec(c,0x4e5e40,0,this=True,ret=lambda em,k:[0,0xffff,0x1234][k%3])
    hook_rec(c,0x4e5e60,0,this=True,ret=lambda em,k:[0,1,0x100,0xffffffff][k%4])
    def advance(em,k): em.w32(em.arg32(0),vals[(k+5)%len(vals)])
    stream=obj(c,0x20,{0x40:pystub(c,1,this=True,stackmark=(0,),side=advance)})
    table_val=[r.getrandbits(32) for _ in range(16)]
    sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:table_val[min(k,len(table_val)-1)])})
    dest=rnd(c,0x80)
    e.w32(dest+4,r.getrandbits(32)); e.wf32(dest+0x4a, r.uniform(-10,10))
    return [dest,stream]
S(0x5d3660,'GUESS read entity fields and resolve references','thiscall',None,ret='al',gen=gen,note='batch104003')
