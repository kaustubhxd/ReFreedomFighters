"""specs_s237.py - area 59, batch237 (src/batch237.cpp): 0x4414a0, a cursor walk. The list nodes are distinct and end in 0
or in the stop value, so the walk terminates. 0x4db9a0 is a recorder with a per-case result (ecx and the flags argument are
logged in heap slots; its stack argument is a constant, so no stack address is recorded)."""
from pilot import S
import serial_stubs as ss
from helpers22 import _rnd, _flush_heap_code, jmp_patch


def _g_4414a0(c):
    self_ = _rnd(c, 0x100)
    nodes = [_rnd(c, 0x100) for _ in range(c.rng.randint(1, 4))]
    grp = []
    for n in nodes:
        t = _rnd(c, 0x40)
        q = _rnd(c, 0x40)
        c.emu.w32(t + 0xc, q)
        c.emu.w32(q + 0x23, c.rng.choice([0x100000, 0, 0x100000 | c.rng.getrandbits(8), c.rng.getrandbits(32)]))
        c.emu.w32(n + 0x54, t if c.rng.random() < 0.85 else 0)
        grp.append(t)
    for i, n in enumerate(nodes):
        c.emu.w32(n + 0x50, nodes[i + 1] if i + 1 < len(nodes) else 0)
        c.emu.w32(n + 0x60, c.rng.choice([0, 0, c.rng.getrandbits(32)]))
    stop = c.rng.choice([nodes[0] ^ 0x1000, nodes[-1] if len(nodes) > 1 else nodes[0] ^ 0x1000])
    c.emu.w32(self_ + 8, stop)
    c.emu.w32(self_ + 0x4c, c.rng.choice([0, 1]))
    cur = _rnd(c, 4)
    c.emu.w32(cur, stop if c.rng.random() < 0.3 else nodes[0])   # stop value at the cursor reaches the first branch
    # 0x4db9a0 stand-in: stores ecx and its argument, returns a case value in eax (ret 4)
    ecx_s = c.emu.alloc(4, 4)
    a_s = c.emu.alloc(4, 4)
    c.emu.w32(ecx_s, 0)
    c.emu.w32(a_s, 0)
    rv = c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])
    code = (b'\x89\x0d' + ss.P(ecx_s) + b'\x8b\x44\x24\x04\xa3' + ss.P(a_s)
            + b'\xb8' + ss.P(rv) + b'\xc2\x04\x00')
    jmp_patch(c, 0x4db9a0, ss.code(c, code))
    _flush_heap_code(c)
    c.emu.mu.ctl_flush_tb()
    return [self_, cur]


S(0x4414a0, 'walkCursor (GUESS)', 'thiscall', None, ret=None, gen=_g_4414a0,
  note='batch237; cursor walk over a list at +0x50 / +0x60; 0x4db9a0 stubbed (ecx and argument recorded)')
