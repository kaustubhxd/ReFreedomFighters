"""specs_s1387.py - unclaimed-13 claim 6 (docs/20-unclaimed-13.md): CMoveAlongPath::MoveToSplineVal (0x523840, GUESS name).
Object: 0x800 random bytes with a fresh vtable. Its slot +8 and +0x20 are stubs that record their arguments in a heap record (so both sides
call the same stubs and wrong arguments show up). These two slots are STUBS, not verified. The global at 0x70039c is a fresh
0x800-byte object with random bits at +0x48. Callees 0x522f60 and 0x524180 run as original code. Every input is a random
dword (floats include NaN, inf and zero) so the clamp, sign and compare paths all run."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _mtsv(c):
    g = _rnd(c, 0x800)
    c.emu.w32(0x70039c, g)
    o = _rnd(c, 0x800)
    # 0x522f60 returns 0.0 when +0x4b is 0; otherwise it runs its own code on the pointer there. Half the cases give
    # it a fresh 0x800-byte object so the nonzero branch (and the |r| > pi/180 state) can run.
    if c.rng.random() < 0.5:
        # A sane spline record for 0x460af0: count at +0x10 (2..6), table pointer at +0xc to small random floats.
        sp = _rnd(c, 0x800)
        c.emu.w32(sp + 0x10, c.rng.randint(2, 6))
        tbl = c.emu.alloc(0x400, 16)
        for k in range(0x400 // 4):
            c.emu.w32(tbl + 4 * k, __import__('struct').unpack('<I', __import__('struct').pack('<f', c.rng.uniform(-100.0, 100.0)))[0])
        c.emu.w32(sp + 0xc, tbl)
        c.emu.w32(o + 0x4b, sp)
    else:
        c.emu.w32(o + 0x4b, 0)
    c.emu.w32(o + 0x4f, 0)   # 0x524180 takes its no-pointer path
    # The stubs record their arguments in a heap record, so a port that passes the wrong values is caught:
    # slot +8 stores its two arguments at rec and rec+4, slot +0x20 stores its argument at rec+8.
    rec = c.emu.alloc(0x10, 4)
    a = rec.to_bytes(4, 'little')
    s8 = (b'\x8b\x44\x24\x04' + b'\xa3' + a + b'\x8b\x44\x24\x08' + b'\xa3' + (rec + 4).to_bytes(4, 'little')
          + b'\xc2\x08\x00')
    s20 = b'\x8b\x44\x24\x04' + b'\xa3' + (rec + 8).to_bytes(4, 'little') + b'\xc2\x04\x00'
    vt = c.emu.alloc(0x40, 4)
    c.emu.w32(vt + 8, _stub(c, s8))
    c.emu.w32(vt + 0x20, _stub(c, s20))
    c.emu.w32(o, vt)
    # 0x522f60 is replaced for this case by a stub that returns a chosen float in st0 (the branch-3 probe). This is a
    # stub of an unverified callee: both the exe and the port call the same stub (the hook is on the code address).
    x = c.rng.choice([0.5, 1e-3, 100.0, 5000.0, -7.5, 0.0, float('nan'), float('inf'), c.rng.uniform(-1e4, 1e4)])
    c.emu.hook(0x522f60, lambda e, r, x=x: e.ret(st0=x, argbytes=8))
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(8)]


S(0x523840, 'CMoveAlongPath::MoveToSplineVal (GUESS) thiscall', 'thiscall', None, ret=None, gen=_mtsv,
  note='unclaimed-13 claim 6; slot +8 and +0x20 are stubs; 0x522f60 and 0x524180 are original code')
