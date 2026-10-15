import struct
from pilot import S
import recruits_util as ru
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub,sysobj

def gen(c):
    clear_hooks(c)
    e=c.emu;r=c.rng
    fb=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
    def vec():return [fb(r.uniform(-10,10)) for _ in range(3)]
    def put(em,p,words):
        for i,w in enumerate(words):em.w32(p+i*4,w)
    P,Q,D,V,O=vec(),vec(),vec(),vec(),vec()
    if r.random()<0.1:D=[0,0,0]
    sub=rnd(c,0x100) if r.randrange(2) else 0
    def out(words):return lambda em,k:put(em,em.arg32(0),words)
    owner=obj(c,0x40,{
        0x84:pystub(c,1,this=True,deref={0:3},side=out(Q)),
        0x50c:pystub(c,0,this=True,ret=sub),
        0x8c:pystub(c,1,this=True,deref={0:3}),
        0x4ac:pystub(c,7,this=True,deref={1:3})})
    target=obj(c,0x40,{0x84:pystub(c,1,this=True,deref={0:3},side=out(P))})
    sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=target)})
    me=rnd(c,0x40);e.w32(me+0x1c,owner)
    arg=rnd(c,0x20);record=rnd(c,8);e.w32(record+4,fb(r.uniform(-80,80)))
    hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:record+4*(k%2))
    def subhook(em,_):
        a=em.reg('edx');b=em.arg32(0)
        em.calllog.append(('subtract',tuple(em.r32(a+4*i) for i in range(3)),tuple(em.r32(b+4*i) for i in range(3))))
        put(em,em.reg('ecx'),D);em.ret(argbytes=4)
    def scalehook(em,_):
        p=em.reg('ecx')
        em.calllog.append(('scale',tuple(em.r32(p+4*i) for i in range(3)),em.arg32(0)))
        put(em,p,V);em.ret(argbytes=4)
    def copyhook(em,_):
        p=em.reg('edx')
        em.calllog.append(('copy',tuple(em.r32(p+4*i) for i in range(3))))
        put(em,em.reg('ecx'),O);em.ret()
    for addr,h in [(0x43e920,subhook),(0x4e0d00,scalehook),(0x441940,copyhook)]:
        e.hook(addr,h);ru._HOOKED.add(addr)
    return [me,arg]
S(0x557d70,'GUESS perpendicular impulse from target positions','thiscall',None,ret=None,gen=gen,nan_heap=True,note='batch65991')
