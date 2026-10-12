"""specs_s729.py - soldier AI batch 729: ZCharisma::Command and CActorActionMarker::Remove.
Command: the engine record (0x7003b8) is a random block; the command word is equal to the one passed in about half the cases;
the game-OSD getter 0x589c20 is hooked (logs its five arguments, returns a fake OSD object) and CharismaAddExperience 0x596940
is hooked (logs). Remove: the marker's count (+0x44) and pointer array (+4) hold 0..5 records of 0x18 bytes (random
contents, unique first dwords); the argument is one of the first dwords or a value that matches none."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _cc(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    gl = _rnd(c, 0x2c20)
    e.w32(0x7003b8, gl)
    osd = _rnd(c, 0x80)

    def h_osd(em, r):
        log('gd', 0x589c20, tuple(em.arg32(k) for k in range(5)))
        em.ret(eax=osd, argbytes=20)

    def h_add(em, r):
        log('osd', 0x596940, ())
        em.ret(eax=0, argbytes=0)

    e.hook(0x589c20, h_osd)
    e.hook(0x596940, h_add)

    self_ = _rnd(c, 0x60)
    cmd = c.rng.getrandbits(16)
    e.wbytes(self_ + 0x4c, struct.pack('<H', cmd))
    e.w32(self_ + 0x48, c.rng.getrandbits(32))
    arg = cmd if c.rng.random() < 0.5 else c.rng.getrandbits(16)
    return [self_, arg, _rnd(c, 0x10)]


def _rm(c):
    e = c.emu
    self_ = _rnd(c, 0x100)
    n = c.rng.randint(0, 5)
    recs = []
    for i in range(n):
        r = _rnd(c, 0x18)
        e.w32(r, 0x1000 + i * 0x18 + c.rng.getrandbits(8))   # unique first dword
        recs.append(r)
    e.w32(self_ + 0x44, n)
    for i, r in enumerate(recs):
        e.w32(self_ + 4 + 4 * i, r)
    if recs and c.rng.random() < 0.7:
        obj = e.r32(recs[c.rng.randrange(n)])
    else:
        obj = c.rng.getrandbits(32) | 0x80000000
    return [self_, obj]


S(0x5b7900, 'ZCharisma::Command', 'thiscall', None, ret='eax', gen=_cc, note='b729 [high]; OSD getter and experience hooked')
S(0x5eac30, 'CActorActionMarker::Remove', 'thiscall', None, ret=None, gen=_rm, note='b729 [medium]; swap-with-last removal')
