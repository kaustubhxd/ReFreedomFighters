"""specs_s909.py - unclaimed-01 claim 8 (docs/20-unclaimed-01.md): CExplode::Save (0x584d00) and ZRelayMessage::Command
(0x4b85c0). Both targets are logging fake vtables (the save object at slot +0x3c with one argument; the relay's object at
+0x44 with slot +0x12c and three arguments). Command's first argument matches the word at +0x48 about half the time."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _save(c):
    o = _rnd(c, 0x100)
    save = _rnd(c, 0x40)
    vt = c.emu.logging_vtable('ZSaveGame', 0x40, argwords={0x3c: 1})
    c.emu.w32(save, vt)
    return [o, save]


def _command(c):
    o = _rnd(c, 0x100)
    w = c.rng.getrandbits(16)
    c.emu.w16(o + 0x48, w)
    vt = c.emu.logging_vtable('ZRelayTarget', 0x130, argwords={0x12c: 3})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    c.emu.w32(o + 0x44, obj)
    r = c.rng.random()
    # Matching low word (half the time), with random high bits a quarter of those, so the 16-bit compare is checked.
    if r < 0.25:
        a1 = w
    elif r < 0.5:
        a1 = w | (c.rng.getrandbits(16) << 16)
    else:
        a1 = c.rng.getrandbits(32)
    return [o, a1, c.rng.getrandbits(32)]


S(0x584d00, 'CExplode::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-01 claim 8; clears +4 bit 0x40, slot +0x3c with dword +0x5e, returns true')
S(0x4b85c0, 'ZRelayMessage::Command (unknown) thiscall', 'thiscall', None, ret='eax', gen=_command,
  note='unclaimed-01 claim 8; slot +0x12c with three arguments when the low word matches +0x48')
