"""specs_s33042.py - h3 () batch 33042."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _seen(base):
    def side(em, k):
        em.calllog.append(('vt', 0, None, (em.r32(em.reg('ecx')),)))
    return side


def _g5e0f80(c):
    clear_hooks(c)
    hook_rec(c, 0x5e0e10, 2, this=True, side=_seen(0))
    return [rnd(c, 0x700), _w(c), _w(c)]


def _g4f6ab0(c):
    clear_hooks(c)
    hook_rec(c, 0x4f97f0, 3, this=True, side=_seen(0))
    return [rnd(c, 0x200), _w(c), _w(c), _w(c)]


def _g5ed460(c):
    clear_hooks(c)
    hook_rec(c, 0x5ec720, 1, this=True, side=_seen(0))
    return [rnd(c, 0x200)]


def _g5fbac0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5f4630, 0, this=True)
    hook_rec(c, 0x5f3e20, 0, this=True)
    me = rnd(c, 0x60)
    n = r.randrange(0, 8)
    cap = r.choice([n - 1, n, n + 1, n + 3, 0]) & 0xffffffff
    c.emu.w32(me + 0x18, rnd(c, 0x80))
    c.emu.w32(me + 0x1c, cap)
    c.emu.w32(me + 0x20, n)
    return [me, rnd(c, 0x40)]


def _g5f4dc0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ffd70, 2, this=True, ret=lambda em, k: r.choice([0xffffffff, 0xffffffff, 0, 5, _w(c)]))
    hook_rec(c, 0x5f5620, 1, this=True, ret=lambda em, k: _w(c))
    return [rnd(c, 0x100), _w(c)]


def _g4e6b40(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x40)
    c.emu.w32(me, r.choice([0, _w(c)]))
    c.emu.w32(me + 4, r.choice([0, _w(c)]))
    c.emu.wbytes(me + 0x14, bytes([r.choice([0, 1, 7])]))
    return [me]


def _g4951f0(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c, table_size=0x5e00)
    tab = c.emu.r32(so + 0x9b)
    c.emu.w32(tab + 0x5d35, r.choice([0, 1, _w(c)]))
    hook_rec(c, 0x4dbb00, 1, this=True)
    n = r.choice([0, 1, 2, 5])
    arr = rnd(c, 0x20)
    return [arr, n]


def _g54e100(c):
    clear_hooks(c)
    hook_rec(c, 0x634123, 5, side=lambda em, k: em.calllog.append(('vt', 0, None, (em.r32(em.arg32(0) - 0x10),))))
    return [rnd(c, 0x200)]


S(0x5e0f80, 'GUESS ctor2 + fields', 'thiscall', None, ret='eax', gen=_g5e0f80, note='batch33042')
S(0x5fbac0, 'GUESS vector push + notify', 'thiscall', None, ret=None, gen=_g5fbac0, note='batch33042')
S(0x4f6ab0, 'GUESS ctor3 + fields', 'thiscall', None, ret='eax', gen=_g4f6ab0, note='batch33042')
S(0x5f4dc0, 'GUESS lookup then store', 'thiscall', None, ret='al', gen=_g5f4dc0, note='batch33042')
S(0x4e6b40, 'GUESS release owned', 'thiscall', None, ret=None, gen=_g4e6b40, note='batch33042')
S(0x5ed460, 'GUESS ctor + fields', 'thiscall', None, ret='eax', gen=_g5ed460, note='batch33042')
S(0x4951f0, 'GUESS loop call 4dbb00', 'stdcall', None, ret=None, gen=_g4951f0, note='batch33042')
S(0x54e100, 'GUESS ctor with array init', 'thiscall', None, ret='eax', gen=_g54e100, note='batch33042')
