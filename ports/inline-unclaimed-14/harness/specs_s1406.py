"""specs_s1406.py - unclaimed-14 batch 6 (slice 13): ZActorIf::SetVisLightMultiplier (0x508410, thiscall with this = the
ZActorIf, one stack argument X, ret 4).

Setup per case: this+0x18 = C (a 0x1000-byte object with random +0x73a); the global at 0x70039c points to A, A+0x9b = B
(0x200 bytes). X+4 = S, a table struct {D, 0, count 1}; D = {T, ..., limit 0x100}; T is 0x800 random bytes, so the
original code at 0x5003d0 (run as original code) returns T. Stubs: B.slot+0x4c stores its argument at B+0x40 and returns a
random eax; B.slot+0x114 stores its second argument at B+0x5c and a random immediate at B+0x48, and returns a random eax (ax is used); B.slot+0x58 stores
its two arguments at B+0x50 and B+0x54 and returns a random eax; C.slot+0x130 stores its argument at C+0x70."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    m = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(m, code)
    return m


def _imm(v):
    return v.to_bytes(4, 'little')


def _vis(c):
    this = _rnd(c, 0x200)
    cobj = _rnd(c, 0x1000)
    vtc = c.emu.alloc(0x140, 4)
    c.emu.w32(vtc + 0x130, _stub(c, b'\x8b\x44\x24\x04' + b'\x89\x41\x70' + b'\xc2\x04\x00'))
    c.emu.w32(cobj, vtc)
    c.emu.w32(this + 0x18, cobj)

    b = _rnd(c, 0x200)
    vtb = c.emu.alloc(0x120, 4)
    r1 = c.rng.getrandbits(32)
    r2 = c.rng.getrandbits(32)
    c.emu.w32(vtb + 0x4c, _stub(c, b'\x8b\x44\x24\x04' + b'\x89\x41\x40' + b'\xb8' + _imm(r1) + b'\xc2\x04\x00'))
    # slot +0x114 takes FIVE stack arguments (&r1, line, file, 0, name: the PC pushes all five and does not adjust esp after the
    # call; its epilogue pops edi, esi, ebx, so the callee must pop 20 bytes: ret 0x14). Stores its second argument at B+0x5c,
    # a random immediate at B+0x48, returns a random eax.
    c.emu.w32(vtb + 0x114, _stub(c, b'\x8b\x44\x24\x08' + b'\x89\x41\x5c'
                                 + b'\xc7\x81' + (0x48).to_bytes(4, 'little') + _imm(r2)
                                 + b'\xb8' + _imm(c.rng.getrandbits(32)) + b'\xc2\x14\x00'))
    c.emu.w32(vtb + 0x58, _stub(c, b'\x8b\x44\x24\x04' + b'\x89\x41\x50' + b'\x8b\x44\x24\x08' + b'\x89\x41\x54'
                                + b'\xb8' + _imm(c.rng.getrandbits(32)) + b'\xc2\x08\x00'))
    c.emu.w32(b, vtb)
    g = _rnd(c, 0x200)
    c.emu.w32(g + 0x9b, b)
    c.emu.w32(0x70039c, g)

    x = _rnd(c, 0x20)
    s = _rnd(c, 0x20)
    d = _rnd(c, 0x20)
    t = _rnd(c, 0x800)
    c.emu.w32(d, t)
    c.emu.w32(d + 8, 0x100)
    c.emu.w32(s, d)
    c.emu.w32(s + 4, 0)
    c.emu.w32(s + 8, 1)
    c.emu.w32(x + 4, s)
    return [this, x]


S(0x508410, 'ZActorIf::SetVisLightMultiplier (unknown) thiscall', 'thiscall', None, ret=None, gen=_vis,
  note='unclaimed-14 batch 6; calls 0x5003d0 (original); stubs B slots +0x4c/+0x114/+0x58 and C slot +0x130')
