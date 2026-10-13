"""specs_s718.py - soldier AI batch 718: CFFCoverList::CreateSpotsAroundBox. GetSize (0x4db7c0) and striwcmp run as exe
code. The geom is a fake (root point slot 0x84 adds a fixed offset, name fill 0x1d8, parent ref 0x20, flag slot 0x210);
its base struct holds the tilt (+0x10, around the 0.717 limit), offset (+0x30) and size (+0x40..+0x48). The name is
"*_depend_on_parent" (in a few spellings), "<NONAME>" or random. CreateSpotsAlong (0x585f90) is hooked and logs its six
arguments; the MYSTR delete (0x634273) is hooked."""
import math
import struct
from pilot import S, f32
from specs_s701 import _rnd
from specs_s705 import _bool, nostk
from specs_s709 import _log_world


def _strchr(em, r):
    sp, ch = em.arg32(0), em.arg32(1) & 0xff
    i = 0
    while True:
        b = em.mu.mem_read(sp + i, 1)[0]
        if b == ch:
            em.ret(eax=sp + i, argbytes=0)   # cdecl import: the caller pops the arguments
            return
        if b == 0:
            em.ret(eax=0, argbytes=0)
            return
        i += 1


def _ab(c):
    e = c.emu
    e.stub_import('strchr', _strchr)
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    e.hook(0x634273, lambda em, r: (log('delete', 0, (em.arg32(0),)), em.ret(eax=0, argbytes=8)))

    def along(em, r):
        a, b = em.arg32(0), em.arg32(1)
        pa = tuple(struct.unpack('<3I', em.rbytes(a, 12)))
        pb = tuple(struct.unpack('<3I', em.rbytes(b, 12)))
        # the bool is passed as a dword whose upper bytes are stack garbage in the original; the callee reads only the low byte (movzx)
        log('along', 0, (pa, pb, em.arg32(2) & 0xff, em.arg32(3), em.arg32(4), em.arg32(5)))
        em.ret(eax=0, argbytes=24)
    e.hook(0x585f90, along)

    base = _rnd(c, 0x80)
    e.wbytes(base + 0x10, struct.pack('<f', f32(c.rng.choice([0.5, 0.7, 0.717, 0.7170001, 0.7169999, 0.9, 0.0]))))
    e.wbytes(base + 0x30, struct.pack('<3f', *[f32(c.rng.uniform(-200, 200)) for _ in range(3)]))
    e.wbytes(base + 0x40, struct.pack('<3f', *[f32(c.rng.choice([c.rng.uniform(1, 200), 0.0, 30.0, 40.0])) for _ in range(3)]))

    names = [e.cstr('*_depend_on_parent'), e.cstr('*_DEPEND_ON_PARENT'), e.cstr('crate'), e.cstr('<NONAME>')]
    g = _rnd(c, 0x80)
    e.w32(g + 4, c.rng.choice([0, 0, names[0], names[1], names[2], names[3]]))
    e.w32(g + 8, base)

    def rootpt(em, r):
        p = em.arg32(0)
        log('geom', 0x84, tuple(struct.unpack('<3I', em.rbytes(p, 12))))
        vals = struct.unpack('<3f', em.rbytes(p, 12))
        em.wbytes(p, struct.pack('<3f', vals[0] + 1.5, vals[1] - 0.25, vals[2] + 3.0))
        em.ret(eax=0, argbytes=4)

    def namefill(em, r):
        out = em.arg32(0)
        log('geom', 0x1d8, (em.arg32(1),))
        em.w32(out, g)            # MYSTR whose c_str is the geom address (only logged for the tilt warning)
        em.ret(eax=out, argbytes=8)

    def parentref(em, r):
        log('geom', 0x20, ())
        em.ret(eax=c.rng.getrandbits(32), argbytes=0)

    def flagged(em, r):
        log('geom', 0x210, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)
    gvt = e.fake_vtable('geom', 0x220, {0x84: rootpt, 0x1d8: namefill, 0x20: parentref, 0x210: flagged})
    e.w32(g, gvt)

    logobj = _rnd(c, 16)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: lambda em, r: (em.calllog.append(('log.printf', 0x2c, None, (em.arg32(1), em.arg32(2)))), em.ret(eax=0, argbytes=0))}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)

    def db4c(em, r):
        log('db', 0x4c, (em.arg32(0),))
        em.ret(eax=_rnd(c, 16), argbytes=4)
    db = _rnd(c, 0x100)
    e.w32(db, e.fake_vtable('db', 0x60, {0x4c: db4c}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))

    def _cs(em, p):
        out = b''
        while len(out) < 4096:
            b = bytes(em.rbytes(p, 1))
            if b == b'\0':
                break
            out += b
            p += 1
        return out

    def stricmp(em, r):
        a, b = _cs(em, em.arg32(0)).lower(), _cs(em, em.arg32(1)).lower()
        em.calllog.append(('stricmp', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=(0 if a == b else (1 if a > b else 0xffffffff)), argbytes=0)
    e.stub_import('_stricmp', stricmp)

    cl = _rnd(c, 0x80)   # the cover list is `this`
    return [cl, g, c.rng.choice([0, 1, 2, 3]), _bool(c)]


S(0x5868e0, 'CFFCoverList::CreateSpotsAroundBox', 'thiscall', None, ret=None, gen=_ab,
  note='b718 [high]; CreateSpotsAlong hooked; GetSize and striwcmp run as exe code')
