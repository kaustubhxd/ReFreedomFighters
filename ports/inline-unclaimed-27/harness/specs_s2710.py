"""specs_s2710.py - residue-07 entry 0x4a1a70 (FUN_4a1a70, GUESS name), thiscall, no arguments, ret 0.
Stubs and hooks, NOT verified:
 - Global 0x70039c -> G with +0x9b -> P9; P9's slot +0x138 returns P (no args).
 - P's slot +0x88 (args: 0x68f724, &local) writes X to *&local (X is 0 or an object).
 - Global 0x70038c -> K: slot +0xcc (one arg) returns R1, slot +0x20 (one arg) returns R2, slot +0xac (one arg) counts calls;
   K+8 is 0 or a stub (no args) returning R3; K+0xc and K+0x10 bound the call path.
 - The static at 0x7002a8 is 0 (then the 0x41e290 / 0x4ccba0 hooks run) or an object S whose slot +4 (one arg) records it.
 - 0x41e290 (cdecl) is hooked to return M (0 or an object); 0x4ccba0 (thiscall) is hooked to return its this.
`this` is at o+0x10, so this-4 is readable."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _mov_eax(v):
    return b'\xb8' + (v & 0xffffffff).to_bytes(4, 'little')


def _f4a1a70(c):
    cnt = c.emu.alloc(0x40, 4)           # +0 K.+0xac calls, +4 K+8 calls, +8 hook 41e290, +0xc hook 4ccba0
    srec = c.emu.alloc(0x10, 4)           # S.+4 argument

    def inc(k):
        return lambda e, r: e.w32(cnt + k, (e.r32(cnt + k) + 1) & 0xffffffff)

    xobj = _rnd(c, 0x100)
    x = xobj if c.rng.random() < 0.7 else 0
    # P9 and P
    pvt = c.emu.alloc(0x200, 4)
    c.emu.w32(pvt + 0x88, _stub(c, b'\x8b\x44\x24\x08' + b'\xc7\x00' + x.to_bytes(4, 'little') + b'\xc2\x08\x00'))
    p = _rnd(c, 0x100)
    c.emu.w32(p, pvt)
    g9vt = c.emu.alloc(0x200, 4)
    c.emu.w32(g9vt + 0x138, _stub(c, _mov_eax(p) + b'\xc3'))
    g9 = _rnd(c, 0x800)
    c.emu.w32(g9, g9vt)
    g = _rnd(c, 0x800)
    c.emu.w32(g + 0x9b, g9)
    c.emu.w32(0x70039c, g)
    # K
    kvt = c.emu.alloc(0x200, 4)
    r1 = c.rng.choice([0, 1])
    r2 = c.rng.choice([0, 1, 0])
    c.emu.w32(kvt + 0xcc, _stub(c, _mov_eax(r1) + b'\xc2\x04\x00'))
    c.emu.w32(kvt + 0x20, _stub(c, _mov_eax(r2) + b'\xc2\x04\x00'))
    c.emu.w32(kvt + 0xac, _stub(c, b'\xff\x05' + (cnt).to_bytes(4, 'little') + b'\xc2\x04\x00'))
    k = _rnd(c, 0x100)
    c.emu.w32(k, kvt)
    r3 = c.rng.getrandbits(32)
    fn = _stub(c, b'\xff\x05' + (cnt + 4).to_bytes(4, 'little') + _mov_eax(r3) + b'\xc3') if c.rng.random() < 0.7 else 0
    c.emu.w32(k + 8, fn)
    if c.rng.random() < 0.6:
        c.emu.w32(k + 0xc, 0)
        c.emu.w32(k + 0x10, 0xffffffff)
    else:
        c.emu.w32(k + 0xc, c.rng.getrandbits(32))
        c.emu.w32(k + 0x10, c.rng.getrandbits(32))
    c.emu.w32(0x70038c, k)
    # the static at 0x7002a8
    if c.rng.random() < 0.5:
        s = 0   # the creation path (0x41e290 then 0x4ccba0) runs and makes the static from M
    else:
        s = _rnd(c, 0x100)
        svt = c.emu.alloc(0x200, 4)
        c.emu.w32(svt + 4, _stub(c, b'\x8b\x44\x24\x04\xa3' + srec.to_bytes(4, 'little') + b'\xc2\x04\x00'))
        c.emu.w32(s, svt)
    c.emu.w32(0x7002a8, s)
    # the hooks for 0x41e290 (cdecl) and 0x4ccba0 (thiscall)
    # M is always a valid object with its own vtable (slot +4 records its argument), since the static created from M becomes
    # the receiver of the final call; a random vtable would jump to random code in both sides.
    mvt = c.emu.alloc(0x200, 4)
    c.emu.w32(mvt + 4, _stub(c, b'\x8b\x44\x24\x04\xa3' + srec.to_bytes(4, 'little') + b'\xc2\x04\x00'))
    mobj = _rnd(c, 0x100)
    c.emu.w32(mobj, mvt)
    c.emu.hook(0x41e290, lambda e, r, mobj=mobj: (e.w32(cnt + 8, (e.r32(cnt + 8) + 1) & 0xffffffff), e.ret(eax=mobj, argbytes=0)))
    c.emu.hook(0x4ccba0, lambda e, r: (e.w32(cnt + 0xc, (e.r32(cnt + 0xc) + 1) & 0xffffffff), e.ret(eax=e.reg('ecx'), argbytes=0)))
    # this = o + 0x10 (this-4 readable)
    o = _rnd(c, 0x800)
    c.emu.mu.ctl_flush_tb()
    return [0 if c.rng.random() < 0.15 else o + 0x10]   # this == 0 in about 15% of cases


S(0x4a1a70, 'FUN_4a1a70 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f4a1a70,
  note='residue-07 batch 10; P/P9/K/S vtable slots and hooks are stubs')
