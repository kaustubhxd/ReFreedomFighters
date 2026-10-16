"""specs_s210075.py - Sonnet-w3a: 0x5fa270 (/GS). The import at the IAT slot 0x676414 is replaced by a recorder stub (cdecl, 2 args) returning 0 or non-zero; the formatting slot 0x14 writes a 16-byte tagged text into the stack buffer and the report slot 0x2c is cdecl with 3 args (the buffer is logged through deref when it is the argument)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g5fa270(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, side=lambda emu, k: emu.calllog.append(('gs',)))
    rv = c.rng.choice([0, 0, 1, 0xffffffff, 5])
    e.w32(0x676414, pystub(c, 2, ret=rv, pop=0, deref={0: -8}))
    tag = bytes(c.rng.randrange(1, 256) for _ in range(15)) + b'\0'

    def s14(emu, k):
        emu.wbytes(emu.arg32(1), tag)
    fmt_obj = obj(c, 0x40, {0x14: pystub(c, 4, ret=_r(c), pop=0, stackmark=(1,), side=s14)}, nslots=0x20)
    e.w32(0x724270, fmt_obj)
    if rv == 0:
        rep = obj(c, 0x40, {0x2c: pystub(c, 3, ret=_r(c), pop=0)}, nslots=0x20)
    else:
        rep = obj(c, 0x40, {0x2c: pystub(c, 3, ret=_r(c), pop=0, deref={2: -16})}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=rep, this=True)}, nslots=0x20)
    e.w32(0x700390, g)
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda e2, r_: (e2.calllog.append(('assert',)), e2.ret(eax=_r(c)))))
    cell = rnd(c, 0x10)
    e.wbytes(cell + 4, bytes([c.rng.choice([0, 1, 2, 0xff])]))
    hook_rec(c, 0x5003d0, 1, ret=cell, this=True)
    name = rnd(c, 0x20)
    p = rnd(c, 0x20); e.w32(p, name); e.w32(p + 8, rnd(c, 0x10))
    s = rnd(c, 0x20)
    return [s, p]


S(0x5fa270, 'register_cell_or_report', 'thiscall', None, ret=None, gen=g5fa270, note='batch210075')
