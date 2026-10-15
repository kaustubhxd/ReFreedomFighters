"""specs_s506.py - weapons batch 506: ZItemWeapon::ScopeReady / ScopeFire."""
import struct
from pilot import S
from wkit import stub, obj, sysobj, b, rnd


def _send_stub(c, newflag):
    """slot 0x12c: SendCommand(cam, id, &flag), pops 12; logs cam and id, then writes newflag (or nothing) to *flag."""
    a = stub(c, 3, skip=(2,))
    if newflag is None:
        return a
    # wrap: mov eax,[esp+12]; mov byte [eax], newflag; jmp a
    code = b'\x8b\x44\x24\x0c\xc6\x00' + bytes([newflag]) + b'\xe9'
    w = c.emu.alloc(0x20, 16)
    code += struct.pack('<i', a - (w + len(code) + 4))
    c.emu.wbytes(w, code)
    return w


def _scope(c):
    r = c.rng
    tm = obj(c, 0x40, {0x32c: stub(c, 0, ret=b(c, 0.2))})
    src = c.emu.alloc(4, 4)
    c.emu.w32(src, r.getrandbits(32) if r.random() < 0.8 else 0)
    x = obj(c, 0x100, {0x88: stub(c, 2, skip=(1,), ofills=((1, 0, src, 1),))})
    sysobj(c, {0x138: stub(c, 0, ret=x), 0x114: stub(c, 5, skip=(4,), ret=r.getrandbits(32))})
    own = obj(c, 0x40, {0x1e0: stub(c, 1, ret=b(c, 0.5)), 0x420: stub(c, 0, ret=r.choice((0, 1, 2)))})
    w = obj(c, 0x100, {0x350: stub(c, 0, ret=tm), 0x2f4: stub(c, 0, ret=0 if r.random() < 0.15 else own),
                       0x12c: stub(c, 2), 0x354: stub(c, 0, ret=b(c, 0.3))})
    return [w]


S(0x470a00, 'ZItemWeapon::ScopeReady', 'thiscall', None, ret='al', gen=_scope)
S(0x470920, 'ZItemWeapon::ScopeFire', 'thiscall', None, ret=None, gen=_scope)
