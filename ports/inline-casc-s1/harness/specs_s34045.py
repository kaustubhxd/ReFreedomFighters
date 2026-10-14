"""specs_s34045.py - cascade tier E, batch 34045.
0x466640: this slot 0x84 writes random dwords through its (stack) pointer; 0x43e920 (fastcall; EDX and the stack pointer argument) writes random dwords into the buffer ECX points at; 0x4e09b0 and 0x4de040
log the contents of the buffers they receive (0x4de040 fills the 9-dword object); this slot 0x370 records both pointed-to buffers; the /GS check is a zero-argument recorder.
0x46c8a0: a chain of 0..3 nodes at [this+0x50]; 0x4d9430 (thiscall) and 0x4d9590 (cdecl) are recorders and 0x4d9590 unlinks the node (the next one becomes [this+0x50]); a is zero in half the cases; this
slot 0x294 (four args) is a recorder.
0x4705a0: hooked 0x441790; s has slots 0x3c, 0x6c and 0x78 returning chain objects whose own slots are recorders (the 0x3c chain is four long)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g466640(c):
    clear_hooks(c)
    r = c.rng

    def wv(em, k):
        for i in range(2):   # only two of the three dwords: the zero initialisation of the third stays visible
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))

    def w43(em, k):
        em.calllog.append(('43e920', em.reg('edx')))
        for i in range(3):
            em.w32(em.reg('ecx') + 4 * i, r.getrandbits(32))

    def l4e(em, k):
        em.calllog.append(('4e09b0', tuple(em.r32(em.reg('ecx') + 4 * i) for i in range(3))))

    def f4de(em, k):
        em.calllog.append(('4de040', tuple(em.r32(em.reg('edx') + 4 * i) for i in range(3))))
        for i in range(9):
            em.w32(em.reg('ecx') + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x43e920, 1, this='mark', side=w43, deref={0: 3})
    hook_rec(c, 0x4e09b0, 0, this='mark', pop=0, side=l4e)
    hook_rec(c, 0x4de040, 1, this='mark', side=f4de)
    hook_rec(c, 0x633654, 0, pop=0)
    me = obj(c, 0x20, {0x84: pystub(c, 1, this=True, side=wv, stackmark=(0,)),
                       0x370: pystub(c, 2, this=True, deref={0: 9, 1: 3})}, nslots=0x380 // 4)
    return [me, r.getrandbits(32)]


def _g46c8a0(c):
    clear_hooks(c)
    r = c.rng
    nn = r.choice([0, 1, 2, 3])
    nodes = [rnd(c, 0x20) for _ in range(nn)]
    def newobj(em, k):
        em.w32(me + 0x50, r.getrandbits(32))   # the created object becomes the new head
    me = obj(c, 0x60, {0x294: pystub(c, 4, this=True, ret=r.getrandbits(32), side=newobj)}, nslots=0x2a0 // 4)
    c.emu.w32(me + 0x50, nodes[0] if nodes else 0)
    seq = nodes + [0]

    def unlink(em, k):
        em.w32(me + 0x50, seq[k + 1] if k + 1 < len(seq) else 0)
    hook_rec(c, 0x4d9430, 0, this=True, pop=0)
    hook_rec(c, 0x4d9590, 1, pop=0, side=unlink)
    return [me, 0 if r.random() < 0.5 else (r.getrandbits(32) | 1)]


def _g4705a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x441790, 1, this=True)
    # chain of four objects for slot 0x3c
    d = obj(c, 0x20, {0x3c: pystub(c, 1, this=True)}, nslots=0x40 // 4)
    cc = obj(c, 0x20, {0x3c: pystub(c, 1, ret=d, this=True)}, nslots=0x40 // 4)
    b = obj(c, 0x20, {0x3c: pystub(c, 1, ret=cc, this=True)}, nslots=0x40 // 4)
    a = obj(c, 0x20, {0x3c: pystub(c, 1, ret=b, this=True)}, nslots=0x40 // 4)
    o6 = obj(c, 0x20, {0x6c: pystub(c, 1, this=True)}, nslots=0x70 // 4)
    o7 = obj(c, 0x20, {0x78: pystub(c, 1, this=True)}, nslots=0x7c // 4)
    s = obj(c, 0x20, {0x3c: pystub(c, 1, ret=a, this=True), 0x6c: pystub(c, 1, ret=o6, this=True),
                      0x78: pystub(c, 1, ret=o7, this=True)}, nslots=0x80 // 4)
    return [rnd(c, 0x80), s]


S(0x466640, 'GUESS transform point through two helpers and pass it on', 'thiscall', None, ret=None, gen=_g466640, note='batch34045')
S(0x46c8a0, 'GUESS drain list and optionally make new object', 'thiscall', None, ret='eax', gen=_g46c8a0, note='batch34045')
S(0x4705a0, 'GUESS copy seven fields into setter chain', 'thiscall', None, ret='al', gen=_g4705a0, note='batch34045')
