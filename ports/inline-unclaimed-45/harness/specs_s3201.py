"""specs_s3201.py - area 45 batch 3201: ZActor::GetCage (0x478b40), ZFFActor::ResetLastHitPos (0x5a2980),
ZActor::SetPathNotify (0x47bfc0). Random object bytes (0x1000) so the reads and stores are checked."""
from pilot import S, F


def _obj(c):
    e, r = c.emu, c.rng
    o = e.alloc(0x1000, 4)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x1000)))
    return [o]


def _objf(c):
    e, r = c.emu, c.rng
    o = e.alloc(0x1000, 4)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x1000)))
    return [o, F(c.fv(-1000.0, 1000.0))]


S(0x478b40, 'ZActor::GetCage', 'thiscall', None, ret='eax', gen=_obj, note='batch3201')
S(0x5a2980, 'ZFFActor::ResetLastHitPos', 'thiscall', None, gen=_obj, note='batch3201')
S(0x47bfc0, 'ZActor::SetPathNotify', 'thiscall', None, gen=_objf, note='batch3201')
