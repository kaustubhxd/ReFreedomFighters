"""specs_s34125.py - three items; callees are recorders (this recorded).
0x5368a0: slots 0x6c / 0x68 / 0x64 / 0x5c return random or -base (so the sum is zero), 0x1d0 and 0x1cc return random; base (unaligned +0x5302) zero in a tenth.
0x5b6ab0: list of 0..3 nodes; hooked 0x4db9a0 returns random low bytes; table slot 0x50, [this+0x48] slot 0x2c; the list's slot 0x50 writes the next node through its pointer.
0x5cd9c0: word at +0xb59 matches in a half; engine object [0x70038c] with slot 0x20 (1 arg), slot 0xac, function pointer +8 (a recorder stub) and bounds +0xc / +0x10 around this; [this-4] zero in a half."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g5368a0(c):
    clear_hooks(c)
    r = c.rng
    base = 0 if r.random() < 0.1 else r.getrandbits(32) | 1

    def mk(k):
        return lambda em, kk: r.choice([(-base) & 0xffffffff, (-base) & 0xffffffff, 0, r.getrandbits(32)])
    slots = {off: pystub(c, 1, ret=mk(off), this=True) for off in (0x6c, 0x68, 0x64, 0x5c)}
    slots[0x1d0] = pystub(c, 1, ret=lambda em, k: r.choice([0, 0, r.getrandbits(32)]), this=True)
    slots[0x1cc] = pystub(c, 1, ret=r.getrandbits(32), this=True)
    me = obj(c, 0x5310, slots, nslots=0x1d4 // 4)
    c.emu.wbytes(me + 0x5302, base.to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


def _g5b6ab0(c):
    clear_hooks(c)
    r = c.rng
    nodes = [rnd(c, 0x20) for _ in range(r.choice([0, 1, 2, 3]))]
    hook_rec(c, 0x4db9a0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    tbl = obj(c, 0x20, {0x50: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)}, nslots=0x54 // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, tbl)
    c.emu.w32(0x70039c, so)
    acc = obj(c, 0x20, {0x2c: pystub(c, 1, ret=lambda em, k: r.choice([0, 0, 1, 7]), this=True)}, nslots=0x30 // 4)
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x48, acc)
    state = {'i': 0}

    def nxt(em, k):
        i = k + 1
        em.w32(em.arg32(0), nodes[i] if i < len(nodes) else 0)
    lst = obj(c, 0x20, {0x50: pystub(c, 1, this=True, side=nxt, stackmark=(0,))}, nslots=0x54 // 4)
    c.emu.w32(lst + 8, nodes[0] if nodes else 0)
    return [me, lst]


def _g5cd9c0(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0xc00)
    me = blk + 8
    w = r.getrandbits(16)
    c.emu.wbytes(blk + 8 + 0xb59, w.to_bytes(2, 'little'))
    a = w if r.random() < 0.5 else r.getrandbits(32)
    if r.random() < 0.4:
        a = (a & 0xffff) | (r.getrandbits(16) << 16)
    stub = pystub(c, 0, ret=r.getrandbits(32), this=True)
    g = obj(c, 0x20, {0x20: pystub(c, 1, ret=lambda em, k: r.choice([0, 0, 1, 5]), this=True), 0xac: pystub(c, 1, this=True)}, nslots=0xb0 // 4)
    c.emu.w32(g + 8, stub if r.random() < 0.7 else 0)
    lo = r.choice([me - 8, me, me + 1, me + 100])
    hi = r.choice([me + 1, me + 100, me, me - 1])
    c.emu.w32(g + 0xc, lo)
    c.emu.w32(g + 0x10, hi)
    c.emu.w32(0x70038c, g)
    c.emu.w32(me - 4, 0 if r.random() < 0.5 else r.getrandbits(32))
    return [me, a, rnd(c, 0x10)]


S(0x5368a0, 'GUESS first non-zero handler result', 'thiscall', None, ret='eax', gen=_g5368a0, note='batch34125')
S(0x5b6ab0, 'GUESS find the first accepted item', 'thiscall', None, ret='eax', gen=_g5b6ab0, note='batch34125')
S(0x5cd9c0, 'GUESS look up an owner pointer', 'thiscall', None, ret='eax', gen=_g5cd9c0, note='batch34125')
