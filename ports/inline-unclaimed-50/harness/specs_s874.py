"""specs_s874.py - area 50, batch 874: 0x4d2cd0 (GUESS name), thiscall, two stack args (ret 8), result in eax.
Stood in: the object's vt +0xb0 (returns an entry, or 0), the entry's flag object (byte +0x10), the logger (0x700390, vt +0x24,
cdecl, logged) and the memcpy import (stub, logged). The entry's block is at entry + [entry] + 0xc with length [entry+8]."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, install_memset


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    install_memset(c)

    def mv(e, rr):
        d, s, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memcpy', d, n))
        if n:
            e.wbytes(d, e.rbytes(s, n))
        e.ret(eax=d, argbytes=0)

    e.stub_import('memcpy', mv)

    def l24(e, rr):
        e.calllog.append(('log.24', e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=0)

    lg = vt_object(c, 0x40, {0x24: l24}, nslots=0x40, name='logger')
    e.w32(0x700390, lg)

    entry = rnd(c, 0x100)
    flags = rnd(c, 0x40)
    e.w32(flags + 0x10, r.getrandbits(8) if r.random() < 0.5 else (r.getrandbits(8) | 4))
    e.w32(entry + 4, flags)
    n = r.randint(0, 12)
    e.w32(entry + 0, r.randint(0, 8))
    e.w32(entry + 8, n)
    have = r.random() < 0.85

    def v0b0(e, rr):
        e.calllog.append(('self.b0', e.arg32(0), e.arg32(1)))
        e.ret(eax=entry if have else 0, argbytes=8)

    self = vt_object(c, 0x40, {0xb0: v0b0}, nslots=0x100, name='self')
    dst = rnd(c, 0x40)
    return [self, r.choice([r.getrandbits(32) | 1, 0x12345678]), dst]


S(0x4d2cd0, 'Copy4d2cd0 (GUESS name)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch874')
