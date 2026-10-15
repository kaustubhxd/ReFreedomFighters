from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    picked=[]
    outvals=[r.getrandbits(32) for _ in range(3)]
    def fill(em,k):
        p=em.arg32(0)
        for i,x in enumerate(outvals): em.w32(p+4*i,x)
    lookup=obj(c,0x20,{0x84:pystub(c,1,this=True,stackmark=(0,),side=fill)})
    transform=obj(c,0x240,{0x218:pystub(c,2,this=True,deref={0:3},ret=r.getrandbits(32))})
    form=obj(c,0x20,{0x58:pystub(c,3,this=True)})
    table_slots={0x58:pystub(c,1,this=True,ret=(0 if r.random()<0.2 else lookup)),
                 0x138:pystub(c,0,this=True,ret=form)}
    sysobj(c,table_slots=table_slots)
    me=rnd(c,0x60); e.w32(me+0x44,transform); e.w32(me+0x48,r.getrandbits(32))
    return [me]
S(0x4c91c0,'GUESS resolve local record and format components','thiscall',None,ret=None,gen=gen,note='batch104004')
