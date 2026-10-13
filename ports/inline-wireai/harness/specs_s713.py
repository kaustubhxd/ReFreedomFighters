"""specs_s713.py - soldier AI batch 713: CCoverSpot type (0x585a10), CFFCoverList::FrameUpdate, CCoverSpot::CheckShootOver.
FrameUpdate: up to 300 spots (the 256-per-frame cap), random holders/users/expiry against the engine tick; the debug
draw (0x588180) and CoverSpotQuality are hooked (quality random incl. NaN; only the low byte of the pushed flag is
logged because the original pushes a dword whose upper bytes are stale stack). The expiry test and Release run as exe
code. CheckShootOver: ray test stub writes the COLI end point (+0x28) it later draws; config lookup and atof stubbed."""
import math
import struct
from pilot import S, F, f32
from specs_s701 import _rnd
from specs_s705 import _bool, nostk
from specs_s709 import _log_world


def _gt(c):
    _log_world(c)
    s = _rnd(c, 0x48)
    c.emu.w32(s + 0x34, c.rng.choice([0, 1, 2, 3, 4, 6, 8, c.rng.getrandbits(32)]))
    return [s]


S(0x585a10, 'CCoverSpot type (unnamed)', 'thiscall', None, ret='eax', gen=_gt, note='b713')


def _fu(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, e.reg('ecx'), tuple(nostk(a) for a in args)))
    eng = _rnd(c, 0x200)
    tick = c.rng.randint(0, 1 << 24)
    e.w32(eng + 0x40, tick)
    e.w32(0x70039c, eng)

    def root(em, r):
        p = em.arg32(0)
        log('geom', 0x84, tuple(struct.unpack('<3I', em.rbytes(p, 12))))
        em.wbytes(p, struct.pack('<3f', *[f32(c.rng.uniform(-500, 500)) for _ in range(3)]))
        em.ret(eax=0, argbytes=4)
    vt = e.fake_vtable('geom', 0x30, {0x84: root})

    def lookup(em, r):
        log('db', 0x58, (em.arg32(0),))
        g = _rnd(c, 32)
        e.w32(g, vt)
        em.ret(eax=g, argbytes=4)
    db = _rnd(c, 32)
    e.w32(db, e.fake_vtable('db', 0x20, {0x58: lookup}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))

    def draw(em, r):
        log('draw588180', 0, (em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=12)
    e.hook(0x588180, draw)

    def csq(em, r):
        log('CoverSpotQuality', 0, (em.arg32(0),) + tuple(struct.unpack('<3I', em.rbytes(em.arg32(1), 12))) + (em.arg32(2) & 0xff,))
        em.ret(argbytes=12, st0=c.rng.choice([0.0, 1.0, 1.0, -0.0, math.nan, -1.0]))
    e.hook(0x585910, csq)
    n = c.rng.choice([0, 1, 5, 40, 300])
    base = _rnd(c, 0x48 * max(n, 1))
    for i in range(n):
        s = base + 0x48 * i
        e.w32(s + 4, c.rng.choice([0, 0, c.rng.getrandbits(32)]))
        e.w32(s + 8, c.rng.choice([0, c.rng.getrandbits(32)]))
        e.wbytes(s, struct.pack('<f', f32((tick + c.rng.randint(-3000, 3000)) / 1024.0)))
    cl = _rnd(c, 0x80)
    e.wbytes(cl + 0x5f, struct.pack('<II', base, base + 0x48 * n))
    e.wbytes(cl + 0x73, struct.pack('<I', c.rng.choice([0, base, base + 0x48 * n, base + 0x48 * c.rng.randrange(max(n, 1))])))
    disp = _rnd(c, 16)
    e.w32(disp, e.logging_vtable('dispatch', 0x50, argwords={0x12c: 3}))
    e.wbytes(cl + 0x44, struct.pack('<I', disp))
    e.mu.mem_write(0x714290, struct.pack('<f', c.rng.choice([-1.0, -1.0, 0.0, 1.0, math.nan])))
    return [cl]


S(0x587850, 'CFFCoverList::FrameUpdate', 'thiscall', None, ret=None, gen=_fu,
  note='b713 [high]; expiry test 0x5de970 and Release run as exe code')


def _atof(em, r):
    s = em.arg32(0)
    raw = em.rbytes(s, 16)
    txt = raw[:raw.index(0)].decode() if 0 in raw else '0'
    em.calllog.append(('atof', 0, None, (s,)))
    try:
        v = float(txt)
    except ValueError:
        v = 0.0
    em.ret(st0=v, argbytes=0)


def _cso(c):
    e = c.emu
    e.stub_import('atof', _atof)
    log = lambda name, off, args: e.calllog.append((name, off, e.reg('ecx'), tuple(nostk(a) for a in args)))
    _log_world(c)
    rd = lambda a, n: tuple(struct.unpack('<%dI' % n, e.rbytes(a, 4 * n)))

    def ray(em, r):
        p = em.arg32(0)
        log('scene', 0x2e0, rd(p, 6) + rd(p + 0x34, 1) + rd(p + 0x44, 1) + (em.r8(p + 0x6c),) + tuple(em.arg32(k) for k in range(1, 6)))
        em.wbytes(p + 0x28, struct.pack('<3f', *[f32(c.rng.uniform(-100, 100)) for _ in range(3)]))
        em.ret(eax=_bool(c), argbytes=24)

    def box(em, r):
        log('scene', 0x238, rd(em.arg32(0), 9) + rd(em.arg32(1), 3) + rd(em.arg32(2), 3) + (em.arg32(3), em.arg32(4)))
        em.ret(eax=0, argbytes=20)

    def line(em, r):
        log('scene', 0x218, rd(em.arg32(0), 3) + rd(em.arg32(1), 3) + (em.arg32(2),))
        em.ret(eax=0, argbytes=12)
    sc = _rnd(c, 32)
    e.w32(sc, e.fake_vtable('scene', 0xc0, {0x2e0: ray, 0x238: box, 0x218: line}))
    vals = [e.cstr(v) for v in ('0', '1', '0.5', '-1')]

    def cfg(em, r):
        log('engine', 0x5c, (em.arg32(0),))
        em.w32(em.arg32(1), c.rng.choice(vals))
        em.ret(eax=_bool(c), argbytes=8)
    eng = _rnd(c, 0x200)
    e.w32(eng, e.fake_vtable('engine', 0x20, {0x5c: cfg}))
    db = _rnd(c, 0xb00)
    e.wbytes(db + 0xadc, struct.pack('<I', sc))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))
    e.w32(0x70039c, eng)
    spot = _rnd(c, 0x48)
    e.wbytes(spot + 0x10, struct.pack('<3f', *[f32(c.rng.uniform(-500, 500)) for _ in range(3)]))
    e.w32(spot + 0x34, c.rng.choice([1, 2, 4, 8]))
    d = e.alloc(12, 4)
    dv = c.rng.choice([[0.0, 0.0, 0.0], [1.0, 0.0, 0.0], [c.rng.uniform(-1, 1) for _ in range(3)], [0.0, 0.0, 1e-40]])
    e.wbytes(d, struct.pack('<3f', *[f32(x) for x in dv]))
    return [spot, d, F(f32(c.rng.uniform(0, 100))), F(f32(c.rng.uniform(0, 300)))]


S(0x5deb20, 'CCoverSpot::CheckShootOver', 'thiscall', None, ret='al', gen=_cso, note='b713 [medium]; x87 normalise')
