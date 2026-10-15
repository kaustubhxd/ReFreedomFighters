from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def g(c):
    clear_hooks(c)
    r,e=c.rng,c.emu
    me=rnd(c,0x50);table=rnd(c,0x7c*12)
    e.w32(me+0x3c,table)
    cell=rnd(c,0x7c);out=rnd(c,0x48*6+32)
    for off in [4,6,8,10,12,14]:
        e.wbytes(cell+off,r.randrange(13).to_bytes(2,'little'))
    salt=r.getrandbits(32)
    def transform(em,k):
        a,b=em.reg('ecx'),em.reg('edx')
        vals=[em.r32(a+i*4) for i in range(3)]
        em.calllog.append(('transform',a,b,tuple(vals),em.r32(b)))
        for i,v in enumerate(vals):em.w32(a+i*4,v^salt^em.r32(b))
    hook_rec(c,0x441940,0,this=True,side=transform)
    hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
    return [me,out,cell]
S(0x4522d0,'GUESS emit exposed cell faces','thiscall',None,ret='eax',gen=g,note='batch46009')
