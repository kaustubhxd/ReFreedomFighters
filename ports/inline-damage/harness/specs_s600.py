"""specs_s600.py - damage batch 600: hitpoint and damage-multiplier accessors (ZFFActor, ZLNKWHANDS)."""
from pilot import S
from wkit import rnd, stub, fedge
import struct


def _s16(c):
    r = c.rng
    return r.choice((0, 1, -1, 100, 300, 0x7fff, -0x8000, r.randrange(-0x8000, 0x8000))) & 0xffff | (r.getrandbits(16) << 16)


def _actor(c):
    a = rnd(c, 0xa00)
    r = c.rng
    for off in (0x7a0, 0x7a2):
        if r.random() < 0.5:
            c.emu.wbytes(a + off, struct.pack('<h', r.choice((0, 1, -1, 100, 150, 300, 0x7fff, -0x8000))))
    return a


def _hands(c):
    a = rnd(c, 0x500)
    for off in range(0x3ea, 0x412, 4):
        c.emu.wf32(a + off, fedge(c))
    return a


def _zone(c):
    r = c.rng
    z = r.choice(list(range(10)) * 3 + [10, 11, 0xff, r.getrandbits(8)])
    return z | (r.getrandbits(24) << 8)   # only the low byte is the argument


def _hook(c):
    """Assert hook at 0x7003b0: always a stub that counts its calls (2026-10-12, hitreact thread: a null hook made the
    int3 path fault in both builds, which the strict rule (faulting_cases == 0) does not accept). The rng draw is kept."""
    c.rng.random()
    c.emu.w32(0x7003b0, stub(c, 0, cdecl=True))


S(0x5a2d90, 'ZFFActor::SetHitpoints', 'thiscall', ret=None, gen=lambda c: [_actor(c), _s16(c)])
S(0x59fe00, 'ZFFActor::GetHitpoints', 'thiscall', ret='eax', gen=lambda c: [_actor(c)])
S(0x5a2dc0, 'ZFFActor::SetMaxHitpoints', 'thiscall', ret=None, gen=lambda c: [_actor(c), _s16(c)])
S(0x59fec0, 'ZFFActor::GetMaxHitpoints', 'thiscall', ret='eax', gen=lambda c: [_actor(c)])
S(0x5a2e10, 'ZFFActor::SetPlayingHitAnimId', 'thiscall', ret=None, gen=lambda c: [_actor(c), c.rng.getrandbits(32)])
S(0x475930, 'ZLNKWHANDS::SetHitAnimation', 'thiscall', ret=None, gen=lambda c: [_actor(c), c.rng.getrandbits(32)])


def _get(c):
    _hook(c)
    return [_hands(c), _zone(c)]


def _set(c):
    return [_hands(c), _zone(c), struct.unpack('<I', struct.pack('<f', fedge(c)))[0]]


S(0x474250, 'ZLNKWHANDS::GetDamageMultForBone', 'thiscall', ret='st0', gen=_get)
S(0x475820, 'ZLNKWHANDS::SetDamageMultForBone', 'thiscall', ret=None, gen=_set)
