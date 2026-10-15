from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    selfp=rnd(c,0xa0)
    target=rnd(c,0x40); tv=rnd(c,0x20)
    e.w32(target,tv)
    count=1
    e.w32(tv+0x14,pystub(c,0,this=True,ret=count))
    e.w32(tv+0x30,pystub(c,1,this=True,ret=lambda em,k:r.getrandbits(32)))
    e.w32(selfp+0x6d,target)
    sys=rnd(c,0xb0); sv=rnd(c,0x80); table=rnd(c,0x100); tabv=rnd(c,0x70)
    e.w32(0x70039c,sys); e.w32(sys+0x9b,table); e.w32(table,tabv)
    recs=[]
    def lookup(em,k):
        rec=recs[k%len(recs)] if recs else 0
        return rec
    e.w32(tabv+0x58,pystub(c,1,this=True,ret=lookup))
    for _ in range(max(1,count)):
        rec=rnd(c,0x30); recs.append(rec)
        e.wf32(rec+0x20,0.25)
    e.wf32(0x67da00,100.0)
    e.wf32(selfp+0x79,0.5)
    e.w32(selfp+0x89,1)
    return [selfp]
S(0x4c1f80,'GUESS update progress ratio','thiscall',None,ret='eax',gen=gen,note='batch104019')
