"""specs_s312.py - unclaimed-03 batch 12 (docs/20-unclaimed-03.md): ZFFSimpleTrain2::Init2 (0x5b88a0), thiscall, no arguments.
Stubs, all patched per gen (see _flush: the code is rewritten at the same addresses each case):
  * 0x59b310 (original, ss.patch): records ECX and its argument, returns R (0 or random);
  * the global 0x700390 -> G; G's vtable slot +0x20 records its two arguments and returns X;
  * X's vtable slot +0x2c records ECX and its three stack arguments (caller cleans: 'ret');
  * 0x5b9250 (the tail-call target, original, ss.patch): records ECX.
The object at 0x7003b8 has its pointer at +0x2c15. The 0x6b2690, 0x6b26d4 and 0xba values are the PC's constants."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _flush(c):
    """Drop Unicorn's translations for the heap and the exe image (as in the other batches)."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _cell(c, n=1):
    a = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(a, bytes(4 * n))
    return a


def _le(v):
    return v.to_bytes(4, 'little')


def _gen(c):
    self_ = _rnd(c, 0x800)
    # A at 0x7003b8, with B at +0x2c15
    A = _rnd(c, 0x3000)
    B = _rnd(c, 0x40)
    c.emu.w32(A + 0x2c15, B)
    c.emu.w32(0x7003b8, A)
    # 0x59b310: record ECX and its argument, return R
    c_ecx1, c_arg1 = _cell(c), _cell(c)
    R = c.rng.choice([0, c.rng.getrandbits(32) | 1])
    code = (b'\x89\x0d' + _le(c_ecx1) +                    # mov [c_ecx1], ecx
            b'\x8b\x44\x24\x04' + b'\xa3' + _le(c_arg1) +  # mov eax, [esp+4]; mov [c_arg1], eax
            b'\xb8' + _le(R) + b'\xc2\x04\x00')            # mov eax, R; ret 4
    ss.patch(c, 0x59b310, _stub(c, code))
    _flush(c)
    # G at 0x700390: slot +0x20 records its two args and returns X
    X = _rnd(c, 0x40)
    vt_x = c.emu.alloc(0x200, 4)
    x_c1, x_c2, x_c3 = _cell(c), _cell(c), _cell(c)
    # X's slot +0x2c: caller cleans, so 'ret' with three recorded args
    x_ecx = _cell(c)
    xcode = (b'\x89\x0d' + _le(x_ecx) +                          # mov [x_ecx], ecx (the this of the call)
             b'\x8b\x44\x24\x04\xa3' + _le(x_c1) +
             b'\x8b\x44\x24\x08\xa3' + _le(x_c2) +
             b'\x8b\x44\x24\x0c\xa3' + _le(x_c3) + b'\xc3')
    c.emu.w32(vt_x + 0x2c, _stub(c, xcode))
    c.emu.w32(X, vt_x)
    g_c1, g_c2 = _cell(c), _cell(c)
    gcode = (b'\x8b\x44\x24\x04\xa3' + _le(g_c1) +
             b'\x8b\x44\x24\x08\xa3' + _le(g_c2) +
             b'\xb8' + _le(X) + b'\xc2\x08\x00')
    vt_g = c.emu.alloc(0x200, 4)
    c.emu.w32(vt_g + 0x20, _stub(c, gcode))
    G_ = _rnd(c, 0x40)
    c.emu.w32(G_, vt_g)
    c.emu.w32(0x700390, G_)
    # 0x5b9250 (tail-call target): record ECX
    t_ecx = _cell(c)
    ss.patch(c, 0x5b9250, _stub(c, b'\x89\x0d' + _le(t_ecx) + b'\xc3'))
    _flush(c)
    return [self_]


S(0x5b88a0, 'ZFFSimpleTrain2::Init2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-03 batch 12; stubs: 0x59b310, global 0x700390 vtbl+0x20, X vtbl+0x2c, tail target 0x5b9250')
