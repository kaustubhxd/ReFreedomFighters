"""specs_f16b025.py - fresh slice 16 batch 25 (see src/f16b025.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr


def _4c6(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    h = codeaddr(c)
    phook(c, seq, h, 0)
    c.emu.w32(0x7003b0, h)
    db = obj(c, 0x80, {0x34: stub(c, seq, 1)})
    s = sysobj(c, db=db)
    c.emu.w32(s, c.emu.r32(obj(c, 0x200, {0x1a8: stub(c, seq, 1)})))
    phook(c, seq, 0x4690b0, 2)
    me = rnd(c, 0x50)
    c.emu.w32(me + 0x4c, obj(c, 0x10, {0: stub(c, seq, 1)}) if r.random() < 0.7 else 0)
    return [me, r.choice([0, 1, 4, 5, 3, 7, r.getrandbits(32)])]


def _63a(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    rec = c.emu.alloc(0x20, 4)

    def fill(e, a):
        tab = e.reg('edx')
        sv = [e.r32(a[0] + 4 * i) for i in range(3)]
        tv = [e.r32(a[1] + 4 * i) for i in range(3)]
        for i, v in enumerate(sv + tv):
            e.w32(rec + 4 * i, v)
        e.w32(rec + 0x18, e.reg('ecx'))
        x = 0x9e3779b9
        for i in range(16):
            x = (x * 0x01000193 ^ sv[i % 3] ^ (tv[i % 3] << 1)) & 0xffffffff
            e.w32(tab + 4 * i, x)
    phook(c, seq, 0x6383a0, 2, pop=True, act=fill)
    lo, hi = rnd(c, 12), rnd(c, 12)
    for p in (lo, hi):
        for i in range(3):
            c.emu.w32(p + 4 * i, r.choice([r.randrange(0, 64), r.getrandbits(32)]))
    idx = c.emu.alloc(64, 4)
    for i in range(16):
        c.emu.w32(idx + 4 * i, r.randrange(0, 4))
    return [r.choice([0, 1, r.getrandbits(32)]), lo, hi, rnd(c, 0x100), idx]


def _443(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    child = r.getrandbits(32)
    frees = [0, r.choice([0, 0, 1])]   # pool count after each free = arrays still to free (+ maybe others)
    ca = codeaddr(c)
    phook(c, seq, ca, 0, this=True, ret=lambda e: frees.__setitem__(0, frees[0] - 1) or frees[0] + frees[1])
    alloc = obj(c, 0x40, {0x20: stub(c, seq, 1), 0x14: ca, 0: stub(c, seq, 1)})
    c.emu.w32(0x6ff968, alloc)
    groups = []
    for _ in range(r.randrange(1, 4)):
        n = r.randrange(1, 5)
        arr = rnd(c, 4 + 4 * n + 8)   # a slot past the entries: a missing child writes arr[count]
        c.emu.w16(arr, n)
        c.emu.w16(arr + 2, r.choice([0, 0, 4, r.getrandbits(16)]))
        if r.random() < 0.8:
            c.emu.w32(arr + 4 + 4 * r.randrange(0, n), child)
        groups.append(arr)
        if n == 1 and c.emu.r32(arr) >> 16 == 0:
            frees[0] += 1
    tgs = []
    for arr in groups:
        g = obj(c, 0x400, {})
        c.emu.w32(g + 0x7b, arr)
        tgs.append(g)
    links = {}
    for k, g in enumerate(tgs):
        nxt = tgs[k + 1] if k + 1 < len(tgs) else 0
        par = rnd(c, 0x10) if (nxt or r.random() < 0.5) else 0
        vt = c.emu.r32(obj(c, 0x400, {0x310: stub(c, seq, 0, ret=r.choice([0, 0, 0, 1, 0x100])),
                                     0x308: stub(c, seq, 0, ret=r.choice([0, 0, 0, 1])),
                                     0x20: stub(c, seq, 0, ret=par)}))
        c.emu.w32(g, vt)
        if par:
            c.emu.w32(par + 8, (nxt ^ 0x5a000000) if nxt else r.getrandbits(32))
            links[(nxt ^ 0x5a000000) if nxt else c.emu.r32(par + 8)] = nxt
    phook(c, seq, 0x4db7e0, 0, this=True, ret=lambda e: links.get(e.reg('ecx'), 0))
    return [tgs[0], child]


S(0x4c6680, 'CRootGroup scalar deleting dtor', 'thiscall', None, ret='eax', gen=_4c6, note='f16b025; SEH not reproduced')
S(0x63a0c0, 'FUN_63a0c0 (colour block decode, GUESS)', 'fastcall', None, ret=None, gen=_63a, note='f16b025; cookie not reproduced')
S(0x443c80, 'ZTreeGroup::RemoveStaticChildTreeGroup', 'thiscall', None, ret=None, gen=_443, note='f16b025')
