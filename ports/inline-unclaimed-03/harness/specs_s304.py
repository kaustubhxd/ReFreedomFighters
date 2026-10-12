"""specs_s304.py - unclaimed-03 batch 4 (docs/20-unclaimed-03.md): ZMatPosAnim::RunOffscreen (0x4a5da0) and
ZMovementBaseMove::GetActiveWalkDefsList (0x488b60). Both call a virtual slot on a fresh vtable per case; the slot is a
stub (ret or mov eax, imm32; ret) so the exe and the port call the same code and get the same answer. The owner's
flags dword at +0x417 is drawn from {0, 0x400, 0x800, 0xc00} so each branch is reached."""
from pilot import S

def _flush(c):
    """Stub code is written into the heap and the exe image at the same addresses each case. Drop Unicorn's translations
    for both so the new bytes run (see docs/20-unclaimed-20.md, harness note; added here, batch 11 review)."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _runoff(c):
    o = _rnd(c, 0x800)
    vt = c.emu.alloc(0x100, 4)
    # slot +0x64 is a thiscall with one stack argument. The stub copies that argument into a heap cell (mov eax,[esp+4];
    # mov [cell],eax; ret 4), so the heap comparison sees the value the caller pushed (the stub log keeps no arguments).
    cell = c.emu.alloc(8, 4)
    c.emu.w32(cell, 0)
    code = b'\x8b\x44\x24\x04' + b'\xa3' + cell.to_bytes(4, 'little') + b'\xc2\x04\x00'
    c.emu.w32(vt + 0x64, _stub(c, code))
    c.emu.w32(o, vt)
    return [o, c.rng.choice([0, 1, 0x80, 0xff, c.rng.getrandbits(8)])]


def _walk(c):
    o = _rnd(c, 0x800)
    owner = _rnd(c, 0x800)
    vt = c.emu.alloc(0x600, 4)
    v = c.rng.choice([0, 1, 0x80, c.rng.getrandbits(8)])
    c.emu.w32(vt + 0x534, _stub(c, b'\xb8' + (v).to_bytes(4, 'little') + b'\xc3'))
    c.emu.w32(owner, vt)
    c.emu.w32(owner + 0x417, c.rng.choice([0, 0x400, 0x800, 0xc00]))
    c.emu.w32(o + 4, owner)
    return [o]


S(0x4a5da0, 'ZMatPosAnim::RunOffscreen (unknown) thiscall', 'thiscall', None, ret=None, gen=_runoff,
  note='unclaimed-03 batch 4; slot +0x64 stub (ret 4); byte to +0x92')
S(0x488b60, 'ZMovementBaseMove::GetActiveWalkDefsList (unknown) thiscall', 'thiscall', None, ret='eax', gen=_walk,
  note='unclaimed-03 batch 4; owner slot +0x534 stub; flags at owner+0x417')
