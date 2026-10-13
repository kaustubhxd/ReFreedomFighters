"""specs_s1006.py - area 81 (residue 0), batch 1006: ZFFHeroMovementCloseCombat::WantControl (0x5e7cc0). The hero object's vtable slots 0x100,
0x50c, 0x504 and 0x560, the chosen object's 0x350 and 0x35c, the q object's 0x328 and the name object's 0x2e8 are counting stubs with random
returns. The name pointer is null, a copy of "MonkeyWrench" (equal to the constant at 0x6ad8b4), or a random string. The float field of the hero
is random, so the truncated comparison runs both ways. The three stack arguments are unused by the function."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(a, text + b'\0')
    return a


def g(c):
    rnd = c.rng
    q = obj(c, 0x40, {0x328: _stub(c, 0, ret=rnd.choice([0, 1]))})
    p = obj(c, 0x100, {0x350: _stub(c, 0, ret=q), 0x35c: _stub(c, 0, ret=rnd.choice([0, 1]))})
    nm_roll = rnd.random()
    s = obj(c, 0x40)
    if nm_roll < 0.4:
        c.emu.w32(s + 4, 0)
    elif nm_roll < 0.7:
        c.emu.w32(s + 4, cstr(c, b'MonkeyWrench'))
    else:
        c.emu.w32(s + 4, cstr(c, bytes(rnd.choice(b'abcMonkeyWrench') for _ in range(rnd.randint(1, 8)))))
    r = obj(c, 0x100, {0x2e8: _stub(c, 0, ret=s)})
    x = obj(c, 0xc00)
    c.emu.wbytes(x + 0xb45, bytes([1 if rnd.random() < 0.2 else 0]))
    hero = obj(c, 0x1000, {0x50c: _stub(c, 0, ret=p if rnd.random() < 0.8 else 0),
                           0x504: _stub(c, 0, ret=r if rnd.random() < 0.8 else 0),
                           0x560: _stub(c, 1, ret=rnd.choice([0, 1])),
                           0x100: _stub(c, 1, ret=x)})
    c.emu.wbytes(hero + 0x66a, bytes([rnd.choice([0, 1])]))
    c.emu.wbytes(hero + 0x66d, bytes([rnd.choice([0, 1])]))
    c.emu.wbytes(hero + 0x831, bytes([1 if rnd.random() < 0.15 else 0]))
    c.emu.w32(hero + 0x85a, x if rnd.random() < 0.5 else 0)
    c.emu.w32(hero + 0x417, 0xe000000 if rnd.random() < 0.2 else r32(c) & 0x1fffffff)
    c.emu.wbytes(hero + 0x7f0, bytes([1 if rnd.random() < 0.3 else 0]))
    c.emu.w32(hero + 0x813, rf(c, -200, 200))
    self_ = obj(c, 0x800)
    c.emu.w32(self_ + 0x36d, hero)
    c.emu.wbytes(self_ + 0x5ac, bytes([1 if rnd.random() < 0.2 else 0]))
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x40, rnd.randint(-2000, 2000) & 0xffffffff)
    return [self_, r32(c), r32(c), r32(c)]


S(0x5e7cc0, 'ZFFHeroMovementCloseCombat::WantControl', 'thiscall', None, ret='al', gen=g)
