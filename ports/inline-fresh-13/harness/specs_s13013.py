"""specs_s13013.py - fresh-13 batch 13: 0x44f550 GUESS (clip records + vertex push-out). Thiscall, no args.
Geoms 0..3 (+0x40..0x48 thresholds), a list of 0..4 nodes whose objects are sometimes `this`, vtbl+0x1e0 returns a
random bool (0x100 = al 0), vtbl+0x80 and the callee 0x4db6c0 fill the record (axes in [-1,1], position in [-5,5]) from
a per-call float list and are logged; this->vtbl+0x94 logged. Records beyond the filled ones keep random finite values.
Vertices 0..6 (two arrays), weights 0 / -0 / NaN / random. The fastcall helpers 0x43e920 / 0x451890 / 0x443ef0 run as
exe code."""
import struct
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _f(r, lo, hi):
    return struct.unpack('<f', struct.pack('<f', r.uniform(lo, hi)))[0]


def _thr(r):
    k = r.random()
    if k < 0.08:
        return r.getrandbits(32)          # any bits (negative ones reject every vertex)
    if k < 0.15:
        return 0x7f7fffff
    return struct.unpack('<I', struct.pack('<f', r.uniform(0, 6)))[0]


def _rec(c, a, r):
    for k in range(9):
        c.emu.wf32(a + 4 * k, _f(r, -1, 1))
    for k in range(3):
        c.emu.wf32(a + 0x24 + 4 * k, _f(r, -5, 5))
    for k in range(3):
        c.emu.w32(a + 0x30 + 4 * k, _thr(r))


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=64, width=4)
    ng = r.choice([0, 1, 2, 3])
    nl = r.choice([0, 1, 2, 4])
    fills = [([_f(r, -1, 1) for _ in range(9)], [_f(r, -5, 5) for _ in range(3)]) for _ in range(8)]
    cnt = {'f': 0}

    def _fill(e):
        sp = e.reg('esp')
        a, b = e.r32(sp + 4), e.r32(sp + 8)
        ax, pos = fills[cnt['f'] % 8]
        cnt['f'] += 1
        if r2[cnt['f'] % 8] < 0.85:
            for k in range(9):
                e.wbytes(a + 4 * k, struct.pack('<f', ax[k]))
            for k in range(3):
                e.wbytes(b + 4 * k, struct.pack('<f', pos[k]))
        return 0
    r2 = [r.random() for _ in range(8)]

    def geom():
        g = rnd(c, 0x50)
        for k in range(3):
            c.emu.w32(g + 0x40 + 4 * k, _thr(r))
        return g
    me = vobj(c, 0xd0, {0x94: logstub(c, log, 2, 2)})
    nrec = max(ng + nl, 1) + 2
    recs = c.emu.alloc(nrec * 0x3c, 4)
    for k in range(nrec):
        _rec(c, recs + k * 0x3c, r)
    garr = c.emu.alloc(4 * max(ng, 1), 4)
    for k in range(ng):
        c.emu.w32(garr + 4 * k, geom())
    loghook(c, log, 0x4db6c0, 2, 1, ret=_fill)
    bools = [r.choice([0, 1, 1, 0x100, 0x201]) for _ in range(8)]
    cb = {'b': 0}

    def _b(e):
        v = bools[cb['b'] % 8]
        cb['b'] += 1
        return v
    s1e0 = logstub(c, log, 1, 3, ret=_b)
    s80 = logstub(c, log, 2, 4, ret=_fill)
    q = 0
    for k in range(nl):
        node = rnd(c, 0x64)
        if r.random() < 0.15:
            o = me
        else:
            o = vobj(c, 0x20, {0x1e0: s1e0, 0x80: s80})
            c.emu.w32(o + 8, geom())
        c.emu.w32(node + 0x54, o)
        c.emu.w32(node + 0x60, q)
        q = node
    p = rnd(c, 0x60)
    c.emu.w32(p + 0x50, q)
    c.emu.w32(me + 0xc8, r.choice([p, p, p, 0]))
    nv = r.choice([0, 1, 2, 3, 6])
    va = c.emu.alloc(4 * 6 * max(nv, 1), 4)
    for k in range(6 * nv):
        c.emu.wf32(va + 4 * k, _f(r, -5, 5))
    vp = c.emu.alloc(4, 4)
    c.emu.w32(vp, va)
    wa = c.emu.alloc(4 * max(nv, 1), 4)
    for k in range(nv):
        c.emu.w32(wa + 4 * k, r.choice([0, 0x80000000, 0x7fc00000, 0x3f800000, r.getrandbits(32) & 0x3fffffff]))
    c.emu.w32(me + 0x44, nv)
    c.emu.w32(me + 0x64, wa)
    c.emu.w32(me + 0x7c, vp)
    c.emu.w32(me + 0xa4, ng)
    c.emu.w32(me + 0xa8, r.choice([0, nrec, nrec - 1, ng + nl, 1]))
    c.emu.w32(me + 0xac, garr)
    c.emu.w32(me + 0xb0, recs)
    if r.random() < 0.25:
        # edge case: two unit records (n = +y and n = +z, axes = +x, thresholds 1.0, position 0) and one vertex whose
        # x / y / z hit the threshold, a tie between the records, or the -500 start of the best value
        ax0, ax1 = r.choice([((1.0, 0, 0), (1.0, 0, 0)), ((0, 0, 0), (1.0, 0, 0)), ((1.0, 0, 0), (0, 0, 0))])
        for k, nrm in ((0, (0.0, 1.0, 0.0)), (1, (0.0, 0.0, 1.0))):
            e = recs + k * 0x3c
            for i, f in enumerate(ax0 + nrm + ax1 + (0, 0, 0) + (1.0, 1.0, 1.0)):
                c.emu.wf32(e + 4 * i, f)
        if nv == 0:
            nv = 1
            c.emu.w32(me + 0x44, 1)
        c.emu.wf32(va, r.choice([0.0, 0.0, 1.0, -1.0, 0.5]))
        c.emu.wf32(va + 4, r.choice([-2.0, -2.0, -490.0, -500.0, -501.0]))
        c.emu.wf32(va + 8, r.choice([-2.0, -2.0, -490.0, -500.0, -501.0]))
        c.emu.w32(wa, 0x3f800000)
        c.emu.w32(me + 0xa4, 0)
        c.emu.w32(me + 0xc8, 0)
        c.emu.w32(me + 0xa8, 2)
    flush(c)
    return [me]


S(0x44f550, 'FUN_0044f550 (GUESS clip records + vertex push-out)', 'thiscall', None, ret=None, gen=_gen,
  note='fresh13 batch13013; record fillers and vcalls logged; vector helpers run as exe code')
