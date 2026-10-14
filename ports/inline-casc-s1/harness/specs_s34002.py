"""specs_s34002.py - cascade escalation batch 34002: forwarders 0x436160 / 0x4675d0 (member pointer at +0x65 / +0x1ce) and 0x474450 / 0x474680
(embedded subobject at +0x2e7 / +0x34f). The target's vtable slot is a recorder stub (records ECX and 2 stack args, random return); an
unaligned vtable pointer is written into the object for the embedded cases."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _fwd(off, slot, embedded):
    def g(c):
        clear_hooks(c)
        r = c.rng
        me = rnd(c, 0x400)
        stub = pystub(c, 2, ret=r.getrandbits(32), this=True)
        if embedded:
            vt = c.emu.alloc(0x40, 4)
            c.emu.wbytes(vt, bytes(r.getrandbits(8) for _ in range(0x40)))
            c.emu.w32(vt + slot, stub)
            c.emu.wbytes(me + off, vt.to_bytes(4, 'little'))
        else:
            inner = obj(c, 0x40, {slot: stub})
            c.emu.wbytes(me + off, inner.to_bytes(4, 'little'))
        return [me, r.getrandbits(32), r.getrandbits(32)]
    return g


S(0x436160, 'GUESS forward to member +0x65 slot 0xc', 'thiscall', None, ret='eax', gen=_fwd(0x65, 0xc, False), note='batch34002')
S(0x4675d0, 'GUESS forward to member +0x1ce slot 0x10', 'thiscall', None, ret='eax', gen=_fwd(0x1ce, 0x10, False), note='batch34002')
S(0x474450, 'GUESS forward to subobject +0x2e7 slot 0x10', 'thiscall', None, ret='eax', gen=_fwd(0x2e7, 0x10, True), note='batch34002')
S(0x474680, 'GUESS forward to subobject +0x34f slot 0x14', 'thiscall', None, ret='eax', gen=_fwd(0x34f, 0x14, True), note='batch34002')
