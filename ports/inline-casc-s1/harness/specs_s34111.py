"""specs_s34111.py - seven items; callees are recorders (this recorded; edx logged for register-argument callees)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _edx(em, k):
    em.calllog.append(('edx', em.reg('edx')))


def _g4d1320(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4d21b0, 2, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g5cda40(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5cf110, 0, this=True, pop=0, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)]))
    me = rnd(c, 0xe10)
    c.emu.wbytes(me + 0xb45, bytes([r.choice([0, 1, 5])]))
    mid = rnd(c, 0x60)
    leaf = rnd(c, 0x20)
    c.emu.w32(mid + 0x54, leaf)
    c.emu.w32(me + 0x44, mid)
    return [me]


def _g65bfe0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x647fd0, 4, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x634d10, 3, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x28), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)] if False else [rnd(c, 0x10040), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g532ed0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4de420, 0, this=True, pop=0, ret=r.getrandbits(32), side=_edx)
    me = rnd(c, 0x51b0)
    e = rnd(c, 0x60)
    c.emu.wbytes(me + 0x51a9, e.to_bytes(4, 'little'))
    return [me]


def _g659bb0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4ce1c0, 2, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x30)
    inner = rnd(c, 0x10)
    c.emu.w32(inner + 4, r.choice([0, 1, 0x80000001, r.getrandbits(32)]))
    mode = r.choice(['null', 'own', 'inline', 'own'])
    c.emu.w32(me + 8, 0 if mode == 'null' else (me + 0x10 if mode == 'inline' else inner))
    if mode == 'inline':
        c.emu.w32(me + 0x14, r.choice([0, 1, 0x80000001, r.getrandbits(32)]))
    c.emu.w32(me + 0xc, rnd(c, 0x20))
    return [me]


def _g54da10(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634d10, 3, pop=0, ret=r.getrandbits(32))
    me = rnd(c, 0x40b0)
    c.emu.wbytes(me + 0x75, r.choice([3, 3, 0, 1, r.getrandbits(32)]).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x29, (0 if r.random() < 0.3 else rnd(c, 0x60)).to_bytes(4, 'little'))
    return [me]


def _g64de00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4de420, 0, this=True, pop=0, ret=r.getrandbits(32), side=_edx)
    return [rnd(c, 0x80), rnd(c, 0x18270)]


S(0x4d1320, 'GUESS constructor with tail init', 'thiscall', None, ret='eax', gen=_g4d1320, note='batch34111')
S(0x5cda40, 'GUESS set constants and probe', 'thiscall', None, ret='eax', gen=_g5cda40, note='batch34111')
S(0x65bfe0, 'GUESS constructor with cleared table', 'thiscall', None, ret='eax', gen=_g65bfe0, note='batch34111')
S(0x532ed0, 'GUESS append record to cursor', 'thiscall', None, ret='eax', gen=_g532ed0, note='batch34111')
S(0x659bb0, 'GUESS release inline-or-owned block', 'thiscall', None, ret=None, gen=_g659bb0, note='batch34111')
S(0x54da10, 'GUESS reset state and buffer', 'thiscall', None, ret=None, gen=_g54da10, note='batch34111')
S(0x64de00, 'GUESS copy two blocks and vectors', 'thiscall', None, ret='eax', gen=_g64de00, note='batch34111')
