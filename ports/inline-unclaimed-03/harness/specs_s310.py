"""specs_s310.py - unclaimed-03 batch 10 (docs/20-unclaimed-03.md): CEnemyFlag::SetFlagFrame (0x5c2120), thiscall with one
stack argument (ret 4). The team is drawn from 0..9 (so the table and the default case both run). Stubs per gen:
  * global 0x70039c -> rm (0x2000 bytes): rm+0x9b -> o; rm+0x1aa3 -> obj3; obj3+0x18 -> obj4;
  * o's vtable slot +0x58: 'mov eax, obj2; ret' (obj2 is a random 0x800-byte object, so obj2+8 is read);
  * obj4's vtable slot +0xe0: records its two stack arguments into heap cells, ret 8."""
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
    rm = _rnd(c, 0x2000)
    obj2 = _rnd(c, 0x800)
    vt_o = c.emu.alloc(0x200, 4)
    c.emu.w32(vt_o + 0x58, _stub(c, b'\xb8' + obj2.to_bytes(4, 'little') + b'\xc3'))
    o = c.emu.alloc(0x40, 4)
    c.emu.w32(o, vt_o)
    obj3 = c.emu.alloc(0x40, 4)
    c.emu.wbytes(obj3, bytes(0x40))
    obj4 = c.emu.alloc(0x40, 4)
    c.emu.wbytes(obj4, bytes(0x40))
    cell1, cell2 = c.emu.alloc(4, 4), c.emu.alloc(4, 4)
    c.emu.w32(cell1, 0)
    c.emu.w32(cell2, 0)
    code = (b'\x8b\x44\x24\x04\xa3' + cell1.to_bytes(4, 'little') +
            b'\x8b\x44\x24\x08\xa3' + cell2.to_bytes(4, 'little') + b'\xc2\x08\x00')
    vt_4 = c.emu.alloc(0x200, 4)
    c.emu.w32(vt_4 + 0xe0, _stub(c, code))
    c.emu.w32(obj4, vt_4)
    c.emu.w32(obj3 + 0x18, obj4)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(rm + 0x1aa3, obj3)
    c.emu.w32(0x70039c, rm)
    team = c.rng.choice([c.rng.randint(0, 9), c.rng.getrandbits(32)])
    return [self_, team]


S(0x5c2120, 'CEnemyFlag::SetFlagFrame (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-03 batch 10; render-manager chain stubbed: vtbl+0x58 of o, vtbl+0xe0 of obj4')
