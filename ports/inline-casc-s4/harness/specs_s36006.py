"""specs_s36006.py - cascade s4 batch 36006: 0x54f010 (query interface bits + log), 0x631620 (sum u16 tables, compare), 0x63d840 (shutdown / free owned objects)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger, stub_memset


def _g54f010(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    hook_rec(c, 0x54ef60, 0, this=True, ret=r.choice([0, 1, 0x100, 0x101, 0x80]))

    def side(em, k):
        em.w32(em.arg32(3), r.choice([0, 1, 2, 3, 7, 0xfffffffb, 0xffffffff, r.getrandbits(32)]))
    rv = r.choice([0, 0, 1, 5, 0x80000000, 0xffffffff])
    p = obj(c, 0x20, {0x14: pystub(c, 4, ret=rv, side=side, stackmark=(3,))})
    me = rnd(c, 0x10)
    e.w32(me + 4, 0 if r.random() < 0.15 else p)
    return [me]


def _g631620(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    p = e.alloc(0x500, 4)
    mode = r.random()
    mA, mB = r.choice([0, 0xff, 0xffff, 0x3]), r.choice([0, 0xff, 0xffff, 0x3, 0x1fff])
    b = bytearray(0x500)
    for off in range(0x8c, 0x4a0, 2):
        b[off:off + 2] = (r.getrandbits(16) & (mB if (0xa8 <= off < 0x288 or off == 0x288) else mA)).to_bytes(2, 'little')
    if mode < 0.2:
        b = bytearray(0x500)
        v = r.randint(0, 40)
        b[0x8c:0x8e] = v.to_bytes(2, 'little')
        b[0x288:0x28a] = max(0, 4 * v + r.randint(0, 3) + (0 if r.random() < 0.7 else r.choice([-4, 4]))).to_bytes(2, 'little')
    if r.random() < 0.6:   # calibrated: make ebx == edi >> 2 (or one off) so that any single changed word flips the flag
        b = bytearray(0x500)
        hw = lambda o: int.from_bytes(b[o:o + 2], 'little')
        for off in range(0x8c, 0x4a0, 2):
            b[off:off + 2] = r.randint(1, 15).to_bytes(2, 'little')
        ebx = sum(hw(o) for o in (0x8c, 0x90, 0x94, 0x98, 0x9c, 0xa0, 0xa4))
        ebx += sum(hw(0x28c + 8 * k) + hw(0x290 + 8 * k) for k in range(0x40))
        sa = sum(hw(0xa8 + 8 * k) + hw(0xac + 8 * k) for k in range(0x3c))
        need = 4 * ebx + r.choice([0, 0, 3, 3, 4, -1]) - sa
        b[0x288:0x28a] = max(0, min(0xffff, need)).to_bytes(2, 'little')
    b[0x1c] = r.getrandbits(8)
    e.wbytes(p, bytes(b))
    return [p]


def _g63d840(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memset(c)
    for a in (0x64b070, 0x648280, 0x63fc20, 0x65f0f0):
        hook_rec(c, a, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    vt = obj(c, 0x10, {0x64: pystub(c, 0, this=True)})
    me = e.alloc(0x8300, 4)
    e.wbytes(me, bytes(r.getrandbits(8) for _ in range(0x110)))
    e.w32(me, e.r32(vt))
    e.wbytes(me + 5, bytes([1 if r.random() < 0.85 else 0]))
    n = r.choice([0, 1, 2, 4, r.randint(0, 4)])
    e.w32(me + 0xec, n)
    for i in range(4):
        e.w32(me + 0xf0 + 4 * i, 0 if r.random() < 0.25 else rnd(c, 0x10))
    return [me]


S(0x54f010, 'GUESS check interface flags and log', 'thiscall', None, ret='al', gen=_g54f010, note='batch36006')
S(0x631620, 'GUESS compare table sums, set flag byte', 'cdecl', None, ret=None, gen=_g631620, note='batch36006')
S(0x63d840, 'GUESS shutdown, free owned objects', 'thiscall', None, ret=None, gen=_g63d840, note='batch36006')
