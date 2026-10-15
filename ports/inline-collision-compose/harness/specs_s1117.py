"""specs_s1117.py - collision thread batch 1117: room queries. Callbacks 0x4eda00 / 0x4ed840 get a heap room
record and records with axis-aligned or rotated frames around the query point; the render manager maps keys to
rooms (slot 0x58) and geoms (slot 0x54); the room directory's slots 0x1c / 0x20 log the values behind their
pointer args. GetRoomsLst's octree stub logs the record and fills the out list (so the release loop runs)."""
import math
import struct
from pilot import S, F
from specs_s1110 import _vt

HB = 0x20000000


def _hx(em, p, n):
    return bytes(em.mu.mem_read(p, n)).hex()


def _rot(r):
    if r.random() < 0.5:
        return [1, 0, 0, 0, 1, 0, 0, 0, 1]
    a = r.uniform(-math.pi, math.pi)
    ca, sa = math.cos(a), math.sin(a)
    return [ca, 0, -sa, 0, 1, 0, sa, 0, ca]


def _world(c):
    e, r = c.emu, c.rng
    sysobj = e.alloc(0x1b00, 4)
    e.w32(0x70039c, sysobj)
    e._image_dirty = True
    rm = e.alloc(0x100, 4)
    e.w32(sysobj + 0x9b, rm)
    X = e.alloc(0x40, 4)
    e.w32(sysobj + 0x1aa3, X)
    c.vars['rooms'] = {}
    c.vars['geoms'] = {}
    e.w32(rm, _vt(c, 'rm', {0x58: (1, lambda em, a: (c.vars['rooms'][a[0]], a[0])),
                           0x54: (1, lambda em, a: (c.vars['geoms'].get(a[0], 0), a[0]))}, 0x5c // 4))
    c.vars['dir'] = r.choice([0, 1, 0x100])
    rd = e.alloc(0x10, 4)
    e.w32(rd, _vt(c, 'roomdir', {0x1c: (3, lambda em, a: (c.vars['dir'], (a[0], _hx(em, a[1], 12), a[2]))),
                                0x20: (4, lambda em, a: (c.vars['dir'], (a[0], _hx(em, a[1], 36), _hx(em, a[2], 12), a[3])))},
                 0x24 // 4))
    e.w32(X + 0x18, rd)


def _room(c):
    e, r = c.emu, c.rng
    room = e.alloc(0x10, 4)
    v = r.choice([0, 0, 0, 1, 2, 0x101])
    e.w32(room, _vt(c, 'room', {0x37c: (0, lambda em, a: (v, ())), 0x378: (2, lambda em, a: (0, tuple(a)))}, 0x380 // 4))
    return room


def _rec(c, base, centre):
    e, r = c.emu, c.rng
    off = r.choice([0, 0x10, 0x100])
    rec = base + off
    e.w32(rec, r.choice([0, 1, 0x100]))
    m = _rot(r)
    for i in range(9):
        e.wf32(rec + 4 + 4 * i, m[i])
    for j in range(3):
        e.wf32(rec + 0x28 + 4 * j, centre[j] + r.uniform(-8, 8))
        e.wf32(rec + 0x34 + 4 * j, centre[j] + r.uniform(-8, 8))
        e.wf32(rec + 0x40 + 4 * j, r.uniform(0.5, 10))
    key = r.getrandbits(32)
    c.vars['rooms'][key] = _room(c)
    e.w32(rec + 0x4c, key)
    gk = 0
    if r.random() < 0.5:
        gk = r.getrandbits(32) | 1
        if r.random() < 0.8:
            g = e.alloc(0x70, 4)
            e.w32(g + 0x6c, r.getrandbits(32))
            c.vars['geoms'][gk] = g
    e.w32(rec + 0x50, gk)
    return off


def _info(c, n_out):
    e, r = c.emu, c.rng
    info = e.alloc(0xc0, 4)
    e.wbytes(info, bytes(r.getrandbits(8) for _ in range(0xc0)))
    base = e.alloc(0x200, 4)
    e.w32(info + 0x5c, base)
    out = e.alloc(4 * 8, 4)
    e.w32(info + 0x60, out)
    cnt = r.choice([0, 1, 7, 8])
    e.w32(info + 0x68, cnt)
    e.w32(info + 0x64, out + 4 * r.choice([cnt, cnt + 1, 8]))
    centre = [r.uniform(-20, 20) for _ in range(3)]
    for j in range(3):
        e.wf32(info + 0x90 + 4 * j, centre[j])
        e.wf32(info + 0x9c + 4 * j, r.uniform(0.1, 5))
        e.wf32(info + 0xa8 + 4 * j, r.uniform(0.1, 8))
    m = _rot(r)
    for i in range(9):
        e.wf32(info + 0x6c + 4 * i, m[i])
    return info, base, centre


def _pcb(c):
    e, r = c.emu, c.rng
    _world(c)
    info, base, centre = _info(c, 8)
    off = _rec(c, base, centre)
    obj = e.alloc(8, 4)
    e.w32(obj, off)
    return [obj, info]


def _rl(c, box):
    e, r = c.emu, c.rng
    _world(c)
    out = e.alloc(4 * 8, 4)
    end = out + 4 * r.choice([0, 1, 4, 8])
    rooms = [_room(c) for _ in range(8)]
    oct_ = e.alloc(0x20, 4)
    e.w32(oct_ + 0x14, r.getrandbits(32))

    def query(em, a):
        info = a[0]
        rec = (_hx(em, info, 8), _hx(em, info + 0x5c, 4), em.r32(info + 0x60), em.r32(info + 0x64), em.r32(info + 0x68),
               _hx(em, info + 0x6c, 0x48) if box else _hx(em, info + 0x90, 12),
               tuple(_hx(em, p, 12) for p in a[1:]))
        n = (em.r32(info + 0x64) - em.r32(info + 0x60)) // 4
        for i in range(n):
            em.w32(em.r32(info + 0x60) + 4 * i, rooms[i])
        em.w32(info + 0x68, n)
        return 0, rec
    e.w32(oct_, _vt(c, 'oct', {0x24: (2, query), 0x1c: (3, query)}, 0x28 // 4))
    this = e.alloc(0x1b0, 4)
    p = e.alloc(0x10, 4)
    for j in range(3):
        e.wf32(p + 4 * j, r.uniform(-50, 50))
    if not box:
        return [this, out, end, oct_, p]
    m = e.alloc(0x30, 4)
    for i, v in enumerate(_rot(r)):
        e.wf32(m + 4 * i, v)
    h = e.alloc(0x10, 4)
    for j in range(3):
        e.wf32(h + 4 * j, r.uniform(0.1, 5))
    return [this, out, end, oct_, m, p, h]


def _fwd(c, off):
    e, r = c.emu, c.rng
    this = e.alloc(0x1b0, 4)
    e.w32(this + off, r.getrandbits(32))
    e.w32(this, _vt(c, 'cbase', {0x14: (6, lambda em, a: (0, tuple(a)))}, 0x18 // 4))
    return [this] + [r.getrandbits(32) for _ in range(5)]


def _mmt(c):
    from specs_s1100 import _vec
    return [_vec(c, 9, -1, 1), _vec(c, 9, -2, 2), _vec(c, 9, -2, 2)]


S(0x4de4b0, 'mmtmul (guessed)', 'fastcall', None, gen=_mmt, note='batch1117')
S(0x4eda00, 'point-in-room callback (0x4eda00)', 'fastcall', None, ret='al', gen=_pcb, note='batch1117')
S(0x4ed840, 'box-in-room callback (0x4ed840)', 'fastcall', None, ret='al', gen=_pcb, note='batch1117')
S(0x4ed4f0, 'ZCollisionBase::GetRoomsLst (point)', 'thiscall', None, gen=lambda c: _rl(c, False), note='batch1117')
S(0x4ed390, 'ZCollisionBase::GetRoomsLst (box)', 'thiscall', None, gen=lambda c: _rl(c, True), note='batch1117')
S(0x4ed340, 'ZCollisionBase::GetInsideRoomsLst', 'thiscall', None, gen=lambda c: _fwd(c, 0x1a1), note='batch1117')
S(0x4ecb00, 'ZCollisionBase::GetColiRoomsLst', 'thiscall', None, gen=lambda c: _fwd(c, 0x19d), note='batch1117')
