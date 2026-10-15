from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub

def _g67002(c):
    clear_hooks(c)
    r,e=c.rng,c.emu
    e.w32(0x7003b0,e.stub_fn('assert',lambda em,_:em.ret(eax=r.getrandbits(32))))
    so=sysobj(c,table_slots={0x4c:pystub(c,1,this=True,pop=4,ret=lambda em,k:0x12345678)},table_size=0x100)
    cfg=rnd(c,0x300)
    count=0
    e.w32(cfg+0x21,count)
    arr=e.alloc(max(1,count)*0x1df,4); e.wbytes(arr,bytes(r.getrandbits(8) for _ in range(max(1,count)*0x1df)))
    e.w32(cfg+0x25,arr)
    e.w32(cfg+0x2d,e.alloc(max(1,count)*4,4))
    if count:
        e.w32(e.r32(cfg+0x2d),0x9876)
        e.w32(arr+0x36,0x41)
        e.w32(arr+0x17f,1)
        e.wbytes(arr+0x15,b'\0')
    entry=e.alloc(0x200,4); e.wbytes(entry,bytes(r.getrandbits(8) for _ in range(0x200)))
    e.w32(cfg+0x29,entry)
    e.w32(entry+0x36,0x42)
    e.w32(entry+0x17f,0)
    e.wbytes(entry+0x15,b'\0')
    ob=obj(c,0x20,{0x44:pystub(c,1,this=True,pop=4),0x3c:pystub(c,1,this=True,pop=4),
                   0x68:pystub(c,1,this=True,pop=4),0x60:pystub(c,1,this=True,pop=4)})
    return [cfg,ob]

S(0x644e70,'GUESS configure_entries','thiscall',None,ret='al',gen=_g67002)
