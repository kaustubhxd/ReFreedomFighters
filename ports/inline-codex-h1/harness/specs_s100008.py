from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
import struct

def g4fdc30(c):
    clear_hooks(c); e=c.emu; r=c.rng
    n=r.randrange(1,5)
    nodes=[rnd(c,0x20) for _ in range(n)]
    ids={}
    for i,node in enumerate(nodes):
        ident=0x200+i
        ids[ident]=None
        e.w32(node,ident); e.w32(node+4,struct.unpack('<I',struct.pack('<f',r.uniform(-5,5)))[0])
        e.w32(node+0xc,nodes[i+1] if i+1<n else 0)
        e.w8(node+0x14,1 if r.randrange(4)==0 else 0)

    callbacks={}
    def table_lookup(em,k):
        return callbacks.get(em.arg32(0),0)
    table_slot=pystub(c,1,this=True,ret=table_lookup)
    so=sysobj(c,table_slots={0x58:table_slot})
    # The function reads [node.id] through engine slot 0x58. Some IDs resolve
    # to null (the fallback constant); others expose a callback returning a
    # float through the caller's stack-local output pointer.
    for ident in ids:
        if r.randrange(3)==0:
            callbacks[ident]=0
        else:
            value=r.uniform(-8,8)
            def write_out(em,k,v=value):
                em.w32(em.arg32(1),struct.unpack('<I',struct.pack('<f',v))[0])
            callback=pystub(c,3,this=True,deref={1:1},side=write_out)
            callbacks[ident]=obj(c,0x20,{0x128:callback})
    me=rnd(c,0x80); e.w16(me+0x58,r.randrange(0x10000)); e.w32(me+0x48,nodes[0])
    # Reachable starting node is the field at +0x48 of the receiver.
    hook_rec(c,0x4fdb70,0,this=True,ret=0)
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('ecx'))
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [me]

S(0x4fdc30,'GUESS update linked-node float thresholds','thiscall',None,ret=None,gen=g4fdc30,note='batch100008')
