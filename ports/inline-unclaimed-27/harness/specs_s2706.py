"""specs_s2706.py - unclaimed-27 claim 6 (docs/20-unclaimed-27.md): ZGEOM::CopyExData (0x45d720, thiscall, ret 4).
Stubs, NOT verified: the object's vtable slots +0x44 and +0x40 (no args), +0xfc and +4 (one argument each; they record it),
and the object at 0x70038c's slot +0xbc (one argument; records it). The global at 0x70039c is a fresh object whose +0x9b
points to G9; G9's +0x1c5d is the array base R, whose dword at R-8 holds a size (low 29 bits). The source's +0x10 points
to a block whose +0xc is a value V (0, inside [R, R+size), or outside), or the source's +0x10 is 0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _seqstub(seq, rec, has_arg):
    # Shared call counter at seq: increments it, stores the new count at rec+8 (so the call order is visible), and for
    # one-argument slots stores the argument at rec. Returns (ret 4) for one argument, plain ret otherwise.
    code = (b'\xff\x05' + seq.to_bytes(4, 'little')                     # inc dword [seq]
            + b'\xa1' + seq.to_bytes(4, 'little')                        # mov eax, [seq]
            + b'\xa3' + (rec + 8).to_bytes(4, 'little'))                 # mov [rec+8], eax
    if has_arg:
        code += b'\x8b\x44\x24\x04' + b'\xa3' + rec.to_bytes(4, 'little') + b'\xc2\x04\x00'
    else:
        code += b'\xc3'
    return code


def _cx(c):
    seq = c.emu.alloc(0x10, 4)
    rec_40 = c.emu.alloc(0x10, 4)
    rec_fc = c.emu.alloc(0x10, 4)
    rec_4 = c.emu.alloc(0x10, 4)
    rec_bc = c.emu.alloc(0x10, 4)
    vt = c.emu.alloc(0x800, 4)
    c.emu.w32(vt + 0x44, _stub(c, b'\xc3'))
    c.emu.w32(vt + 0x40, _stub(c, _seqstub(seq, rec_40, False)))
    c.emu.w32(vt + 0xfc, _stub(c, _seqstub(seq, rec_fc, True)))
    c.emu.w32(vt + 4, _stub(c, _seqstub(seq, rec_4, True)))
    o = _rnd(c, 0x800)
    c.emu.w32(o, vt)
    # the array: header with a size at base-8
    size = c.rng.randint(0x10, 0x400)
    blk = c.emu.alloc(size + 16, 16)
    base = blk + 8
    c.emu.w32(blk, size | (c.rng.getrandbits(3) << 29))
    # the global chain
    kvt = c.emu.alloc(0x200, 4)
    c.emu.w32(kvt + 0xbc, _stub(c, _seqstub(seq, rec_bc, True)))
    k = _rnd(c, 0x100)
    c.emu.w32(k, kvt)
    c.emu.w32(0x70038c, k)
    g9 = _rnd(c, 0x2000)
    c.emu.w32(g9 + 0x1c5d, base if c.rng.random() < 0.85 else 0)
    g = _rnd(c, 0x800)
    c.emu.w32(g + 0x9b, g9)
    c.emu.w32(0x70039c, g)
    # the source and this's +0x10 block
    a = _rnd(c, 0x100)
    c.emu.w32(o + 0x10, a)
    src = _rnd(c, 0x800)
    r = c.rng.random()
    if r < 0.2:
        c.emu.w32(src + 0x10, 0)
    else:
        b = _rnd(c, 0x100)
        r2 = c.rng.random()
        if r2 < 0.3:
            v = 0
        elif r2 < 0.7:
            v = base + c.rng.randrange(size)
        else:
            v = c.rng.choice([base - 4, base + size, base + size + 0x100, 0xffffffff, c.rng.getrandbits(32)])
        c.emu.w32(b + 0xc, v & 0xffffffff)
        c.emu.w32(src + 0x10, b)
    c.emu.mu.ctl_flush_tb()
    return [o, src]


S(0x45d720, 'ZGEOM::CopyExData (unknown) thiscall', 'thiscall', None, ret=None, gen=_cx,
  note='unclaimed-27 claim 6; slots +0x44 +0x40 +0xfc +4 and the 0x70038c object slot +0xbc are stubs')
