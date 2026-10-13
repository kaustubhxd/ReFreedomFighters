"""specs_s275.py - area 22, batch275 (src/batch275.cpp): ZFFHERO::ZFFHERO. Hooked by address (both sides reach the hooks):
ZPlayer::ZPlayer 0x480a40, MYSTR::MYSTR 0x4cbeb0 and the debug variable ctor 0x4d8330 (none verified: GUESS stubs), and the
inventory controller ctor 0x5afc10 (verified in audit/inline-inventory, hooked to keep the world small). The info list ctor
0x5aede0, SetDamageMultForBone 0x475820 (inline-damage) and the allocator 0x41e290 (over a Python allocator at
[0x70038c]) run as exe code. Engine db vt[0x114] returns a per-call random word; the render manager's config lookup
vt[0x5c](name, &value) answers per case (missing, or one of several value strings) and atoi is a Python import stub."""
import struct
from pilot import S
from helpers22 import _rnd, _multi_vt, _hk, _pyvt


def _atoi(em, r):
    s = em.rbytes(em.arg32(0), 32).split(b'\0')[0]
    t = s.lstrip(b' \t')
    sign = 1
    if t[:1] in (b'-', b'+'):
        sign = -1 if t[:1] == b'-' else 1
        t = t[1:]
    n = 0
    for ch in t:
        if 48 <= ch <= 57:
            n = n * 10 + ch - 48
        else:
            break
    em.ret(eax=(sign * n) & 0xffffffff, argbytes=0)


def _g_58ab50(c):
    e = c.emu
    e.stub_import('atoi', _atoi)
    db = _rnd(c, 0x100)
    e.w32(db, _multi_vt(c, {0x114: (lambda em, a: (c.rng.getrandbits(32), None), 4)}))
    strs = {}
    for name in ('blood', 'followsneak'):
        v = c.rng.choice([None, b'0', b'1', b'00', b'', b'abc', b' 7', b'-3', b'0x', b'01'])
        if v is None:
            strs[name] = None
        else:
            a = _rnd(c, 16)
            e.wbytes(a, v + b'\0')
            strs[name] = a

    def cfg(em, r):
        nm = em.rbytes(em.arg32(0), 16).split(b'\0')[0].decode()
        em.calllog.append(('rm.5c', 0, None, (nm,)))
        v = strs.get(nm)
        if v is not None:
            em.w32(em.arg32(1), v)
        em.ret(eax=0x1200 | (1 if v is not None else 0), argbytes=8)   # only al is tested

    def r1a4(em, r):
        em.calllog.append(('rm.1a4', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    rm = _rnd(c, 0x100)
    e.w32(rm, _pyvt(c, {0x5c: cfg, 0x1a4: r1a4}))
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    blk = c.rng.choice([_rnd(c, 0x108), _rnd(c, 0x108), 0])
    al = _rnd(c, 0x10)
    e.w32(al, _multi_vt(c, {8: (lambda em, a: (blk, None), 1)}))
    e.w32(0x70038c, al)
    _hk(c, 0x480a40, 'zplayer.480a40', 3, eax=lambda em: em.reg('ecx'))
    _hk(c, 0x4cbeb0, 'mystr.4cbeb0', 0, eax=lambda em: em.reg('ecx'))
    _hk(c, 0x4d8330, 'dbgvar.4d8330', 3, eax=lambda em: em.reg('ecx'))
    _hk(c, 0x5afc10, 'invctl.5afc10', 0, eax=lambda em: em.reg('ecx'))
    e.mu.ctl_flush_tb()
    return [_rnd(c, 0x1000), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x58ab50, 'ZFFHERO::ZFFHERO', 'thiscall', None, ret='eax', gen=_g_58ab50,
  note='batch275; base ctor 0x480a40, MYSTR ctor, debug variable ctor hooked (GUESS), inventory controller ctor hooked (verified); SEH frame and cookie not reproduced')
