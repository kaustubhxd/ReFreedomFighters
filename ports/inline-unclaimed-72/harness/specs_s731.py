"""specs_s731.py - soldier AI batch 731: CActorActionMarker::Update. The marker holds 0..6 records (random contents, types drawn
from 0, 1, 2, 8, times in [-2, 2], flags random). The object's slots 0x20 (returns an object whose +8 points at a block with
flags, the 0x800 bit set in about a third of the cases), 0x3a0 (fills B and A, returns a value), 0x390 and 0x84 (fills A) are
fakes that log their arguments. The on-screen display is the marker's first dword and ZOnScreenDisplay::ActionMarkerAdd
0x5a57a0 is hooked (logs the vector and its arguments). The engine record at 0x70039c carries the frame step at +0x48."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _upd(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    e.wbytes(eng + 0x48, struct.pack('<f', _f(c.rng.uniform(0.01, 0.2))))

    osd = _rnd(c, 0x40)

    def h_add(em, r):
        A = em.arg32(0)
        log('osd', 0x5a57a0, (em.rbytes(A, 12), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=0, argbytes=16)
    e.hook(0x5a57a0, h_add)

    # the object's +8 block and the 0x3a0 / 0x390 / 0x84 answers
    blk = _rnd(c, 0x40)
    e.w32(blk + 0x3c, 0x800 if c.rng.random() < 0.33 else c.rng.getrandbits(12))
    xobj = _rnd(c, 0x20)
    e.w32(xobj + 8, blk)
    r1 = c.rng.getrandbits(32)

    def f20(em, r):
        log('obj', 0x20, ())
        em.ret(eax=xobj, argbytes=0)

    def f3a0(em, r):
        B, A = em.arg32(0), em.arg32(1)
        vals = [c.rng.uniform(-50.0, 50.0) for _ in range(6)]
        e.wbytes(B, struct.pack('<fff', *vals[:3]))
        e.wbytes(A, struct.pack('<fff', *vals[3:]))
        log('obj', 0x3a0, ())
        em.ret(eax=r1, argbytes=8)

    def f390(em, r):
        log('obj', 0x390, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)

    def f84(em, r):
        # in place, as the geom's slot 0x84 (batch 718): the input point is moved, so earlier edits to it show
        A = em.arg32(0)
        x, y, z = struct.unpack('<fff', em.rbytes(A, 12))
        e.wbytes(A, struct.pack('<fff', x + 1.5, y * 1.25, z - 2.0))
        log('obj', 0x84, ())
        em.ret(eax=0, argbytes=4)

    obj = _rnd(c, 0x40)
    e.w32(obj, e.fake_vtable('obj', 0x400, {0x20: f20, 0x3a0: f3a0, 0x390: f390, 0x84: f84}))

    self_ = _rnd(c, 0x100)
    e.w32(self_, osd)
    n = c.rng.randint(0, 6)
    e.w32(self_ + 0x44, n)
    for i in range(n):
        r = _rnd(c, 0x18)
        e.w32(r, obj)
        e.w32(r + 4, c.rng.choice([0, 1, 2, 8]))
        e.wbytes(r + 8, struct.pack('<f', c.rng.uniform(-2.0, 2.0)))
        e.w32(r + 0xc, c.rng.choice([0, 0, 0, 3]))
        e.w32(r + 0x10, _fb(c.rng.uniform(-2.0, 2.0)))
        e.wbytes(r + 0x14, bytes([c.rng.choice([0, 1])]))
        e.w32(self_ + 4 + 4 * i, r)
    return [self_]


S(0x5eac90, 'CActorActionMarker::Update', 'thiscall', None, ret=None, gen=_upd,
  note='b731 [medium]; object slots and ActionMarkerAdd are fakes; the removal pass is exercised')
