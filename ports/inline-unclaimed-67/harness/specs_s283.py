"""specs_s283.py - unclaimed area 67, gap band: 0x5f2e60 (cursor advance to the next NUL; the buffer always has a NUL)."""
from pilot import S


def _case(c):
    buf = c.emu.alloc(0x100, 4)
    data = bytes(c.rng.choice(b'abcdef') for _ in range(0xff)) + b'\x00'
    if c.rng.random() < 0.3:
        data = b'\x00' + data[1:]
    c.emu.wbytes(buf, data)
    out = c.emu.alloc(0x10, 4)
    c.emu.wbytes(out, b'\x00' * 0x10)
    self_ = c.emu.alloc(0x40, 4)
    start = buf + c.rng.choice([0, 1, 5, 0x40, 0x80])
    c.emu.w32(self_ + 8, start)
    c.emu.mu.ctl_flush_tb()
    return [self_, out]


S(0x5f2e60, 'FUN_5f2e60 (cursorPastNul)', 'thiscall', None, ret=None, gen=_case, note='batch283; cursor walk to NUL, then +1')
