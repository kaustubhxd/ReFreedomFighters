from pilot import S,F
from recruits_util import rnd,clear_hooks,sysobj,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    sys=sysobj(c); e.w32(sys+0x40,0x20010000)
    me=rnd(c,0x1b00); a=r.choice([0,1,2,3]); b=r.choice([0,1,2])
    e.w32(me+0x8d,a); e.w32(me+0x91,b)
    vec=rnd(c,0x20)
    v=[r.uniform(-5,5) for _ in range(3)]
    for j,x in enumerate(v): e.wf32(vec+4*j,x)
    for base,n in ((0xe91,a),(0x1829,b)):
        for i in range(n):
            rec=me+base+i*0x133
            for j,x in enumerate([r.uniform(-5,5) for _ in range(3)]): e.wf32(rec+4*j,x)
            if all(abs(e.rf32(rec+4*j)-v[j])<1e-4 for j in range(3)):
                e.wf32(rec,r.uniform(20,25))
    for base,n in ((0x95,a),(0x785,b)):
        for i in range(n):
            e.wf32(me+base+i*0xde+0x41,r.uniform(-2,2))
            e.wf32(me+base+i*0xde+0x55,r.uniform(-2,2))
    return [me,F(r.choice([0.25,0.5,1.0,2.0])),vec]
S(0x5289d0,'GUESS update two record groups from vector distance','thiscall',None,ret=None,gen=gen,note='batch104005')
