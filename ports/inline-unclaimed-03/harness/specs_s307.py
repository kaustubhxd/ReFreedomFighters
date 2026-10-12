"""specs_s307.py - unclaimed-03 batch 7 (docs/20-unclaimed-03.md): ZActor::SetRootTM (0x47c0e0), thiscall, two stack
arguments (ret 8). Each case builds the fake world the function touches, and each callee is a stub in both runs:
  * global 0x700390 -> object G whose vtable slot +0x20 is a stub returning X (a fresh object);
  * X's vtable slot +0x2c is a stub 'ret' (the caller cleans its two arguments: 'add esp, 8' follows the call);
  * global 0x7003b0 -> a stub 'ret' (the PC code int3-faults when it is null, so it is always set);
  * the object's own vtable slot +0x578 is a stub that copies its two stack arguments into heap cells.
The stub's argument cells are in the heap, so a wrong argument shows in the heap compare."""
from pilot import S

def _flush(c):
    """Stub code is written into the heap and the exe image at the same addresses each case. Drop Unicorn's translations
    for both so the new bytes run (see docs/20-unclaimed-20.md, harness note; added here, batch 11 review)."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _cells(c, n):
    a = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(a, bytes(4 * n))
    return a


def _gen(c):
    self_ = c.emu.alloc(0x800, 4)
    c.emu.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    # the object's own vtable: +0x578 records (a1, a2) in heap cells (mov eax,[esp+4]; mov [c1],eax; mov eax,[esp+8];
    # mov [c2],eax; ret 8)
    c1, c2 = _cells(c, 1), _cells(c, 1)
    code = (b'\x8b\x44\x24\x04\xa3' + c1.to_bytes(4, 'little') +
            b'\x8b\x44\x24\x08\xa3' + c2.to_bytes(4, 'little') + b'\xc2\x08\x00')
    vt_self = c.emu.alloc(0x600, 4)
    c.emu.w32(vt_self + 0x578, _stub(c, code))
    c.emu.w32(self_, vt_self)
    # X and its vtable: +0x2c is 'ret' (the caller cleans); it records its two arguments in heap cells
    X = c.emu.alloc(0x40, 4)
    vt_x = c.emu.alloc(0x100, 4)
    x1, x2 = _cells(c, 1), _cells(c, 1)
    xcode = (b'\x8b\x44\x24\x04\xa3' + x1.to_bytes(4, 'little') +
             b'\x8b\x44\x24\x08\xa3' + x2.to_bytes(4, 'little') + b'\xc3')
    c.emu.w32(vt_x + 0x2c, _stub(c, xcode))
    c.emu.w32(X, vt_x)
    # G and its vtable: +0x20 returns X ('mov eax, X; ret 8')
    G_ = c.emu.alloc(0x40, 4)
    vt_g = c.emu.alloc(0x100, 4)
    c.emu.w32(vt_g + 0x20, _stub(c, b'\xb8' + X.to_bytes(4, 'little') + b'\xc2\x08\x00'))
    c.emu.w32(G_, vt_g)
    c.emu.w32(0x700390, G_)
    # 0x7003b0: a hook that returns at once
    c.emu.w32(0x7003b0, _stub(c, b'\xc3'))
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x47c0e0, 'ZActor::SetRootTM (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-03 batch 7; callees stubbed: vtbl+0x20 of *0x700390, vtbl+0x2c of X, *0x7003b0, own vtbl+0x578')
