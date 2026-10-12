"""specs_s268.py - area 22, batch268 (src/batch268.cpp): ZFFItemBomb::FrameUpdate. Every object is a Python vtable; slots
that receive stack buffers write per-case floats into them and log only values (never stack addresses). SetBombTime 0x5ea840
(inline-unclaimed-57) and GetOwnerRoom 0x4db3b0 (audit/inline-frameupdate) run as original code; the CRT sin/cos thunk
0x634d70 goes to pe_emu's math stub on both sides. 20% of cases put the timer just before a whole second or just before 10 s
so the beep and explosion edges are exercised."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _slot(name, nargs, ret=0):
    def h(em, r):
        em.calllog.append((name, 0, None, tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret(em) if callable(ret) else ret, argbytes=4 * nargs)
    return h


def _fill(name, ret, *counts):
    """Slot whose stack-buffer arguments get per-case floats (len(counts) arguments, counts[i] floats each)."""
    def h(em, r):
        em.calllog.append((name, 0, None, ()))
        for i, (n, vals) in enumerate(counts):
            a = em.arg32(i)
            for j in range(n):
                em.w32(a + 4 * j, vals[j])
        em.ret(eax=ret, argbytes=4 * len(counts))
    return h


def _fl(c, n, lo, hi):
    return [_fb(c.rng.uniform(lo, hi)) for _ in range(n)]


def _logbuf(name, nargs):
    """Slot that logs the float contents of its buffer arguments (9 then 3 floats)."""
    def h(em, r):
        a = [em.arg32(i) for i in range(nargs)]
        em.calllog.append((name, 0, None, (em.rbytes(a[0], 36), em.rbytes(a[1], 12)) + tuple(a[2:])))
        em.ret(eax=0, argbytes=4 * nargs)
    return h


def _g_5d42d0(c):
    e = c.emu
    fx2 = _rnd(c, 0x10)
    e.w32(fx2, _pyvt(c, {0x2c: _slot('fx2.2c', 0), 0x138: _slot('fx2.138', 3)}))
    fx = _rnd(c, 0x10)
    e.w32(fx, _pyvt(c, {0x1bc: (lambda em, r: (em.calllog.append(('fx.1bc', 0, None, (em.arg32(0), em.rbytes(em.arg32(1), 36),
                                                                                 em.rbytes(em.arg32(2), 12)) + tuple(em.arg32(i) for i in range(3, 7)))),
                                               em.ret(eax=fx2, argbytes=28)))}))
    room = _rnd(c, 0x10)
    e.w32(room, _pyvt(c, {0x94: _logbuf('room.94', 2)}))
    nm = _rnd(c, 0x10)
    e.w32(nm + 4, c.rng.choice([0, _r(c)]))
    owner = _rnd(c, 0x60)
    db = _rnd(c, 0xb00)
    if c.rng.random() < 0.6:
        e.w32(owner + 0x3c, 0x40000)
        e.w16(owner + 0x5c, 0)
        e.w32(db + 0xadc, room)
    else:
        e.w32(owner + 0x3c, 0)
        lk = _rnd(c, 0x30)
        e.w32(lk + 0x23, 0x100021)
        e.w32(owner + 0x50, 0)
        e.w32(owner + 0x54, room)
        e.w32(room + 0xc, lk)
    item = _rnd(c, 0x10)
    e.w32(item + 8, owner)
    mat = _fl(c, 9, -1, 1)
    pos = _fl(c, 3, -100, 100)
    e.w32(item, _pyvt(c, {0x80: _fill('item.80', 0, (9, mat), (3, pos)), 0x20: _slot('item.20', 0, nm),
                          0x128: (lambda em, r: (em.calllog.append(('item.128', 0, None, (em.arg32(0), em.r32(em.arg32(1)),
                                                                                      em.r32(em.arg32(1) + 4), em.arg32(2)))),
                                                 em.ret(eax=0, argbytes=12))),
                          0x210: _slot('item.210', 1)}))
    disp = _rnd(c, 0x10)
    e.w32(disp, _pyvt(c, {0x7c: _logbuf('disp.7c', 2), 0x234: _slot('disp.234', 1), 0x28: _slot('disp.28', 0),
                          0x210: _slot('disp.210', 1)}))
    tgt = _rnd(c, 0x10)
    e.w32(tgt, _pyvt(c, {0x128: (lambda em, r: (em.calllog.append(('tgt.128', 0, None, (em.arg32(0), em.r32(em.arg32(1)),
                                                                                     em.r32(em.arg32(1) + 4), em.arg32(2)))),
                                                em.ret(eax=0, argbytes=12)))}))
    tgt2 = _rnd(c, 0x10)
    e.w32(tgt2, _pyvt(c, {0x128: (lambda em, r: (em.calllog.append(('tgt2.128', 0, None, (em.arg32(0), em.r32(em.arg32(1)),
                                                                                       em.r32(em.arg32(1) + 4), em.arg32(2)))),
                                                 em.ret(eax=0, argbytes=12)))}))
    tid = _r(c) | 1
    hd = _r(c)
    scene = _rnd(c, 0x10)
    e.w32(scene, _pyvt(c, {0x88: (lambda em, r: (em.calllog.append(('scene.88', 0, None, (em.arg32(0),))),
                                                 em.w32(em.arg32(1), hd), em.ret(eax=0, argbytes=8)))}))
    e.w32(db, _pyvt(c, {0x58: _slot('db.58', 1, lambda em: tgt if em.arg32(0) == tid else tgt2), 0x138: _slot('db.138', 0, scene),
                        0x4c: _slot('db.4c', 1, lambda em: em.arg32(0) ^ 0x5a5a0000)}))
    dl = _rnd(c, 0x10)
    e.w32(dl, _pyvt(c, {0xcc: _slot('dl.cc', 1, lambda em: em.arg32(0) ^ 0x33330000)}))
    e.w32(0x70038c, dl)
    snd = _rnd(c, 0x10)
    e.w32(snd, _pyvt(c, {0x120: _slot('snd.120', 2)}))
    rm = _rnd(c, 0x1b00)
    e.w32(rm + 0x9b, db)
    e.w32(rm + 0x1a9f, c.rng.choice([snd, snd, 0]))
    ms = c.rng.choice([16, 33, 1, 0, 100, 1500, c.rng.randrange(0, 2000)])
    base = c.rng.randrange(-2 ** 31, 2 ** 31 - 3000)
    e.w32(rm + 0x40, (base + ms) & 0xffffffff)
    e.w32(rm + 0x44, base & 0xffffffff)
    e.w32(0x70039c, rm)
    osd = _rnd(c, 0x1d20)
    self_ = _rnd(c, 0x80)
    e.w32(self_, _pyvt(c, {0x68: _slot('self.68', 2)}))
    edge = c.rng.random() < 0.2
    dt = ms / 1024.0
    exact10 = c.rng.random() < 0.04
    if exact10:
        ms = 0
        e.w32(rm + 0x40, base & 0xffffffff)
        t = 10.0
    elif c.rng.random() < 0.08:
        t = c.rng.choice([1.0, 5.0, 9.0]) + c.rng.uniform(0, 0.02)
    elif edge:
        t = c.rng.choice([9.0, 3.0, 0.0, 10.0, 7.0]) + c.rng.uniform(-1.2, 0.05) * max(dt, 0.001)
    else:
        t = c.rng.choice([c.rng.uniform(0, 10), c.rng.uniform(9, 11), c.rng.uniform(-1, 12)])
    e.w32(self_ + 0x5b, _fb(t))
    e.w32(self_ + 0x44, item)
    e.w32(self_ + 0x48, c.rng.choice([disp, disp, 0]))
    e.w32(self_ + 0x5f, osd)
    e.w32(self_ + 0x63, c.rng.choice([fx, fx, 0]))
    if e.r32(self_ + 0x63) and not e.r32(self_ + 0x48):
        e.w32(self_ + 0x48, disp)
    e.w32(self_ + 0x56, c.rng.choice([tid, tid, 0, _r(c) | 1]))
    e.w8(self_ + 0x5a, c.rng.choice([0, 1, 0x80]))
    e.w32(self_ + 0x67, c.rng.choice([_r(c), 0]))
    e.mu.ctl_flush_tb()
    return [self_]


S(0x5d42d0, 'ZFFItemBomb::FrameUpdate', 'thiscall', None, ret=None, gen=_g_5d42d0, nan_heap=True,
  note='batch268; void; SetBombTime and GetOwnerRoom as exe code; SEH cookie not reproduced')
