"""specs_s6537.py - unclaimed-65 batch 37 (docs/20-unclaimed-65.md, claim 21), group 3: ZInputActions::GetButtonName (stdcall, ret 8) with the
high word 1: case 1. P = slot 0x190 of the render object (global 0x70039c); slot 0x198 of P is called with ecx = &L38 and four stack
arguments (P, &L38, 0x67a9b8, index + 1), CALLER-CLEANED; the spec's fake fills the object at ecx with characters inline (its first dword
points at its own +4) and returns zero. Then slot 0 of ([0x70039c] + 0x9b + 0xae4) is called with (0x67a9c4, &L38) and returns a char
pointer, which is assigned to out (the real 0x4cbe80 and 0x4cc630 run). The cookie check runs as the real code."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cstr(c, s):
    a = c.emu.alloc(len(s) + 1, 4)
    c.emu.wbytes(a, s + b'\x00')
    return a


def _setup(c):
    _flush_code(c)


def _gen(c):
    # P: its slot 0x198 (caller-cleaned, four arguments) writes the text inline into the object at ecx
    text = bytes([c.rng.randint(0x41, 0x5a) for _ in range(c.rng.randint(0, 6))])

    def s198(e, r):
        e.calllog.append(('0x198', (e.arg32(0), e.arg32(2), e.arg32(3))))   # ecx (the frame object) is not logged
        o = e.reg('ecx')
        e.w32(o, (o + 4) & 0xffffffff)
        e.wbytes(o + 4, text + b'\x00')
        e.ret(eax=0, argbytes=0)                          # caller cleans the four arguments

    p_vt = c.emu.fake_vtable('gbn-p', 0x300, {0x198: s198})
    p = _rnd(c, 0x40)
    c.emu.w32(p, p_vt)

    # the render object: slot 0x190 returns P
    rend_vt = c.emu.fake_vtable('gbn-render3', 0x300, {
        0x190: lambda e, r: (e.calllog.append(('0x190', e.reg('ecx'), ())), e.ret(eax=p, argbytes=0))})
    rend = _rnd(c, 0x200)
    c.emu.w32(rend, rend_vt)
    c.emu.w32(0x70039c, rend)

    # +0x9b: a block whose +0xae4 is the object o; o's slot 0 returns a C string (the copy source for out)
    tail_s = _cstr(c, b'Button' + bytes([c.rng.randint(0x30, 0x39)]))

    def s0(e, r):
        # logs the key (arg 0) and the C string that the frame object (arg 1, the L38 of the exe) points at: what slot 0x198 wrote
        a = e.r32(e.arg32(1))
        txt = b''
        while len(txt) < 0x40 and e.rbytes(a + len(txt), 1) != b'\x00':
            txt += e.rbytes(a + len(txt), 1)
        e.calllog.append(('0xo0', e.reg('ecx'), (e.arg32(0), txt)))
        e.ret(eax=tail_s, argbytes=8)

    o_vt = c.emu.fake_vtable('gbn-o', 0x40, {0x0: s0})
    o = _rnd(c, 0x40)
    c.emu.w32(o, o_vt)
    r9b = _rnd(c, 0x1000)
    c.emu.w32(r9b + 0xae4, o)
    c.emu.w32(rend + 0x9b, r9b)

    out = _rnd(c, 0x80)
    idx = c.rng.randint(0, 0xffff)
    return [out, (1 << 16) | idx]


S(0x439020, 'ZInputActions::GetButtonName (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen, setup=_setup,
  note='unclaimed-65 batch 37 (claim 21); group 3: case 1, the caller-cleaned slot 0x198 and the slot 0 string')
