"""specs_s5710.py - unclaimed-57, batch 10: vmul (0x4e0940). Fastcall: out in ECX, b in EDX, a on the stack (callee pops). Three single
precision products. Random 16-byte buffers; the harness compares the stored bits (NaN payloads are handled by the harness's NaN rule)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vm(c):
    return [_rnd(c, 16), _rnd(c, 16), _rnd(c, 16)]


S(0x4e0940, 'vmul (unknown) fastcall', 'fastcall', None, ret=None, gen=_vm,
  note='unclaimed-57 batch 10; leaf; out[i] = a[i] * b[i] (a on the stack, b in EDX, out in ECX)')
