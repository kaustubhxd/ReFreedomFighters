"""specs_s34003.py - cascade escalation batch 34003: vtable forwarders (member pointer or embedded subobject), tail stubs 0x453120 (edx=4 recorded)
and 0x5b0290, 0x4c8350 (clear bit 6), 0x46f500 (>= 5 signed), 0x655a60 (vtable store, returns this). Slots are recorder stubs."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fwd(fo, ad, slot):
    def g(c):
        clear_hooks(c)
        r = c.rng
        me = rnd(c, 0x400)
        stub = pystub(c, 2, ret=r.getrandbits(32), this=True)
        if fo is not None:
            inner = obj(c, 0x40, {slot: stub})
            c.emu.wbytes(me + fo, inner.to_bytes(4, 'little'))
        else:
            vt = c.emu.alloc(0x2d0, 4)
            c.emu.wbytes(vt, bytes(r.getrandbits(8) for _ in range(0x2d0)))
            c.emu.w32(vt + slot, stub)
            c.emu.wbytes(me + ad, vt.to_bytes(4, 'little'))
        return [me, r.getrandbits(32), r.getrandbits(32)]
    return g


def _tail(tgt, rec_edx=False):
    def g(c):
        clear_hooks(c)
        side = (lambda em, k: em.calllog.append(('edx', em.reg('edx')))) if rec_edx else None
        hook_rec(c, tgt, 1, ret=c.rng.getrandbits(32), this=True, side=side)
        return [rnd(c, 0x2000), c.rng.getrandbits(32)]
    return g


def _g4c8350(c):
    clear_hooks(c)
    return [rnd(c, 0x40), c.rng.getrandbits(32)]


def _g46f500(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x100)
    v = r.choice([3, 4, 5, 6, 7, 0, -1, -5, 0x7fffffff, -0x80000000, r.getrandbits(32)]) & 0xffffffff
    c.emu.w32(me + 0x8c, v)
    return [me]


def _g655a60(c):
    clear_hooks(c)
    return [rnd(c, 0x40), c.rng.getrandbits(32)]


F = 'GUESS vtable forwarder'
S(0x467cf0, F + ' member +0x1ce slot 8', 'thiscall', None, ret='eax', gen=_fwd(0x1ce, 0, 8), note='batch34003')
S(0x474460, F + ' subobj +0x2e7 slot 0x14', 'thiscall', None, ret='eax', gen=_fwd(None, 0x2e7, 0x14), note='batch34003')
S(0x562380, F + ' member +0x44 slot 0x2c4', 'thiscall', None, ret='eax', gen=_fwd(0x44, 0, 0x2c4), note='batch34003')
S(0x650c10, F + ' member +0x8c slot 0xc', 'thiscall', None, ret='eax', gen=_fwd(0x8c, 0, 0xc), note='batch34003')
S(0x64f930, F + ' this slot 4', 'thiscall', None, ret='eax', gen=_fwd(None, 0, 4), note='batch34003')
S(0x465a70, F + ' member +0x1ce slot 0xc', 'thiscall', None, ret='eax', gen=_fwd(0x1ce, 0, 0xc), note='batch34003')
S(0x474670, F + ' subobj +0x34f slot 0x10', 'thiscall', None, ret='eax', gen=_fwd(None, 0x34f, 0x10), note='batch34003')
S(0x453120, 'GUESS this+0x22, edx=4 tail', 'thiscall', None, ret='eax', gen=_tail(0x4e2bb0, True), note='batch34003')
S(0x5b0290, 'GUESS set flags +0x1d8c/+0x1d91 tail', 'thiscall', None, ret='eax', gen=_tail(0x5b0220), note='batch34003')
S(0x4c8350, 'GUESS clear bit 6 of +4, true', 'thiscall', None, ret='al', gen=_g4c8350, note='batch34003')
S(0x46f500, 'GUESS field +0x8c >= 5', 'thiscall', None, ret='al', gen=_g46f500, note='batch34003')
S(0x655a60, 'GUESS vtable store, return this', 'thiscall', None, ret='eax', gen=_g655a60, note='batch34003')
