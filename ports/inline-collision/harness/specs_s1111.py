"""specs_s1111.py - collision thread batch 1111: MYSTR c_str, the primitive line callback 0x4ec610 and
ZCollisionBase::CalcLineCollision 0x4ebcf0 (primitive-octree path; the no-octree log path needs the exe's string
allocator and is not run). The octree stub logs the line-check record's fields, not its stack address."""
import struct
from pilot import S, F
from specs_s1110 import _world, _vt


def _rec(em, p):
    raw = bytes(em.mu.mem_read(p, 0x81))
    return (raw[0:8].hex(), raw[0x5c:0x81].hex())


def _fv(em, p):
    return bytes(em.mu.mem_read(p, 12)).hex()


def _cstr(c):
    return [c.bytes_(8)]


def _pcb(c):
    e, r = c.emu, c.rng
    sysobj, rm, X = _world(c)
    c.vars['hit'] = r.choice([0, 1, 0x100, 0x3ff])
    o1c = e.alloc(0x10, 4)
    e.w32(o1c, _vt(c, 'caster', {0x60: (6, lambda em, a: (c.vars['hit'], (a[0], a[1], _fv(em, a[2]), _fv(em, a[3]), a[4], a[5])))}, 0x64 // 4))
    e.w32(X + 0x1c, o1c)
    chk = e.alloc(0x90, 4)
    e.wbytes(chk, bytes(r.getrandbits(8) for _ in range(0x90)))
    imp = e.alloc(0x20, 4)
    e.w32(imp, r.getrandbits(32))
    e.w32(chk + 0x5c, imp)
    obj = e.alloc(0x10, 4)
    e.w32(obj, r.getrandbits(32))
    return [obj, chk]


def _clc(c):
    e, r = c.emu, c.rng
    sysobj, rm, X = _world(c)
    c.vars['hit'] = r.choice([0, 1, 0x100, 0x3ff])
    rd = e.alloc(0x40, 4)
    e.w16(rd + 2, 0 if r.random() < 0.85 else r.choice([0x100, 1, 0x8000]))
    prim = e.alloc(0x10, 4)
    e.w32(prim, _vt(c, 'prim', {0x18: (3, lambda em, a: (c.vars['hit'], (_rec(em, a[0]), a[1], _fv(em, a[2]))))}, 0x1c // 4))
    e.w32(rd + 0x28, prim if r.random() < 0.6 else ((prim - c.vars['octb']) | 1) & 0xffffffff)
    o18 = e.alloc(0x10, 4)
    e.w32(o18, _vt(c, 'rooms', {0xc: (1, lambda em, a: (rd, a[0]))}, 0x10 // 4))
    e.w32(X + 0x18, o18)
    this = e.alloc(0x1a0, 4)
    e.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x1a0)))
    imp = e.alloc(0x20, 4)
    e.wbytes(imp, bytes(r.getrandbits(8) for _ in range(0x20)))
    geom = e.alloc(0x80, 4)
    e.w32(geom + 0x6c, e.alloc(0x10, 4) if r.random() < 0.9 else 0)
    f = e.alloc(0x10, 4)
    v = e.alloc(0x10, 4)
    for j in range(3):
        e.wf32(f + 4 * j, r.uniform(-100, 100))
        e.wf32(v + 4 * j, r.uniform(-100, 100))
    return [this, imp, geom, f, v, r.getrandbits(32), r.getrandbits(32)]


S(0x4cc1d0, 'MYSTR::c_str (guessed)', 'thiscall', None, ret='eax', gen=_cstr, note='batch1111')
S(0x4ec610, 'primitive line callback (0x4ec610)', 'fastcall', None, ret='al', gen=_pcb, note='batch1111')
S(0x4ebcf0, 'ZCollisionBase::CalcLineCollision', 'thiscall', None, ret='al', gen=_clc, note='batch1111')


def _clc_(c, fwd=False):
    from specs_s1100 import _chain
    e, r = c.emu, c.rng
    sysobj, rm, X = _world(c)
    dyn = e.alloc(0x10, 4)
    c.vars['dynok'] = r.choice([0, 1, 0x100])
    e.w32(dyn, _vt(c, 'dyn', {0x30c: (0, lambda em, a: (c.vars['dynok'], ()))}, 0x310 // 4))
    e.w32(rm + 0xadc, dyn)
    olds = []
    for i in range(16):
        ob = e.alloc(0x10, 4)
        e.w32(ob, _vt(c, 'ring%d' % i, {0x378: (2, lambda em, a: (0, tuple(a)))}, 0x37c // 4))
        olds.append(ob)
    c.vars['hit'] = r.choice([0, 1, 0x100])
    c.vars['dhit'] = r.choice([0, 1, 0x200])
    ringn = r.choice([0, 0, 1, 5, 16])
    full = r.choice([0, 0, 1])

    def rooms(em, a):
        R = a[0]
        G = em.r32(R + 0x78)
        P = em.r32(G + 0x78)
        rec = (bytes(em.mu.mem_read(R, 8)).hex(), bytes(em.mu.mem_read(R + 0x5c, 0x1c)).hex(), em.r32(R + 0x7c),
               em.r32(R + 0xc0), em.mu.mem_read(R, 0xc8)[0xc4],
               bytes(em.mu.mem_read(G, 8)).hex(), bytes(em.mu.mem_read(G + 0x5c, 0x1c)).hex(),
               bytes(em.mu.mem_read(P, 8)).hex(), bytes(em.mu.mem_read(P + 0x5c, 8)).hex(),
               bytes(em.mu.mem_read(P + 0x7c, 5)).hex(), a[1], _fv(em, a[2]))
        # act like the walk: leave bound objects in the ring
        for i in range(16):
            em.w32(R + 0x80 + 4 * i, olds[i])
        em.w32(R + 0xc0, ringn)
        em.w8(R + 0xc4, full)
        return c.vars['hit'], rec
    ro = e.alloc(0x20, 4)
    e.w32(ro, _vt(c, 'roomtree', {0x18: (3, rooms)}, 0x1c // 4))
    e.w32(ro + 0x14, r.getrandbits(32))
    this = e.alloc(0x1b0, 4)
    e.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x1b0)))
    e.w32(this + 0x19d, ro)
    e.w32(this, _vt(c, 'cbase', {0x58: (7, lambda em, a: (c.vars['dhit'], tuple(a)))}, 0x5c // 4))
    imp = e.alloc(0x90, 4)
    e.wbytes(imp, bytes(r.getrandbits(8) for _ in range(0x90)))
    for j in range(3):
        e.wf32(imp + 4 + 4 * j, r.uniform(-10, 10))
    e.w32(imp + 0x10, _chain(c))
    f = e.alloc(0x10, 4)
    v = e.alloc(0x10, 4)
    for j in range(3):
        e.wf32(f + 4 * j, r.uniform(-100, 100))
        e.wf32(v + 4 * j, r.uniform(-100, 100))
    bools = [r.getrandbits(32) & r.choice([0xffffff00, 0xffffffff, 1]) for _ in range(3)]
    return [this, imp, r.getrandbits(32), f, v, bools[0], r.getrandbits(32), bools[1], bools[2]]


S(0x4eba90, 'ZCollisionBase::CalcLineColi_', 'thiscall', None, ret='al', gen=_clc_, note='batch1111')
S(0x4eba80, 'ZCollisionBase::CalcLineColi (forwarder)', 'thiscall', None, ret='al', gen=_clc_, note='batch1111')
