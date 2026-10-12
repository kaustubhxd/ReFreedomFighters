"""specs_s308.py - unclaimed-03 batch 8 (docs/20-unclaimed-03.md): ZItem::GetItemRootTM (0x46e760), thiscall with two
output pointers (ret 8). The five engine helpers are original code (not stubbed). Stubs in both runs:
  * the object's vtable slot +0x2c8 (thiscall, two arguments): records its arguments in heap cells, ret 8;
  * the object's vtable slot +0x2dc (thiscall, no arguments): returns X, a fresh object whose +8 points at a random
    0x800-byte object Y (so the helpers read real memory), 'mov eax, X; ret'.
Outputs a1 and a2 are random 0x100-byte buffers, so the helpers' writes are compared in the heap."""
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


def _gen(c):
    self_ = _rnd(c, 0x800)
    cells = c.emu.alloc(8, 4)
    c.emu.wbytes(cells, bytes(8))
    code = (b'\x8b\x44\x24\x04\xa3' + cells.to_bytes(4, 'little') +
            b'\x8b\x44\x24\x08\xa3' + (cells + 4).to_bytes(4, 'little') + b'\xc2\x08\x00')
    vt = c.emu.alloc(0x400, 4)
    c.emu.w32(vt + 0x2c8, _stub(c, code))
    Y = _rnd(c, 0x800)
    X = _rnd(c, 0x800)
    c.emu.w32(X + 8, Y)
    c.emu.w32(vt + 0x2dc, _stub(c, b'\xb8' + X.to_bytes(4, 'little') + b'\xc2\x00\x00'))
    c.emu.w32(self_, vt)
    return [self_, _rnd(c, 0x100), _rnd(c, 0x100)]


S(0x46e760, 'ZItem::GetItemRootTM (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-03 batch 8; stubs: vtbl+0x2c8 (records args), vtbl+0x2dc (returns X); helpers 0x4dfd10, 0x4de480, 0x441970, 0x4de420, 0x43e960 original')
