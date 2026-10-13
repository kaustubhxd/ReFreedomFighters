"""specs_s44.py - inline session batch 44 (Haiku, night): 0x4dc290 ZBaseGeom::RequestCustomDraw. The object at this+0x54 gets
a test vtable whose slot 0xd0 points at 0x4dc2a1 (the exe's own 'xor al,al; ret' stub), so the dispatch runs as original code."""
from pilot import S

STUB = 0x4dc2a1


def _rcd(c):
    r = c.rng
    obj = c.emu.alloc(0x80, 4)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    if r.random() < 0.3:
        c.emu.w32(obj + 0x54, 0)
    else:
        target = c.emu.alloc(0x80, 4)
        vt = c.emu.alloc(0x400, 4)
        c.emu.w32(vt + 0xd0, STUB)
        c.emu.w32(target, vt)
        c.emu.w32(obj + 0x54, target)
    return [obj]


S(0x4dc290, 'ZBaseGeom::RequestCustomDraw', 'thiscall', None, ret='al', gen=_rcd,
  note='batch44; null child returns 0; otherwise slot 0xd0 of the child vtable (test vtable points at the exe stub 0x4dc2a1)')
