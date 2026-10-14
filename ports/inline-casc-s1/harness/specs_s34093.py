"""specs_s34093.py - six items. 0x4e50a0: the exe faults on a non-negative [c+4] so the spec keeps it negative (bit 0x40000000 random), index small; 0x494030: tail target slot 0x124 recorder; 0x655f60: block header size word around the argument."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4e50a0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x20)
    cc = rnd(c, 0x60)
    v = 0x80000000 | (r.getrandbits(32) & 0x7fffffff)
    c.emu.w32(cc + 4, v)
    c.emu.w32(cc + 0x10, r.randrange(0, 8))
    c.emu.w32(me + 4, cc)
    return [me]


def _g494030(c):
    clear_hooks(c)
    r = c.rng
    so = rnd(c, 0x1b00)
    o = 0 if r.random() < 0.3 else obj(c, 0x20, {0x124: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x128 // 4)
    c.emu.w32(0x70039c, so)
    c.emu.wbytes(so + 0x1a9f, o.to_bytes(4, 'little'))
    return [r.getrandbits(32)]


def _g534150(c):
    clear_hooks(c)
    return [rnd(c, 0x4020)]


def _g65da30(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x430)
    buf = rnd(c, 0x80)
    m = rnd(c, 0x10)
    c.emu.w32(m + 4, r.randrange(0, 8))
    c.emu.w32(me + 0x404, buf)
    c.emu.w32(me + 0x40c, m)
    lo = r.choice([0, 4, 100, 0xffffffff])
    c.emu.w32(me + 0x41c, lo)
    c.emu.w32(me + 0x420, r.choice([lo, (lo + 1) & 0xffffffff, (lo + 4) & 0xffffffff, 0, 0xffffffff, 200]))
    return [me, r.getrandbits(32)]


def _g5ab1e0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x3d0)
    cur = r.choice([0, 1, 5])
    c.emu.wbytes(me + 0x3c6, bytes([cur]))
    c.emu.wbytes(me + 0x3c2, r.choice([8, 8, 0, 3, r.getrandbits(32)]).to_bytes(4, 'little'))
    return [me, r.choice([0, 0, 1, 5, 0x100, 0x101, r.getrandbits(32)])]


def _g655f60(c):
    clear_hooks(c)
    r = c.rng
    so = rnd(c, 0x1ab0)
    o = rnd(c, 0x40)
    blk = rnd(c, 0x80)
    cptr = blk + 0x20
    c.emu.w32(cptr - 8, r.choice([0, 0x10, 0x20, 0x20000010, 0xe0000040, 0x10000020, 0x1ffffff0, r.getrandbits(32) & 0xffff]))
    c.emu.w32(o + 0x20, 0 if r.random() < 0.2 else cptr)
    c.emu.w32(0x70039c, so)
    c.emu.wbytes(so + 0x1aa3, o.to_bytes(4, 'little'))
    sz = c.emu.r32(cptr - 8) & 0x1fffffff
    a = r.choice([cptr - 1, cptr, cptr + 1, cptr + sz - 1, cptr + sz, cptr + sz + 1, cptr + 5, r.getrandbits(32), 0]) & 0xffffffff
    return [a]


S(0x4e50a0, 'GUESS indexed element read', 'thiscall', None, ret='eax', gen=_g4e50a0, note='batch34093')
S(0x494030, 'GUESS forward to engine object slot 0x124', 'stdcall', None, ret='eax', gen=_g494030, note='batch34093')
S(0x534150, 'GUESS init free-list table (second copy)', 'thiscall', None, ret='eax', gen=_g534150, note='batch34093')
S(0x65da30, 'GUESS append dword with budget', 'thiscall', None, ret=None, gen=_g65da30, note='batch34093')
S(0x5ab1e0, 'GUESS toggle mode byte', 'thiscall', None, ret=None, gen=_g5ab1e0, note='batch34093')
S(0x655f60, 'GUESS address inside block', 'stdcall', None, ret='al', gen=_g655f60, note='batch34093')
