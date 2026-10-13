"""specs_s2730.py - unclaimed-27 batch 32: FUN_588940 (GUESS, fastcall: this in ecx, out pointer in edx; returns this).
Stubs, NOT verified: this's vtable slot +0x48 (one arg) writes a chosen count (-1..4) to *arg; slot +0x40 writes a chosen item to
*arg; the global 0x70039c's +0x9b engine object's slot +0x58 (one arg) returns a chosen object X or 0; X's slot +0x1e0 (one arg)
returns a chosen al (0 or 1); X+0x54 holds a random dword. The out buffer has a random count of 0..3 and 0x80 random bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _store_arg_ret4(v):
    # mov eax,[esp+4]; mov dword [eax], v; ret 4
    return b'\x8b\x44\x24\x04' + b'\xc7\x00' + (v & 0xffffffff).to_bytes(4, 'little') + b'\xc2\x04\x00'


def _ret_eax_ret4(v):
    return b'\xb8' + (v & 0xffffffff).to_bytes(4, 'little') + b'\xc2\x04\x00'


def _f8940(c):
    cnt = c.rng.choice([-1, 0, 1, 2, 3, 4])
    item = c.rng.getrandbits(32)
    T_vt = c.emu.alloc(0x200, 4)
    c.emu.w32(T_vt + 0x48, _stub(c, _store_arg_ret4(cnt)))
    c.emu.w32(T_vt + 0x40, _stub(c, _store_arg_ret4(item)))
    T = _rnd(c, 0x100)
    c.emu.w32(T, T_vt)
    X = _rnd(c, 0x100) if c.rng.random() < 0.7 else 0
    X_vt = c.emu.alloc(0x200, 4)
    al = c.rng.choice([0, 1])
    c.emu.w32(X_vt + 0x1e0, _stub(c, _ret_eax_ret4(al)))
    if X:
        c.emu.w32(X, X_vt)
        c.emu.w32(X + 0x54, c.rng.getrandbits(32))
    E_vt = c.emu.alloc(0x200, 4)
    c.emu.w32(E_vt + 0x58, _stub(c, _ret_eax_ret4(X)))
    E = _rnd(c, 0x100)
    c.emu.w32(E, E_vt)
    G = _rnd(c, 0x800)
    c.emu.w32(G + 0x9b, E)
    c.emu.w32(0x70039c, G)
    out = _rnd(c, 0x80)
    c.emu.w32(out, c.rng.randint(0, 3))
    c.emu.mu.ctl_flush_tb()
    return [T, out]


S(0x588940, 'FUN_588940 (GUESS) fastcall', 'fastcall', None, ret='eax', gen=_f8940, reg_values=True,
  note='unclaimed-27 batch 32; this slots +0x48/+0x40, engine slot +0x58, object slot +0x1e0 are stubs')
