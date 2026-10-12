"""specs_s708.py - soldier AI batch 708: ZFFActor::ClassCommand. Callees (ZActor::ClassCommand, 0x5ab0d0,
SSquad::AddTarget, ZTargetManager::ObjectVisible/NotVisible) are hooked and logged; the message-id globals are set to
distinct values and the id is drawn from them (upper 16 bits random)."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import _bool, nostk

IDS = [0x7142d0, 0x7142d4, 0x7142d8, 0x7142dc, 0x7142e0, 0x7142e4, 0x7142e8]


def _hook(e, addr, name, nargs):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx'), tuple(nostk(em.arg32(k)) for k in range(nargs))))
        em.ret(eax=0x5a5a, argbytes=4 * nargs)
    e.hook(addr, h)


def _cc(c):
    e = c.emu
    for a, n, k in [(0x477950, 'ZActor::ClassCommand', 2), (0x5ab0d0, 'fn5ab0d0', 1), (0x589980, 'SSquad::AddTarget', 1),
                    (0x5a0e60, 'TM::ObjectVisible', 2), (0x5a0e10, 'TM::ObjectNotVisible', 2)]:
        _hook(e, a, n, k)
    log = lambda name, off, args: e.calllog.append((name, off, e.reg('ecx'), tuple(nostk(a) for a in args)))
    vals = c.rng.sample(range(1, 60), 8)
    for g, v in zip(IDS, vals):
        e.w16(g, v)
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)

    def slot(off, nargs, gen):
        def h(em, r):
            log('geom', off, tuple(em.arg32(k) for k in range(nargs)))
            em.ret(eax=gen(), argbytes=4 * nargs)
        return h

    def getint(em, r):
        log('data', 0x88, (em.arg32(0), em.arg32(1)))
        em.w32(em.arg32(1), c.rng.choice([0, 1, 5, -1 & 0xffffffff, c.rng.getrandbits(32), em.r32(em._self + 0x90f), em.r32(em._self + 0x90f)]))
        em.ret(eax=0, argbytes=8)
    vt = e.fake_vtable('geom', 0x1c0, {0x4d4: slot(0x4d4, 0, lambda: 0), 0x6c0: slot(0x6c0, 1, lambda: 0),
                                       0x6c4: slot(0x6c4, 1, lambda: 0),
                                       0x4c4: slot(0x4c4, 0, lambda: c.rng.choice([0, 7, c.rng.getrandbits(32)])),
                                       0x1e0: slot(0x1e0, 1, lambda: _bool(c)), 0x88: getint})

    def obj(n=0x960):
        g = _rnd(c, n)
        e.w32(g, vt)
        return g

    def lookup(em, r):
        log('db', 0x58, (em.arg32(0),))
        g = obj(0x80)
        if c.rng.random() < 0.3:
            em.w32(g + 0x54, 0)
        em.ret(eax=g, argbytes=4)
    db = _rnd(c, 64)
    e.w32(db, e.fake_vtable('db', 0x60, {0x58: lookup}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))
    a = obj()
    e._self = a
    team = _rnd(c, 16)
    e.w32(team + 4, c.rng.choice([0, 0, 1]))
    e.w32(a + 0x54, team)
    h = _rnd(c, 0x900)
    h2 = _rnd(c, 0x1d20)
    e.wbytes(h + 0x852, struct.pack('<I', h2))
    for off in (0x921, 0x92a, 0x90f):
        if c.rng.random() < 0.35:
            e.w32(a + off, 0)
    e.w32(a + 0x92e, h if c.rng.random() < 0.6 else 0)
    e.w8(a + 0x79e, c.rng.choice([0, 1, 2, 255]))
    pick = c.rng.random()
    if pick < 0.75:
        m = struct.unpack('<H', e.rbytes(c.rng.choice(IDS), 2))[0]
    elif pick < 0.9:
        m = struct.unpack('<H', e.rbytes(a + 0x128, 2))[0]
    else:
        m = c.rng.getrandbits(16)
    idv = m | (c.rng.getrandbits(16) << 16)
    data = obj(0x80)
    return [a, idv, data]


S(0x59e080, 'ZFFActor::ClassCommand', 'thiscall', None, ret='eax', gen=_cc, note='b708 [high]; callees hooked')
