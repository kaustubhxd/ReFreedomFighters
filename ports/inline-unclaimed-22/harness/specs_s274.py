"""specs_s274.py - area 22, batch274 (src/batch274.cpp): ZPlayer::ClassCommand. Callees are hooked by address (both
sides reach the hooks): the base ZLNKWHANDS::ClassCommand 0x472ae0 and the box setup 0x4eb080 are not verified anywhere
(GUESS stubs); PositionCollisionBox 0x484b10 (unclaimed-41), the box point test 0x4eaea0 (unclaimed-63) and
CheckMoveObjectTorso 0x481990 (batch273) are verified and hooked here only to keep the world small. Hooks log buffer
contents, never stack addresses, and write per-case floats into their output buffers. PSVECSubtract, vmtmul, vmmul,
PSVECAdd, vdist, mcpy and the CRT sqrt thunk run as original code."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _log_world


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


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _wfl(e, a, vals):
    for j, v in enumerate(vals):
        e.w32(a + 4 * j, _fb(v))


def _g_481e10(c):
    e = c.emu
    _log_world(c, pslot=0x2c)
    words = [c.rng.getrandbits(16) for _ in range(10)]
    for a, w in zip((0x6ff9a0, 0x6ff9a4, 0x6ff9a8, 0x6ff9ac, 0x6ff9bc), words[:5]):
        e.w16(a, w)

    def hook(addr, name, nargs, outs=None, logs=None, ret=0, st0=None):
        outs = outs or {}
        logs = logs or {}
        """outs: {argindex: list of float bit patterns to write}; logs: {argindex: nbytes} to log by content."""
        def h(em, r):
            a = [em.arg32(i) for i in range(nargs)]
            rec = tuple(em.rbytes(a[i], logs[i]) if i in logs else ('stack' if i in outs else a[i]) for i in range(nargs))
            em.calllog.append((name, 0, None, rec))
            for i, vals in outs.items():
                for j, v in enumerate(vals):
                    em.w32(a[i] + 4 * j, v)
            if st0 is not None:
                em.ret(st0=st0, argbytes=4 * nargs)
            else:
                em.ret(eax=ret(em) if callable(ret) else ret, argbytes=4 * nargs)
        e.hook(addr, h)
    hook(0x472ae0, 'base.472ae0', 2, ret=c.rng.getrandbits(32))
    hook(0x484b10, 'posbox.484b10', 5, logs={2: 12})
    hook(0x4eb080, 'boxset.4eb080', 3, logs={0: 36, 1: 12, 2: 12})
    tests = [c.rng.choice([0, 1, 1, 0x100]) for _ in range(2)]
    tq = list(tests)
    newpt = _fl(c, 3, -100, 100) if c.rng.random() < 0.7 else None
    shift = c.rng.choice([45.0, 49.0, 55.0, 30.0]) if c.rng.random() < 0.4 else None
    first = [True]

    def boxtest(em, r):
        a0, a1 = em.arg32(0), em.arg32(1)
        em.calllog.append(('boxtest.4eaea0', 0, None, (em.rbytes(a0, 12), em.rbytes(a1, 12))))
        if first[0] and newpt:
            if shift is not None:   # move the point by a set distance (the 50-unit drop edge)
                x = struct.unpack('<f', em.rbytes(a0, 4))[0]
                em.w32(a0, _fb(x + shift))
            else:
                for j in range(3):
                    em.w32(a0 + 4 * j, newpt[j])
        first[0] = False
        em.ret(eax=tq.pop(0) if tq else 0, argbytes=8)
    e.hook(0x4eaea0, boxtest)
    hook(0x481990, 'cmot.481990', 9, outs={0: _fl(c, 3, -100, 100), 1: _fl(c, 9, -1, 1)},
         logs={3: 36, 4: 12, 5: 36, 6: 12, 7: 36, 8: 12}, st0=c.rng.uniform(0, 1))
    box = _rnd(c, 0x40)
    coli = _rnd(c, 0x10)
    e.w32(coli, _pyvt(c, {0x48: _slot('coli.48', 2, box), 0x4c: _slot('coli.4c', 1)}))
    osd = _rnd(c, 0x20)
    e.w32(osd + 0x1c, coli)
    obj = _rnd(c, 0x10)
    e.w32(obj, _pyvt(c, {0x80: _fill('obj.80', 0, (9, _fl(c, 9, -1, 1)), (3, _fl(c, 3, -100, 100)))}))
    itg = _rnd(c, 0x10)
    e.w32(itg, _pyvt(c, {0x210: _slot('itg.210', 1)}))
    item = _rnd(c, 0x10)
    e.w32(item, _pyvt(c, {0x20: _slot('item.20', 0, c.rng.choice([itg, itg, 0]))}))
    heldid = c.rng.getrandbits(32)
    itemid = c.rng.getrandbits(32)
    other = _rnd(c, 0x10)
    e.w32(other, _pyvt(c, {0x20: _slot('other.20', 0, 0), 0x80: _fill('other.80', 0, (9, _fl(c, 9, -1, 1)), (3, _fl(c, 3, -100, 100)))}))
    held = c.rng.choice([obj, other, 0])

    def db58(em):
        a = em.arg32(0)
        return held if a == heldid else (item if a == itemid else (other if a & 4 else 0))
    db = _rnd(c, 0x40)
    e.w32(db, _pyvt(c, {0x58: _slot('db.58', 1, db58), 0x4c: _slot('db.4c', 1, lambda em: em.arg32(0) ^ 0x5a5a0000)}))
    rm = _rnd(c, 0x1b00)
    e.w32(rm + 0x9b, db)
    e.w32(rm + 0x1aa3, osd)
    f592 = c.rng.choice([0.0, 1.0, 2.0, 0.5, c.rng.uniform(0, 4)])
    e.w32(rm + 0x40, c.rng.choice([c.rng.randrange(0, 4000), int(f592 * 1024), int(f592 * 1024) + 1]))
    e.w32(0x70039c, rm)
    self_ = _rnd(c, 0x700)
    e.w32(self_, _pyvt(c, {0x594: _slot('a.594', 1), 0x598: _slot('a.598', 1),
                           0x5a0: _fill('a.5a0', 0, (9, _fl(c, 9, -1, 1)), (3, _fl(c, 3, -100, 100)), (3, _fl(c, 3, -100, 100))),
                           0x428: _slot('a.428', 0, c.rng.choice([heldid, c.rng.getrandbits(32)])),
                           0x618: _slot('a.618', 1), 0x424: _slot('a.424', 1), 0x36c: _slot('a.36c', 0),
                           0x368: _slot('a.368', 0)}))
    e.w8(self_ + 0x412, c.rng.choice([1, 1, 1, 1, 0, 0x80]))
    e.w32(self_ + 0x413, c.rng.choice([itemid, itemid, c.rng.getrandbits(32)]))
    e.w32(self_ + 0x417, c.rng.choice([0, 0, 0, 0x40000, c.rng.getrandbits(32) & ~0x40000]))
    e.w8(self_ + 0x5ff, c.rng.choice([0, 1, 1]))
    e.w32(self_ + 0x592, _fb(f592))
    for k, o in enumerate((0x61e, 0x620, 0x622, 0x624, 0x626, 0x628)):
        e.w16(self_ + o, words[5 + k] if k < 5 else c.rng.getrandbits(16))
    w628 = struct.unpack('<H', e.rbytes(self_ + 0x628, 2))[0]
    cmds = words + [w628] * 6 + [c.rng.getrandbits(16)]
    cmd = c.rng.choice(cmds) | (c.rng.choice([0, 0, c.rng.getrandbits(16)]) << 16)
    data = _rnd(c, 0x80)
    e.w32(data + 1, c.rng.choice([obj, obj, other]))
    e.w32(data + 5, _fb(c.rng.choice([0.0, 1.0, 2.0, 3.0, 1.5])))
    big = c.rng.random() < 0.5
    for o in (9, 0xd, 0x11):
        e.w32(data + o, _fb(c.rng.uniform(1, 50)))
    for o in range(0x15, 0x39, 4):
        e.w32(data + o, _fb(c.rng.uniform(-1, 1)))
    for o in range(0x45, 0x69, 4):
        e.w32(data + o, _fb(c.rng.uniform(-1, 1)))
    p0 = [c.rng.uniform(-100, 100) for _ in range(3)]
    p1 = [v + (c.rng.uniform(-100, 100) if big else c.rng.choice([0.0, 0.00001, 0.0005, 0.00008, c.rng.uniform(-0.01, 0.01)])) for v in p0]
    if c.rng.random() < 0.15:   # identity frame and a move with two equal components (the axis tie)
        k = c.rng.choice([5.0, -5.0, 0.5])
        p1 = [p0[0] + k, p0[1] + k, p0[2] + c.rng.choice([0.0, k, 2 * k])]
        for j, v in enumerate([1.0, 0, 0, 0, 1.0, 0, 0, 0, 1.0]):
            e.w32(data + 0x15 + 4 * j, _fb(v))
    for j in range(3):
        e.w32(data + 0x39 + 4 * j, _fb(p0[j]))
        e.w32(data + 0x69 + 4 * j, _fb(p1[j]))
    e.mu.ctl_flush_tb()
    return [self_, cmd, data]


S(0x481e10, 'ZPlayer::ClassCommand', 'thiscall', None, ret='eax', gen=_g_481e10, nan_heap=True,
  note='batch274; callees hooked (472ae0, 4eb080 GUESS; 484b10, 4eaea0, 481990 verified); vector helpers and sqrt as exe code; SEH cookie not reproduced')
