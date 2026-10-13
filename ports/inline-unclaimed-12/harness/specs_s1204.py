"""specs_s1204.py - unclaimed-12 batch 4 (docs/20-unclaimed-12.md, claim 4): ZProjectile::CopyData, ZRelayMessage::Command and
ZActor::SetEndDir. All thiscall. Callees stay original code (0x4ba310, 0x44c840); the virtual call of ZRelayMessage::Command
goes to a logging vtable, so the call, its object and its three arguments are compared."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    return [_rnd(c, 0x100), _rnd(c, 0x100)]


def _command(c):
    # this+0x44: a logging object (vtable slot +0x12c takes 3 stack args); word +0x48 equals the argument's low word in
    # a third of the cases, a third with high bits set, a third random
    vt = c.emu.logging_vtable('relay-target', 0x130, argwords={0x12c: 3})
    target = _rnd(c, 0x40)
    c.emu.w32(target, vt)
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x44, target)
    word = c.rng.randint(0, 0xffff)
    c.emu.w16(self_ + 0x48, word)
    r = c.rng.random()
    if r < 0.33:
        arg = word
    elif r < 0.66:
        arg = word | (c.rng.getrandbits(16) << 16)
    else:
        arg = c.rng.getrandbits(32)
    return [self_, arg, _rnd(c, 0x20)]


def _enddir(c):
    # the direction is three floats (edge values included); null in 20% of cases
    self_ = _rnd(c, 0x800)
    if c.rng.random() < 0.2:
        return [self_, 0]
    d = _rnd(c, 16)
    for i in range(3):
        c.emu.wf32(d + 4 * i, c.fv(-10.0, 10.0))
    return [self_, d]


S(0x4b9530, 'ZProjectile::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-12 batch 4; dword +0x4c/+0x48, byte +0x50, dword +0x91/+0x89 from src, then initScales 0x4ba310')
S(0x4b85c0, 'ZRelayMessage::Command (unknown) thiscall', 'thiscall', None, ret='eax', gen=_command,
  note='unclaimed-12 batch 4; if word arg == word +0x48: vtable +0x12c of [this+0x44] with (dword +0x4c, word +0x4a, arg2)')
S(0x47bd90, 'ZActor::SetEndDir (unknown) thiscall', 'thiscall', None, ret=None, gen=_enddir,
  note='unclaimed-12 batch 4; copies 3 floats to +0x69a, zeroes +0x69e, normalises (0x44c840), flag +0x699')
