"""specs_s2701.py - unclaimed-27 claim 1 (docs/20-unclaimed-27.md): ZPlayer::MoveToMatPos (0x484320) and ZPlayer::SetDialog
(0x484fa0). Objects are 0x800 random bytes with a fresh vtable.
Stubs (NOT verified): MoveToMatPos's slot +0x5b0 records its first argument and the three floats it is given (copied
through its second argument). SetDialog's slot +0x534 returns a random value in al, and slot +0x220 counts calls in a heap record.
0x475910 is original code (sets this+0x3bb). The translation cache is flushed at the end of each gen."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _mtmp(c):
    rec = c.emu.alloc(0x10, 4)
    a = rec.to_bytes(4, 'little')
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + a                        # mov eax,[esp+4]; mov [rec],eax
            + b'\x8b\x44\x24\x08'                                    # mov eax,[esp+8]
            + b'\x8b\x08\x89\x0d' + (rec + 4).to_bytes(4, 'little')  # mov ecx,[eax]; mov [rec+4],ecx
            + b'\x8b\x48\x04\x89\x0d' + (rec + 8).to_bytes(4, 'little')    # mov ecx,[eax+4]; mov [rec+8],ecx
            + b'\x8b\x48\x08\x89\x0d' + (rec + 12).to_bytes(4, 'little')   # mov ecx,[eax+8]; mov [rec+12],ecx
            + b'\xc2\x08\x00')                                       # ret 8
    o = _rnd(c, 0x800)
    vt = c.emu.alloc(0x600, 4)
    c.emu.w32(vt + 0x5b0, _stub(c, code))
    c.emu.w32(o, vt)
    c.emu.wbytes(o + 0x451, bytes(c.rng.getrandbits(8) for _ in range(4)))
    inp = _rnd(c, 12)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32), inp]


def _sd(c):
    o = _rnd(c, 0x800)
    vt = c.emu.alloc(0x600, 4)
    r = c.rng.getrandbits(8)
    c.emu.w32(vt + 0x534, _stub(c, b'\xb8' + r.to_bytes(4, 'little') + b'\xc3'))   # mov eax, r; ret (al = r)
    cnt = c.emu.alloc(0x10, 4)
    c.emu.w32(vt + 0x220, _stub(c, b'\xff\x05' + cnt.to_bytes(4, 'little') + b'\xc2\x04\x00'))   # inc [cnt]; ret 4
    c.emu.w32(o, vt)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.choice([0, 1, 0x100, 0xff, c.rng.getrandbits(32)])]


S(0x484320, 'ZPlayer::MoveToMatPos (unknown) thiscall', 'thiscall', None, ret=None, gen=_mtmp,
  note='unclaimed-27 claim 1; slot +0x5b0 is a stub that records its arguments')
S(0x484fa0, 'ZPlayer::SetDialog (unknown) thiscall', 'thiscall', None, ret=None, gen=_sd,
  note='unclaimed-27 claim 1; slot +0x534 and +0x220 are stubs; 0x475910 is original code')
