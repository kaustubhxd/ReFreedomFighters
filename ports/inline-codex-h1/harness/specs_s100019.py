from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def g4f27c0(c):
    clear_hooks(c);e=c.emu;r=c.rng
    filt=rnd(c,0x20);e.w32(filt+4,1);e.w32(filt+8,0x1234);e.w8(filt+0x10,0)
    entries=[]
    for mask,ident,require_id in ((1,0x1234,1),(2,0x1234,0),(1,0x9999,0)):
        p=rnd(c,0x20);e.w32(p+4,r.getrandbits(32));e.w32(p+8,mask)
        e.w32(p+0xc,ident);e.w8(p+0x10,require_id);entries.append(p)
    def next_entry(em,k): return entries[k] if k<len(entries) else 0
    get=pystub(c,1,this=True,ret=next_entry)
    init=pystub(c,1,this=True,ret=0)
    vt=e.alloc(0x68,4)
    e.w32(vt+0x4c,init);e.w32(vt+0x64,get)
    def dispatch_side(em,k):
        e.w8(em.arg32(2)+0x10,1 if k==1 else 0)
    main=obj(c,0x40,{0x12c:pystub(c,3,this=True,side=dispatch_side)})
    # main is the receiver; the embedded iterator lives at receiver+0x9f.
    e.w32(main+0x9f,vt)
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('ecx'))
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [main,filt]

S(0x4f27c0,'GUESS filter iterator records and dispatch match','thiscall',None,ret='al',gen=g4f27c0,note='batch100019')
